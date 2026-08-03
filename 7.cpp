class Solution {
public:
    int reverse(int x) {
        if (x==INT_MIN)
            return 0;
        int sign=1;
        if(x<0)
            sign=-1;
        x=abs(x);

        int end= 214748364;
        int len=0;
        int fin=0;
        while(x && len<9){
            fin=fin*10 +x%10;
            x/=10;
            len++;
        }
        if(x){
            if(fin>end)
                return 0;
            return sign*(fin*10+x);
        }
        return sign*fin;
    }
};