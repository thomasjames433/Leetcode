int longestValidParentheses(char* s) {
    int n=strlen(s);
    int stack[n+1];
    int top=-1;
    stack[++top]=-1;
    int max=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            stack[++top]=i;
        }
        else{
            top--;
            if(top==-1){
                stack[++top]=i;
            }
            else{
                if(max<i-stack[top])
                    max=i-stack[top];
            }

        }
    }
    return max;
}