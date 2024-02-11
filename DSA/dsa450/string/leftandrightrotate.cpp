#include <bits/stdc++.h>
using namespace std; 
string leftRotate(string str, int d) {
    int len = str.length();
    str = str+str;
    string ans;
    int i = d;
    while(i<(d+len))
    {
        ans.push_back(str[i]);
        i++;
    }
    return ans;
}

string rightRotate(string str, int d) {
    int len = str.length();
    str = str+str;
    string ans;
    int s = len-d;
    while(s<str.length()-d)
    {
        ans.push_back(str[s]);
        s++;
    }
    return ans;
}
int main()
{
    string str = "codingninjas";
    string strl = leftRotate(str,3);
    string strr = rightRotate(str,3);
    cout<<strl<<"\n"<<strr;
    //ingninjascod jascodingnin

}