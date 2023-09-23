#include "Util.h"

void Util::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Util::pauseScreen()
{
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
#endif
}

std::string Util::validateInput(const std::string &regexPattern)
{
    std::string input;
    std::regex pattern(regexPattern);

    while (true)
    {
        try
        {
            std::getline(std::cin, input);
            if (std::regex_match(input, pattern))
            {
                return input;
            }
            else
            {
                throw std::invalid_argument("Invalid input!");
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << " Please try again: ";
        }
    }
}

bool Util::validateDatabaseExist()
{
    const char *databasePathH = "Settings.db";
    bool exist = (access(databasePathH, F_OK) != -1);

    if (exist)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Util::createDatabase()
{
    sqlite3 *database;
    const char *databasePathH = "Settings.db";
    if (sqlite3_open(databasePathH, &database) == SQLITE_OK)
    {
        const char *createTableSQL = "CREATE TABLE IF NOT EXISTS settings ("
                                     "name TEXT, "
                                     "key TEXT, "
                                     "email TEXT, "
                                     "odo INTEGER, "
                                     "remindService INTEGER, "
                                     "displayLight INTEGER, "
                                     "screenLight INTEGER, "
                                     "taploLight INTEGER, "
                                     "media INTEGER, "
                                     "call INTEGER, "
                                     "navi INTEGER, "
                                     "noti INTEGER, "
                                     "language TEXT, "
                                     "timezone TEXT);";
        if (sqlite3_exec(database, createTableSQL, 0, 0, 0) == SQLITE_OK)
        {
            sqlite3_close(database);
            return true;
        }
        sqlite3_close(database);
    }
    return false;
}

std::vector<std::string> Util::getResource(const std::string &filePath)
{
    std::vector<std::string> resource;

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Unable to open " << filePath << " for reading!" << std::endl;
        return resource;
    }
    std::string line;
    while (std::getline(file, line))
    {
        resource.push_back(line);
    }
    file.close();
    return resource;
}

void Util::printResource(const std::vector<std::string> &resource)
{
    for (int i = 0; i < resource.size(); i++)
    {
        if (i < 9)
        {
            std::cout << " " << i + 1 << ". " << resource.at(i) << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". " << resource.at(i) << std::endl;
        }
    }
}