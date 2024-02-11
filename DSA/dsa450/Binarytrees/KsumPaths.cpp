#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

// int solve(TreeNode<int> * &root,int k,int sum)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }
//     int ans =0;
//     if(sum==k) ans++;
//     int excllef = solve(root->left,k,0);
//     int incllef = solve(root->left,k,sum+root->data);
//     int exclrig = solve(root->right,k,0);
//     int inclrig = solve(root->right,k,sum+root->data);

//     ans += excllef + incllef + exclrig + inclrig;
//     return ans;
// }
// int noWays(TreeNode < int > * root, int k) {
//     // Write your code here.
//     return solve(root,k,0);
// }

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode < int > * root, int targetSum, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, targetSum, count, path);
        //right
        solve(root->right, targetSum, count, path);
        
        //check for K Sum
        int size = path.size();
        long int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum = sum + path[i];
            if(sum == targetSum)
                count++;
        }
        path.pop_back();
}

int noWays(TreeNode < int > * root, int k) {
    // Write your code here.
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}
int main()
{
    return 0;
}