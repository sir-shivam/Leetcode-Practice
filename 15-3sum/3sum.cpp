class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;

        int n = nums.size();

        for( int i = 0 ; i < n ; i++){
            
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i +1 ;
            int r = n-1;

            while( l < r){
                int sum = nums[i] + nums[l] + nums[r] ;
                  
                if( sum > 0 ){
                    r --;
                    while( l < r &&   nums[r+1] == nums[r]) r -- ;
                }else if( sum < 0 ){
                    l ++ ;
                    while( l < r &&  nums[l-1] == nums[l]) l ++;
                }else {
                    ans.push_back({nums[i] , nums[l], nums[r]});
                    r --;
                    while( l <= r &&   nums[r+1] == nums[r]) r -- ;
                    l ++ ;
                    while( l <= r &&  nums[l-1] == nums[l]) l ++;
                }
            }
        }
            return ans;
    }
};