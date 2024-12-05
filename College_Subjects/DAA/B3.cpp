// Problem Statement No.06
// Implement a problem of minimum work to be done per day to finish given tasks within D days problem
// Given an array task[] of size N denoting amount of work to be done for each task
// The problem is to find the minimum amount of work to be done on each day
// so that all the tasks can be completed in at most D days.
// On one day work can be done for only one task

// Input task[] = {3, 4, 7, 15} days = 10
// Output = 4

#include <bits/stdc++.h>
using namespace std;

bool valid(int per_day, vector<int> task, int d)
{
    int cur_day = 0;
    for (int index = 0; index < task.size(); index++)
    {
        int day_req = ceil((double)(task[index]) / (double)(per_day));
        cur_day += day_req;
        if (cur_day > d)
        {
            return false;
        }
    }
    return cur_day <= d;
}

int minimumTask(vector<int> task, int d)
{
    int left = 1;
    int right = INT_MAX;

    for (int index = 0; index < task.size(); index++)
    {
        right = max(right, task[index]);
    }

    int per_day_task = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (valid(mid, task, d))
        {
            per_day_task = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return per_day_task;
}

int main()
{
    vector<int> task;
    int num, temp, days;
    cout << "Enter the number of tasks to be completed" << endl;
    cin >> num;
    cout << "Enter the size of each task" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        task.push_back(temp);
    }
    cout << "Enter the number of days for the task" << endl;
    cin >> days;
    cout << "The minimum amount of work to be done each day is ";
    cout << minimumTask(task, days) << endl;
}
