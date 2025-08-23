class MyStack {
public:
    queue<int> qt; 
    MyStack() {
    }
    
    void push(int x) {
        qt.push(x);
        int n=qt.size();
       for(int i=1;i<n;i++){
        qt.push(qt.front());
        qt.pop();
      }
    }
    
    int pop() {
        int n= qt.front();
        qt.pop();
        return n;
        
    }
    
    int top() {
        return qt.front();
    }
    
    bool empty() {
        return !qt.size();
    }
};
