class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;

        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        cout<<nums[start]<<" "<<start;
        end=start+n-1;
        while(start<end){
            
            int mid=(start+end)/2;
            if(nums[mid%n]==target)
                return mid%n;
            else if(nums[mid%n]>target)
                end=mid-1;
            else 
                start=mid+1;
        }
        if(nums[start%n]==target)
            return start%n;
        return -1;
    }
};