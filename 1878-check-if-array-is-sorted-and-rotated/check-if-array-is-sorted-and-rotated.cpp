class Solution {
public:
    bool check(vector<int>& arr) {
        
        int cnt = 0 ;

        int n = arr.size();
        if( arr[0] < arr[n-1]) cnt ++;

        for( int i = 1 ; i < n ; i++){
            if( arr[i] < arr[i-1]){
                cnt ++;
            }
        }

        return cnt <= 1 ;
    }
};