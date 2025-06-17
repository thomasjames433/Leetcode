class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int n=arr.size();
        int i=1;int j=0;
        int count=1;
        int occ=1;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                i++;
                occ++;
                if(occ>count)
                    count++;
            }
            else{
                j++;
                occ--;
            }
        }
        return count;
    }
};