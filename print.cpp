#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

// Function to calculate if a year is a leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Function to calculate the number of days in a month
int getDaysInMonth(int month, int year)
{
    std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return daysInMonth[month - 1];
}

// Function to print the calendar graph
void printCalendarGraph(int startDayOfWeek)
{
    // Adjust startDayOfWeek to match with Monday being the first day of the week
    startDayOfWeek = (startDayOfWeek + 6) % 7;

    // Create a buffer for days to align the start day to Monday
    for (int i = 0; i < startDayOfWeek; ++i)
    {
        std::cout << "   ";
    }

    // Print the days
    for (int i = 0; i < 365 + startDayOfWeek; ++i)
    {
        // Simulate data with random values for demonstration
        int intensity = rand() % 5; // Random intensity between 0 and 4
        char symbol = ' ';
        switch (intensity)
        {
        case 0:
            symbol = ' ';
            break;
        case 1:
            symbol = '.';
            break;
        case 2:
            symbol = 'o';
            break;
        case 3:
            symbol = 'O';
            break;
        case 4:
            symbol = 'X';
            break;
        }
        std::cout << std::setw(3) << symbol;

        // Start a new line every Sunday (or after 7 days)
        if ((i + 1) % 7 == 0)
        {
            std::cout << std::endl;
        }
    }
}

int main()
{
    // For the sake of this example, let's assume the following:
    // Today is Thursday, January 25th, 2024
    // And we know that January 1st, 2024 was a Monday
    int startDayOfYear = 1; // 0 for Sunday, 1 for Monday, ..., 6 for Saturday

    // Calculate the day of the week for the first day 365 days ago
    int totalDaysLastYear = 365;
    if (isLeapYear(2023))
    {
        totalDaysLastYear = 366;
    }

    int startDayOfWeek365DaysAgo = (startDayOfYear - totalDaysLastYear % 7 + 7) % 7;

    // Print the calendar graph for the last 365 days
    printCalendarGraph(startDayOfWeek365DaysAgo);

    return 0;
}
