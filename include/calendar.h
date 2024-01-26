#ifndef CALENDAR_H
#define CALENDAR_H

#include <deque>
#include <ctime>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

class Calendar
{
public:
    Calendar();
    void printCommits(vector<int> dailyCommits);
    void printCell(int val, bool today);

protected:
    string getCellColour(int val, bool today);

    int getDayOfWeek();
    int dayOfWeekCalculation(int daysBefore, int currentDay);

    void printMonth(int dayOfMonth, int month);
    string monthName(int month);
};

#endif