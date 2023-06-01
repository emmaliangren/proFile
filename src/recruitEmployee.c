#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL)
{
    //traversing through the linked list
    a3Emp * temp;
    temp=calloc(1,sizeof(a3Emp));
    a3Emp * ptr;
    ptr = *headLL;

    //if LL is not null, traverse the LL
    if (*headLL!=NULL)
    {
        while (ptr -> nextEmployee != NULL)
        {
            ptr = ptr -> nextEmployee;
        }
        ptr->nextEmployee=temp;
    }
    else
    {
        *headLL=temp;
    }


    //getting info: employee name, & dependents 
    char dname[MAX_LENGTH];
    char input='y';
    printf("Enter the first name of the employee: ");
    scanf(" %s",temp->fname);
    printf("Enter the last name of the employee: ");
    scanf(" %s",temp->lname);
    printf("\n");

    int idx=1;
    temp->dependents=calloc(1,sizeof(char *));
    temp->numDependents=0;

    while (input=='y'||input=='Y')
    {
        temp->numDependents+=1;
        printf("Enter the name of dependent # %d: ",idx);
        scanf("%s", dname);
        temp->dependents=realloc(temp->dependents,sizeof(char *)*(idx+1));
        temp->dependents[idx-1]=calloc(strlen(dname)+1,sizeof(char));
        strcpy(temp->dependents[idx-1],dname);

        printf("Do you have any more dependents? ");
        getchar();
        scanf("%c",&input);
        printf("\n");
        idx+=1;
    }

    //calculating empId
    for(int i=0;i<strlen(temp->fname);i++)
    {
        temp->empId+=temp->fname[i];
    }
    temp->empId+=strlen(temp->lname);

    //adding random numbers if empId already exists
    struct employee * cmp;
    cmp = *headLL;
    time_t s;
    srand((unsigned)time(&s));

    if (*headLL!=NULL)
    {
        while (cmp->nextEmployee!=NULL)
        {
            while (temp->empId==cmp->empId)
            {
                temp->empId+=(rand()% 999);
            }
            cmp = cmp->nextEmployee;
        }
    }

    temp->nextEmployee=NULL;
    printf("You have %d dependents.\n\n",temp->numDependents);
    printf("Your computer-generated empId is %d\n",temp->empId);
}