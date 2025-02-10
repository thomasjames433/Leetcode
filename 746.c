int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int minCostClimbingStairs(int* cost, int costsize) {
    for(int i=2;i<costsize;i++){
        cost[i]+=min(cost[i-1],cost[i-2]);
    }
    return min(cost[costsize-1],cost[costsize-2]);
}