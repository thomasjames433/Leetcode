// int pow(int a,int b){
//     int k=1;
//     for(int i=0;i<b;i++)
//         k*=a;
//     return k;
// }

int findComplement(int num) {
    int j=0; int k=0;
    while(num!=0){
        j+=((num-1)%2)*pow(2,k); //pow function already exists
        num/=2;k++;
    }
    return j;
}