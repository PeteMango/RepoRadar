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

class Commit
{
public:
    string message, author, email;
    git_time_t timestamp;

    Commit(git_time_t time, const string &msg, const git_signature *author);
};

class Repo
{
public:
    string name, path, link;
    int totalCommits, pastYearCommits;
    vector<shared_ptr<Commit>> commitLog;

    Repo(const string &name, const string &path);
    Repo(const string &name, const string &path, const string &link); // constructors

    void getCommits();                                                         // populate commitLog
    void getGithubLink();                                                      // gets repo's github link
    vector<shared_ptr<Commit>> getCommitsByAuthor(const string &author);       // get commits by an author
    vector<shared_ptr<Commit>> getPastYearCommits(vector<shared_ptr<Commit>>); // get commits from the past year
};

class Calendar
{
public:
    vector<shared_ptr<Commit>> year[365];

    Calendar();

    void getDailyCommits(vector<shared_ptr<Commit>>);
};

#endif
