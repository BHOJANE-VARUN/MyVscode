#include<iostream>
#include<vector>
using namespace std;

int minimizeIt(int A[], int K)
{
	int min=INT16_MAX;
	int max = INT16_MIN;
   for(int i = 0;i<13;i++)
   {
	  if(A[i]-K>0){
		  if(A[i]-K>max)
		  {
			  max = A[i]-K;
		  }
		  else if(A[i]-K<min){
			  min = A[i]-K;
		  }
	  }
	  else{
		  if(A[i]+K>max)
		  {
			  max = A[i]+K;
		  }
		  else if(A[i]+K<min){
			  min = A[i]+K;
		  }
	  }
   }
   return max-min;
}
int main(){
    int arr[15] = {10,4,20,19,9,4,20,14,15,10,9,15,8};
    int k = 9;
    int a = minimizeIt(arr,k);
    cout<<a;
}