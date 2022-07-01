#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <new>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
#include <cstdarg>
#include <climits>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

#define MAX_SIZE 100

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};

    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

typedef struct Student
{
    string* rollNo;
    string* name;
    Student* next;
}student;

class stringHash
{

    int keysPresent;
    student* hashTable[MAX_SIZE];

    int computeHash(string s)
    {
        int hash = 0;
        for (int i = 0; i < s.length(); i++)
        {
            hash += s[i];
        }
        return (hash % MAX_SIZE);
    }

    bool isFull()
    {
        return (MAX_SIZE == keysPresent);
    }

public:
    stringHash()
    {
        keysPresent = 0;
        memset(hashTable,0,sizeof(hashTable));
    }

    void insert(string rollNo,string name)
    {
        if (isFull())
        {
            cout << ("ERROR : Hash Table Full\n");
            return;
        }

        int hashVal = computeHash(rollNo);
        
        student* newStudent = new student;
        newStudent->name = new string(name);
        newStudent->rollNo = new string(rollNo);
        newStudent->next = nullptr;

        if (hashTable[hashVal] == nullptr)
        {
            hashTable[hashVal] = newStudent;
            keysPresent += 1;
            return;
        }

        student* pvsStudent = hashTable[hashVal];
        student* presentStudent =  hashTable[hashVal]->next;
        while (presentStudent != NULL)
        {
            presentStudent = presentStudent->next;
        }

        presentStudent = newStudent;
        pvsStudent->next = presentStudent;
        keysPresent += 1;

        return;
    }

    void erase(string s)
    {
        bool found = false;
        int hashVal = computeHash(s);

        student* pvsStudent = nullptr;
        student* presentStudent =  hashTable[hashVal];
        while (presentStudent != nullptr)
        {
            if (*(presentStudent->rollNo) == s)
            {
                if (pvsStudent != nullptr)
                {
                    pvsStudent->next = presentStudent->next;
                }
                if (pvsStudent == nullptr)
                {
                    if (presentStudent->next != nullptr)
                    {
                        hashTable[hashVal] = presentStudent->next;
                    }
                    else
                    {
                        hashTable[hashVal] = NULL;
                    }
                }
                
                delete  presentStudent->name;
                delete presentStudent->rollNo;
                delete presentStudent;

                found = true;
                keysPresent--;
                return;
            }
            else
            {
                pvsStudent = presentStudent;
                presentStudent = presentStudent->next;
            }
        }

        if (found == false)
        {
            cout << "Roll Number not found" << endl;
        }
        
    }

    bool search(string s)
    {
        int hashVal = computeHash(s);
        
        if (hashTable[hashVal] == nullptr)
        {
            return false;
        }
        else
        {
            student* presentStudent =  hashTable[hashVal];
            while (presentStudent != nullptr)
            {
                if (*(presentStudent->rollNo) == s)
                {
                    return true;
                }
                else
                {
                    presentStudent = presentStudent->next;
                }
            }
        }
        return false;
    }
    
    void print()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            student* presentStudent =  hashTable[i];
            while (presentStudent != nullptr)
            {
                cout << "Roll Number: " << *(presentStudent->rollNo) << " Name: " << *(presentStudent->name) << endl;
                presentStudent = presentStudent->next;
            }
        }
    }
};

int main()
{

    stringHash myHash; 
    myHash.insert("21BKT0162","SaiSreekar");
    myHash.insert("21BDS0162","Sai");
    myHash.insert("21BKT2610","Sai2");
    cout << myHash.search("21BKT2610") << endl;
    myHash.erase("21BKT0162");
    myHash.print();
}
