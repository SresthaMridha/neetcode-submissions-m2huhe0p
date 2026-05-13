class MedianFinder {
public:
    priority_queue<int> leftmaxheap;

    priority_queue<int,vector<int>,greater<int>> rightminheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(rightminheap.empty() || num >= rightminheap.top()){
            rightminheap.push(num);
        }
        else{
            leftmaxheap.push(num);
        }

        if(rightminheap.size() > leftmaxheap.size() + 1){
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }
        else if(leftmaxheap.size() > rightminheap.size()){
            rightminheap.push(leftmaxheap.top());
            leftmaxheap.pop();
        }
    }
    
    double findMedian() {
        if(leftmaxheap.size() == rightminheap.size()){
            return (leftmaxheap.top() + rightminheap.top())/2.0;
        }

        return rightminheap.top();
    }
};
