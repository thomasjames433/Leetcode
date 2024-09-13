/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* num, int numsize, int target, int* rs) {
    int i=0;
    int last=numsize-1;
    int f=-1;
    int r=-1;
    *rs=2;
    int *ret=(int *)malloc(2*sizeof(int));
    ret[0]=-1;
    ret[1]=-1;
    while(i<=last){
        int mid=i+(last-i)/2;
        if(num[mid]==target){
            f=mid;r=mid;
            while(f>=i &&num[f]==target)
                f--;
            if(f==-1 || num[f]!=target)
            f++;
            while(r<last &&num[r]==target)
                r++;
            if(r==numsize || num[r]!=target)
            r--;
            ret[0]=f;
            printf("%d %d",f,r);
            ret[1]=r;
            return ret;
            
        }
        else if(num[mid]<target){
            // f=i;
            i=mid+1;
        }
        else if(num[mid]>target){
            // r=last;
            last=mid-1;
        }
            
    }
    return ret;
    
        
}