#include <stdlib.h>
#include <time.h>

typedef enum
{
    HR,
    Sales,
    Research,
    Software,
    Executive
} Department;

typedef struct
{
    Department dept; // Department
    int salary;      // Annual salary
    unsigned ssn;    // Social Security Number
} Employee;

// Function to generate a salary based on department
int generateSalary(Department dept)
{
    int baseSalaries[] = {50000, 60000, 55000, 70000, 65000};
    int offset = rand() % 10000; // Random offset between 0 and 9999
    return baseSalaries[dept] + offset;
}

// Function to print employee details
void printEmployee(Employee emp)
{
    const char *deptNames[] = {"HR", "Sales", "Research", "Software", "Executive"};
    printf("Department: %s, Salary: $%d, SSN: %u\n",
           deptNames[emp.dept], emp.salary, emp.ssn);
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    Employee employees[10];

    for (int i = 0; i < 10; i++)
    {
        employees[i].dept = rand() % 5; // Randomly assign a department
        employees[i].salary = generateSalary(employees[i].dept);
        employees[i].ssn = rand() % 100000000; // Random SSN
    }

    for (int i = 0; i < 10; i++)
    {
        printEmployee(employees[i]);
    }

    return 0;
}