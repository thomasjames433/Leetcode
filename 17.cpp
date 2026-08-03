class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> alpnum={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string>ret;
        ret.push_back("");
        int n=digits.size();
        for(int p=0;p<n;p++){
            int cur=digits[p]-'0';
            auto alphabets= alpnum[cur];
            int alpcount=alphabets.size();

            int retsize=ret.size();
            ret.reserve(retsize*alpcount);
            for(int i=1;i<alpcount;i++)
                ret.insert(ret.end(),ret.begin(),ret.begin()+retsize);
            for(int i=0;i<alpcount;i++){
                for(int j=0;j<retsize;j++){
                    ret[i*retsize+j]+=alphabets[i];
                }
            }
        }
        return ret;
    }
};