class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        
        vector<int> ans;

        int n = nums.size();

        for( int i = 0 ; i < n ; i++){
            
            int dis = 0 ;
            int curr1 =nums[i];

            while (!ans.empty() && ans.back() > 0 && curr1 < 0){
                int curr2 = abs(curr1);
                int curr = abs(ans.back());
                if(curr < curr2 ){
                    ans.pop_back();
                    continue;
                }else if(curr ==  curr2){
                    ans.pop_back();
                    dis = 1;
                    break;
                }else{
                    dis = 1;
                    break;
                }
            }

            if(!dis){
            ans.push_back(curr1);
            }
        }

        return ans;
    }
};