class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxlen = 0;
        int zerocount = 0;
        for (int right = 0; right < n; right++) {
            // Step 1: expand — if nums[right] is 0, increment zeroCount
            if(nums[right] == 0) zerocount++;

            // Step 2: shrink — if zeroCount > k, move left
            while (zerocount > k) {
                if(nums[left] == 0) {
                    zerocount--;
                }
                left++;
            }

            // Step 3: update answer
            maxlen = max(maxlen,right-left+1);
        }

        return maxlen;
    }
};