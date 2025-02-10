bool isSubsequence(char* s, char* t) {
    int lens=strlen(s);
    int lent=strlen(t);
    if(t<s)
        return 0;
    int x=0;
    for(int i=0;i<lent;i++){
        if(s[x]==t[i])
            x++;
    }
    if(x==lens)
        return 1;
    return 0;
}