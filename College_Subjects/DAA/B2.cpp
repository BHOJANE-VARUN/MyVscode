// Problem Statement No.05
// Implement a problem of maximize Profit by trading stocks based on given rate per day.
// Given an array arr[] of N positive integers which denotes the cost of selling and buying a stock on each of the N days. 
// The task is to find the maximum profit that can be earned by buying a stock on or selling all previously bought stocks on a particular day.
// Input: arr[] = {2, 3, 5} Output: 5

#include <iostream>
using namespace std;

// Function to find the maximum profit
int maxProfit(int *prices, int n)
{
    int profit = 0, currentDay = n - 1;

    // Start from the last day
    while (currentDay > 0)
    {
        int day = currentDay - 1;
        // Traverse and add the profit until stock with higher than current day is achived
        while (day >= 0 && (prices[currentDay] > prices[day]))
        {
            profit += (prices[currentDay] - prices[day]);
            day--;
        }

        // Set this day as currentDay with maximum cost of stock currently
        currentDay = day;
    }
    return profit;
}

int main()
{
    int n;
    cout << "Enter the number of days" << endl;
    cin >> n;
    int prices[n];
    cout << "Enter the stock prices per day" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    // Function call
    cout << "The maximum profit can be earned " << maxProfit(prices, n);
    return 0;
}
