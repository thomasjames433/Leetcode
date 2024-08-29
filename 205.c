bool isIsomorphic(char* s, char* t) {
    int len=strlen(s);
    char store[1001];
    char val[1000];
    for(int i=0;i<1000;i++){
        store[i]='A';val[i]='A';
    }
    for(int i=0;i<len;i++){

        if(store[s[i]]=='A'){
            if (val[t[i]]!='A' && val[t[i]] !=s[i])
                return false;
            store[s[i]]=t[i];
            val[t[i]]=s[i];
        }
        else{
            if(store[s[i]]!=t[i])
                return false;
        }
    }
    return true;
}
