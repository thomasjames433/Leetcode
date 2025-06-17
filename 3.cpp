class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int maxno=0;
        int temp=0;
        int latest=-1;
        for(int i=0;i<s.size();i++){
            auto it=mpp.find(s[i]);
            if(it!=mpp.end()){
                if((*it).second>latest){
                    temp=i-(*it).second;
                    latest=(*it).second;
                }
                else{
                    temp++;
                }
                (*it).second=i;
            }
            else{
                mpp.insert({s[i],i});
                temp++;
            }
            maxno=max({maxno,temp});
        }
        return maxno;
    }
};