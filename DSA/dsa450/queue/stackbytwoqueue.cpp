#include<iostream>
#include<queue>
using namespace std;
class Stack {
	// Define the data members.
    queue<int> q1,q2;
    int topp ;
   public:
    Stack() {
        // Implement the Constructor.
        topp =-1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return max(q1.size(),q2.size());
    }

    bool isEmpty() {
        return q1.empty() && q2.empty();
    }

    void push(int element) {
        if(q1.size()>0)
        {
            q1.push(element);
        }
        else if(q2.size()>0)
        {
            q2.push(element);
        }
        else q1.push(element);
    }

    int pop() {
        if(!q1.empty())
        {
            while (q1.size()>1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
        else if(!q2.empty())
        {
            while (q2.size()>1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }
        else return -1;
    }

    int top() {
        if(!q1.empty())
        {
            return q1.back();
        }
        else if(!q2.empty())
        {
            return q2.back();
        }
        else return -1;
    }
};
int main()
{
    Stack obj;
    obj.push(3);
    obj.push(5);
    obj.push(9);
    cout<<obj.pop()<<endl;
    cout<<obj.top()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
}