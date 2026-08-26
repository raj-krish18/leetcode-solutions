class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n,0);
        // brute force approach
        // for(int i = 0; i < n; i++){
        //     long long sum = 0;
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] == nums[j] && i != j){
        //             sum = sum + abs(i - j);
        //         }
        //     }
        //     result.push_back(sum);
        // }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [val, indices] : mp) {
            // now work on this group
            long long leftSum = 0, leftCount = 0;
            long long rightsum = 0, rightcount = 0;
            for (int p = 0; p < indices.size(); p++) {
                int idx = indices[p];
                result[idx] += idx * leftCount - leftSum;
                leftSum += idx;
                leftCount++;
            }
            for (int p = indices.size()-1; p >=0; p--) {
                int idx = indices[p];
                result[idx] += rightsum - idx * rightcount;
                rightsum += idx;
                rightcount++;
            }

        }

        return result;
    }
};