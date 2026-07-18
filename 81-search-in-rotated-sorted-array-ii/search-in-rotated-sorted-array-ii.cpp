class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0 ;
        int r = n-1 ;

        while( l < n && nums[l] == nums[r] && l != r){
            l ++;
        }

        while( l <= r ){
            int mid = l + ( r - l ) / 2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[l] <= nums[mid]){
                // sorted 
                if( target>= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid +1 ;
                }
            }else{
                // this one is sorted 

                if( nums[mid] <= target && nums[r] >= target){
                    l = mid +1 ;
                }else{
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};