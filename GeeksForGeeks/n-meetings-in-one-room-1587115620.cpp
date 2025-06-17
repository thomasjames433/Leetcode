class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        map<int,int>mpp;
        for(int i=0;i<start.size();i++){
            auto it=mpp.find(start[i]);
            if (it==mpp.end()){
                mpp.insert({start[i],end[i]});
            }
            else{
                if ((*it).second>end[i])
                    (*it).second=end[i];
            }
            
        }
        int high=-1;
        int count=0;
        for(auto it:mpp){
            if(it.first>high){
                count++;
                high=it.second;
            }
            else if(it.second< high){
                high=it.second;
            }
        }
        return count;
    }
};