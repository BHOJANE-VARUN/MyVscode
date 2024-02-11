#include <bits/stdc++.h> 
using namespace std;
string reArrangeString(string &s)
{   if(s.length()<3) return "not possible";
	unordered_map<int,int> map;
    for(auto i:s)
    {
        map[(int)i]++;
    }
    int a= map.size();
    if(map.size()==1) return "not possible";
    priority_queue<pair<int,int>> pq;
    for(auto i:map)
    {
        pq.push({i.second,i.first});
    }
    if(pq.top().first==1) return "not possible";
    pair<int,int> p1,p2;
    p1 =pq.top();
    pq.pop();
    p2 = pq.top();
    pq.pop();
    string ans;
    while (!pq.empty())
    {
        while (p1.first>0 && p2.first>0)
        {   char p11 = (char)p1.second;
            int num1 = p1.first;
            char p22 = (char)p2.second;
            int num2 = p2.first;
            ans.push_back((char)p1.second);
            p1.first--;
            ans.push_back((char)p2.second);
            p2.first--;

        }
        if(p1.first==0)
        {
            p1=pq.top();
            pq.pop();
        }
        else{
            
            p2=pq.top();
            pq.pop();
        }
        
    }
    while (p1.first>0 || p2.first>0)
        {
            if(p1.first>0)
            {ans.push_back((char)p1.second);
            p1.first--;}
            if(p2.first>0)
            {ans.push_back((char)p2.second);
            p2.first--;}

        }
    for(int i =0;i<ans.length()-1;i++)
    {
        if(ans[i]==ans[i+1]) return "not possible";
    }
    return ans;
    
}
/*
string reArrangeString(string &s)

{

    map<char,int>m;

    int n=s.size();

    for(int i=0;i<n;i++)m[s[i]]++;

    vector<pair<int,char>>v;

    for(auto i:m)v.push_back(make_pair(i.second,i.first));

    sort(v.begin(),v.end());

    reverse(v.begin(),v.end());

    int idx=0;

    for(auto i:v){

        int val=i.first;

        char key=i.second;

        if(val>n/2+n%2)return "not possible";

        while(val--){

            if(idx>=n)idx=1;

            s[idx]=key;

            idx+=2;

        }

    }

    return s;        

}*/
int main()
{
    string str = "vryxozbafpfmowgrgonuatdqlahyggyljddjhmltedzlodsrkeutgtnkntarjkpxinovgzdthunwooxvjjmpsvknhkwjopmmlebksucvzqlyqnwcmbvbhrmlowpjbwyvwtgtoqnmicxapzarknnxtuufarzrosdqwsmtcjghecqudosrtjxyaaykqrxycrxuwjxnpqjnbkcpdmokalxapemvbqlzsvxzkutappwgzpdpyzkzcvbntcvfxsxpjaoxtfhvxxytgokrcxaetauqgndmphwzyiayabjrqgeppxyjsttyzuvldvybsuxkbmfzvrtnovidznpghozvafmsnsnqivmvubcwtfsrqtmknepbhowejazhkwcmmtpixxxlzqysxtwwtaidyaxyqleprxibexxyfvsddygthcuyyfwpjsfybglgzmbintattnhodtonpyzwotkgnguphpkxeatow";
    cout<<reArrangeString(str);
}
