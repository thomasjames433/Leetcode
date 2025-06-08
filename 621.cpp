class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(auto it:tasks)
            count[it-'A']++;
        
        sort(count.begin(),acount.end(),greater<int>());

        int idleslots=(count[0]-1)*n;
        
        for(int i=1;i<26;i++){
            idleslots-=min(count[i],count[0]-1);
        }
        if(idleslots>0)
            return tasks.size()+idleslots;
        return tasks.size();
    }

};