#include "limits.h"
#include "queue"
class node{
    public:
    int data,row,col;
    node(int d,int r,int c)
    {
        data = d;
        row = r;
        col = c;
    }
};
class comp{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini = INT_MAX,maxi = INT_MIN;
    priority_queue<node*,vector<node*>,comp> minheap;
    
    for(int i =0;i<k;i++)
    {
        int ele = a[i][0];
        mini = min(mini,ele);
        maxi = max(maxi,ele);
        minheap.push(new node(ele,i,0));
    }
    int start = mini,end = maxi;
    while(!minheap.empty())
    {
        node* temp = minheap.top();
        minheap.pop();
        mini = temp->data;
        if(maxi-mini<end-start)
        {
            start = mini;
            end = maxi;
        }

        if(temp->col+1 < n)
        {
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minheap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return end-start+1;
}