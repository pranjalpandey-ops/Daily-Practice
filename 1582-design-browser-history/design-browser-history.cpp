class BrowserHistory {
public:
    stack<string>st;   
    stack<string>q; 
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        st.push(url);
        while(!q.empty()) {
            q.pop();
        }
    }
    
    string back(int steps) {
        while(steps-- && st.size()>1){
            q.push(st.top());
            st.pop();
        }       
        return st.top();
    }
    
    string forward(int steps) {
        while(steps-- && !q.empty()){
            st.push(q.top());
            q.pop();
        }
        return st.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */