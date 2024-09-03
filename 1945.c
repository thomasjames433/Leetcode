int getLucky(char* s, int k) {
    int sum=0;
    int i=0;
    int x=0;
    while(s[i]){
        x=s[i]-'a'+1;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        i++;
    }
    x=0;
    for(i=1;i<k;i++){
        x=0;
        while(sum!=0){
            x+=sum%10;
            sum/=10;
        }
        sum=x;
        if(x/10==0)
            return x;
    }
    return sum;
}