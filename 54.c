/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* rs) {
    int n=matrixColSize[0];
    int m=matrixSize;
    int k= m*n;
    *rs=k;
    int *ret=(int*)malloc(k*sizeof(int));
    int i=0;int j=0;int p=0;
    
    while(p<k){
        while(j<n && matrix[i][j]!=-1000){
            ret[p]=matrix[i][j];
            printf("%d ",ret[p]);
            matrix[i][j]=-1000;
            p++;
            j++;
            if(p==k)
                return ret;
        }j--;i++;

        while(i<m && matrix[i][j]!=-1000){
            ret[p]=matrix[i][j];
            printf("%d ",ret[p]);
            matrix[i][j]=-1000;
            p++;
            i++;
            if(p==k)
                return ret;
        }i--;j--;

        while(j>-1 && matrix[i][j]!=-1000){
            ret[p]=matrix[i][j];
            printf("%d ",ret[p]);
            matrix[i][j]=-1000;
            p++;
            j--;
            if(p==k)
                return ret;
        }
        j++;i--;

        while(matrix[i][j]!=-1000){
            ret[p]=matrix[i][j];
            printf("%d ",ret[p]);
            matrix[i][j]=-1000;
            p++;
            i--;
            if(p==k)
                return ret;
        }
        j++;i++;

    }
    return ret;
}