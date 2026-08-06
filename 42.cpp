class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        int maxh=-1;
        for(int i=1;i<n;i++){
            if(height[i-1]>maxh)
                maxh=height[i-1];
            left[i]=maxh;
        }
        maxh=-1;
        for(int i=n-2;i>=0;i--){
            if(height[i+1]>maxh)
                maxh=height[i+1];
            right[i]=maxh;
        }
        int water=0;
        for(int i=0;i<n;i++)
            water+=max(0,min(right[i],left[i])-height[i]);
        return water;
    }
};
