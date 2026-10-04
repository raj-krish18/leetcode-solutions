class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxlen = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0) zeroCount++;
            while(zeroCount > 1){
                if(nums[left] == 0) zeroCount--;
                left++;
            }
            maxlen = max(maxlen, right - left );
        }
        return maxlen;
    }
};