class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        
        map<int , int> mpp;
        int n = nums.size();

        int maxi = -1 ;
        for(auto & a : nums){

            mpp[a] ++;
            maxi = max( maxi , a);
        }

        // 
        vector<long long > arr( maxi +1 , 0 );

        for( int i = maxi ; i >= 1 ; i--){

            long long  num = i ;

            int cnt = 0 ;

            int j = 1;

            long long  rem = 0 ;

            while(num *j  <= maxi ){
                
                rem += arr[num * j ];
                cnt += mpp[num * ( j ++)] ;


            }


            long long  tot = ( 1LL * cnt * ( cnt -1)) / 2;

            arr[i] = tot - rem;
        }

        vector<long long > preff( maxi +1 );

        for( long long i = 1 ; i <= maxi ; i ++){

            preff[i] = preff[i-1] + arr[i];

        }

    

        vector<int> ans;

        for( auto & x : queries){
            int it = upper_bound(preff.begin() , preff.end() , x) - preff.begin();

            ans.push_back(it );
        }

        return ans;
    }
};