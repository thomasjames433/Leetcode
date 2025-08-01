class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int maxno=nums[0];
        int i=0;
        int pref=0;
        int suf=n-1;
        while(i<n){
            pref=i;
            while(i<n && nums[i]!=0)
                i++;
            suf=i-1;
            i++;
            int temp=1;
            int j=pref;
            while(j<=suf){
                temp*=nums[j];
                maxno=max(temp,maxno);
                j++;
            }
            temp=1;
            j=suf;
            while(j>=pref){
                temp*=nums[j];
                maxno=max(temp,maxno);
                j--;
            }
            
        }
        if(pref==0 && suf==n-1)
            return maxno;
        return max(maxno,0);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int totmax=nums[0];
        int maxwin=nums[0];
        int minwin=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(maxwin,minwin);
            maxwin=max({nums[i],maxwin*nums[i]});
            minwin=min({nums[i],minwin*nums[i]});
            totmax=max({totmax,maxwin});
        }
        return totmax;

    }
};