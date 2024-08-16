int compare_ints(const void *a, const void *b) {
    int int_a = *((int *)a);
    int int_b = *((int *)b);
    return (int_a > int_b) - (int_a < int_b); // Equivalent to: return int_a - int_b;
}

int majorityElement(int* num, int numsize) {
    qsort(num, numsize, sizeof(int), compare_ints);
    int max=0;int x=0;int m=0;
    for(int i=0;i<numsize-1;i++){
        if(num[i]==num[i+1])
            x++;
        else{
            if(x>max){
                    max=x;
                    m=i;
                }
            x=0;
        }
        if(i==numsize-2){
            if(x>max)
                m=i;
        }
    }
    return num[m];
}