class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        
        map<int , int> mpp;
        
        for(auto num : nums){

            string s = to_string(num);

            sort(s.begin() , s.end() , greater<>());


            mpp[s[0] - s.back()] += num;

        
        }

        auto it = mpp.rbegin();

        return it -> second;
    }
};