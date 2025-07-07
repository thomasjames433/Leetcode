class Solution {
public:
    int trap(vector<int>& height) {
        int h=height.size();
        int sum=0;
        vector<int> maxl(h,0);
        vector<int> maxr(h,0);
        int left=height[0];
        for(int i=1;i<h-1;i++){
            if(left<height[i])
                left=height[i];
            maxl[i]=left;
            
        }
        int right=height[h-1];
        for(int i=h-2;i>0;i--){
            if(right<height[i])
                right=height[i];
            maxr[i]=right;
            sum+= min(maxl[i],maxr[i])-height[i];
            
        }
        return sum;
    }
};