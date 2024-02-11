#include<iostream>
#include<vector>
using namespace std;

int minimumJumps(int arr[], int n)
{
    if(n==0){
        return 0;
    }
    int i=0;
    int steps =0;
    while(i<n-1){
        if(i+arr[i]>n-1){
            return steps+1;
        }
        int max=0;
        int index =0;
        for(int j = i+1;j<=i+arr[i];j++)
        {
            if(max<arr[j]){
                max = arr[j];
                index =j;
            }
        }
        if(max==0){
            return -1;
        }
        i = index;
        steps++;

    }
    return steps;
}
int main(){
    int arr[10]={1,2,0,1,1,2,0,2,1,0};
    int n = 10;
    int a = minimumJumps(arr,n);
    cout<<a;

}