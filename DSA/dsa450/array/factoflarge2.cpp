#include <bits/stdc++.h>
using namespace std;
std::string convertVectorToString(const std::vector<int> &vec)
{
    std::ostringstream oss;

    // Iterate over the vector in reverse order
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        oss << *it;
    }

    // Get the string representation
    std::string reverseString = oss.str();

    return reverseString;
}
string factorial(int n)
{
    if (n < 2)
    {
        // return "1";
    }
    vector<int> ans(1, 1);
    int count = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int j = 0;
        int remain = 0;
        while (j < count)
        {
            int temp = (i * ans[j]) + remain;
            ans[j] = temp % 10;
            remain = temp / 10;

            if (remain != 0 && j == count - 1)
            {
                while (remain > 0)
                {
                    ans.push_back(remain % 10);
                    count++;
                    remain = remain / 10;
                }
                break;
            }
            j++;
        }
    }
    return convertVectorToString(ans);
}
int main()
{
    string test = factorial(20);
    cout << test;
}