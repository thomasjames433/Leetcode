long long coloredCells(int n) {
    return ((long long)n-1)*((long long)n-1) + (long long)n*(long long)n;
}

/*

    // if(n==1)
    //     return 1;
    // return (n-1)*4+ coloredCells(n-1);


return n*(n-1)*2 +1;
*/