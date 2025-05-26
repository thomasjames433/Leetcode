class Solution {
public:
    string triangleType(vector<int>& num) {
        sort(num.begin(),num.end());
        // for(auto it:num)
        //     cout<< it <<" ";
        
        if( *(num.end()-1) >= *(num.begin())+ *(num.begin()+1))
            return "none";
        
        if (num[0]==num[1] ){
            if(num[1]==num[2])
                return "equilateral";
            return "isosceles";
        }
        if (num[1]==num[2] ){
            if(num[1]==num[0])
                return "equilateral";
            return "isosceles";
        }
        return "scalene";
    }
};
