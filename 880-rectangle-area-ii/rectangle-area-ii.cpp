class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7 ;
        set<int> x , y ;

        for( auto & rect : rectangles){
            x.insert(rect[0]);
            y.insert(rect[1]);
            x.insert(rect[2]);
            y.insert(rect[3]);
        }

        map<int , int> cord_x , cord_y ;

        int i = 0 ;

        for(auto & a:  x ){
            cord_x[a] = i++;
        }

        i = 0 ;

        for(auto & a : y ){
            cord_y[a] = i ++;
        }

        vector<int> vect_x(x.begin() , x.end()) , vect_y(y.begin() , y.end());

        vector<vector<int>> vis(x.size()  ,(vector<int> ( y.size() , 0 )));

        long long ans = 0 ;
        for( auto & rect : rectangles){
            for(int i = cord_x[rect[0]] ; i < cord_x[rect[2]] ; i++ ){
                for( int j = cord_y[rect[1]] ; j < cord_y[rect[3]] ; j ++){
                    if( vis[i][j]) continue;
                    long long  w = (vect_x[i+1] - vect_x[i] );
                    long long h = ( vect_y[j+1] - vect_y[j] );
                    ans = (ans + w * h) % MOD;
                    vis[i][j] = 1;
                }
            }
        }

        return ans;

    }
};