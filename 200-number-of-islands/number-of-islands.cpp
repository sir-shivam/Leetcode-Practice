class Solution {

    vector<pair< int , int>> dir = { { 0 , 1 } , { 1 , 0 } , { -1 , 0 } , { 0 , -1}};

    int n , m ;
    void help( int i , int j , vector<vector<char> >& grid , vector<vector<int>> & vis ){

        if(vis[i][j]) return ;
        vis[i][j] = 1;

        for(auto & [ x, y ] : dir ){
            int ix = i + x ;
            int jx = j + y ;

            if( ix >= 0 && jx >= 0 && ix < n && jx < m && grid[ix][jx] == '1' ){
                help( ix , jx , grid , vis);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        
        int cnt = 0 ;
        vector<vector<int>>  vis( n ,vector<int> (m , 0 ));

        for( int i =0 ; i < n ; i++){
        for( int j = 0 ; j < m ; j++){
            if( vis[i][j] == 0 && grid[i][j] == '1'){
                cnt ++;
                help( i , j , grid , vis);
            }
        }
        }

        return cnt ;
    }
};