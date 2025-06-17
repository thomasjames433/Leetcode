class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int end=nums.size()-1;
        int start=0;
        return nums[binarysearch(nums,start,end)];
    }

    int binarysearch(vector<int>&nums,int start,int end){
        if(end-start<2)
            return start;
        int mid=(start+end)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid] !=nums[mid+1])
            return mid;
        if(mid%2==0){
            if(nums[mid]==nums[mid-1])
                return binarysearch(nums,start,mid-2);
            return binarysearch(nums,mid+2,end);
        }
        else{
            if(nums[mid]==nums[mid-1])
                return binarysearch(nums,mid+1,end);
            return binarysearch(nums,start,mid-1);
        }
    }
};