class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int c=0;
        int n=nums.size()-1;
        while(i<n){
            int curjump=nums[i];
            int maxjump=i;
            c++;
            for(int j=1;j<=curjump;j++){
                if(i+j>=n)
                    return c;
                if(nums[i+j]>=nums[maxjump]-(i+j-maxjump))
                    maxjump=i+j;
            }
            i=maxjump;
            
        }
        return c;

    }
};

int jump(int* nums, int n) {
    int *a=(int *)calloc(n,sizeof(int));
    a[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<nums[i];j++){
            if(i+1+j<n && (a[i+1+j]==0 || a[i+1+j]>a[i]+1))
                a[i+1+j]=a[i]+1;
        }
    }
    return a[n-1];
}


Other code 

int jump(int* nums, int numsSize) {
    if(numsSize <= 1)return 0;
    int jump = 0;
    int current = 0;
    int next = 0;
    for(int i = 0; i < numsSize; i++){
        if((i + nums[i]) > next){
            next = i + nums[i];
        }
        if(i == current){
            jump++;
            current = next;
            if(current >= (numsSize-1))return jump;
        }
    }
    return jump;
}