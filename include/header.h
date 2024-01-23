#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <git2.h>
using namespace std;

struct GitCommits
{
    git_time_t commitTime;
    GitCommits(git_time_t time);
};

struct MonitoredRepos
{
    string name, path;
    vector<GitCommits> commits;

    MonitoredRepos(string repoPath);
};

#endif
