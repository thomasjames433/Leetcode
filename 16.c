int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* num, int n, int target) {
    int x=num[0]+num[1]+num[2];
    qsort(num, n, sizeof(int), compare);


    
    for(int i=0;i<n-2;i++){

        int l=i+1;
        int r=n-1;
        while(l<r){
            int y= num[i]+num[l] +num[r]-target;
            if(abs(x-target)>abs(y))
                x=y+target;
                
            if(y<0)
                l++;
                
            else
                r--;
                
        }

    }
    
    return x;
}