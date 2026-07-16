class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);
        int p = 0 ; int m = 1;

        for(int i = 0 ; i < n ; i++){
            if( nums[i] < 0 ){
                arr[m] = nums[i];
                m+= 2 ;
            }else{
                arr[p] = nums[i];
                p += 2;
            }
        }

        return arr;
    }
};