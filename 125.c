bool isPalindrome(char* s) {
    int len=strlen(s);
    int a=0;len--;
    while(a<len){
        if(isalnum(s[a])&& isalnum(s[len])){
            if(s[a]!=s[len] && s[a]!=toupper(s[len]) && s[a]!=tolower(s[len]))
            return false;
            printf("%c",s[a]);
            a++;len--;
        }
        while(a<len && !isalnum(s[a]))
        a++;
        while(a<len &&!isalnum(s[len]))
        len--;
    }
    return true;
}