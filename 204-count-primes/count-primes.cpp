class Solution {
    
    void help(vector<int> &arr ,  int n ){
        if(n >= 0)
        arr[0] = 0;
        if(n>=1)
        arr[1] = 0;


        for(int i = 2 ; i * i <= n ; i++ ){

            if(arr[i] == 1){
                for(int j = i* i ; j <= n ; j += i){
                    arr[j] = 0;
                }
            }
        }
    }
    
public:
    int countPrimes(int n) {
        vector<int> arr( n+1 , 1);

        help(arr , n);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]){
                count ++;
            }
        }

        return count;
    }
};