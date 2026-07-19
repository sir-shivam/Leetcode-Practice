class Solution {

    vector<pair<int , int>> dir = { { 0 , 1 } , { 1 , 0 } , { -1 ,0 } , { 0 , - 1}};
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();


        int i = 0 ;
        int j = 0 ;

        while( i < n && j < m ){

            int found = 0 ;
            for( auto & [ a , b ] : dir){
                int ix = i + a;
                int jx = j + b ;

                if( ix >= 0 && jx >= 0 && ix < n && jx < m ){
                    if(mat[ix][jx] > mat[i][j]){
                        i = ix ;
                        j = jx ;
                        found = 1;
                        break;
                    }
                }

                
            }

            if( !found ){
                    return {i , j };
                }

        }
        
        return {};

    }
};