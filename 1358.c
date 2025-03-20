int min(int a , int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    return c;
}

int numberOfSubstrings(char* s) {
    int count=0;
    int a=-1,b=-1,c=-1;
    int y=0;
    int n=strlen(s);
    int prev=0;
    int start=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(a==-1)
                y++;
            a=i;
            
        }
        else if(s[i]=='b'){
           if(b==-1)
                y++;
            b=i;
        }
        else if(s[i]=='c'){
            if(c==-1)
                y++;
            c=i;
        }
        if(y==3){
            start=min(a,b,c);
            count = count + (n-i)*(start-prev) + (n-i);
            y=0;
            i=start;
            prev=i+1;
            a=-1;
            b=-1;
            c=-1;
        }
    }
    return count;
}