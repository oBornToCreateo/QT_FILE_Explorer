#include <exception>
#include <iostream>

#include <QTextStream>
#include <QDirIterator> 
#include <QCoreApplication>
#include <QFileSystemWatcher>

#include <qstring.h>

auto input = QTextStream(stdin);
auto output = QTextStream(stdout);


int main(int argc, char* argv[])
{
    output.setEncoding(QStringConverter::Utf8);

    //auto encoding = QStringConverter::encodingForName("UTF-8");

    try {
        QCoreApplication a(argc, argv);
        auto path = QString();

        // --- Read User Input  & Test Message

        output << "źźźźńńńńńśśśCśóóóó" << Qt::endl;

        output << "Enter Valid File Path : " << Qt::endl;
        path = input.readLine();
        output << path << Qt::endl;

        // ---- Pass the path and start watching the directory

        QFileSystemWatcher watcher;
        watcher.addPath(path);

        // ---- Iterate throught folder Contents          
        //QDirIterator it(path, QDirIterator::Subdirectories);

        QDirIterator folderIt(path, {}, QDir::Files | QDir::Dirs);

        while (folderIt.hasNext()) {

            QFile file(folderIt.next());
            qDebug() << file.fileName() << Qt::endl;

        }

        return a.exec();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}

//namespace fs = std::filesystem;

/*
std::vector<std::pair<long long, std::wstring>> IterateThroughtAndDisplayContents(std::wstring path) {

    int item_number = 1;
    std::vector<std::pair<long long, std::wstring>>  Names;

    for (const auto& entry : fs::directory_iterator(path)) {
        auto pathfiles_names = entry.path().filename().wstring();
        auto pathfiles_size = entry.file_size();
        auto pathfiles_regtype = entry.is_regular_file();
        auto pathfiles_dirtype = entry.is_directory();

        //--------------------[DSPLAY DIR CONTENT]--------------------------

        std::wcout.width(6); std::wcout << item_number << L". ";
        if (pathfiles_regtype)
            std::wcout << L"[FILE]" << L" ";
        else if (pathfiles_dirtype)
            std::wcout << L"[DIR]" << L" ";
        std::wcout << pathfiles_names << std::endl;
        std::wcout << std::endl;

        //------------------[PREPARE FOR COMPARASION]----------------------

        Names.push_back(std::make_pair(pathfiles_size, pathfiles_names));
        item_number++;
    }
    item_number = 1;

    return Names;
}
*/
/*

try {

    const char* const localeName = "pl_PL.utf-8";
    std::setlocale(LC_ALL, localeName);
    std::locale::global(std::locale(localeName));

    do {
        std::wstring path;
        std::vector<std::pair<long long, std::wstring>>  Names_Old, Names_New;

        std::wcout << L"enter directory path : ";
        std::wcin >> path; std::cout << std::endl;
        std::wcout << L"Choosen directory content" << std::endl << std::endl;

        QFileSystemWatcher Watcher;

        if (Watcher.addPath(QString::fromStdWString(path)))
        {
            std::cout << " Patch Exists " << std::endl;
        }
        else
        {
            std::cout << " Patch Does Not Exists " << std::endl;

        }

        Names_Old = IterateThroughtAndDisplayContents(path);


        do {
            std::wcout << std::endl;
            std::wcout << L"Refresh? [Y/N] : ";

            std::wstring choise;
            std::wcin >> choise;

            if (choise == L"Y") {

                Names_New = IterateThroughtAndDisplayContents(path);

                if (Names_New == Names_Old)

                    std::cout << " There are no changes in the contents " << std::endl;
                else
                    std::cout << " There are changes in the contents " << std::endl;

                continue;

            }
            else if (choise == L"N")
                break; // display beginning

            else
                std::wcout << std::endl;
            std::wcout << L"Wrong command !" << std::endl;

        } while (true);

    } while (true);

}
catch (const std::exception& error)
{
    std::wcout << error.what() << std::endl;
}*/