#include <bits/stdc++.h>
using namespace std;
bool check(string &a, string &b, string &c, int i, int j, int k) {
    if (k == c.length()) {
        return (i == a.length() && j == b.length());
    }

    bool result = false;

    if (i < a.length() && a[i] == c[k]) {
        result = result || check(a, b, c, i + 1, j, k + 1);
    }

    if (j < b.length() && b[j] == c[k]) {
        result = result || check(a, b, c, i, j + 1, k + 1);
    }

    return result;
}

bool isInterleave(string a, string b, string c) {
    if (c.length() != a.length() + b.length()) {
        return false;
    }
    vector<vector<vector<int>>> dp(c.length())
    return check(a, b, c, 0, 0, 0);
}

int main() {
    string a = "abcbbc";
    string b = "bcabc";
    string c = "abcbcabbcbc";
    cout << isInterleave(a, b, c); // This should output "1" (true)
}
