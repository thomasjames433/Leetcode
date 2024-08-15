void push(char A[],int* top,char x){
    (*top)++;
    A[*top]=x;
}
void pop(int*top){
    (*top)--;
}
char* simplifyPath(char* path) {
    int len=strlen(path);
    if(len==1)
    return path;
    char *A=(char*)malloc((len+1)*sizeof(sizeof(char)));
    int top=0;
    A[0]='/';
    
    for(int i=1;i<len;i++){
        if((path[i]=='/' && A[top]=='/')){

        }
        else if(i==len-1 && path[i]=='/'){

        }
        else if(path[i-1]=='/' && path[i]=='.' && path[i+1]=='.' && (path[i+2]=='/' ||path[i+2]=='\0' ) ){
            if(i!=1&& top!=0)
            pop(&top);
            while(top>-1 && A[top]!='/')
            pop(&top);
            i+=2;
        }
        else if(path[i-1]=='/' && path[i]=='.' && (path[i+1]=='/' ||path[i+1]=='\0')){
           
            if(i!=1 && top!=0)
            pop(&top);
            
        }
        else{
            push(A,&top,path[i]);
        }
        
    }
    
    if(top >0 && A[top]=='/'  )
    pop(&top);
    
    A[top+1]='\0';

    return A;
}
