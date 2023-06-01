#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL)
{
    //counting the # employees in passed linked list
    if (headLL==NULL)
    {
        printf("The linked list you passed is empty.\n");
        return 0;
    }
    else
    {
        int numEmp=0;
        a3Emp * temp;
        temp=headLL;

        while (temp!=NULL)
        {
            numEmp+=1;
            temp=temp->nextEmployee;
        }

        return numEmp;
    }
}