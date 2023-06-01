#include "../include/headerA3.h"

void printAll (struct employee * headLL)
{
    if (headLL==NULL)
    {
        printf("The linked list is empty, there are no employees.\n");
    }
    else
    {
        //printing all employees in linked list & their data
        struct employee * temp;
        temp = headLL;
        int idx=1;

        while (temp != NULL)
        {
            printf("Employee # %d:\n",idx);
            printf("\tEmployee id: %d\n",temp->empId);
            printf("\tFirst name: %s\n",temp->fname);
            printf("\tLast name: %s\n",temp->lname);
            printf("\tDependents [%d]: ",temp->numDependents);
            for (int i=0;i<temp->numDependents;i++)
            {
                if (i==temp->numDependents-1)
                {
                    printf("%s\n",temp->dependents[i]);
                }
                else
                {
                    printf("%s, ",temp->dependents[i]);
                }
            }

            temp = temp -> nextEmployee;
            idx+=1;
        }
        printf("\nCurrently, there are %d employees.\n",idx-1);
    }
}