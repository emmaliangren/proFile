#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId)
{
    if (headLL==NULL)
    {
        printf("Linked list is empty!\n");
        return -1;
    }
    else
    {
        int pos=1;
        a3Emp * temp;
        temp=headLL;

        //if id matches whichEmpId, return!
        while(temp!=NULL)
        {
            if (temp->empId==whichEmpId)
            {
                break;
            }
            pos+=1;
            temp=temp->nextEmployee;
        }

        //if the empId was never found in list, return -1
        if (temp == NULL)
        {
            return -1;
        }

        return pos;
    }
}