int findMin(int* num, int n) {
    int left=0;
    int right=n-1;
    while(left<right){
        int mid=left + (right-left)/2;

        if(num[mid]>num[right]){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return num[left];
}





