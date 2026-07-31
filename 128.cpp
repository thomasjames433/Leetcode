class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto it:nums)
            s.insert(it);
        if(s.empty())
            return 0;
        int maxno=1;
        for(auto i:s){
            auto it=s.find(i-1);

            if(it==s.end()){
                int count=1;
                it=s.find(i+1);
                while(it!=s.end()){
                    count++;
                    it=s.find(i+count);
                }
                maxno=max(maxno,count);
            }
        }
        return maxno;
        
    }
};