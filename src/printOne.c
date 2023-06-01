#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne)
{
    if (headLL==NULL)
    {
        printf("The linked list is empty!\n");
    }
    else
    {
        //printing one employee if LL is not null :)
        a3Emp * temp;
        temp=headLL;
        for (int i=0;i<whichOne-1;i++)
        {
            temp=temp->nextEmployee;
        }
        printf("\tEmployee id: %d\n",temp->empId);
        printf("\tFirst name: %s\n",temp->fname);
        printf("\tLast name: %s\n",temp->lname);
        printf("\tDependents: ");
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
    }
}