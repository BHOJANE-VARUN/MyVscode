#include <iostream>
using namespace std;
int keys[20];
int n = 0;
class hashtable
{
public:
    // any data like string, more ints
    int data;
    int chain;
    hashtable()
    {
        chain = -1;
        data = -1;
    }
} hashtable[10];
void accept()
{
    cout << "Enter the no. of keys:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th key";
        cin >> keys[i];
    }
}
void makehash()
{
    for (int i = 0; i < n; i++)
    {
        int hashvalue = keys[i] % n;
        if (hashtable[hashvalue].data == -1)
        {
            cout << "Enter the data";
            cin >> hashtable[hashvalue].data;
        }
        else
        {
            int j = 0;
            while (j < 10)
            {
                if (hashtable[hashvalue].data == -1 and hashtable[hashvalue].chain!=-1)
                {
                    cout << "Enter the data";
                    cin >> hashtable[hashvalue].data;
                }
                if (hashtable[hashvalue].chain != -1)
                {
                    hashvalue = hashtable[hashvalue].chain;
                }
                else
                {
                    int cur = (hashvalue + j) % n;
                    if (hashtable[cur].data == -1)
                    {
                        cout << "Enter the data";
                        cin >> hashtable[cur].data;
                        hashtable[hashvalue].chain = cur;
                        break;
                    }
                    j++;
                }
            }
        }
    }
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << hashtable[i].data << " " << hashtable[i].chain << endl;
    }
}
void delet(int key, int data)
{
    int prev = -1;
    int cur = key % n;
    while (hashtable[cur].data != data and cur != -1)
    {
        prev = cur;
        cur = hashtable[cur].chain;
    }
    if (hashtable[cur].data == data)
    {
        if (prev == -1)
        {
            hashtable[cur].data=-1;
            break;
        }
        else{
            hashtable[cur].data =-1;
            hashtable[prev].chain = hashtable[cur].chain;
            hashtable[cur].chain =-1;
        }
    }
}
int main()
{
    accept();
    makehash();
    display();
}