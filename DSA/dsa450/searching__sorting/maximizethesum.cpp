#include <bits/stdc++.h> 
using namespace std;
int maximiseSum(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	int i =0,j=0;
    int sum1 =0,sum2=0;
    int ans=0;
    int flag = 1;
    while (i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            if(i<j)ans += sum2+arr2[j],sum1=0,sum2=0,j++,i++,flag=1;
            else if(i>j) ans += sum1 + arr1[i],sum1 =0,sum2=0,j++,i++,flag=2;
            else{
                if(flag == 1) ans+= sum1;
                if(flag==2) ans+= sum2;
				sum1= arr1[i],sum2 = arr2[j];
                i++,j++;
            }
        }
        else if(arr1[i]>arr2[j])
        {
            sum2+= arr2[j],j++;
        }
        else{
            sum1+= arr1[i],i++;
        }
    }
    while (i<n)
    {
        sum1+= arr1[i];
        i++;
    }
    while (j<m)
    {
        sum2 += arr2[j];
        j++;
    }
    
    ans += max(sum1,sum2);
    return ans==0?max(sum1,sum2):ans;
}
/*
#include <bits/stdc++.h> 
int maximiseSum(vector<int>& arr1, vector<int>& arr2, int n, int m) {
	int i =0,j=0;
    int sum1 =0,sum2=0;
    int ans=0;
    int flag = 1;
    while (i<n && j<m)
    {
        if(arr1[i]==arr2[j])
        {
            ans += max(sum1,sum2)+arr1[i];
			i++,j++;
			sum1=sum2=0;
        }
        else if(arr1[i]>arr2[j])
        {
            sum2+= arr2[j],j++;
        }
        else{
            sum1+= arr1[i],i++;
        }
    }
    while (i<n)
    {
        sum1+= arr1[i];
        i++;
    }
    while (j<m)
    {
        sum2 += arr2[j];
        j++;
    }
    
    ans += max(sum1,sum2);
    return ans==0?max(sum1,sum2):ans;
}*/
int main()
{
    /*2
2 4 5 8 10
4 6 8 9  */
    vector<int> test1 = {1,2,3};
    vector<int> test2 = {1,2,3};
    cout<<maximiseSum(test1,test2,test1.size(),test2.size());
}