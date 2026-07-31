class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s=="")
            return 0;
        int maxlen =1;
        unordered_map <char,int>mpp;
        int curlen=1;
        mpp[s[0]]=0;
        int start=0;
        for(int i=1;i<s.size();i++){
            if (mpp.find(s[i]) !=mpp.end()){
                int x=mpp[s[i]];
                if (x>=start)
                    start=x+1;
            }
            mpp[s[i]]=i;
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};