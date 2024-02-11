#include <bits/stdc++.h>
using namespace std;
bool valid(int index, string s)
{ // left
    if (index == 0)
        return true;
    if (s[index - 1] == '0')
        return true;
    else
        return false;
}
void solve(int index, string output, vector<string> &ans, int N)
{ // base case
    if (index == N)
    {
        ans.push_back(output);
        return;
    }

    // insert 0
    output.push_back('0');
    solve(index + 1, output, ans, N);
    output.pop_back();

    // insert 1
    if (valid(index, output))
    {
        output.push_back('1');
        solve(index + 1, output, ans, N);
        output.pop_back();
    }
    else{
        output.pop_back();
    }
}
vector<string> generateString(int N)
{
    vector<string> ans;
    string s;
    solve(0, s, ans, N);
    return ans;
}
int main()
{
    vector<string> ans = generateString(3);
    for (auto i : ans)
        cout << i << " ";
}