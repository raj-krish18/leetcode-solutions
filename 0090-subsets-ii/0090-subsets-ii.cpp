class Solution {
public:
    void solve(vector<int>& nums,vector<int> &current,int start,vector<vector<int>> &result){
        result.push_back(current);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            solve(nums,current,i+1,result);
            current.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> current;
        vector<vector<int>> result;
        solve(nums,current,0,result);
        return result;
    }
};