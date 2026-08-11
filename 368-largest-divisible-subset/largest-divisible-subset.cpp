class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {

        sort(arr.begin() , arr.end());
        vector<int> nums = arr;
        int last = 0 ;
        int n = arr.size();
        int maxi = 0 ;
    
        
        vector<int> dp( n , 1 ) ; vector<int> hash( n );
        
        for( int i = 0 ; i < n ; i++){
            
            hash[i] = i ;
            
            for( int prev = 0 ; prev < i  ; prev ++){
                
                if(nums[i] %nums[prev] == 0   &&  dp[prev] +1  > dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev ;
                }    
            }
            
            if( dp[i] > maxi ){
                maxi = dp[i];
                
                last = i ;
            }
        }
        
        
        vector<int> ans ;
        
        while(true) {
            ans.push_back(arr[last]);

            if(hash[last] == last)
                break;

            last = hash[last];
        }
        
        
        reverse( ans.begin() , ans.end());
        
        return ans;
    }
};