class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int maxar=0;
        int area=0;
        int minh;
        while(start<end){
            minh = min(height[start],height[end]);
            area = minh*(end-start);
            maxasr=max(area,maxar);
            if(minh==height[start])
                start++;
            else
                end--;
        }
        return maxar;
    }
};