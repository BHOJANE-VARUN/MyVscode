class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        if(n==1)
        {
            return true;
        }
        return arr[n-1]>arr[n-2]  && arraySortedOrNot(arr[],--n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends