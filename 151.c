char *reverse(char *a,int x,int y){
    char *new=(char*)malloc((y-x+1)*sizeof(char));
    int i=0;int j=y-1;
    while(x<=j){
        new[i++]=a[j--];
    }
    new[i]='\0';
    return new;
}

char* reverseWords(char* s) {
    int len=strlen(s);
    char *new=(char*)malloc((len+2)*sizeof(char));
    new[0]='\0';
    int i=0;
    while(i<len){
        while(i<len && s[i]==' ')
            i++;
        int j=i;
        if(i==len)
            break;
        while(j<len && s[j]!=' ')
            j++;
        char *a=reverse(s,i,j);
        strcat(new,a);
        strcat(new," ");
        i=j;
    }    
    new[strlen(new)-1]='\0';
    new=reverse(new,0,strlen(new));
    return new;
}