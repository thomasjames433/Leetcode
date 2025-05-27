class Solution {
    public:
        int differenceOfSums(int n, int m) {
        //    int ret=0;
        //    for(int i=1;i<=n;i++){
        //     if(i%m)
        //         ret+=i;
        //     else
        //         ret-=i;
        //    } 
        //    return ret;
        return n*(n+1)/2 - 2*m*((n/m)*((n/m)+1)/2);
        }
        
    };