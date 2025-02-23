#include <bits/stdc++.h>
#define int long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl
#define MOD 1000000007
// const int maxsize = 1e5;
// int arr[maxsize+1];
#define test     \
    int monu;    \
    cin >> monu; \
    while (monu--)
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    map<int, int> mp;
    for (auto i : arr)
    {
        if (mp.find(i.first) == mp.end())
            mp[i.first] = i.second;
        else
            continue;
    }
   // for(auto i:mp) cout<<i.first<<' '<<i.second<<endl;
    vector<vector<int>> varun;
    for (auto i : mp)
    {
        vector<int> temp;
        temp.push_back(i.first);
        temp.push_back(i.second);
        varun.push_back(temp);
    }
   // cout<<arr.size();
   // for(auto i:varun) cout<<i[0]<<' '<<i[1]<<endl;
int xxx = varun.size();


    vector<int> left(xxx), right(xxx);
    int maxi = INT_MAX;
    for (int i = 0; i < xxx; i++)
    {
        left[i] = maxi;
        if (varun[i][1] < maxi)
        {
            maxi = varun[i][1];
        }
        
    }
    maxi = INT_MAX;
    for (int i = xxx - 1; i >= 0; i--)
    {
        right[i] = maxi;
        if (varun[i][1] < maxi)
        {
            maxi = varun[i][1];
        }
        
    }
    // for (int i = 0; i < xxx; i++)
    // {
    //     cout << left[i] << " " << right[i] << endl;
    // }
    
    vector<vector<int>> ans;
    ans.push_back(varun[0]);
   // cout<<ans.size()<<endl;
   
    for (int i = 1; i < xxx - 1; i++)
    {
        int x1 = varun[i - 1][0], y1 = varun[i - 1][1];
        int x2 = varun[i][0], y2 = varun[i][1];
        int x3 = varun[i + 1][0], y3 = varun[i + 1][1];

        if (y2 >= left[i] and y2 >= right[i])
        {
           // cout<<y2<<" "<<left[i-1]<<" "<<right[i-1]<<endl;
            continue;
        }
        else if (y2 < left[i] and y2 < right[i])
        {
            ans.push_back(varun[i]);
        }
        else
        {
            //cout<<x2<<" "<<y2<<endl;
            float m = (y3 - y1) / (x3 - x1);
            float sumit = (m * x2) + (y1 - m * x1);
            if (y2 <= sumit)
            {
                ans.push_back(varun[i]);
            }
        }
    }
    ans.push_back(varun[xxx - 1]);
    float finalans =0;
    int xxxx = ans.size();
    for(int i =1;i<xxxx;i++)
    {
        float x = pow(abs(ans[i][0]-ans[i-1][0]),2);
        float y = pow(abs(ans[i][1]-ans[i-1][1]),2);
        finalans += sqrt(x+y);
    }  
    // int finnnn = finalans + 0.5;
    // if(finnnn>finalans)
    // {
    //     cout<<finnnn<<endl;
    // }
    // cout<<floor(finalans)<<endl;
    cout<<roundf(finalans)<<endl;
    //for(auto i:varun) cout<<i.first<<' '<<i.second<<endl;
    // dusro ka code copy karne se ghar nahi chalta bhai
}