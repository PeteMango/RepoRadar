#ifndef REPO_H
#define REPO_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <git2.h>
using namespace std;

class GitCommit
{
public:
    string commitMessage;
    git_time_t commitTime;

    GitCommit(git_time_t time, const string &msg);
};

class MonitoredRepo
{
public:
    string repoName, diskPath, githubLink;
    int numCommits;
    vector<shared_ptr<GitCommit>> commits;

    MonitoredRepo(const string &name, const string &path, const string &link);
    MonitoredRepo(const string &name, const string &path);
    void populateCommits();
    int countCommits() const;
};

#endif
