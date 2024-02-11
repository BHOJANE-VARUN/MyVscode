class SpecialStack {
    public:
        int arr[1001];
        int topp =-1;
        int mini = INT_MAX;
    void push(int data) {
        // Implement the push() function.
        topp++;
        arr[topp]=data;
        if(data<mini)
        {
            mini = data;
        }
    }
    int setmini()
    {   int temp = INT_MAX;
        for(int i=0;i<topp;i++)
        {
            if(temp>arr[i]) temp = arr[i];
        }
        return temp;
    }
    void pop() {
        // Implement the pop() function.
        if(arr[topp]==mini)
        {
            mini = setmini();
        }
        topp--;
    }

    int top() {
        // Implement the topp() function.
        return arr[topp];
    }

    int getMin() {
        // Implement the getMin() function.
        return mini;
    }  
};