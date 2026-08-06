class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        map<int , int> mpp;

        int j = 0;
        int n = fruits.size();

        int ans = 0 ;
        for( int i = 0 ; i < n ; i ++){
            mpp[fruits[i]]++;
            while( j <= i && mpp.size() > 2 ){
                mpp[fruits[j]] -- ;
                if( mpp[fruits[j]] == 0 ){
                    mpp.erase(fruits[j]);
                }
                j ++;
            }

            ans = max( ans , i - j +1 );

        }

        return ans;
    }
};