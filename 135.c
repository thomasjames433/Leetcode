
int totsum(int a){
    return a*(a+1)/2;
}
int candy(int* num, int numsize) {
    int x=numsize;
    int max=0;
    int min=0;
    int i=0;
    if(i<numsize-1 && num[i]>num[i+1]){
        max=i;
        while(i<numsize-1 &&num[i]>num[i+1])
        i++;
        min=i;
        x+=totsum(min-max);
    }
    if(i<numsize-1 && num[i]==num[i+1] && num[0]>num[1]){
            while(i<numsize-2 &&num[i]==num[i+1]==num[i+2])
            i++;
            i++;
            
        }
    //   

    while(i<numsize-1){
        int dif1=-1;
        int dif2=-1;
        // slpe up
        min=i;
        while(i<numsize-1 &&num[i]<num[i+1])
        i++;
        max=i;
        dif1=max-min;
        
        if(i<numsize-1 && num[i]==num[i+1]){
            while(i<numsize-2 &&num[i]==num[i+1] && num[i+1]==num[i+2])
            i++;
            i++;
            x=x+totsum(dif1);
            dif1=-1;
        }

        // slpe down
        max=i;
        while(i<numsize-1 &&num[i]>num[i+1])
        i++;
        min=i;
        dif2=min-max;

        if(dif2>=dif1){
            if(dif1!=-1)
            x=x+totsum(dif2)+totsum(dif1-1);
            else
            x=x+totsum(dif2);
        }
        else{
            if(dif2!=-1)
            x=x+totsum(dif1)+totsum(dif2-1);

        }
        


        if(i<numsize-1 && num[i]==num[i+1]){
            while(i<numsize-2 &&num[i]==num[i+1] && num[i+1]==num[i+2])
            i++;
            i++;

        }

    }
    return x;

}

/*
test cases to be inputed

[1,3,2,2,1]
[1,2,3,5,4,3,2,1,4,3,2,1,3,2,1,1,2,3,4]
[0,3,34,34,5,3,1,1,5,8,78,78,78,2,2,2,2,7,0]
[1,0,3,34,34,5,3,1,1,5,8,78,78,78,2,2,2,2,7,0]
[0,3,34,34,5,3,1,1,5,8,78,78,78,2,2,2,2,7,0,0,0,0]
[1,0,3,34,34,5,3,1,1,5,8,78,78,78,2,2,2,2,7,0]
*/