class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size();
        vector<int> ans = { 0 , 0 };

        int m = mat[0].size();

        for( int i = 0 ; i < n ; i++){

            int sum = 0 ;
            for( int j = 0 ; j < m ; j++){
                sum += mat[i][j] ;
            }

            if( sum >  ans[1] ){
                ans = { i , sum};
            }
        }

        return ans;
    }
};