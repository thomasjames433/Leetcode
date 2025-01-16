int xorAllNums(int* num1, int num1s, int* num2, int num2s) {
    int a=0;int b=0;

    if(num2s%2!=0){
        for(int i=0;i<num1s;i++)
            a^=num1[i];
    }

    if(num1s%2!=0){
        for(int i=0;i<num2s;i++)
            b^=num2[i];
    }
    return a^b;
}
