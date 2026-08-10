class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        
        int N = nums.size();

        int n = N / 2;

        int n1 = n ;
        int n2 = n ;

        int mini = 1e9 ;


        long long tot = accumulate(nums.begin() , nums.end() , 0LL);

        map<int , vector<int>> leftSum;
        map<int , vector<int>> rightSum;

        for( int i = 0 ; i < ( 1 << n1 ) ; i++){
            int cnt = 0 ;
            long long sum = 0 ;
            for( int j = 0 ; j < n1 ; j ++ ){
                
                if( i & ( 1 << j )){
                    cnt ++;
                    sum += nums[j];
                }  

            }
                leftSum[cnt].push_back(sum);     
        }

        for( int i = 0 ; i < ( 1 << n2 ); i ++){
            int cnt = 0 ;
            long long sum = 0 ;

            for( int j = 0 ; j <n2 ; j++){
                if( i & ( 1 << j )){
                    cnt ++;
                    sum += nums[n1 + j];
                }

            }
                rightSum[cnt].push_back(sum);
        }

        for(int cnt = 0 ; cnt <= n1 ; cnt ++){
            sort(rightSum[cnt].begin() , rightSum[cnt].end());
        }

        for( int k  = 0 ; k <= n1 ; k ++){
            
            int m = n - k;

            for(int left : leftSum[k]){
                int best = ( tot - 2* left) / 2;

                int low = lower_bound(rightSum[m].begin() , rightSum[m].end() , best ) - rightSum[m].begin();

                if( low < rightSum[m].size()){
                    int right = rightSum[m][low];

                    mini = min( 1LL*mini , abs(2* (left + right ) - tot));
                }

                if(low -1 >= 0 ){
                    int right = rightSum[m][low - 1];

                    mini = min( 1LL*mini , abs(2* ( left + right) - tot));
                }

            }

        }

        return mini ;


    }
};