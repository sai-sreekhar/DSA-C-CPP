#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH_DATE 10

struct DATE
{
    int day;
    int month;
    int year;
};

bool isValidDate(struct DATE *date);
int isLeapYear(int year);
void displayNextDate(struct DATE *date);
void displayDiffTwoDates(struct DATE *date1, struct DATE *date2);

int main()
{
    struct DATE *date1;
    struct DATE *date2;

    date1 = (struct DATE *)malloc(sizeof(struct DATE));
    if (date1 == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }

    date2 = (struct DATE *)malloc(sizeof(struct DATE));
    if (date2 == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }

    printf("Enter day:");
    scanf("%d",&date1->day);

    printf("Enter month:");
    scanf("%d",&date1->month);

    printf("Enter year:");
    scanf("%d",&date1->year);

    printf("Enter day:");
    scanf("%d",&date2->day);

    printf("Enter month:");
    scanf("%d",&date2->month);

    printf("Enter year:");
    scanf("%d",&date2->year);

    bool checkDate = isValidDate(date1);
    if (checkDate == false)
    {
        printf("Invalid Date\n");
    }
    else
    {
        printf("Valid Date\n");
    }
    
    displayNextDate(date1);
    displayDiffTwoDates(date1,date2);

    free(date1);
    free(date2);
    return 0;

}

bool isValidDate(struct DATE *date)
{
    if (date->year <= 0)
    {
        return false;
    }

    if ((date->month < 1) || (date->month > 12))
    {
        return false;
    }

    if ((date->day < 1) || (date->day > 31))
    {
        return false;
    }

    if (date->month == 2)
    {
        if (isLeapYear(date->year))
        {
            if (date->day <= 29)
            {
                return true;
            }

            return false;
        }
        else
        {
            if (date->day <= 28)
            {
                return true;
            }

            return false;
        }
    }

    if ((date->month == 4) || (date->month == 6) || (date->month == 9) || (date->month == 11))
    {
        if (date->day <= 30)
        {
            return true;
        }
        return false;
    }

    return true;
}

int isLeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void displayNextDate(struct DATE *date)
{
    struct DATE *nextDate;
    if (nextDate == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }

    nextDate->day = date->day;
    nextDate->month = date->month;
    nextDate->year = date->year;
    
    if (isValidDate(date) == false )
    {
        printf("Invalid Date\n");
        return;
    }
    
    if ((nextDate->day > 0) && (nextDate->day < 28))
    {
        nextDate->day += 1;
    }

    if (nextDate->day == 28)
    {
        if (nextDate->month == 2)
        {
            if (isLeapYear(nextDate->year))
            {
                nextDate->day = 29;
            }
            else
            {
                nextDate->day = 1;
                nextDate->month = 3;
            }
        }
        else
        {
            nextDate->day += 1;
        }
    }

    if (nextDate->day == 29)
    {
        if (nextDate->month == 2)
        {
            nextDate->day = 1;
            nextDate->month = 3;
        }
        else
        {
            nextDate->day += 1;
        }
    }

    if (nextDate->day == 30)
    {
        if ((nextDate->month == 1) || (nextDate->month == 3) || (nextDate->month == 5) ||
            (nextDate->month == 7) || (nextDate->month == 8) || (nextDate->month == 10) || (nextDate->month == 12))
        {
            nextDate->day += 1;
        }
        else
        {
            nextDate->day = 1;
            nextDate->month += 1;
        }
    }

    if (nextDate->day == 31)
    {
        nextDate->day = 1;
        if (nextDate->month == 12)
        {
            nextDate->year += 1;
            nextDate->month = 1;
        }
        else
        {
            nextDate->month += 1;
        }
    }

    printf("The next date is %d-%d-%d\n", nextDate->day, nextDate->month, nextDate->year);

    return;
}

void displayDiffTwoDates(struct DATE *date1, struct DATE *date2)
{
    if ((isValidDate(date1) == false)|| (isValidDate(date2)== false))
    {
        printf("Invalid Date/Dates\n");
        return;
    }

    if (date2->day < date1->day)
    {
        if (date2->month == 3)
        {
            if (isLeapYear(date2->year) == true)
            {
                date2->day += 29;
            }
            else
            {
                date2->day += 28;
            }
        }

        else if (date2->month == 5 || date2->month == 7 || date2->month == 10 || date2->month == 12)
        {
            date2->day += 30;
        }
        else
        {
            date2->day += 31;
        }

        date2->month = date2->month - 1;
    }

    if (date2->month < date1->month)
    {
        date2->month += 12;
        date2->year -= 1;
    }

    int diffDates = date2->day - date1->day;
    int diffMon = date2->month - date1->month;
    int diffYear = date2->year - date1->year;

    printf("Difference: %d years %d months and %d days.\n", diffYear, diffMon, diffDates);
    return;
}
