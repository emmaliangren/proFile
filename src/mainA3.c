#include "../include/headerA3.h"

int main()
{
    struct employee * headA3=NULL; 
    int exit=0, input=0, inputInt, inId, printer;
    int numEmp, firePos=0;
    char inChar='\0';
    char firstName[MAX_LENGTH+1];
    char lastName[MAX_LENGTH+1];
    char fullName[MAX_LENGTH*2+1];
    fullName[0]='\0';
    
    loadEmpData (&headA3, "proFile.txt");
    
    do
    {
        printf("\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n\n");
        printf("Choose a menu option: ");
        scanf("%d",&input);
        printf("\n");

        switch (input)
        {
            case 1:
                recruitEmployee(&headA3);
                break;
            case 2:
                printAll(headA3);
                break;
            case 3:
                while (inputInt>countEmployees(headA3)||inputInt<1)
                {
                    printf("Enter a position: ");
                    scanf("%d",&inputInt);
                    printf("\n");
                }
                printOne(headA3,inputInt);
                break;
            case 4: 
                //calling function and returning position
                printf("Enter an employee ID: ");
                scanf("%d",&inId);
                printf("\n");                
                printer=lookOnId(headA3,inId);

                //printing at said position!
                if (printer==-1)
                {
                    printf("The employee ID was not present in the linked list.\n");
                }
                else
                {
                    printOne(headA3,printer);
                }
                break;
            case 5:
                //calling function and returning position
                printf("Enter the full name of an employee: ");
                getchar();
                scanf("%s %s",firstName,lastName);
                strcat(firstName," ");
                strcpy(fullName, firstName);
                strcat(fullName, lastName);
                printf("\n");               
                printer=lookOnFullName(headA3,fullName);

                //printing at said position!
                if (printer==-1)
                {
                    printf("The employee's name was not present in the linked list.\n");
                }
                else
                {
                    printOne(headA3,printer);
                }
                break;
            case 6:
                numEmp=countEmployees(headA3);
                printf("Total number of employees = %d\n", numEmp);
                break;
            case 7: //not working!! :)
                printf("After sorting on empId, the employees are as follows: \n\n");
                sortEmployeesId(headA3);
                break;
            case 8:
                numEmp=countEmployees(headA3);
                printf("Currently there are %d employees.\n", numEmp);
                while (firePos>numEmp||firePos<1)
                {
                    printf("Which employee do you wish to fire - enter a value between 1 and %d: ",numEmp);
                    scanf("%d",&firePos);
                }
                fireOne(&headA3,firePos);
                numEmp=countEmployees(headA3);
                printf("There are now %d employees.\n", numEmp);
                break;
            case 9:
                while (inChar!='y'&& inChar!='n')
                {
                    printf("Are you sure you want to fire everyone: ");
                    getchar();
                    scanf("%c",&inChar);
                }
                if (inChar=='y')
                {
                    fireAll(&headA3);
                    printf("All fired. Linked list is now empty.\n");
                }
                break;
            case 10:
                exit=1;
                break;
            default:
                break;
        }
    } while (!exit);

    fireAll(&headA3);
    return 0;
}