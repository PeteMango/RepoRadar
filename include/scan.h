#ifndef SCAN_H
#define SCAN_H

string trimPath(string directoryPath);
void findPaths(string directoryToScan, ofstream &out);
void buildReposList(vector<shared_ptr<Repo>> &repos);

#endif