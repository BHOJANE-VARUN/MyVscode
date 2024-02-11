#include <bits/stdc++.h>
using namespace std;

int minimizeIt(vector<int> &arr, int k)
{int size = arr.size();
	 if(size<2){
	return 0;
}
for(int i = 0;i<size;i++)
{
	if(arr[i]<=k){
		arr[i]=arr[i]+k;
	}
	else{
		arr[i]=arr[i]-k;
	}
	
}
int max = *max_element(arr.begin(), arr.end());
int min = *min_element(arr.begin(), arr.end());
return max-min;
}
int main(){
    int k =9;
    vector<int> vec={10,4,20,19,9,4,20,14,15,10,9,15,8};
    int ans = minimizeIt(vec,k);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
    cout<<"\n"<<ans<<endl;
}