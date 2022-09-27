#include <iostream>

using namespace std;

#define NO_OF_SLOTS 5             // 9 to 10, 10 to 11, 11 to 12, 2 to 5;
#define NO_OF_DAYS 5              // mon to friday
#define NO_OF_TYPES_OF_STUDENTS 5 // 1st 2nd 3rd 4th pg
#define TUTORAL_START_TIME 8
#define TUTORIAL_END_TIME 9
#define LAB_START_TIME 14
#define LAB_END_TIME 17
typedef struct Slot
{
    string courseCode;
    int startTime; // 24hr clock
    int endTime;
} slot;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    // int N, M, L, P;
    slot timeTable[NO_OF_TYPES_OF_STUDENTS][NO_OF_DAYS][NO_OF_SLOTS];

    // memset
    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        for (int j = 0; j < NO_OF_DAYS; j++)
        {
            for (int k = 0; k < NO_OF_SLOTS; k++)
            {
                timeTable[i][j][k].courseCode = "-";
                timeTable[i][j][k].startTime = 0;
                timeTable[i][j][k].endTime = 0;
            }
        }
    }

    // cin >> N >> M >> L >> P;

    int noOfTheoryCoursesPerYear[NO_OF_TYPES_OF_STUDENTS];
    int noOfLabCoursesPerYear[NO_OF_TYPES_OF_STUDENTS];
    int noOfTutorialsPerYear[NO_OF_TYPES_OF_STUDENTS];

    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        cout << "Enter the number of theory courses for each year\n";
        cin >> noOfTheoryCoursesPerYear[i];
    }

    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        cout << "Enter the number of lab courses for each year\n";
        cin >> noOfLabCoursesPerYear[i];
    }

    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        cout << "Enter the number of tutorials courses for each year\n";
        cin >> noOfTutorialsPerYear[i];
    }

    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        // tutorial filling
        int tutorialDay = 0;
        int tutorialSlot = 0; // always 8 to 9;
        for (int j = 0; j < noOfTutorialsPerYear[i]; j++)
        {
            cout << "Enter the tutorial course code:";
            cin >> timeTable[i][tutorialDay][tutorialSlot].courseCode;
            timeTable[i][tutorialDay][tutorialSlot].startTime = TUTORAL_START_TIME;
            timeTable[i][tutorialDay][tutorialSlot].endTime = TUTORIAL_END_TIME;
            tutorialDay++;
        }

        // lab filling
        int labDay = 0;
        int labSlot = 4; // always 2 to 5;
        for (int j = 0; j < noOfLabCoursesPerYear[i]; j++)
        {
            cout << "Enter the lab course code:";
            cin >> timeTable[i][labDay][labSlot].courseCode;
            timeTable[i][labDay][labSlot].startTime = LAB_START_TIME;
            timeTable[i][labDay][labSlot].endTime = LAB_END_TIME;
            labDay++;
        }

        // theory filling;
        int theoryDay = 0;
        int theorySlot = 1;
        int toFill = noOfTheoryCoursesPerYear[i];
        int theoryStartTime = 9;
        int theoryEndTime = 10;

        while (toFill > 0)
        {
            cout << "Enter the theory course Code: ";
            cin >> timeTable[i][theoryDay][theorySlot].courseCode;
            timeTable[i][theoryDay][theorySlot].startTime = theoryStartTime;
            timeTable[i][theoryDay][theorySlot].endTime = theoryEndTime;

            if (theoryDay == 4)
            {
                theoryDay = 0;
                theorySlot++;
                theoryStartTime++;
                theoryEndTime++;
            }
            else
            {
                theoryDay++;
            }

            toFill--;
        }
    }

    for (int i = 0; i < NO_OF_TYPES_OF_STUDENTS; i++)
    {
        cout << "For student of year " << i + 1 << "\n";
        for (int j = 0; j < NO_OF_DAYS; j++)
        {
            cout << "On Day " << j + 1 << "\n";
            for (int k = 0; k < NO_OF_SLOTS; k++)
            {
                cout << "The course code is: " << timeTable[i][j][k].courseCode << "\n";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}
