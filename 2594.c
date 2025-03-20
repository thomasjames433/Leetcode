int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long int gettot(int *num,int n,long long time){
    long long  tot=0;

    for(int i=0;i<n;i++){
        if(time<num[i])
            break;
        tot+=(long long )sqrt(time/num[i]);
    }
    return tot;
}

long long repairCars(int* num, int n, int cars) {
    qsort(num, n, sizeof(int), compare);

    long long  l=num[0];
    long long  r=(long long)num[0] * (long long)cars* (long long)cars;

    while(l<r){
        long long  mid= l+ (r-l)/2;

        long long int x= gettot(num,n,mid);
        if(x<cars)
            l=mid+1;
        else{
            r=mid;
        }
    }   
    return l;

}