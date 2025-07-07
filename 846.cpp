class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size()%gs)
            return 0;
        map<int,int>mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        for(int i=0;i<hand.size()/gs;i++){
            
            auto it=mpp.begin();
            int x=it->first;
            for(int j=0;j<gs;j++){
                if(it==mpp.end())
                    return 0;
                if(it->first!=x+j)
                    return 0;
                int y=it->second;
                if(y>1)
                    it->second--;
                else
                    mpp.erase(x+j);
                it++;
            }
        }
        return 1;
    }
};