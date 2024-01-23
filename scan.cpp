#include "include/repo.h"
using namespace std;
namespace fs = filesystem;

vector<shared_ptr<MonitoredRepo>> repos;

const string monitoredRepositories = "../data/repos.txt";

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
        }
    }

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

void buildReposList()
{
    // repos.clear();
    ifstream inFile(monitoredRepositories);
    if (!inFile)
    {
        throw runtime_error("could not open the repo file\n");
        return;
    }

    string input = "";
    while (getline(inFile, input))
    {
        repos.push_back(make_shared<MonitoredRepo>(trimPath(input), input));
    }
    cout << "DEBUG: " << repos.size() << "\n";

    for (auto repo : repos)
    {
        repo->populateCommits();
        repo->filterCommitsByAuthor();
        cout << repo->repoName << " " << repo->countCommits() << "\n";
    }

    for (auto repo : repos)
    {
        cout << "NAME: " << repo->repoName << "\n";
        for (auto p : repo->authorCommits)
        {
            cout << p.first << " " << p.second.size() << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    string pathToDirectory = "/Users/petemango/Library/Mobile Documents/com~apple~CloudDocs/Documents";
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

    try
    {
        buildReposList();
    }
    catch (runtime_error &e)
    {
        cout << "ERROR: " << e.what() << "\n";
        return 1;
    }
}