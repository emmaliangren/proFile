#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL)
{
    if (*headLL==NULL)
    {
        printf("The passed linked list is empty.\n");
    }
    else
    {
        int size;
        size=countEmployees(*headLL);
        for (int i=0;i<size;i++)
        {
            fireOne(headLL,1);
        }
    }
}