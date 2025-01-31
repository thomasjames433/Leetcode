void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void rotate(int** matrix, int m, int* matrixColSize) {
    for(int i=0;i<m;i++){

        for(int j=i+1;j<m;j++){
            swap(&matrix[i][j],&matrix[j][i]);
        }

    }
    for(int i=0;i<m;i++){

        for(int j=0;j<m/2;j++){
            swap(&matrix[i][j],&matrix[i][m-j-1]);
        }

    }
    return;
}