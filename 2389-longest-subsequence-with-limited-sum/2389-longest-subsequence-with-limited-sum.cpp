class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        // sort(queries.begin(),queries.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> sum(n+1);
        vector<int> answer(m);

        sum[0] = 0;
        for(int i = 0; i < n; i++){
            sum[i+1] = nums[i] + sum[i];
        }
        for(int i = 0; i < m; i++){
            auto it = upper_bound(sum.begin(),sum.end(),queries[i]);
            int idx = it - sum.begin();
            answer[i] = idx-1;
        }
        return answer;
    }
};