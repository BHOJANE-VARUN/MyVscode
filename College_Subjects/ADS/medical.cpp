#include<iostream>
#include<string>
using namespace std;
int key[20],c[20],n;
class medical
{
    public:
    int t_id,price;
    string t_name;
    void declare();
    void htable();
    void accept();
    void search();
    void update();
    void remove();
    

}h[100];

void medical::declare()
{
    cout<<"enter total no. of tablets :";
    cin>>n;
    cout<<"enter the tablet id:";
    for(int i = 0;i<n;i++)
    {
    cin>>key[i];
    }
    for(int i =0;i<n;i++)
     {
    h[i].t_id=-1;
    c[i]=0;
    }
    }
void medical::htable()
{
    cout<<" \nTablet_id\tprice\t tablet_name\tCHAIN";
   
    for(int i =0;i<n;i++)
    {
    cout<<"\n"<< h[i].t_id<<"\t"<<h[i].price<<"\t"<< h[i].t_name<<"\t"<<c[i];
}
}
void medical::accept()
{
    int no,pos;
    for(int i=0;i<n;i++)
    {
        no = (2*key[i]+3) % 10;
        pos=no;
    
    do{
        if(h[no].t_id==-1)
        {
            h[no].t_id=key[i];
           cout <<"\nEnter medical details:\n";
           cout <<"\nt:nTablet_id";
           cin>>h[no].t_id;
           cout<<"\nprice:";
           cin>>h[no].price;
           cout<<"\nTablet_id:";
           cin>>h[no].t_id;
            break;
        }
        else{
            no++;
            c[pos]=no;
            if(no>n){
                no=0;
            }
        }
    }while(no<100);
    }
}
void medical::search()
{
    int tab_id, f = 0,i,no;
    cout << "\nEnter tablet ID that you want to search: ";
    cin >> tab_id;
    for(i=0;i<n;i++)
    {
        no=(2*t_no+3)%10;
        if(h[no].t_id==tab_id)
        {
            f=1;
            cout<<"record is found...";
            break;
        }
    }
    if(f==0)
    {
        cout<<"record is not found...";
    }
    
}
void medical::update()
{
    int tab_id, f = 0,i,no;
    cout << "\nEnter tablet id that you want to search: ";
    cin >> tab_id;
    for(i=0;i<n;i++)
    {
        no=(2*tab_id+3)%10;
        if(h[no].t_id==tab_id)
        {
               f=1;
               cout<<"record is found...";
               cout <<"\nEnter new tablet details:\n";
            cout <<"\nt:nTablet_id";
           cin>>h[no].tab_id;
           cout<<"\nprice:";
           cin>>h[no].price;
           cout<<"\nTablet_name:";
           cin>>h[no].t_name;
            break;
        }
    }
    if(f==0)
    {
        cout<<"record is not found...";
    }
}

void medical::remove()
{

   int tab_id, f = 0;
    cout << "\nEnter track_no that you want to delete: ";
    cin >> tab_id;

    int no= (2*tab_id+3) % 10;
    int pos = no;
    if(h[no].t_id==-1)
    {
        cout<<"\ntable is empty.";
    }
    else{

    while (h[no].tab_id != -1)
    {
        if (h[no].tab_id == t_no)
        {
            f = 1;
            cout << "Record found at location " << no<< "\n";
            // Marking record as deleted
            h[no].tab_id = -1;
            h[no].price = -1; // Assuming -1 as a flag for deleted record
            h[no].t_name = " ";
            break;
        }
       no = (no + 1) % n; // Linear probing to handle collisions
        if (no==pos) // If we come back to the initial index, break to avoid infinite loop
            break;
    }

    if (f == 0)
    {
        cout << "Record not found!\n";
    }
}
}

int main()

{
   medical b;
    int ch,y;
   
    do{
        cout<<"\n1.Declare\n2.Htable\n3.Accept\n4.Search\n5.Update\n6.Remove\n7.Exit\n";
        cout<<"Enter ur choice:\n";
        cin>>ch;
    switch(ch)
    {
    case 1:
    b.declare();
    break;
    case 2:
    b.htable();
    break;
    case 3:
    b.accept();
    break;
    case 4:
    b.search();
    break;
    case 5:
    b.update();
    break;
    case 6:
    b.remove();
    break;
    case 7:
    exit(0);
    break;
    }cout<<"\nIf u want to continue press 1 or for exit press 0\n";
    cin>>y;
    }while(y==1);
    return 0;
}