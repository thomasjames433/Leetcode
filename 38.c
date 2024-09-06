char *RLE(char *a){
    int len=strlen(a);
    char *ret=(char*)malloc((3*len)*sizeof(char));
    int i=0;int j=0;
    for(i=0;i<len;i++){
        int x=1;
        while(a[i+1] && a[i]==a[i+1]){
            x++;
            i++;
        }
        ret[j]=x+'0';
        ret[j+1]=a[i];
        j+=2;
    }
    ret[j]='\0';
    return ret;
}
char* countAndSay(int n) {
    char *a=(char*)malloc(2*sizeof(char));
    a[0]='1';
    a[1]='\0';
    for(int i=1;i<n;i++)    
        a=RLE(a);
    return a;
}