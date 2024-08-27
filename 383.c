bool canConstruct(char* rn, char* mag) {
    int a[26];
    for(int i=0;i<strlen(rn);i++)
        a[rn[i]-'a']++;
    for(int i=0;i<strlen(mag);i++)
        a[mag[i]-'a']--;
    for(int i=0;i<26;i++)
        if(a[i]>0)
            return false;
    return true;
}