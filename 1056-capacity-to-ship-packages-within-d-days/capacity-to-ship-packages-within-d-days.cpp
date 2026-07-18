class Solution {

    int check( int mid , vector<int> weights){
        
        int cnt = 0 ;
        int sum = 0 ;
        for(  auto & a : weights){
            if( sum + a <= mid){
            sum += a ;
            }else {
                cnt ++;
                sum = a;
            }
        }

        return cnt ;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = *max_element(weights.begin() , weights.end());
        int r = accumulate(weights.begin() , weights.end() , 0);
        int ans = -1;
        while( l <= r){
            int mid = l + ( r - l ) / 2 ;

            if( check( mid , weights) < days){
                ans = mid ;
                r = mid -1 ;
            }else{

                l = mid +1 ;
            }
            
        } 

        return ans;
    }
};