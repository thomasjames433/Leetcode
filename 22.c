/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 void makepar(char ***ret, char*first, int n, int len,int *rs,int x,int y){
    if(len==2*n){
        *ret=(char**)realloc(*ret,((*rs)+1)*sizeof(char*));
        first[len]='\0';
        (*ret)[(*rs)++]=strdup(first);
    }
    else{
        if(x<n){
            first[len]='(';
            makepar(ret,first,n,len+1,rs,x+1,y);
        }
        
        if(y<x){
            first[len]=')';
            makepar(ret,first,n,len+1,rs,x,y+1);
        }
    }
    return;
}

char** generateParenthesis(int n, int* rs) {
    *rs=0;
    char **ret=NULL;
    char *first=(char*)malloc((2*n+1)*sizeof(char));
    first[0]='(';
    makepar(&ret,first,n,1,rs,1,0);
    return ret;
}