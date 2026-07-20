class MyStack {

    private:
    int * arr;

    int cap ;
    int curr ;
public:

    // using array 
    MyStack() {
        cap = 1000;
        arr = new int[cap];
        curr = -1;
    }
    
    void push(int x) {
        arr[++curr] = x;
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        return arr[curr --];
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        return arr[curr];
    }
    
    bool empty() {
        return curr == -1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */