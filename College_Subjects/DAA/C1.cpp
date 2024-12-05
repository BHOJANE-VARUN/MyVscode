// Problem Statement No.07
// Implement coin exchange problem
// Given a integer array of coins[] of size N representing different types of coins and an integer sum.
// The task is to find the number of ways to make sum by using different combinations from coins[].

// Input sum = 4, coins[] = {1, 2, 3}
// Output 4

#include <bits/stdc++.h>
using namespace std;

int countRecur(vector<int> &coins, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || n == 0)
    {
        return 0;
    }

    return countRecur(coins, n, sum - coins[n - 1]) + countRecur(coins, n - 1, sum);
}

int count(vector<int> &coins, int sum)
{
    return countRecur(coins, coins.size(), sum);
}

int main()
{
    vector<int> coins;
    int sum, num, temp;
    cout << "Enter the number types of coins" << endl;
    cin >> num;
    cout << "Enter the coins" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        coins.push_back(temp);
    }
    cout << "Enter the sum you want to calculate" << endl;
    cin >> sum;
    cout<<"The number of combinations possible are ";
    cout << count(coins, sum);
    return 0;
}
