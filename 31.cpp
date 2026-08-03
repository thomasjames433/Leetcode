class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                break;
            }
            i--;
        }
        cout<<i;
        if(i==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int minno=i+1;
        int j=i+2;
        while(j<nums.size()){
            if(nums[minno]>nums[j] && nums[j]>nums[i]){
                minno=j;
            }
            j++;
        }
        swap(nums[i],nums[minno]);
        sort(nums.begin()+i+1,nums.end());
        return ;
    }
};


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void nextPermutation(int* num, int numsize) {
    int min=numsize-1;
    for(int i=numsize-1;i>0;i--){
        if(num[i]>num[i-1]){
            while(num[i-1]>=num[min]){
                min--;
            }

            swap(&num[i-1],&num[min]);
            int x=i;
            int y=numsize-1;
            while(x<y){
                swap(&num[x],&num[y]);
                x++;y--;
            }
            return;
        } 
        // else{
        //     min=i;
        // }
    }
    int x=0;
    int y=numsize-1;
    while(x<y){
        swap(&num[x],&num[y]);
        x++;y--;
    }
    return;
}