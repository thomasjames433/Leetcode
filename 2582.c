int passThePillow(int n, int time) {
    if((time/(n-1))%2==0){
        return time%(n-1)+1;
    }
    else{
        return n-time%(n-1);
    }
}

// 2  just changed n to n-1

int passThePillow(int n, int time) {
    n--;
    if((time/(n))%2==0){
        return time%(n)+1;
    }
    else{
        return n-time%(n)+1;
    }
}
