#include "include/repo.h"
#include <git2.h>

const string monitoredRepositories = "../data/repos.txt";

string trimAuthorEmail(const char *authorEmail)
{
    string email(authorEmail), ret = "";
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '+')
        {
            for (int j = i + 1; j < email.length(); j++)
            {
                if (email[j] == '@')
                {
                    break;
                }
                ret += email[j];
            }
            break;
        }
    }
    return ret;
}

Commit::Commit(git_time_t time, const string &msg, const git_signature *author) : timestamp(time), message(msg)
{
    this->author = author->name;
    this->email = trimAuthorEmail(author->email);
}

Repo::Repo(const string &name, const string &path, const string &link) : name(name), path(path), link(link)
{
    this->totalCommits = 0;
    this->pastYearCommits = 0;
}

Repo::Repo(const string &name, const string &path) : name(name), path(path)
{
    this->totalCommits = 0;
    this->pastYearCommits = 0;
}

void Repo::getCommits()
{
    git_repository *repo = nullptr; // git2.h constants
    git_revwalk *walker = nullptr;
    git_oid oid;
    git_commit *commit = nullptr;

    git_libgit2_init(); // init git2.h

    if (git_repository_open(&repo, this->path.c_str()) != 0) // open repo
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

        git_time_t timestamp = git_commit_time(commit);
        string message = git_commit_message(commit) ? git_commit_message(commit) : "";
        const git_signature *author = git_commit_author(commit);

        commitLog.push_back(make_shared<Commit>(timestamp, message, author));

        git_commit_free(commit);
    }

    git_revwalk_free(walker); // free revwalker and repo
    git_repository_free(repo);

    git_libgit2_shutdown(); // close git2.h
}

vector<shared_ptr<Commit>> Repo::commitsByAuthor(const string &author)
{
    vector<shared_ptr<Commit>> ret;
    for (const auto &commit : this->commitLog)
    {
        if (commit->author == author)
        {
            ret.push_back(commit);
        }
    }
    return ret;
}
