class Solution {

    vector<pair<int , int>> dir = { { 0 , 1 } , { -1 , 0 } , { 0 , -1 } , {1 , 0 }};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        using pp = tuple<int , int , int> ;

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis( n , vector<int> ( m , 0 ));

        priority_queue<pp , vector<pp> , greater<pp>> pq;

        pq.push({0 , entrance[0] , entrance[1]});

        vis[ entrance[0]][ entrance[1]] = 1;

        while( !pq.empty()){
            auto [ d , i , j ] = pq.top();

            pq.pop();

            for( auto & [ x , y ] : dir){
                int ix = x + i ;
                int jx = y + j ;

                

                if(ix >= 0 && jx >= 0 && ix < n && jx < m && maze[ix][jx] == '.' && vis[ix][jx] == 0 ){
                    if (ix  == 0 || ix  == n - 1 || jx == 0 || jx == m - 1)
                    return d + 1;
                    vis[ix][jx] = 1;
                    pq.push({ d+1 , ix , jx });
                }
            }
        }

        return -1;
    }
};