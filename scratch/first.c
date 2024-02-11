#include<stdio.h>
#include<stdlib.h>
struct myarr
{
    int usedspace;
    int totalspace;
    int* ptr;
};
void contr(struct myarr* a,int b,int c
){
 a->usedspace = b;
 a->totalspace = c;
 a->ptr = (int *) malloc(c * sizeof(int)); 
};
void fillspace(struct myarr *a)
{
for (int i=0 ;i<a->usedspace;i++)
{int n;
printf("enter your int %d",i);
    scanf("%d",&n);
    (a->ptr)[i] = n;
};};
void showspace(struct myarr *a){
for (int i = 0 ;i<a->usedspace ;i++){
printf("%d\n",a->ptr[i]);

};};
int main(){
    struct myarr marks;
    contr(&marks,5,10);
    fillspace(&marks);
    showspace(&marks);
   
};