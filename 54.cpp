class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir=0;
        vector<int>ret;
        int i=0;
        int x=0;int y=0;
        int m=matrix[0].size();
        int n=matrix.size();
        cout<<m<<' '<<n<<'\n';
        while(i<m*n){
            // cout<<x<<' '<<y<<'\n';
            ret.push_back(matrix[x][y]);
            matrix[x][y]=-1000;
            if(dir==0){
                y++;
                cout<<x<<' ';
                if(y>=m || matrix[x][y]==-1000){
                    dir=1;
                    y--;
                    x++;
                }
            }
            else if(dir==1){
                x++;
                if(x>=n || matrix[x][y]==-1000){
                    dir=2;
                    x--;
                    y--;
                }
            }
            else if(dir==2){
                y--;
                if(y<0 || matrix[x][y]==-1000){
                    dir=3;
                    y++;
                    x--;
                }
            }
            else if(dir==3){
                x--;
                if(x<0 || matrix[x][y]==-1000){
                    dir=0;
                    x++;
                    y++;
                }
            }

            i++;
        }
        return ret;
    }
};


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