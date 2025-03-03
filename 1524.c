// a*b %c= (a%c * b%c)%c

#define MOD 1000000007

int numOfSubarrays(int* arr, int n) {

    int odd=0;
    int even=1;
    long long int prefixsum=0;
    long long int result=0;
    for(int i=0;i<n;i++){
        prefixsum+=arr[i];
        if(prefixsum%2==0){
            result+=odd;
            even++;
        }
        else{
            result+=even;
            odd++;
        }
    }
    return (int) (result %1000000007);
}

/*
Index:    0   1   2   3   4  
Arr:      1   2   3   5   6  
Prefix:   1   3   6  11  17
          O   O   E   O   O  
O = Odd Prefix Sum
E = Even Prefix Sum
Let’s focus on index 3 (prefixSum = 11, which is Odd):

How do we form odd subarrays?
We subtract an even prefix sum.
Previous even prefix sums are at:
Index 2 (prefixSum = 6) → Forms subarray [3, 5]
Index 0 (prefixSum = 0) (empty sum is even) → Forms subarray [1, 2, 3, 5]
This means at index 3, we can form evenCount = 2 new odd subarrays.
We add evenCount to result.
*/