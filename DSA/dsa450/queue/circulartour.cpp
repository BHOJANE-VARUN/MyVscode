#include <bits/stdc++.h> 
using namespace std;
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	// write your code here
    long long defin =0;
	long long front =0;
	int cur =0;
	int start =0;
	for(int i =0;i<N;i++)
	{	 front += (petrol[i]-distance[i]);
          if (front < 0) {
            defin += front;
            front = 0;
            start = i + 1;
          }
        }

	if(defin+front>=0)
	{
		return start;
	}
	else return -1;
}

int main()
{
    vector<int> vec = {1,10,3};
    vector<int> test = {10,20,10};
    cout<<firstCircularTour(test,vec,test.size());
}
