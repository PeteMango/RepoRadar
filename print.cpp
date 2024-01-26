#include "include/calendar.h"

const string RESET = "\033[0m";
const string BLACK = "\033[30m";   // Black
const string RED = "\033[41m";     // Red
const string GREEN = "\033[42m";   // Green
const string YELLOW = "\033[43m";  // Yellow
const string MAGENTA = "\033[45m"; // Magenta
const string WHITE = "\033[47m";   // White
const string BOLD = "\033[1m";     // Bold

Calendar::Calendar() {}

string Calendar::getCellColour(int val, bool today)
{
    if (today)
    {
        return RED;
    }

    if (val == 0) // no commits
    {
        return WHITE;
    }
    else if (val < 5) // < 5
    {
        return YELLOW;
    }
    else if (val < 10) // < 10
    {
        return GREEN;
    }
    return MAGENTA; // 11+
}

void Calendar::printCell(int val, bool today)
{
    string color = this->getCellColour(val, today);
    cout << color; // sets background colour

    if (val > 0)
    {
        if (val < 10)
        {
            cout << " " << val << " ";
        }
        else
        {
            cout << " " << val;
        }
    }
    else
    {
        cout << "   ";
    }

    cout << RESET;
}

int Calendar::getDayOfWeek()
{
    time_t t = time(nullptr);
    tm *now = localtime(&t);

    if (now->tm_wday == 0)
    {
        return 7;
    }

    return now->tm_wday; // 0 is sunday so + 1 to weekday align
}

int Calendar::dayOfWeekCalculation(int daysBefore, int currentDay)
{
    int weekDayDiff = daysBefore % 7;
    return (currentDay - weekDayDiff) < 0 ? (currentDay - weekDayDiff + 7) : (currentDay - weekDayDiff);
}

string Calendar::monthName(int month)
{
    if (month == 1)
    {
        return "Jan";
    }
    else if (month == 2)
    {
        return "Feb";
    }
    else if (month == 3)
    {
        return "Mar";
    }
    else if (month == 4)
    {
        return "Apr";
    }
    else if (month == 5)
    {
        return "May";
    }
    else if (month == 6)
    {
        return "Jun";
    }
    else if (month == 7)
    {
        return "Jul";
    }
    else if (month == 8)
    {
        return "Aug";
    }
    else if (month == 9)
    {
        return "Sep";
    }
    else if (month == 10)
    {
        return "Oct";
    }
    else if (month == 11)
    {
        return "Nov";
    }
    else
    {
        return "Dec";
    }
}

void Calendar::printMonth(int dayOfMonth, int month)
{
    int numSpaces = (dayOfMonth / 7 - 1) * 3;
    string toPrint = "";
    for (int i = 0; i < numSpaces; i++)
    {
        toPrint += " ";
    }
    toPrint = this->monthName(month);

    string monthSpace = "         ";
    for (int i = 0; i < 5; i++)
    {
        month--;
        if (month < 1)
        {
            month = 12;
        }
        toPrint = monthSpace + toPrint;
        toPrint = this->monthName(month) + toPrint;
    }
    toPrint = "      " + toPrint; // day of week buffer
    cout << toPrint << "\n";
    return;
}

void Calendar::printCommits(vector<int> dailyCommits)
{
    int dayOfWeek = this->getDayOfWeek();
    deque<int> weekday[8];

    for (int i = 139; i >= 0; i--)
    {
        weekday[this->dayOfWeekCalculation((139 - i), dayOfWeek) + 1].push_front(dailyCommits[i]);
    }

    for (int i = 1; i <= dayOfWeek; i++)
    {
        weekday[i].push_front(-1);
    }

    time_t t = time(nullptr);
    tm *now = localtime(&t);

    int month = now->tm_mon + 1, dayOfMonth = now->tm_mday;
    this->printMonth(dayOfMonth, month);

    for (int i = 1; i <= 7; i++)
    {
        if (i == 1)
        {
            cout << "Mon   ";
        }
        else if (i == 3)
        {
            cout << "Wed   ";
        }
        else if (i == 5)
        {
            cout << "Fri   ";
        }
        else if (i == 7)
        {
            cout << "Sun   ";
        }
        else
        {
            cout << "      ";
        }
        for (int j = 0; j < weekday[i].size(); j++)
        {
            if (weekday[i][j] == -1)
            {
                cout << "   ";
                continue;
            }
            printCell(weekday[i][j], false);
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> commitData(140);
    generate(commitData.begin(), commitData.end(), []()
             { return rand() % 15; });
    Calendar c;
    // c.printCell(4, false);
    c.printCommits(commitData);
}
