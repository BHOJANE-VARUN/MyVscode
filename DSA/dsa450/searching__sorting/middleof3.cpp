#include <bits/stdc++.h> 
int middleOfThree(int x, int y, int z)
{
    int sum = x+y+z;
    int mini = min(x,min(y,z));
    int maxi = max(x,max(y,z));
    return sum-maxi-mini;
}
/*

    Time complexity: O(1) 
    Space complexity: O(1)
    



int middleOfThree(int x, int y, int z)
{ 
  
    // Checking if B is middle  
    if ((x-y) * (y-z) > 0)
    { 
    
        // y is the middle element
        return y; 
    }

    // Checking if C is middle (x and z both are positive) 
    else if ((x - y) * (x - z) > 0) 
    {

        // z is the middle element
        return z; 
    }
    else
    {

        // x is the middle element
        return x; 
    }
}

*/