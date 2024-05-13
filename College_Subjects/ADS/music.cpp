#include<iostream>
#include<string>
using namespace std;
int key[20],c[20],n;
class music
{
    public:
    int track_no;
    string s_title,singer;
    void declare();
    void htable();
    void accept();
    void search();
    void update();
    void remove();
    

}h[100];

void music::declare()
{
    cout<<"enter total no. of tracks :";
    cin>>n;
    cout<<"enter the track_no:";
    for(int i = 0;i<n;i++)
    {
    cin>>key[i];
    }
    for(int i =0;i<n;i++)
     {
    h[i].track_no=-1;
    c[i]=0;
    }
    }
void music::htable()
{
    cout<<" \nTRACK_NO\tSONG_TITLE\t SINGER\tCHAIN";
   
    for(int i =0;i<n;i++)
    {
    cout<<"\n"<< h[i].track_no<<"\t"<<h[i].s_title<<"\t"<< h[i].singer<<"\t"<<c[i];
}
}
void music::accept()
{
    int no,pos;
    for(int i=0;i<n;i++)
    {
        no = (2*key[i]+3) % 10;
        pos=no;
    
    do{
        if(h[no].track_no==-1)
        {
            h[no].track_no=key[i];
           cout <<"\nEnter music details:\n";
           cout <<"\ntrack_no:";
           cin>>h[no].track_no;
           cout<<"\nsong_title:";
           cin>>h[no].s_title;
           cout<<"\nSinger:";
           cin>>h[no].singer;
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
void music::search()
{
    int t_no, f = 0,i,no;
    cout << "\nEnter track number that you want to search: ";
    cin >> t_no;
    for(i=0;i<n;i++)
    {
        no=(2*t_no+3)%10;
        if(h[no].track_no==t_no)
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
void music::update()
{
    int t_no, f = 0,i,no;
    cout << "\nEnter track number that you want to search: ";
    cin >> t_no;
    for(i=0;i<n;i++)
    {
        no=(2*t_no+3)%10;
        if(h[no].track_no==t_no)
        {
               f=1;
               cout<<"record is found...";
               cout <<"\nEnter new music details:\n";
               cout <<"\ntrack_no:";
               cin>>h[no].track_no;
               cout<<"\nsong_title:";
               cin>>h[no].s_title;
               cout<<"\nSinger:";
               cin>>h[no].singer;
               break;
        }
    }
    if(f==0)
    {
        cout<<"record is not found...";
    }
}

void music::remove()
{

   int t_no, f = 0;
    cout << "\nEnter track_no that you want to delete: ";
    cin >> t_no;

    int no= (2*t_no+3) % 10;
    int pos = no;
    if(h[no].track_no==-1)
    {
        cout<<"\ntable is empty.";
    }
    else{

    while (h[no].track_no != -1)
    {
        if (h[no].track_no == t_no)
        {
            f = 1;
            cout << "Record found at location " << no<< "\n";
            // Marking record as deleted
            h[no].track_no = -1;
            h[no].s_title = " "; // Assuming -1 as a flag for deleted record
            h[no].singer = " ";
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
   music m;
    int ch,y;
   
    do{
        cout<<"\n1.Declare\n2.Htable\n3.Accept\n4.Search\n5.Update\n6.Remove\n7.Exit\n";
        cout<<"Enter ur choice:\n";
        cin>>ch;
    switch(ch)
    {

    case 1:
    m.declare();
    break;
    case 2:
    m.htable();
    break;
    case 3:
    m.accept();
    break;
    case 4:
    m.search();
    break;
    case 5:
    m.update();
    break;
    case 6:
    m.remove();
    break;
    case 7:
    exit(0);
    break;
    }cout<<"\nIf u want to continue press 1 or for exit press 0\n";
    cin>>y;
    }while(y==1);
    return 0;
}