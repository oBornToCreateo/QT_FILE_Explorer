#include <exception>
#include <iostream>


#include <QSet>
#include <QVector> 
#include <QTextCodec>
#include <QTextStream>
#include <QDirIterator> 
#include <QCoreApplication>
#include <QFileSystemWatcher>

#include <qdebug.h>


QVector<QString> IterateAndDisplayContent(QString path) {

    QVector<QString> entries;

    QDirIterator folderIt(path, {}, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
     
    qDebug() << Qt::endl << " ----------------------------------[ Folder Contents ]----------------------------- " << Qt::endl << Qt::endl;

    int position = 0;
    while (folderIt.hasNext()) {

        QFile file(folderIt.next());
        entries.insert(position, file.fileName());
        qDebug() << position << " " << file.fileName() << Qt::endl;
        position++;

    }
    position = 1;
    
    return entries;
}


int main(int argc, char* argv[]) {

    try {
        QCoreApplication a(argc, argv);

        QVector<QString> entriesNew, entriesOld;

        QTextStream input(stdin);
        input.setCodec("UTF-8");
        input.autoDetectUnicode();

        QTextStream output(stdout);
        output.setCodec("UTF-8");
        output.autoDetectUnicode();

        // --- Read User Input  & Test Message

        QString path;
        output << "Enter Valid File Path : " << Qt::endl;
        path = input.readLine();

        // ---- Pass the path and start watching the directory
        do{
            QFileSystemWatcher* watcher = new QFileSystemWatcher();

            if (!watcher->files().contains(path))
            {
                watcher->addPath(path);
                output << " Directory added " << Qt::endl;
            }

            QStringList directoryList = watcher->directories();
            Q_FOREACH(QString directory, directoryList)
                qDebug() << "Directory name" << directory << "\n";

            // ---- Iterate throught folder Contents          

            entriesOld = IterateAndDisplayContent(path);


        } while (true);
       
        return a.exec();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}
