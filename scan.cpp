#include "include/repo.h"
#include "include/calendar.h"
using namespace std;
namespace fs = filesystem;

const string monitoredRepositories = "../data/repos.txt";

/* gets directory name from directory path */
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
    if (!fs::is_directory(directoryToScan)) // check if item is directory
    {
        throw runtime_error("not a path to a directory");
        return;
    }

    string directName = trimPath(directoryToScan);

    if (directName == "node_modules" || directName == "vendor") // ignore large folders that can't contain git files
    {
        return;
    }

    for (const fs::directory_entry &eachItem : fs::directory_iterator(directoryToScan)) // stop searching if found git
    {
        if (fs::is_directory(eachItem.path()))
        {
            string subdirectName = trimPath(eachItem.path());
            if (subdirectName == ".git")
            {
                out << directoryToScan << "\n";
                return;
            }
        }
    }

    for (const fs::directory_entry &eachItem : fs::directory_iterator(directoryToScan)) // search subdirectories
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

void buildReposList(vector<shared_ptr<Repo>> &repos)
{
    ifstream inFile(monitoredRepositories);
    if (!inFile) // open file
    {
        throw runtime_error("could not open the repo file\n");
        return;
    }

    string input = "";
    while (getline(inFile, input)) // read from previously watched repos
    {
        repos.push_back(make_shared<Repo>(trimPath(input), input));
    }

    for (auto repo : repos)
    {
        repo->getCommits(); // populate commits
    }
    return;
}
