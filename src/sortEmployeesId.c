#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) 
{
    if (headLL==NULL)
    {
        printf("The linked list passed is empty and cannot be sorted.\n");
        return;
    }
    else
    {
        int counter=0, flag=0, size=countEmployees(headLL);
        int holder, printer, swap=0;
        int idArr[size];
        a3Emp * temp;
        temp=headLL;

        //get employee ids in an int array
        while (temp!=NULL)
        {
            idArr[counter]=temp->empId;
            temp=temp->nextEmployee;
            counter++;
        }
        
        //bubble sort the array :)
        for (int i=0; !flag && i<size-1;i++)
        {
            swap=0;
            for (int j=0; j<size-i-1;j++)
            { 
                if (idArr[j]>idArr[j+1])
                {
                    holder=idArr[j];
                    idArr[j]=idArr[j+1];
                    idArr[j+1]=holder;
                    swap=1;
                   
                }
            }

            if (swap!=1)
            {
                flag=1;
            }
        }        

        //use lookonid & printone on the int array!
        for (int k=0;k<size;k++)
        {
            printer=lookOnId(headLL,idArr[k]);
            printOne(headLL,printer);
            printf("\n");
        }
    }
}