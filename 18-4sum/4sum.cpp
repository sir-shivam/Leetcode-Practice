class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort( nums.begin() , nums.end());
        int n = nums.size();

        vector<vector<int>> ans ;

        for( int i = 0 ; i < n ; i ++){
            if( i > 0 && nums[i] == nums[i -1]) continue;
            for( int j = i + 1 ; j < n ; j ++){
                if( j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1 ;
                int r = n -1 ;

                while( j < n-1 &&  l < r ){
                    long long  sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];

                    if( sum > target ){
                        r -- ;
                    while( l <= r && nums[r] == nums[r+1]) r --;
                    }else if( sum < target ){
                        l ++;
                    while( l<= r && nums[l] == nums[l-1]) l ++;
                    }else{
                        ans.push_back( {nums[i], nums[j] , nums[l] , nums[r]});
                        r-- ;
                        l ++;
                    while( l <= r && nums[r] == nums[r+1]) r --;
                    while( l<= r && nums[l] == nums[l-1]) l ++;
                    }


                }
            }
        }

        return ans;
    }
};