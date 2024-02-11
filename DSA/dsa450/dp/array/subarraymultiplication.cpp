#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_subarray_multiplications(vector<int>& arr) {
    vector<int> subarray_multiplications;
    int n = arr.size();
    vector<int> dp(n, 1);  // DP array to store subarray multiplications

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = arr[i];
        for (int j = i + 1; j < n; ++j) {
            dp[j] = dp[j - 1] * arr[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            subarray_multiplications.push_back(dp[j] / (i > 0 ? dp[i - 1] : 1));
        }
    }

    return subarray_multiplications;
}

int main() {
    vector<int> input_array = {1, 2, 3};
    vector<int> subarray_multiplications = generate_subarray_multiplications(input_array);
    for (int product : subarray_multiplications) {
        cout << product << " ";
    }
    return 0;
}
