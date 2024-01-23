#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <git2.h>
using namespace std;
namespace fs = filesystem;

const string monitoredRepositories = "../data/repos.txt";

/* searches for Git repositories in a given path */
void scanPath(string path)
{
    cout << "Scanning: " << path << "\n";
}

/* prints the github stats */
void printStats()
{
    cout << "Printing Stats: \n";
}

/* trims the directory path to get directory name */
string trimPath(string directoryPath)
{
    string directName = "";
    for (int i = directoryPath.length() - 1; i >= 0; i--)
    {
        if (directoryPath[i] == '/')
        {
            break;
        }
        directName += directoryPath[i];
    }
    reverse(directName.begin(), directName.end());
    return directName;
}

/* recursively searches for directories with a .git folder */
void findPaths(string directoryToScan, ofstream &out)
{
    if (!fs::is_directory(directoryToScan))
    {
        throw runtime_error("not a path to a directory");
        return;
    }

    string directName = trimPath(directoryToScan);

    /* ignores large folders that can't possibly contain git repositories */
    if (directName == "node_modules" || directName == "vendor")
    {
        // cout << "ignored: " << directName << "\n";
        return;
    }
    // cout << "currently in [" << directName << "]\n";

    for (const fs::directory_entry &eachItem : fs::directory_iterator(directoryToScan))
    {
        if (fs::is_directory(eachItem.path()))
        {
            string subdirectName = trimPath(eachItem.path());
            if (subdirectName == ".git")
            {
                out << directoryToScan << "\n";
                return;
            }
            findPaths(eachItem.path(), out);
        }
        else
        {
            continue;
        }
    }
    return;
}

int main()
{
    string pathToDirectory = "/Users/petemango/Library/Mobile Documents/com~apple~CloudDocs";
    ofstream outFile(monitoredRepositories);

    if (!outFile)
    {
        cerr << "ERROR: could not open monitored repo file\n";
        return 1;
    }

    try
    {
        findPaths(pathToDirectory, outFile);
    }
    catch (runtime_error &e)
    {
        cerr << "ERROR: " << e.what() << "\n";
        return 1;
    }
    outFile.close();
}