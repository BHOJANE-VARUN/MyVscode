#include <iostream>
using namespace std;
string arr[100];
int n = 0;
class record
{
public:
    int c;
    string name, prn;
    record()
    {
        prn = "";
        c = -1;
        name = "";
    }
} st[100];
void accept()
{
    cout << "Enter the no. of records to fill:";
    cin >> n;
    cout << "Enter the prn no's:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int key = arr[i][arr[i].size() - 1] - '0';
        int pos = key;
        do
        {
            if (st[pos].prn.size() == 0)
            {
                st[pos].prn = arr[i];
                cout << "Enter the name of " << arr[i] << endl;
                cin >> st[pos].name;
                break;
            }
            else
            {
                if (st[pos].c != -1)
                {
                    pos = st[pos].c;
                    pos = key;
                }
                else
                {
                    pos++;
                    st[key].c = pos;
                }
            }
            pos = pos % 100;
        } while (pos != key);
    }
}
void display()
{
    cout << "chain" << '\t' << "PRN No      " << '\t' << "Name" <<'\t'<<"Hashno"<< endl;
    for (int i = 0; i < 100; i++)
    {
        if(st[i].prn.size())
        cout << st[i].c << '\t' << st[i].prn << '\t' << st[i].name <<'\t'<<i<< endl;
    }
}
void deleterecord()
{
    string p;
    cout<<"Enter the PRN No to be deleted: ";
    cin>>p;
    int key = p[p.size() - 1] - '0';  
    int prev =-1;
    while(st[key].c!=-1 and st[key].prn!=p)
    {
        prev = key;
        key = st[key].c;
    }
    if(st[key].prn==p)
    {
        st[key].prn = "";
        if(prev!=-1)
        {
            st[prev].c = st[key].c;
        }
    }
    else cout<<"record not found"<<endl;
}
void search()
{
    string p;
    cout<<"Enter the PRN No to be deleted: ";
    cin>>p;
    int key = p[p.size() - 1] - '0';  
    int prev =-1;
    while(st[key].c!=-1 and st[key].prn!=p)
    {
        prev = key;
        key = st[key].c;
    }
    if(st[key].prn==p)
    {
       cout<<"record found"<<endl;
    }
    else cout<<"record not found"<<endl;
}
void update()
{
    string p;
    cout<<"Enter the PRN No to be deleted: ";
    cin>>p;
    int key = p[p.size() - 1] - '0';  
    int prev =-1;
    while(st[key].c!=-1 and st[key].prn!=p)
    {
        prev = key;
        key = st[key].c;
    }
    if(st[key].prn==p)
    {
       cout<<"Enter the information"<<endl;
       cin>>st[key].name;
    }
    else cout<<"record not found"<<endl;
}
int main()
{
    while (true)
    {
        int ch;
        cout<<"Enter choice\n 1.initialize hash table\n 2.display\n 3.update\n 4.delete\n 5.search\n 6.exit";
        cin>>ch;
        switch (ch)
        {
        case 1:
            accept();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        case 4:
            deleterecord();
            break;
        case 5:
            search();
            break;
        default:
            return 0;
            break;
        }
    }
}