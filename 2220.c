int minBitFlips(int start, int goal) {
    int x=0;
    for(int i=0;i<32;i++){
        if(start%2!=goal%2)
            x++;
        start/=2;
        goal/=2;
        if(start==goal)
            return x;
    }
    return x;
}