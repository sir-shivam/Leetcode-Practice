class Solution {

        

        long long help( long long  mid ,vector<int>& monsters , vector<long long > &  mpp ){
            int n = monsters.size();

            long long st  = mid ;
            
            for( int i = 0 ; i < n ; i++){
                if(st  + mpp[i] >= monsters[i]){
                    st -= monsters[i];
                    st = st < 0 ? 0 : st ;
                }else{
                    return false;
                }
            }

            return true;
        }

    
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        // sort( boosts.begin() , boosts.end());

        // vector<vector<int>> com;

        int n = monsters.size();

        vector<long long > diff( n , 0 );


        for(auto & ed : boosts){
            int a = ed[0];
            int b = ed[1];
            int c = ed[2];

            diff[a] +=  c;

            if( b +1 < n ){
                diff[b+1] -= c;
            }
        }


        vector<long long > bonus( n , 0 );

        bonus[0] = diff[0];

        for( int i = 1 ; i < n ; i ++){
            bonus[i] = bonus[i-1] + diff[i];
        }

        // left to right 
        long long left = 0;
        long long right = accumulate(monsters.begin() , monsters.end() , 1LL * 0 ) ;

        long long ans  = 1e9 ;

        while( left <= right){
            long long mid = (left + ( right - left )/ 2);

            if( help( mid , monsters , bonus)){
                ans = mid ;
                right  = mid -1 ;
            }else{
                left = mid +1;
            }
        }


            return ans ;
        
    }
};