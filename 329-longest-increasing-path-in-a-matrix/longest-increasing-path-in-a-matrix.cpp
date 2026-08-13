class Solution {

    int n , m;
    vector<vector<int>> mat;
    vector<pair<int ,  int>> dir = { { 0 , 1 } , { 1 , 0 } , { -1 , 0 } , { 0 , -1}};

    int help( int i ,int j , vector<vector<int>> & vis){

        if( vis[i][j] != -1) return vis[i][j];

        int maxi = 0 ;
        
        for( auto & [x , y ] : dir){
            int ix = i + x ;
            int jx = j + y;

            if( ix >= 0 && jx >= 0 && ix < n && jx < m ){
                if(mat[ix][jx] > mat[i][j]){
                   maxi = max( maxi , help(ix , jx , vis));
                }
            }
        }

        return vis[i][j] = 1 + maxi;
        
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        this -> n = matrix.size();

        this -> m = matrix[0].size();

        this -> mat = matrix;

        int maxi = 0 ;
        vector<vector<int>> vis( n , vector<int> ( m , -1));

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                maxi = max( maxi , help( i , j , vis));
            }
        }

        return maxi ;
    }
};