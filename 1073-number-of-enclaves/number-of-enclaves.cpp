class Solution {
    vector<pair<int , int>> dir = {{1 , 0} , {0 , 1} , {-1 , 0} , { 0 , -1}}; 

    int n , m;
    
    void dfs(int i , int j , vector<vector<int>>& grid ){

        grid[i][j] = 0;

        for( auto [ x , y] : dir){
            int ix = i + x;
            int jx = j + y;

            if(ix >= 0 && jx >= 0 && ix < n && jx < m && grid[ix][jx] == 1){
                dfs(ix , jx , grid);
            }
        }



    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 1){
                dfs(i , 0 , grid);
            }
            if(grid[i][m-1] == 1){
                dfs(i , m-1 , grid );
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(grid[0][j] == 1) dfs(0 , j , grid);

            if(grid[n-1][j] == 1) dfs(n-1 , j , grid);
        }

        int count =0 ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(grid[i][j]) {
                    count ++;
                }
            }
        }

        return count;




    }
};