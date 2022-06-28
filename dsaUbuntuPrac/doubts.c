#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define MAX_NAME_fN 100
typedef struct Staff
{
    char name[MAX_NAME_fN];
    int age;
    int staffID;
    float weight;
    float height;

} staff;

void readStaffInfo_Regno(staff *staffArr, int n);
void bmi_Regno(staff *staffArr, int n);

int main()
{
    int n;
    scanf("%d", &n);

    staff *staffArr;
    staffArr = (staff *)malloc(n * sizeof(staff));
    if (staffArr == NULL)
    {
        printf("Memory Allocation Faifd");
        return 1;
    }

    readStaffInfo_Regno(staffArr, n);
    bmi_Regno(staffArr, n);

    free(staffArr);
    return 0;
}

void readStaffInfo_Regno(staff *staffArr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", staffArr[i].name);
        scanf("%d", &staffArr[i].age);
        scanf("%d", &staffArr[i].staffID);
        scanf("%f", &staffArr[i].weight);
        scanf("%f", &staffArr[i].height);
    }
    return;
}

void bmi_Regno(staff *staffArr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", staffArr[i].staffID);
        float denomiator = staffArr[i].height * staffArr[i].height;
        float val = staffArr[i].weight / denomiator;
        float bmi = val * 10000;

        printf("%.2f\n", bmi);
        if (bmi <= 18.5)
        {
            printf("Underweight\n");
        }
        else if ((18.6 <= bmi) && (bmi <= 24.9))
        {
            printf("Ideal\n");
        }
        else
        {
            printf("Overweight\n");
        }
    }
    return;
}