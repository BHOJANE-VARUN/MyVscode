#include<stdio.h>
#include<string.h>
struct student{
    int roll_no;
    int cet;
    char branch[25];
    char name[25];
};
void main()
{
    
    struct student stud[5];
    for (int i = 0; i < 20; i++)
    {
        printf("enter the roll no:");
        scanf("%d",&stud[i].roll_no);
        printf("enter the cet score:");
        scanf("%d",&stud[i].cet);
        printf("enter the branch :");
        scanf("%s",&stud[i].branch);
        printf("enter the name of student :");
        scanf("%s",&stud[i].name);

        
    }
     for (int i = 0; i < 20; i++)
    {

        printf("%d\n",stud[i].roll_no);

        printf("%d\n",stud[i].cet);

        printf("%s\n",stud[i].branch);

        printf("%s\n",stud[i].name);

        
    }
    
    
    

}