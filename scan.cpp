#include <iostream>
#include <filesystem>
#include <git2.h>
using namespace std;
namespace fs = filesystem;

/*
    - searches for Git repositories in a given path
*/
void scanPath(string path)
{
    cout << "Scanning: " << path << "\n";
}

/*
    - prints the github stats
*/
void printStats()
{
    cout << "Printing Stats: \n";
}

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

void findPaths(string directoryToScan)
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
                cout << trimPath(directoryToScan) << "\n";
                return;
            }
            findPaths(eachItem.path());
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
    try
    {
        findPaths(pathToDirectory);
    }
    catch (runtime_error &e)
    {
        cerr << e.what() << "\n";
        return 1;
    }
}