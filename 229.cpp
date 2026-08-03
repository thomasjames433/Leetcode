class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int,int>m1={nums[0],1};
        pair<int,int>m2={INT_MIN,-1};
        for(int i=1;i<nums.size();i++){
            if(m1.first==nums[i]){
                m1.second++;
            }
            else if(m2.first==INT_MIN){
                m2.first=nums[i];
                m2.second=1;
            }
            else if(m2.first==nums[i]){
                m2.second++;
            }
            else if(m1.second==0){
                m1.first=nums[i];
                m1.second=1;
            }
            else if(m2.second==0){
                m2.first=nums[i];
                m2.second=1;
            }
            else{
                m2.second--;
                m1.second--;
            }
        }
        cout<< m1.first<<" "<<m2.first;
        m2.second=0;
        m1.second=0;
        for(int i=0;i<nums.size();i++){
            if(m1.first==nums[i])
                m1.second++;
            if(m2.first==nums[i])
                m2.second++;
        }
        vector<int>ret;
        if(m1.second>nums.size()/3)
            ret.push_back(m1.first);
        if(m2.second>nums.size()/3)
            ret.push_back(m2.first);
        return ret;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* num, int n, int* rs) {
    // 2elements can appear more than n/3 times therefore
    int me1,me2,c1,c2;
    me1=me2=c1=c2=0;

    for(int i=0;i<n;i++){
        if(num[i]==me1){
            c1++;
        }
        else if(num[i]==me2){
            c2++;
        }
        else if(c1==0){
            me1=num[i];
            c1=1;
        }
        else if(c2==0){
            me2=num[i];
            c2=1;
        }
        else{
            c1--;
            c2--;
        }        
    }
    c1=0;c2=0;
    for(int i=0;i<n;i++){
        if(num[i]==me1)
            c1++;
        else if(num[i]==me2)
            c2++;
    }
    *rs=0;
    int *a=NULL;
    if(c1>n/3){
        a=(int*)realloc(a,(++(*rs))*sizeof(int));
        a[(*rs)-1]=me1;
    }

    if(c2>n/3){
        a=(int*)realloc(a,(++(*rs))*sizeof(int));
        a[(*rs)-1]=me2;
    }
    return a;
}