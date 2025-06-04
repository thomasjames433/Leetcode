class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>>v1={{}};
            sort(nums.begin(),nums.end());
            int start=0;int end=0;
            for(int i=0;i<nums.size();i++){
                start=0;
    
                if(i!=0 && nums[i]==nums[i-1])
                    start=end;
                
                end=v1.size();
    
                for(int j=start;j<end;j++){
                    auto news=v1[j];
                    news.push_back(nums[i]);
                    v1.push_back(news);
                }
            }
            return v1;
        }
    };