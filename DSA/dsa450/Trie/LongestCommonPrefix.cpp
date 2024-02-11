string longestCommonPrefix(vector<string> &arr, int n)
{
    int prefi = 0;
    for (int j = prefi; arr[0][j] == arr[1][j] && prefi<arr[0].size(); j++)
    {
        prefi++;
    }
    prefi--;
    if(prefi==-1)
    {
        return "";
    }
    for (int i = 1; i < arr.size()-1; i++)
    {
        int j = 0;
        while (j!=prefi+1)
        {
            if(arr[i][j] != arr[i + 1][j])
            {
                prefi = j-1;
                break;
            }
            j++;
        }
        if(prefi==-1)
        {
            return "";
        }
    }
    string temp = arr[0].substr(0, prefi + 1);
    return temp;
}


