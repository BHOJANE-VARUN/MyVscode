#include <iostream>
using namespace std;
class node
{
public:
    string city;
    int fuel;
    node *next;
    node(int f, string c)
    {
        city = c;
        fuel = f;
        next = NULL;
    }
};
class linkedlist
{
public:
    string city;
    node *lister;
    linkedlist *nex;
    linkedlist(string s)
    {
        city = s;
        lister = NULL;
        lister = NULL;
    }
};
class graph
{
private:
    int arr[10][10];
    int n;
    string city[10];
    linkedlist *head, *tail;

public:
    void create()
    {
        cout << "Enter no. of cities:" << endl;
        cin >> n;
        cout << "Enter the city names:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the " << i + 1 << "th city name" << endl;
            cin >> city[i];
        }
    }
    void makemat()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    cout << "Enter fuel of ";
                    cout << city[i] << " - " << city[j] << endl;
                    cin >> arr[i][j];
                    arr[j][i] = arr[i][j];
                }
            }
        }
    }
    void display()
    {
        cout << endl;
        cout << "\t";
        for (int i = 0; i < n; i++)
            cout << city[i] << "\t";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << city[i] << '\t';
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }
    }
    void attach(string a,string b,int f)
    {
        linkedlist *temp = head;
        while (temp and temp->city != a)
        {
            temp = temp->nex;
        }
        if (temp)
        {
            if (temp->lister)
            {
                node *cur = temp->lister;
                while (cur->next and cur->city != b)
                {
                    cur = cur->next;
                }
                if (cur->city == b)
                {
                    cur->fuel = f;
                }
                else
                {
                    cur->next = new node(f, b);
                }
            }
            else
            {
                temp->lister = new node(f, b);
            }
        }
        else
        {
            cout << a << " not in list of cities" << endl;
        }
    }
    void makelinkedlist()
    {
        for (int i = 0; i < n; i++)
        {
            if (head == NULL)
            {
                head = new linkedlist(city[i]);
                tail = head;
            }
            else
            {
                linkedlist *temp = new linkedlist(city[i]);
                tail->nex = temp;
                tail = tail->nex;
            }
        }
        int choice;
        do
        {
            string a, b;
            cout << "Enter the first city name:";
            cin >> a;
            cout << "Enter the second city name:";
            cin >> b;
            if (a != b)
            {
                int f;
                cout << "Enter the fuel:";
                cin >> f;
                attach(a,b,f);
                attach(b,a,f);
            }
            cout << "want to enter more 0 for no and 1 for yes:";
            cin >> choice;
        } while (choice);
    }
    void showlist()
    {
        linkedlist *temp = head;
        while (temp)
        {
            cout << temp->city << "\t";
            node *cur = temp->lister;
            while (cur)
            {
                cout << cur->city << " " << cur->fuel << "\t";
                cur = cur->next;
            }
            temp = temp->nex;
            cout << endl;
        }
    }
};
int main()
{
    graph g;
    g.create();
    g.makelinkedlist();
    g.showlist();
}