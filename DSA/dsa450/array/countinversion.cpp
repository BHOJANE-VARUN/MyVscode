#include<iostream>
using namespace std;
long long getInversions(long long *arr, int n){
    int i=0;
    long long count=0;
    while (i<n-1)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                count++;
            }
            
        }
        i++;
        
    }
    return count;
    
}
int main(){
    long long  arr[10]={2,5,1,3,4};
    int n = 5;
    long long ans = getInversions(arr,n);
    cout<<ans<<endl;
}