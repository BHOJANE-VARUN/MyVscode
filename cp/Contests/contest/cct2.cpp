#include <iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test)
	{
	    int size;
	    cin>>size;
	    int *arr = new int[size];
        int mini = INT_MAX;
        int sum =0;
	    for (int i = 0; i < size; i++)
        {   int temp;
            cin>>temp;
            mini = min(temp,mini);
            arr[i] = temp;
            sum += temp;
        }
       cout<<sum-mini<<endl;
       test--; 
	}
	return 0;
}
