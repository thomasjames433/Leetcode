class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.insert(nums1.begin(),n,0);
        nums1.erase(nums1.end()-n,nums1.end());
        for(auto it:nums1)
            cout<<it<<" ";
        int i=n;
        int j=0;
        int cur=0;
        while(i<m+n && j<n){
            if(nums1[i]>nums2[j]){
                nums1[cur]=nums2[j];
                j++;
            }
            else{
                nums1[cur]=nums1[i];
                i++;
            }
            cur++;
        }
        // cout<<i<<" "<<j;
        while(i<m+n){
            nums1[cur]=nums1[i];
            i++;
            cur++;
        }
        while(j<n){
            nums1[cur]=nums2[j];
            j++;
            cur++;
        }
        return;
    }
};

void merge(int* num1, int nums1Size, int m, int* num2, int nums2Size, int n) {
    int k=m+n-1;
    int a1=m-1;
    int a2=n-1;
    // printf("%d %d",a1,a2);
    while(1){
        if(k==-1)
            return;
        if(a1<0 || (a2>-1 && num2[a2]>num1[a1]) ){
            num1[k--]=num2[a2--];
            printf("%d ",num1[k+1]);
        }
        else if(a2<0 || (a1>-1 && num2[a2]<=num1[a1])){
            num1[k--]=num1[a1--];
            printf("%d ",num1[k+1]);
            
        }
    }
}