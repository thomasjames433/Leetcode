int compareInts(const void *a, const void *b) {
    int intA = *(int*)a;
    int intB = *(int*)b;

    return (intA - intB); 
}

long long dividePlayers(int* skill, int s) {
    qsort(skill, s, sizeof(int), compareInts);
    
    for(int i=0;i<s;i++)
        printf("%d ",skill[i]);

    long long int x=skill[0]*skill[--s];
    int a=skill[0]+skill[s--];;
    int i=1;
    while(i<s){
        if(skill[i]+skill[s]!=a)
            return -1;
        x+=skill[i++]*skill[s--];
    }
    return x;
}