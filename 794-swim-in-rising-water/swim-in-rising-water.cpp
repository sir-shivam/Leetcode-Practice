using pp = tuple< int , int , int>;

class Solution {

    vector<pair<int , int>> dir = { { 0 ,1 } , { 1 , 0 } , { -1 , 0 } , { 0 , -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<pair<int , int > >> dis( n , vector<pair<int , int>> (m , {0  , 1e9}));


        int i = 0 ;
        int j = 0 ;

        priority_queue<pp , vector<pp> , greater<pp>> pq;

        pq.push({grid[0][0], 0, 0});

        while( !pq.empty() ){
            auto [d , i , j ] = pq.top();

            pq.pop();


            if( d < dis[i][j].second){
                dis[i][j].second = d ;

                for(auto & [x , y ] : dir ){
                int ix = i + x;
                int jx = j + y;

                if( ix >= 0 && jx >= 0 && ix < n && jx < m ){
                    pq.push({ max(grid[ix][jx] , dis[i][j].second) , ix , jx});
                    
                    }
                }

            }

        }
        return dis[n-1][m-1].second ;

    }
};