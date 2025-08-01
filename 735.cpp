class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int cur=asteroids[i];
            if(st.empty() ||  !(st.top()>0 && cur<0))
                st.push(cur);
            else{
                if(st.top()<-cur){
                    st.pop();i--;
                }
                else if(st.top()==-cur)
                    st.pop();
            }
        }
        int i=st.size();
        vector<int>ret(i);
        while(!st.empty()){
            ret[--i]=st.top();
            st.pop();
        }

        return ret;
    }
};