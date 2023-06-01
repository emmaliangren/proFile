#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100])
{
    if (headLL==NULL)
    {
        printf("Linked list is empty!\n");
        return -1;
    }
    else
    {
        int flag=0, pos=0;
        a3Emp * temp;
        temp=headLL;
        char compName[MAX_LENGTH*2+1];
        compName[0]='\0';

        while (temp->nextEmployee!=NULL && !flag)
        {
            //make string to compare first name, space, last name
            strcpy(compName,temp->fname);
            strcat(compName," ");
            strcat(compName,temp->lname);
            compName[strlen(compName)]='\0';
            if(strcmp(whichName,compName)==0)
            {
                flag=1;
            }
            pos+=1;
            temp=temp->nextEmployee;
        }

        //if flag is never set to true, name is not in list, return -1
        if (!flag)
        {
            return -1;
        }
        return pos;
    }
}