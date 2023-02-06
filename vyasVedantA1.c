#include "givenA1.h"

// command for makefile:    ./vyasVedantA1 courses.txt data.txt

/*
This function will attempt to turn a filename given as a string into a FILE pointer. 
A returned FILE pointer indicates if the file opened successfully, otherwise it will return NULL. 
The file will only open for reading, not writing.
*/

/*
Function name: openFileForReading
Inputs: string, struct
Output: file pointer
*/

FILE *openFileForReading (char fileName [MAX_STR])
{
    FILE *fptr = fopen(fileName, "r");

    if(fptr == NULL) //if the file is empty, return NULL.
    {
        return fptr = NULL;
    }
    else //if the file is not empty, return file pointer.
    {
        return fptr;
    } 
}

/*
This function must read courseNames and courseID from a text file called courses.txt to populate the array of structs called courseInfo with course names and corresponding course IDs.
The text file name “courses.txt” must be read as the first command-line argument (e.g., ./a.out courses.txt data.txt) and not from standard input.
Since NUMBER COURSES is set to 10, the first 10 lines of this file record 10 course names, and the next 10 lines contain 10 course IDs.
*/

/*
Function name: readCourse
Inputs: string, struct
Output: int
*/

int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES])
{
    FILE *fp =  openFileForReading(filename); //use the function above to create a file pointer for reading.

    //variables that will be used in function.

    int i = 0; 
    char temp[MAX_STR]; 
    int line = 0; 

    if(fp == NULL) //if the file is empty, return NULL.
    {
        return -1;
    }
    else //if the file is not empty, loop through contents.
    {
        while(i < NUMBER_COURSES) //repeat the loop 10 times.
        {
            //store the content of the first line inside a temporary string value, increment the lines, copy the temporary string value to courseName & increase the value of i by increments of 1 to fill up courseName.

            fgets(temp, MAX_STR, fp); 
            line++; 
            temp[strlen(temp)-1] = '\0'; 
            strcpy(courseInfo[i].courseName, temp); 
            i++; 

            if(i == NUMBER_COURSES) 
            {
                for(int j = 0; j < NUMBER_COURSES; j++) //repeat the loop 10 times to store all the courseID values.
                {
                    fscanf(fp, "%d", &courseInfo[j].courseID); 
                    line++; //increment by 1 after scanning each line from fscanf.
                }
            }
        }
        if(line < (2 * NUMBER_COURSES) || line > (2 * NUMBER_COURSES)) //check if the amount of lines is greater than or less than 2 times NUMBER_COURSES.
        {
            return -1; //if true, return -1.
        }
        else
        {
            return 1; //if false, return 1.
        }
        fclose(fp); //close file.
    }
}

/*
The prof names and course assignments MUST be read from a text file called data.txt (for example,./a.out courses.txt data.txt).
Since NUMBER PROFS is set to 6, the prof names can be found on the first six lines of the file. 
The letters y or n on the next six lines will indicate whether a professor is teaching the course or not. 
Assume that this function's order of the course IDs matches the order of the course IDs used in function readCourse.
*/

/*
Function name: readProfAndCoursesTaught
Input: string, 2 structs
Returns: int
*/

int readProfAndCoursesTaught (char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES])
{
    FILE *fp = openFileForReading(filename); //use the function above to create a file pointer for reading.

    //variables that will be used in function.

    int i = 0; 
    char temp[MAX_STR]; 
    char response[NUMBER_PROFS][NUMBER_COURSES]; 
 
    if(fp == NULL) //if the file is empty, return NULL.
    {
        return -1; 
    }
    else //if the file is not empty, loop through contents.
    {
        while(i < NUMBER_PROFS) //repeat loop 10 times.
        {
            //store the content of the first line inside a temporary string value, increment the lines, copy the temporary string value to profName & increase the value of i by increments of 1 to fill up profName.

            fgets(temp, MAX_STR, fp); 
            temp[strlen(temp)-1] = '\0'; 
            strcpy(profInfo[i].profName, temp); 
            i++; 

            if(i == NUMBER_PROFS)
            {
                for(int j = 0; j < NUMBER_PROFS; j++) //run loop 10 times.
                {
                    fscanf(fp, "%s", response[j]); //read all the courses taught line by line.
                }
            }
        }
        //the loop will fill coursesTaught with its corresponding courseID.

        for(int i = 0; i < NUMBER_PROFS; i++) //run loop 6 times.
        {
            for(int j = 0; j < NUMBER_COURSES; j++) //run loop 10 times.
            {
                if(response[i][j] == 'y' || response[i][j] == 'Y') //check if each index is a yes or no.
                {
                    profInfo[i].coursesTaught[j] = courseInfo[j].courseID; 
                }
                else
                {
                    profInfo[i].coursesTaught[j] = -1; //if the course is not taught by that professor, set index to -1.
                }
            }
        }
    }
    fclose(fp); //close file.
    return 1;
}

/*
This function adds the names of all professors who teach n or more courses (n >= 0) to an array named profsNCourses. 
The total number of professors who teach n or more courses is then returned.
*/

/*
Function name: nCourses
Input: int, struct, 2d string
Returns: int
*/

int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR])
{
    int num = 0; 
    int count;

    for(int i = 0; i < NUMBER_PROFS; i++) //run loop 6 times.
    {
        count = 0; //after the inner loop is ran 10 times, the count is reinitalized to 0 so each prof data is checked.

        for(int j = 0; j < NUMBER_COURSES; j++) //run loop 10 times.
        {
            if(profInfo[i].coursesTaught[j] != -1) //check if the course is taught by the professor by making sure index is not -1.
            {
                count++; //increase courses by increments of 1.
            }
        }
        if(count >= n) //check if the count is greater or equal to n for the specific professor. 
        {
            strcpy (profsNCourses[num], profInfo[i].profName); //copy the prof name to profsNCourses.
            num++; //increment num to make sure all the profs teaching are added to the 2D array.
        }
    }
    return num; //return the number of profs teaching n or more courses.
}   

/*
When a course number is entered, this function looks for the course name and stores it in a string argument (e.g. cNameFound). 
If the course is located, it returns 1, else it returns 0.
*/

/*
Function name: getCourseName 
Input: int, string, struct
Returns: int
*/

int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES])
{
    for(int i = 0; i < NUMBER_COURSES; i++) 
    {
        if(courseInfo[i].courseID == courseNum) 
        {
            strcpy(cNameFound, courseInfo[i].courseName);
            return 1;
        }
    }
    return 0;
}

/*
This function accepts a course name as input, finds the course number associated with it, and stores the result in an output int parameter (e.g. cNumFound). 
If the course is located, it returns 1, else it returns 0.
*/

/*
Function name: getCourseNum
Input: string, int pointer, struct
Returns: int
*/

int getCourseNum (char cName [50], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES])
{
    for(int i = 0; i < NUMBER_COURSES; i++) 
    {
        if(strcmp(cName, courseInfo[i].courseName) == 0) 
        {
            *cNumFound = courseInfo[i].courseID;
            return 1;
        }
    }
    return 0;
}

/*
This method accepts a course number as input, looks up the professors teaching it, and adds their names to the array taughtBy. 
It displays the overall number of professors who are instructing the course. 
Num is returned if the course is discovered, otherwise 0 is returned.
If no professor is assigned to teach the course, it also returns 0.
*/

/*
Function name: profsTeachingCourse 
Input: int, struct, 2d string
Returns: int
*/

int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR])
{
    int count = 0;

    for(int i = 0; i < NUMBER_PROFS; i++) 
    {
        for(int j = 0; j < NUMBER_COURSES; j++) 
        {
            if(profInfo[i].coursesTaught[j] == courseNum) 
            {
                strcpy(taughtBy[count], profInfo[i].profName);
                count++;
            }
        }
    }
    return count;
}

/*
This function gives the average number of courses a professor teaches. 
The average is normally a float number, so when you return the value, it must be rounded to the nearest integer.
*/

/*
Function name: avgNumCourses
Input: struct
Returns: float
*/

float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]) 
{
    float average = 0; //float type since we need the value rounded to a nearest integer.

    for(int i = 0; i < NUMBER_PROFS; i++)
    {
        for(int j = 0; j < NUMBER_COURSES; j++)
        {
            if(profInfo[i].coursesTaught[j] != -1)
            {
                average++; 
            }
        }
    }
    //calculate average number of courses a prof teaches.

    average = (average / NUMBER_PROFS); 
    average = (int) average + 1;  
    average = (float) average; 

    return average;
}
