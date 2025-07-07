class Solution {
public:
stack<pair<int,int>>st;
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        for(int i=0;i<n;i++){

            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();    
            
            st.push(i);
        }
        stack<int>st1;
        int area=0;
        for(int i=n-1;i>=0;i--){

            while(!st1.empty() && heights[st1.top()]>=heights[i])
                st1.pop();
            if(!st1.empty())
                nse[i]=st1.top();
                
            st1.push(i);
        }
        for(int i=0;i<n;i++)
            area=max(area,heights[i]*(nse[i]-pse[i]-1));
        return area;
    }
};