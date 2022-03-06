#include <stdio.h>
#define SIZE 25 
#define NUM_EMP 3


typedef struct employee 
{ 
   char fname[20]; 
   char lname[20]; 
   int id; 
   char dependents [3][20]; 
} Employees;

void printEmployees (Employees [NUM_EMP], int c);
void saveEmployees (Employees [NUM_EMP], int c, char [SIZE]);
int loadEmployees (Employees [NUM_EMP], char [SIZE]);
void swapEmployees (Employees *, Employees *);

int main(int argc, char *argv[]){
    Employees employeeArr[NUM_EMP];
    int numOfEmployees;
    printf("How many employees:");
    scanf("%d", &numOfEmployees);
    loadEmployees(employeeArr, argv[1]);
    saveEmployees(employeeArr, numOfEmployees, argv[1]);
    printEmployees(employeeArr, numOfEmployees);
    return 0;
}
