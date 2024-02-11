#include <bits/stdc++.h> 
using namespace std;
/*
#include<bits/stdc++.h>

using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){

    if(n>m)

    { return kthElement(arr2, arr1, m, n, k);

    }

    int low=max(0, k-m);

    int high=min(k, n);

    while(low<=high)

    {

        int cut1=(low+high)>>1;

        int cut2=k-cut1;

        int l1=(cut1==0)? INT_MIN:arr1[cut1-1];

        int l2=(cut2==0)? INT_MIN:arr2[cut2-1];

        int r1=(cut1==m)? INT_MAX:arr1[cut1];

        int r2=(cut2==n)? INT_MAX:arr2[cut2];

        if(l1<=r2 && l2<=r1)

        {

            return max(l1, l2);

        }

        else if(l1>r2)

        {

            high=cut1-1;

        }

        else{

            low=cut1+1;

        }

    }

    return 1;

}
in this approch we are clearly using bianry search */
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
   int j = min(m,k/2);
   int i = k-j;
   i--,j--;
   while(0<=j<m && 0<=i<n)
   {
        if(arr1[i]>arr2[j+1])i--,j++;
        else if(arr2[j]>arr1[i+1])j--,i++;
        else return max(arr1[i],arr2[j]);
   }
   if(i==-1)
   {
        if(m>=k)return arr2[k-1];
        else{
            return arr1[k-m-1];
        }
   }
   else{
    if(n>=k)return arr1[k-1];
    else return arr2[k-n-1];
   }
}
int main()
{
    vector<int> vec1 = {1};
    vector<int> vec2 = {4 ,7 ,8 ,9 ,100};
    int n = vec1.size();
    int m = vec2.size();
    cout<<kthElement(vec1,vec2,n,m,6);
}