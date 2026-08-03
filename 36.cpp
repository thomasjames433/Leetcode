// class Solution {

// private:
//     bool insertBox(vector<vector<bool>>&box,int i,int j,int val){
//         if(i==-1){
//             if(box[j][val]==1)
//                 return false;
//             box[j][val]=1;
//             return 1;
//         }
//         else if(j==-1){
//             if(box[i][val]==1)
//                 return false;
//             box[i][val]=1;
//             return 1;
//         }
//         int boxno= (i/3)*3 + j/3;

//         if(box[boxno][val]==1)
//             return 0;
//         box[boxno][val]=1;
//         return 1;
//     }

// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<vector<bool>>rows(9,vector<bool>(9,false));
//         vector<vector<bool>>cols(9,vector<bool>(9,false));
//         vector<vector<bool>>box(9,vector<bool>(9,false));
//         // bool cols[9][9]={false};
//         // bool box[9][9]={false};
        
//         int n=board.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]!='.'){
//                     int cur=board[i][j]-'1';
//                     bool x=1;
//                     x&=insertBox(rows,i,-1,cur);
//                     x&=insertBox(cols,-1,j,cur);
//                     x&=insertBox(box,i,j,cur);
//                     if(!x)
//                         return 0;
//                 }
//             }
//         }
//         return 1;

//     }
// };

class Solution {

private:
    bool insertBox(bool (&box)[9][9],int i,int j,int val){
        if(i==-1){
            if(box[j][val]==1)
                return false;
            box[j][val]=1;
            return 1;
        }
        else if(j==-1){
            if(box[i][val]==1)
                return false;
            box[i][val]=1;
            return 1;
        }
        int boxno= (i/3)*3 + j/3;

        if(box[boxno][val]==1)
            return 0;
        box[boxno][val]=1;
        return 1;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={false};
        bool cols[9][9]={false};
        bool box[9][9]={false};
        
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    int cur=board[i][j]-'1';
                    bool x=1;
                    x&=insertBox(rows,i,-1,cur);
                    x&=insertBox(cols,-1,j,cur);
                    x&=insertBox(box,i,j,cur);
                    if(!x)
                        return 0;
                }
            }
        }
        return 1;

    }
};