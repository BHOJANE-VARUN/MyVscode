// Problem Statement No.04
// Implement a problem of activity selection problem with K persons.
// Given two arrays S[] and E[] of size N denoting starting and closing time of the shops 
// and an integer value K denoting the number of people, the task is to find out the maximum number of shops 
// they can visit in total if they visit each shop optimally based on the following conditions: 
// i) A shop can be visited by only one person 
// ii) A person cannot visit another shop if its timing collide with it
// Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2 Output: 4

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Comparator
bool compareBy(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

// Function to find maximum shops that can be visited by k persons

int maxShops(int *opening, int *closing, int n, int k)
{
    // Store opeing and closing time of the shops
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].first = opening[i];
        a[i].second = closing[i];
    }

    // Sort the pair of array
    sort(a, a + n, compareBy);

    // Stores the result
    int count = 0;

    // Storers current number of persons visiting some shop with their ending time
    multiset<int> st;

    for (int i = 0; i < n; i++)
    {
        // Check if the current shop can be assigned to a person in another shop
        bool flag = false;
        if (!st.empty())
        {
            auto it = st.upper_bound(a[i].first);
            if (it != st.begin())
            {
                it--;

                // Check if any shop closing time is less than current shop opening time
                if (*it <= a[i].first)
                {
                    // Erase the previous shop visited
                    st.erase(it);

                    // Insert closing time of current shop
                    st.insert(a[i].second);

                    // Increase the count
                    count++;

                    flag = true;
                }
            }
        }

        // No closing time less than current shop opeing time but some persons left
        if (st.size() < k && flag == false)
        {
            st.insert(a[i].second);
            count++;
        }
    }
    // Print the number if shops visited
    return count;
}

int main()
{
    int shops, per;
    cout << "Enter the number of shops" << endl;
    cin >> shops;
    int S[shops], E[shops];
    cout << "Enter the number of persons visiting the shops" << endl;
    cin >> per;
    cout << "Enter the opening time of each shop" << endl;
    for (int i = 0; i < shops; i++)
    {
        cin >> S[i];
    }
    cout << "Enter the closing time of each shop" << endl;
    for (int i = 0; i < shops; i++)
    {
        cin >> E[i];
    }

    // Function calls
    cout << "The maximum number of shops that can be visited are " << maxShops(S, E, shops, per) << endl;
}