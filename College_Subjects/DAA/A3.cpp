// Problem Statement No.03
// Implement a problem of smallest number with at least n trailing 0s in factorial.
// Given a number of n. The task is to find the smallest number whose factorial contains at least n trailing 0s.
// Input: n=1       Output: 5
// Input: n=6       Output: 25

#include <iostream>
using namespace std;

int findNum(int n)
{
    int num = 1;
    int cnt = 0;
    while (true)
    {
        int temp = num;
        while (temp % 5 == 0)
        {
            cnt++;
            temp /= 5;
        }
        if (cnt >= n)
        {
            return num;
        }
        num++;
    }
}

int main()
{
    int n;
    cout << "Enter the number of trailing zeroes" << endl;
    cin >> n;
    cout << findNum(n) << " is the smallest number having " << n << " number of trailing zeroes" << endl;
    return 0;
}