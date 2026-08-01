
class FenWick{

    public:

    vector<long long> bit;
    int n ;
    FenWick( int n ){
        this -> n = n ;
        bit.resize(n+1 , 0 );
    }

    void add( int idx , long long val ){
        idx ++;
        while(idx <= n  ){
            bit[idx] += val;
            idx += ( idx & ( -idx));
        }
    }

    long long sum( int idx){
        idx++;

        long long ans = 0 ;
        while( idx > 0   ){
            ans += bit[idx];
            idx -= ( idx & ( - idx));
        }
        return ans;
    }


    void addRange(int l , int r , long long val){
        add(l , val);
        if( r +1 < n ){
            add(r+1 , -val);
        }
    }

};

class Solution {    

        long long help( long long  mid ,vector<int>& monsters , FenWick & ft ){
            int n = monsters.size();

            long long st  = mid ;
            
            for( int i = 0 ; i < n ; i++){
                if(st  + ft.sum(i) >= monsters[i]){
                    st -= monsters[i];
                    st = st < 0 ? 0 : st ;
                }else{
                    return false;
                }
            }

            return true;
        }

    
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        // sort( boosts.begin() , boosts.end());

        // vector<vector<int>> com;

        int n = monsters.size();

        vector<long long > diff( n , 0 );

        FenWick ft( n );

        for(auto & ed : boosts){
            int a = ed[0];
            int b = ed[1];
            int c = ed[2];

            ft.addRange( a , b , c );
        }


        vector<long long > bonus( n , 0 );

        bonus[0] = diff[0];

        for( int i = 1 ; i < n ; i ++){
            bonus[i] = bonus[i-1] + diff[i];
        }

        // left to right 
        long long left = 0;
        long long right = accumulate(monsters.begin() , monsters.end() , 1LL * 0 ) ;

        long long ans  = right ;

        while( left <= right){
            long long mid = (left + ( right - left )/ 2);

            if( help( mid , monsters , ft)){
                ans = mid ;
                right  = mid -1 ;
            }else{
                left = mid +1;
            }
        }


            return ans ;
        
    }
};