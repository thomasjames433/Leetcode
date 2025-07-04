class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        int n=s.size();
        int m=t.size();
        if(m!=n)
            return 0;
        for(int i=0;i<m;i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(auto it:count){
            if(it!=0)
                return 0;
        }
        return 1;
    }
};

bool isAnagram(char* s, char* t) {
    int len=strlen(s);
    if(len!=strlen(t))
        return false;
    int a[26];
    int b[26];
    for(int i=0;i<26;i++){
        a[i]=0;b[i]=0;
    }    
    for(int i=0;i<len;i++){
        a[s[i]-'a']++;b[t[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}