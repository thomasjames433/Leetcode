class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        bool app=0;
        int len=s.size();
        long long int num=0;
        for(int i=0;i<len;i++){
            if((s[i]=='-'|| s[i]=='+') && app==0){
                app=1;
                if(s[i]=='-')
                    sign=-1;
                cout<<sign;
            }
            else if (s[i]==' ' &&  app==0){
                continue;
            }
            else if(s[i]>='0' && s[i]<='9'){
                // if(s[i]!=0)
                    app=1;
                num*=10;
                num+=s[i]-'0';
                if(sign *num>INT_MAX)
                    return INT_MAX;
                if(sign *num<INT_MIN)
                    return INT_MIN;
            }
            else{
                return sign*num;
            }
        }
        return sign*num;
    }
};

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