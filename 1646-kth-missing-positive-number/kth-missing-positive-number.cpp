class Solution {

    bool check(int num , vector<int> & arr ){
        int l = 0 ;
        int r = arr.size() - 1;

        while( l <= r){
            int mid = l + ( r - l ) / 2;

            if( arr[mid] < num ){
                l = mid +1 ;
            }else if( arr[mid] > num){
                r = mid -1 ;
            }else{
                return true;
            }
        }

        return false;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        

        int num = 1 ;

        int cnt = 0 ;
        while( true){
            if( !check(num , arr )){
                cnt ++;
                if( cnt == k ){
                    return num ;
                }
            }
                num ++;
        }

        return -1;
    }
};