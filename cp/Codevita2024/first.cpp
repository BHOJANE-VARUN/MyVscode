// #include<bits/stdc++.h>
// #define int long long int
// #define yes cout<<"YES"<<endl;
// #define no cout<<"NO"<<endl
// #define MOD 1000000007
// //const int maxsize = 1e5;
// //int arr[maxsize+1];
// #define test int monu;cin>>monu;while(monu--)
// using namespace std;
// signed main()
// {
//     int amount;cin>>amount;
//     int secondary = 0;
//     int top = -1;
//     int committed = -1;
//     int n;cin>>n;
//     vector<int> commits;
//     vector<int> arr(n,0);
//     for(int i=0;i<n;i++)
//     {
        
//         string curstr;cin>>curstr;
//         if(curstr=="read")
//         {
//             cout<<amount<<endl;
//             continue;
//         }
//         else if(curstr=="commit")
//         {
//             committed = top;
//             amount += secondary;
//             secondary =0;
//             commits.push_back(amount);
//             continue;
//         }
//         int curnum;cin>>curnum;
//         if(curstr=="credit")
//         {
//             secondary += curnum;
//             top++;
//             arr[top] = (-1*curnum);
//         }
//         else if(curstr=="debit")
//         {
//             secondary -= curnum;
//             top++;
//             arr[top] = curnum; 
//         }
//         else if(curstr=="rollback")
//         {
//             amount = commits[curnum-1];
//             secondary =0;
//         }
//         else{
//             if(committed<curnum)
//             {
//                 //cout<<arr[curnum-1]<<endl;
//                 amount += arr[curnum-1];
//                 arr[curnum-1] = 0;
//             }
//         }
//         //cout<<amount<<endl;
//     }
// //dusro ka code copy karne se ghar nahi chalta bhai
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int b, n, cb = 0;
//     cin >> b >> n;
//     vector<int> t;
//     vector<int> cs = {b};

//     for (int i = 0; i < n; i++) {
//         string varun;
//         cin >> varun;
//         if (varun == "read") {
//             cout << cs[cb] << endl;
//         } 
        
//         else if (varun == "credit" || varun == "debit") {
//             int x;
//             cin >> x;
//             if (varun == "credit") cs[cb] += x;
//             else cs[cb] -= x;
//             t.push_back(varun == "credit" ? x : -x);
//         } 
        
//         else if (varun == "abort") {
//             int x;
//             cin >> x;
//             if (x <= t.size()) cs[cb] -= t[x - 1], t[x - 1] = 0;
//         } 
        
//         else if (varun == "rollback") {
//             int x;
//             cin >> x;
//             cb = x - 1;
//             cs.resize(cb + 1);
//         } 
        
//         else if (varun == "commit") {
//             cs.push_back(cs[cb]);
//             cb++;
//         }
//     }
//     return 0;
// }
