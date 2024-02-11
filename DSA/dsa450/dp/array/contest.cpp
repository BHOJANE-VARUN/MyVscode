// #include <bits/stdc++.h>
// using namespace std;
// void solve(int n,vector<int>&a,int index,int even,int odd,int &ans)
// {
// 	if(index==n) {ans = min(ans,abs(odd-even));return;};
//     int t = a[index];
// 	solve(n, a, index+1, even+t, odd,ans);
// 	solve(n, a, index+1, even, odd+t,ans); 

// }
// int evenOddArrangement(int n, vector<int> & a){
// 	// Write your code here.
//     int ans =INT_MAX;
// 	solve(n, a, 0, 0, 0,ans);
// 	return ans;
// }
// int main()
// {
//     vector<int> a = {8,2,3,4};
//     int n = a.size();
//     cout<<evenOddArrangement(n,a);
// }
#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a, int index, vector<int>& evenArrangement, vector<int>& oddArrangement, int &ans) {
    if (index == n && abs(evenArrangement.size()-oddArrangement.size())<2) {
        int evenSum = accumulate(evenArrangement.begin(), evenArrangement.end(), 0);
        int oddSum = accumulate(oddArrangement.begin(), oddArrangement.end(), 0);
        ans = min(ans, abs(oddSum - evenSum));
    //     if(abs(evenSum-oddSum)==1)
    //    { for(auto i:evenArrangement){cout<<i<<"  ";};
    //     cout<<"\n";for(auto i:oddArrangement){cout<<i<<" ";};cout<<"\n";};
        return;
    }
    if(index==n)return;
    
    // Add the current element to the even arrangement
    evenArrangement.push_back(a[index]);
    solve(n, a, index + 1, evenArrangement, oddArrangement, ans);
    evenArrangement.pop_back(); // Backtrack
    
    // Add the current element to the odd arrangement
    oddArrangement.push_back(a[index]);
    solve(n, a, index + 1, evenArrangement, oddArrangement, ans);
    oddArrangement.pop_back(); // Backtrack
}

int evenOddArrangement(int n, vector<int> &a) {
    int ans = INT_MAX;
    vector<int> evenArrangement, oddArrangement;
    solve(n, a, 0, evenArrangement, oddArrangement, ans);
    return ans;
}

int main() {
    vector<int> a = {8, 2, 3, 4};
    int n = a.size();
    cout << evenOddArrangement(n, a);
}
