#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
printf("enter the size of array");
scanf("%d",&n);
int arr[n];
for (int i = 0 ;i <n; i++)
{
    printf("enter the %dth element:",i+1);
    scanf("%d",&arr[i]);
}
int count = 0;
int key;
int start;
int end;
int choice;
printf("press 1 to search all array or 0 to search in a custom range:");
scanf("%d",&choice);
if(choice==1){
    start = 0;
    end = n;
}
else if (choice==0)
{
printf("enter the range\n");
printf("start(it should be less than %d):",n+1);
scanf("%d",&start);
printf("end:");
scanf("%d",&end);
}
else
{
    printf("invalid input");
}

printf("enter the key to be searched");
scanf("%d",&key);
for (int i = start; i <n ; i++)
{
  if(key==arr[i])
  {
    count++;
  }
}
if (count==0)
{
    printf("element was not found");
}
else{
    printf("key was present in the arrary for %d time",count);
}




}