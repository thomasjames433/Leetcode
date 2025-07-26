class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        n++;
        int s1=1,s2=1;
        int i=n-3;
        while(i>=0){
            int x=s1+s2;
            s1=s2;
            s2=x;
            i--;
        }
        return s2;
    }
};


int dp(int n,int *a){
    if(a[n])
        return a[n];
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    int r=dp(n-1,a)+dp(n-2,a);
    a[n]=r;
    return r;
}

int climbStairs(int n) {
    int *a=(int*)calloc(n+1,sizeof(int));
    return dp(n,a);
}