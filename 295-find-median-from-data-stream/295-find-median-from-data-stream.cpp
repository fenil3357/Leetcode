class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn; 
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        if(mx.empty()){
            mx.push(x);
            return;
        }
        if(mx.size() > mn.size()){
            if(mx.top() > x){
                mn.push(mx.top());
                mx.pop();
                mx.push(x);
            }
            else
                mn.push(x);
        }
        else{
            if(mx.top() > x)
                mx.push(x);
            else{
                mn.push(x);
                mx.push(mn.top());
                mn.pop();
            }
        }
    }
    
    double findMedian() {
        if(mx.size() > mn.size()) return mx.top();
        else return (mx.top() + mn.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */