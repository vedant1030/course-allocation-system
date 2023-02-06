/*
Student Name: Vedant Vyas
Student ID: 1214467
Due Date: February 3, 2023
Course: CIS*2500

I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz

I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_PROFS 6
#define NUMBER_COURSES 10
#define MAX_STR 50

struct courseStruct 
{
   char courseName [MAX_STR];
   int courseID;
};

struct profStruct 
{
   char profName [MAX_STR];
   int  coursesTaught [NUMBER_COURSES];
};

FILE *openFileForReading(char fileName [MAX_STR]);

int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]);

int readProfAndCoursesTaught (char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]);

int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR]);

int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES]);

int getCourseNum (char cName [50], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]);

int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR]);

float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]);
