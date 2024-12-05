bool canChange(char* start, char* target) {
    int t=0;
    int s=0;
    int n=strlen(start);
    while(1){
        while(s<n && start[s]=='_'){
            s++;   
        }
        while(t<n && target[t]=='_'){
            t++;    
        }
        if((s==n && t!=n )|| (t==n && s!=n ))
            return false;
        else if(s==n && t==n)
            return true;
        if(start[s]!=target[t]){
            
            return false;
        }
        
        if(start[s]=='L'){
            if(t>s)
                return false;
        }
        
        else if(start[s]=='R'){
            if(t<s)
                return false;
        }
        s++;t++;
        if(s==n && t==n)
            return true;
        
        printf("%d %d ",s,t);
    }
    // return false;
}