bool checkPowersOfThree(int n) {
    int a=1;
    while(3*a<n)
        a*=3;
        printf("%d",a);
    while(n!=0){
        if(n/a==2)
            return 0;
        n= n- ((n/a) *a) ;
        a/=3;
    }
    return 1;
}

/*
while (n > 0) {
        if (n % 3 == 2) {  // If we find a "2" in base-3 representation, return false
            return false;
        }
        n /= 3;  // Move to the next ternary digit
    }
    return true;
*/