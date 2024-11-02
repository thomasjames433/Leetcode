bool isCircularSentence(char* sen) {
    int n=strlen(sen);
    if(sen[0] != sen[n-1])
        return false;
    for(int i=1;i<n-1;i++){
        if(sen[i]==' '){
            if(sen[i-1]!=sen[i+1])
                return false;
        }
    }
    return true;
}