class Solution {


    vector<pair< int , int>> dir = { { 0 , 1 } , { 1 , 0 } , { -1 , 0 } , { 0 , -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<tuple<int , int , int>> q;
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis( n , vector<int> ( m , 1e9 ));

        // int n = mat.size();
        // int m = mat[0].size();

        for( int i = 0 ; i < n ; i++){
            for( int j= 0 ; j < m ; j++){
                if(mat[i][j] == 0 ){
                    q.push({ i , j , 0 });
                    dis[i][j] = 0 ;
                }
            }
        }


        while( !q.empty()){
            auto [ i , j , d ] = q.front();
            q.pop();

            for(auto & [ x , y ] : dir){
                int ix = x + i ;
                int jx = j + y ;

                if( ix >= 0 && jx >= 0 && ix < n && jx < m ){
                    if(mat[ix][jx] == 1){
                        if( d +1 <   dis[ix][jx] ){
                            dis[ix][jx] = d +1;
                            q.push({ ix , jx , d+1});
                        }
                    }
                }
            }
        }

        return dis;
    }
};