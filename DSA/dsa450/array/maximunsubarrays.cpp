#include <iostream>
using namespace std;
long max(long a,long b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long bestsum=0,sum=INT8_MIN;
    
    if(n==0){
        return 0;
    }
    else{
    for(int i=1;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        bestsum = max(bestsum,sum);
    }
    return bestsum;
}
}
int main()
{
  int arr[10]={1,2,7,-4,3,2,-10,9,1};
  int n = 9;
  long long b = maxSubarraySum(arr,n);
  cout<<b;
   
}
