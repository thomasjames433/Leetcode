int findDuplicate(int* num, int n) {
    int s=0;
    int f=0;
    do{
        s=num[s];
        f=num[num[f]];
    }while(s!=f);
    
    s=0;
    while(s!=f){
        s=num[s];
        f=num[f];
    }
    
    return s;

}
