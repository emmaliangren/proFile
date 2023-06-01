#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne)
{
    if (*headLL==NULL)
    {
        printf("The passed linked list is empty.\n");
    }
    else
    {
        a3Emp * temp1;
        a3Emp * temp2;

        //if whichOne is position one, head needs to be changed
        if (whichOne==1)
        {
            temp1=*headLL;
            temp2=temp1->nextEmployee;

            printf("Employee [Id: %d] fired.\n",temp1->empId);

            //freeing temp1
            int num;
            num=temp1->numDependents;
            for (int i=0;i<num;i++)
            {
                free(temp1->dependents[i]);
            }

            free(temp1->dependents);

            free(temp1);

            //changing head
            *headLL=temp2;
        }
        
        else
        {
            //moving pointers to correct location, temp1 is node prior, temp2 is node getting freed
            temp1=*headLL;
            for (int j=0;j<whichOne-2;j++)
            {
                temp1=temp1->nextEmployee;
            }
            temp2=temp1->nextEmployee;

            //changing the links of the LL 
            temp1->nextEmployee=temp2->nextEmployee;

            printf("Employee [Id: %d] fired.\n",temp2->empId);

            //freeing temp2
            int num;
            num=temp2->numDependents;
            for (int i=0;i<num;i++)
            {
                free(temp2->dependents[i]);
            }
            
            free(temp2->dependents);

            free(temp2);
        }
    }
}