/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)

    Where 'N' is the length of string
*/

int findIndex(string &str, int si, int ei)
{
    if (si > ei)
    {
        return -1;
    }

    int c = 0;

    for (int i = si; i <= ei; i++)
    {

        // If open parenthesis, increment
        if (str[i] == '(')
            c++;

        // If close parenthesis, decrement
        else if (str[i] == ')')
        {
            c--;

            // Valid index is found
            if (c == 0)
                return i;
        }
    }

    // If not found return -1
    return -1;
}

BinaryTreeNode<int> *treeFromBracketHelper(string &str, int si, int ei)
{
    // Base case
    if (si > ei)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(str[si] - '0');

    int index = -1;

    // If next char is '(' find the index of its complement ')'
    if (si + 1 <= ei && str[si + 1] == '(')
    {
        index = findIndex(str, si + 1, ei);
    }

    // If index found
    if (index != -1)
    {
        // Call for left subtree
        root->left = treeFromBracketHelper(str, si + 2, index - 1);

        // Call for right subtree
        root->right = treeFromBracketHelper(str, index + 2, ei - 1);
    }

    return root;
}

BinaryTreeNode<int> *treeFromBracket(string &str)
{
    return treeFromBracketHelper(str, 0, str.size());
}
