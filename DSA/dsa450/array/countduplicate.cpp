#include<iostream>
using namespace std;

int findDuplicate(int arr[],int n) 
{   int sum = 0;
    int min =0;
    for (int i = 0; i < n; i++)
    {   if (i>0)
    {
        min +=i;
    }
    
        sum += arr[i];
    }
return sum-min;
    
	
}
int main(){
    int n =2;
    int arr[2]={1,1};
    int a = findDuplicate(arr,n);
    cout<<a;
}