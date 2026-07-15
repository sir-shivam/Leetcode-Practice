class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return 1;
        int j = 1 ;

        while( j < n &&  nums[j] != nums[j-1]){
            j ++;
        }

        if( j == n ) return j ;

        for(int i = j+1 ; i < n ; i++){
            if( nums[i] != nums[i-1]){
                nums[j] = nums[i];
                j ++;
            }
        }

        return j ;
    }
};