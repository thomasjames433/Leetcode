int findPermutationDifference(char* s, char* t) {
    int sa[26];int ta[26];
    for(int i=0;i<26;i++){
        sa[i]=0;ta[i]=0;
    }
    int len=strlen(s);
    for(int i=0;i<len;i++){
        sa[s[i]-'a']=i;
        ta[t[i]-'a']=i;
    }
    int n =0;
    for(int i=0;i<26;i++){
        n=n+ abs(sa[i]-ta[i]);
    }
    return n;
}