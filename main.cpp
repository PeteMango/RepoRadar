#include "include/repo.h"
#include "include/scan.h"
#include "include/calendar.h"

const string monitoredRepositories = "../data/repos.txt";
vector<shared_ptr<Repo>> repos;
vector<string> githubUsername = {"PeteMango"};
vector<string> pathToDirectory = {"/Users/petemango/Library/Mobile Documents/com~apple~CloudDocs/Documents/Github", "/Users/petemango/Library/Mobile Documents/com~apple~CloudDocs/Documents/University"};
vector<int> year(365, 0);

int main()
{
    Calendar c;
    ofstream outFile(monitoredRepositories);

    if (!outFile)
    {
        cerr << "ERROR: could not open monitored repo file\n";
        return 1;
    }

    for (auto path : pathToDirectory)
    {
        try
        {
            findPaths(path, outFile);
        }
        catch (runtime_error &e)
        {
            cerr << "ERROR: " << e.what() << "\n";
            return 1;
        }
    }

    outFile.close();

    try
    {
        buildReposList(repos);
    }
    catch (runtime_error &e)
    {
        cout << "ERROR: " << e.what() << "\n";
        return 1;
    }

    for (auto repo : repos)
    {
        vector<shared_ptr<Commit>> commits = repo->getCommitsByAuthor(githubUsername[0]);
        vector<shared_ptr<Commit>> pastYear = repo->getPastYearCommits(commits);

        time_t current = time(nullptr);
        for (const auto &commit : pastYear)
        {
            int day = (current - commit->timestamp) / (24 * 60 * 60);
            year[364 - day]++;
        }
    }

    vector<int> past20Weeks(year.end() - 140, year.end());
    c.printCommits(past20Weeks);
}