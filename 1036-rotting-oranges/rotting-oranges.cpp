class Solution {

    vector<pair<int , int>> dir = {{ 0 , 1 } , { 1 , 0 } , {-1 , 0 } , {0 , -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int m = grid[0].size();

        int cnt = 0 ;

        queue<pair<int , int>> q;

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j });
                }else if( grid[i][j] == 1){
                    cnt ++;
                }
            }
        }

        if( cnt == 0 ) return 0 ;


        int time = 0 ;
        while(!q.empty()){


            int s = q.size();
            time ++;

            while( s --){
            auto [ i , j ] = q.front();
            q.pop();
            
            for( auto & [ x , y ] : dir){
                int ix = x + i ;
                int jx = j + y ;

                if( ix >= 0 && jx >= 0 && ix <n && jx < m ){
                    if(grid[ix][jx] == 1){
                        grid[ix][jx] = 2 ;
                        cnt --;
                        if( cnt == 0 ) return time;
                        q.push({ ix , jx});
                    }
                }
            }

            }
        }

        if( cnt != 0 ) return -1;

        return time;
    }
};