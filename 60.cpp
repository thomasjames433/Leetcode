class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        vector<int>st;
        st.push_back(1);
        int fact=1;
        for(int i=2;i<=n;i++){
            fact*=i;
            st.push_back(i);
        }
        k--;
        for(int i=n;i>0;i--){
            fact/=i;
            int spot=k/fact;
            s.push_back(st[spot]+'0');
            st.erase(st.begin()+spot,st.begin()+spot+1);
            k%=fact;

        }
        return s;
    }
};