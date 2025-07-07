class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && price>=st.top().first){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
public:
int span=0;
vector<int>prices={};
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i=prices.size();

        if(i>0 && price>=prices[i-1]){
            while(span<=i && prices[i-span]<=price){
                span++;
            }
        }
        else{
            span=1;
        }
        prices.push_back(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */