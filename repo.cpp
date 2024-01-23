#include "include/repo.h"
#include <git2.h>

using namespace std;

const string monitoredRepositories = "../data/repos.txt";

GitCommit::GitCommit(git_time_t time, const string &msg) : commitTime(time), commitMessage(msg) {}

MonitoredRepo::MonitoredRepo(const string &name, const string &path, const string &link) : repoName(name), diskPath(path), githubLink(link) {}

MonitoredRepo::MonitoredRepo(const string &name, const string &path) : repoName(name), diskPath(path) {}

void MonitoredRepo::populateCommits()
{
    git_repository *repo = nullptr; // git2.h constants
    git_revwalk *walker = nullptr;
    git_oid oid;
    git_commit *commit = nullptr;

    git_libgit2_init(); // init git2.h

    if (git_repository_open(&repo, this->diskPath.c_str()) != 0) // open repo
    {
        throw runtime_error("could not open repository");
        return;
    }

    if (git_revwalk_new(&walker, repo) != 0) // init rev walker
    {
        throw runtime_error("could not revwalk the repo");
        git_repository_free(repo);
        return;
    }

    git_revwalk_sorting(walker, GIT_SORT_TOPOLOGICAL); // set revwalker to head of repo
    git_revwalk_push_head(walker);

    while (git_revwalk_next(&oid, walker) == 0)
    {
        if (git_commit_lookup(&commit, repo, &oid) != 0) // check commit validity
        {
            continue;
        }

        git_time_t commit_time = git_commit_time(commit);
        const char *commit_msg = git_commit_message(commit);

        string commitMessage = commit_msg ? commit_msg : "";

        commits.push_back(make_shared<GitCommit>(commit_time, commitMessage));

        git_commit_free(commit);
    }

    git_revwalk_free(walker); // free revwalker and repo
    git_repository_free(repo);

    git_libgit2_shutdown(); // close git2.h
}

int MonitoredRepo::countCommits() const
{
    return static_cast<int>(commits.size());
}