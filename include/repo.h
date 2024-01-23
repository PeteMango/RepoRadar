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
    string commitMessage, authorName, authorEmail;
    git_time_t commitTime;

    GitCommit(git_time_t time, const string &msg, const git_signature *author);
};

class MonitoredRepo
{
public:
    string repoName, diskPath, githubLink;
    int numCommits;
    vector<shared_ptr<GitCommit>> commits;
    unordered_map<string, vector<shared_ptr<GitCommit>>> authorCommits;
    unordered_map<string, string> emailAuthorMap;

    MonitoredRepo(const string &name, const string &path, const string &link);
    MonitoredRepo(const string &name, const string &path);
    void populateCommits();
    void filterCommitsByAuthor();
    int countCommits() const;

private:
};

#endif
