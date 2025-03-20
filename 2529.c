int maximumCount(int* num, int n) {
    int l=0;
    int r=n-1;
    while(l<r){
        int mid= l+ (r-l)/2;
        if(num[mid]>0){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d %d %d\n",l,r,n);
    while(r>=0 && r<n && num[r]<=0)
        r++;
    while(l>=0 && l<n && num[l]>=0)
        l--;
    
    printf("%d %d %d",l,r,n);    
    if(l==-1 && r==n)
        return 0;
    if(l==r)
        return n;
        
    if(n-r<l+1)
        return l+1;
    return n-r;

}