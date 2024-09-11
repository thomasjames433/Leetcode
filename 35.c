int searchInsert(int* num, int numsize, int target) {
    int start=0;
    int end=numsize-1;
    if(target>num[end])
        return numsize;
    if(target<num[0])
        return 0;
    while(start<=end){
        int mid=(start+end)/2;
        
        if(target>num[mid]){
            start=mid+1;
        }
        else if(target<num[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return start;
}