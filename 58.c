int lengthOfLastWord(char* s) {
    int len=strlen(s);
    while(s[len-1]==' ')
        len--;
    int i=len-1;
    while(i>=0 && s[i]!=' ')
        i--;
    return len-i-1;

    
}