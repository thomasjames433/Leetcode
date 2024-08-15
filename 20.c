void push(int  A[],int *top, int x){
    (*top)++;
    A[*top]=x;
}
void pop(int *top){
    (*top)--;
}
bool isValid(char* s) {
    if(*s==')' || *s==']' || *s=='}' || s[strlen(s)-1]=='(' || s[strlen(s)-1]=='[' || s[strlen(s)-1]=='{' || s[1]=='\0')
    return false;
    int len=strlen(s);
    
    int A[len];
    int c=0;
    int i=-1;
    for(c=0;c<len;c++){
        if(s[c]=='(' || s[c]=='{' || s[c]=='['){
            push(A,&i,s[c]);
            printf("%d %c",i,A[i]);
        }
        else{
            if((s[c]==')' && (i==-1 ||A[i]!='(' )) ||(s[c]=='}' && (i==-1 ||A[i]!='{')) ||(s[c]==']' && (i==-1 ||A[i]!='[')) )
            return false;
            else 
            pop(&i);
        }
    }
    if(i==-1)
    return true;
    return false;
}