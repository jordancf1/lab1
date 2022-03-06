#include <stdio.h>
#include <string.h>
#define SIZE 25 
#define NUM_EMP 3


typedef struct employee 
{ 
   char fname[20]; 
   char lname[20]; 
   int id; 
   char dependents [3][20]; 
} Employees;

void printEmployees(Employees employeeArr[NUM_EMP], int c)
{
    for(int i = 0; i < c; i++)
    {
        //loops through all employees and prints their info
        printf("=========Employee #%d=========\n", i+1);
        printf("Name: %s %s\n", employeeArr[i].fname, employeeArr[i].lname);
        printf("ID: %d\n", employeeArr[i].id);
        for(int j = 0; j < 3; j++)
        {
            printf("Dependant #%d: %s\n", j+1, employeeArr[i].dependents[j]);
        }
        printf("=============================\n");
    }
}

void saveEmployees(Employees employeeArr[NUM_EMP], int c, char filename[SIZE])
{
    //open file, writing mode
    FILE* f;
    f = fopen(filename, "w");
    for(int i = 0; i < c; i++)
    {
        //similar to printEmployee, writes all employee info into the file
        fprintf(f,"=========Employee #%d=========\n", i+1);
        fprintf(f,"Name: %s %s\n", employeeArr[i].fname, employeeArr[i].lname);
        fprintf(f,"ID: %d\n", employeeArr[i].id);
        for(int j = 0; j < 3; j++){
            fprintf(f,"Dependant #%d: %s\n", j+1, employeeArr[i].dependents[j]);
        }
        fprintf(f,"=============================\n");
    }
    fclose(f);
}

int loadEmployees(Employees employeeArr[NUM_EMP], char filename[SIZE])
{
    //open file, read mode
    FILE* f;
    f = fopen(filename, "r");
    int count = 0;
    while(!feof(f))
    {
        //scanf all info, word by word, and puts it into its appropiate variabel
        fscanf(f, "%s", employeeArr[count].fname);
        fscanf(f, "%s", employeeArr[count].lname);
        fscanf(f, "%d", &employeeArr[count].id);
        fscanf(f, "%s", employeeArr[count].dependents[0]);
        fscanf(f, "%s", employeeArr[count].dependents[1]);
        fscanf(f, "%s", employeeArr[count].dependents[2]);
        count++;
    }
    fclose(f);
    return count;
}

void swapEmployees(Employees* employee1,Employees* employee2)
{
    Employees temp = *employee1;
    *employee1 = *employee2;
    *employee2 = temp;
}