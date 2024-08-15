#include <math.h>
bool isPalindrome(int x) {
    if(x<0)
    return 0;
    else if(x>=0 && x<10)
    return 1;
    else{
        int len=0;
        int y=x;
        while(y!=0){
            len++;
            y/=10;
        };
        while(len>1){
            y=(pow(10,len-1));
            if(x/y != x%10 )
            return 0;
            x=x%y;
            x=x/10;
            len-=2;
        }
        return 1;
    }
}