#include "givenA1.h"

int main(int argc, char * argv[])
{
    int choice; 
    int task2Check;
    int task3Check;
    int locate; 
    int courseNum; 
    int cNumFound; 
    
    char cNameFound[MAX_STR]; 
    char profsNCourses[NUMBER_PROFS][MAX_STR]; 
    char cName[MAX_STR]; 
    char taughtBy[NUMBER_PROFS][MAX_STR]; 
 
    struct courseStruct courseInfo[NUMBER_COURSES]; 
    struct profStruct profInfo[NUMBER_PROFS]; 

    task2Check = readCourse(argv[1], courseInfo);

    if(task2Check == -1)
    {
        printf("Unsuccessful operation for task 2!\n");
    }
    
    task3Check = readProfAndCoursesTaught(argv[2], profInfo, courseInfo);

    if(task3Check == -1)
    {
        printf("Unsuccessful operation for task 3!\n");
    }
    if(task2Check == -1 || task3Check == -1)
    {
        return 0;
    }

    printf("Menu Options: \n");
    printf("\nFunction 4 - nCourses\nFunction 5 - getCourseName\nFunction 6 - getCourseNum\nFunction 7 - profsTeachingCourse\nFunction 8 - avgNumCourses\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    printf("\n");
  
    if(choice >=4 && choice <=8)
    {
        if(choice == 4)
        {
            int total; 
            int n; 
            
            do
            {
                printf("Enter value for n: ");
                scanf("%d", &n);
            } while(n < 0);
            
            total = nCourses(n, profInfo, profsNCourses); 
            printf("There are %d professor(s) that teach %d courses or more: \n", total, n);
            
            for(int i = 0; i < total; i++)
            {
                printf("%s\n", profsNCourses[i]);
            }
        }
        else if(choice == 5)
        {
            printf("Enter a course ID: ");
            scanf("%d", &courseNum);
            locate = getCourseName(courseNum, cNameFound, courseInfo); 
            
            if(locate == 0)
            {
                printf("Course ID could not be located.\n");
            }
            else
            { 
                printf("The course name is: %s\n", cNameFound);
            }
        }
        else if(choice == 6)
        {
            printf("Enter a course name: ");
            fgets(cName, MAX_STR, stdin); 
            cName[strlen(cName)-1] = '\0'; 
            locate = getCourseNum(cName, &cNumFound, courseInfo); 

            if(locate == 0)
            {
                printf("The course could not be located.\n");
            }
            else
            { 
                printf("%d\n", cNumFound);
            }
        }
        else if(choice == 7)
        {
            printf("Enter a course ID: ");
            scanf("%d", &courseNum);
            locate = profsTeachingCourse(courseNum, profInfo, taughtBy); 
            
            if(locate == 0)
            {
                printf("There is no professor teaching this course.\n");
            }
            else
            { 
                printf("There are %d profs that teach the course %d: \n", locate, courseNum);

                for(int j = 0; j < locate; j++)
                {
                    printf("%s\n", taughtBy[j]); 
                }
            }
        }
        else if(choice == 8)
        {
            float average; 
            average = avgNumCourses(profInfo); 
            printf("The average courses taught by a professor is %.1f courses.\n", average); 
        }
    }
    else
    {
        printf("Invalid option!");
        return 0;
    }
}