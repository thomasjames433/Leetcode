class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ret(nums1.size(),-1);
        unordered_map<int,int>mpp;
        for(auto it:nums2){
            while(st.size()>0 && st.top()<it){
                mpp[st.top()]=it;
                st.pop();
            }
            st.push(it);
        }
        for (int i=0;i<nums1.size();i++){
            auto it=mpp.find(nums1[i]);
            if(it!=mpp.end())
                ret[i]=it->second;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st1;
        stack<int>st2;
        for(auto it:nums2)
            st1.push(it);
        vector<int>ret;
        for(auto it:nums1){
            int max=-1;
            while(st1.top()!=it){
                int x=st1.top();
                if(x>it)
                    max=x;
                st1.pop();
                st2.push(x);
            }
            ret.push_back(max);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        return ret;
    }
};