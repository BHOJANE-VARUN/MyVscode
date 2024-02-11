#include <bits/stdc++.h>
using namespace std;
string writeAsYouSpeak(int n)
{
    string num = "1";

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        string ans = "";
        for (int j = 1; j < num.length(); j++)
        {
            if (num[j] == num[j - 1])
            {
                count++;
            }
            else
            {
                ans += to_string(count);
                ans += num[j - 1];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += num[num.length() - 1];
        num = ans;
    }
    return num;
}
int main()
{
    string str = writeAsYouSpeak(3);
    cout << str;
}