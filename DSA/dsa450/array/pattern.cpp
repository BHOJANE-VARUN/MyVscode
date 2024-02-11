#include <iostream>
using namespace std;
/// @brief
/// @param x
int main()
{
    /*
       a
      bab
     cbabc
    dcbabcd
    */
    int a = 'a';
    int r;
    cin >> r;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (j >= (r - 1) - i)
            {
                char temp = a + (r - 1) - j;
                cout << temp;
            }
            else
            {
                cout << " ";
            }
        }
        for (int k = 1; k < r; k++)
        {
            if (i > 0)
            {
                if (k <= i)
                {
                    char temp = a + k;
                    cout << temp;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    
    }
}