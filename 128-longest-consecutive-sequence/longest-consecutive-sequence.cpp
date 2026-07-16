class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int maxi = 0 ;

        unordered_set<int> spp( nums.begin() , nums.end());

        for( auto  x : spp){

            if(!spp.count(x - 1)){
                int cnt = 1 ;

                while(spp.count(x +1 )){
                    x = x +1 ;
                    cnt ++;
                }

                maxi = max( maxi , cnt );
            }
        }

        return maxi;
    }
};