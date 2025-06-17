class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int>s;
        for(auto it:nums)
            s.insert(it);
        int maxno=1;
        int temp=1;
        for (auto it=s.begin();it!=s.end();it++){
            auto prev= s.find(*(it)-1);
            if(prev!=s.end())
                continue;
            int x=*it;
            prev=it;
            while(prev!=s.end()){
                prev=s.find(++x);
                temp++;
            }
            temp--;
            maxno=max({maxno,temp});
            temp=1;
        }
        return maxno;
        
    }
};