int getnum(char *str,int *i){
    int num=0; int flag=0;
    while(str[*i]== ' ')
        (*i)++;
    if(str[*i]=='-'){
        flag=1;
        (*i)++;
    }
    else if(str[*i]=='+'){
        (*i)++;
    }
    while(isdigit(str[*i])){
        if(flag==1 &&  (num>214748364  || (num== 214748364 && str[*i]-'0'>7)) )
            return INT_MIN;
        
        if(flag==0 &&  (num>214748364  || (num== 214748364 && str[*i]-'0'>6)) )
            return INT_MAX;
            
        num=num*10-'0'+str[*i];
        (*i)++;
    }
    if(flag)
        return -num;
    return num;
}

int myAtoi(char* s) {
    int i=0;
    return getnum(s,&i);
}