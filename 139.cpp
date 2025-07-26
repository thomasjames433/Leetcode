class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>isword;
        unordered_set<string>words;
        for(auto it:wordDict)
            words.insert(it);
        int x=-1;
        string cur="";
        for(int i=0;i<s.size();i++){
            
            cur+=s[i];
            auto it=words.count(cur);
            int y=x;
            while(it==0){
                if(y==-1)
                    break;
                if(words.count(s.substr((isword[y])+1,i-(isword[y]))))
                    break;
                y--;
            }
            if(it!=0 || y!=-1){
                isword.push_back(i);
                x++;
            }
        }
        if(x!=-1 && isword[x]==s.size()-1)
            return 1;
        return 0;
    }
};

