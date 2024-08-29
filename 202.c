bool isHappy(int n) {
    if(n==1 || n==7)
        return 1;
    else if(n<10)   
        return 0;
    int num=0;
    while(n!=0){
        num+=(n%10) *(n%10);
        n/=10;
    }
    return isHappy(num);
}