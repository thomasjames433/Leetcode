class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(swap==0){
            swap=1;
            cout<<"0"<<" ";
            if(!minheap.empty()){
                int x=minheap.top();
                if (x<num){
                    minheap.pop();
                    minheap.push(num);
                    maxheap.push(x);
                    return;
                }
            }
            maxheap.push(num);
            return;

        }
        else{
            cout<<"1"<<" ";
            swap=0;
            int x=maxheap.top();
            if(x>num){
                maxheap.pop();
                maxheap.push(num);
                minheap.push(x);
                return;
            }
            minheap.push(num);
            return;
        }

    }
    
    double findMedian() {
        double x=maxheap.top();
        if(minheap.size()==maxheap.size()){
            double y=minheap.top();
            return (x+y)/2;
        }
        
        return x;
    }
private:
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;
int swap=0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */