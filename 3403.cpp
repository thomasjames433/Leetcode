class Solution {
    public:
        string answerString(string word, int numFriends) {
            if(numFriends==1)
                return word;
    
            int n=word.size();
            int wordlength = n- numFriends+1;
            vector<int>maxarr={0};
    
            for(int i=1;i<n;i++){
                if(word[i]==word[maxarr[0]]){
                    maxarr.push_back(i);
                }
                else if(word[i]>word[maxarr[0]]){
                    maxarr.clear();
                    maxarr.push_back(i);
                }
            }  
            string s;
            if(maxarr[0] +wordlength<n)
                s=word.substr(maxarr[0],wordlength);
            else
                s=word.substr(maxarr[0],n);
            for(int j=1;j<wordlength;j++){
                int max2=0;
    
                for (int x=1;x<maxarr.size();x++){
                    
                    if(word[maxarr[x]+j] >word[maxarr[max2]+j]){
                        maxarr.erase(maxarr.begin(),maxarr.begin()+x);
                        max2=0;
                        cout << max2<<" ";
                        x=0;
                    }
                    else if(word[maxarr[x]+j] <word[maxarr[max2]+j]){
                        maxarr.erase(maxarr.begin()+x);
                        cout<<"HI";
                        x--;
                    }
                }
                if(maxarr.size()==1)
                    break;
            }
            if(maxarr[0] +wordlength<n){
                s=word.substr(maxarr[0],wordlength);
            
            }
            else
                s=word.substr(maxarr[0],n);
            
            return s;
            
        }
    };