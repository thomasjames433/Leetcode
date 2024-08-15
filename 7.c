#include <stdio.h>
int reverse(int x){
    int a=x;
    int y=0;
    if(x==-2147483648)
    return 0;
    if(x<0){
        a=-a;
        y=1;
    }
    int new=0;
    for(int i=1;i<=9;i++){
        new=new*10+a%10;
        a=a/10;
        if(a==0)
        break;
    }
    if(a==0){
        if(x>=0)
        return new;
        else 
        return -new;
    }
    else{
        if(new>214748364)
        return 0;
        else {
            if(x>=0)
            return new*10+a;
            else{
                return -new*10-a;
            }
        }
       
    }
      
}
int main(){
    printf("%d",reverse(1463847412));
}

