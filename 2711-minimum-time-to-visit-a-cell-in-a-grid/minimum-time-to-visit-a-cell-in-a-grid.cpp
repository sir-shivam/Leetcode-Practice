using pp = tuple<int , int, int>;
class Solution {

    vector<pair< int , int>> dir = { { 0 , 1 } , { 1 ,0 } , { -1 , 0 } , { 0 , -1 }};
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        // queue<tuple < int , int , int>> q;
        priority_queue<pp , vector<pp> , greater<pp>> pq;

        vector<vector<int>> vis( n , vector<int> ( m , 0  ));

        pq.push({ 0 , 0 , 0 });
        

        while( !pq.empty()){
            auto [ d , i , j ] = pq.top();

            pq.pop();

            if(i == n-1 && j == m-1){
                return d ;
            }

            if( vis[i][j]) continue;
            vis[i][j] = 1;

            

                for( auto & [ x , y ] : dir){
                    int ix = x + i ;
                    int jx = j + y ;

                    if( ix >= 0 && jx >= 0 && ix < n && jx < m ){
                        if( d +1 >= grid[ix][jx]){
                            pq.push({ d +1 , ix , jx });
                        }else{
                            int t = grid[ix][jx] - d ;
                            if(t % 2 == 0 ){
                                t = grid[ix][jx] +1;
                            }else{
                                t = grid[ix][jx] ;
                            }
                            pq.push({ t  , ix , jx});
                        }
                    }
                }

            }


            return -1;


    }
};