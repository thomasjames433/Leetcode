class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=INT_MIN;
        int cur=-100000;
        for(int i=0;i<nums.size();i++){
            cur=max(nums[i],cur+nums[i]);
            ret=max(cur,ret);
        }
        return ret;
    }
};

int maxSubArray(int* num, int numsize) {
    int i=0;int max=num[0];
    while(i<numsize){
        int temp=0;
        while(i<numsize && num[i]<1){
            if(num[i]>max)
            max=num[i];
            i++;

        }
        if(i==numsize)
            return max;
        while(i<numsize && temp>=0){
            temp+=num[i];
            i++;
            if(temp>max)
            max=temp;
        }
        if(i==numsize)
            return max;

    }
    return max;
}