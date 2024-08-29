char * getword(char *s,int *i){
    char *a=(char*)malloc(3001*sizeof(char));
    a[0]='\0'; int j=0;
    while(s[*i]!='\0' && s[*i]!=' '){
        a[j++]=s[(*i)++];
    }
    a[j]='\0';
    return a;
}

bool wordPattern(char* pattern, char* s) {
    char **str=(char **)malloc(26*sizeof(char*));
    char letter[26];
    for(int i=0;i<26;i++){
        letter[i]='a'+i;
        str[i]=(char*)malloc(3001*sizeof(char));
        str[i][0]='\0';
    }
    int i=0;int j=0;
    while(pattern[j]!='\0'){
        if(i>0 && s[i-1]=='\0')
            return false;
        char *x=getword(s,&i);
        if(str[pattern[j]-'a'][0]=='\0'){
            for(int i=0;i<26;i++){
                if(!strcmp(x,str[i]))
                    return false;
            }
            strcat(str[pattern[j]-'a'],x);
        }
        else{

            printf("%s",x);
            if(strcmp(x,str[pattern[j]-'a']))
                return false;
        }
        i++;
        j++;
    }
    if(s[i-1]=='\0')
    return true;
    return false;
}