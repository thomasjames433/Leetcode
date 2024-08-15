bool canJump(int* num, int numsize) {
    if(numsize==1)
    return true;
    if(numsize!=1 && num[0]==0)
    return false;
    for(int i=1;i<=num[0];i++){
        int j=1;
        int c=0;
       
        while(j<numsize-1){    
            // when int k=0 here test 3 no problem but test 6&7 problem
            int k=0;
            if(num[j]==0){
                for(int x=j-1;x>=c;x--){
                    if(num[x]>j-x){
                        k=1;
                        break;
                }
                }
                printf("%d ",k);
                if(k==0)
                return false;
                if(num[j]!=0)
                c=j+1;
            }
            j++;
        }
    }
    return true;
}