class Solution {
public:
    void combination(vector<int>&candidates, int target,vector<int>current,vector<vector<int>>&result,int idx){
        if(target < 0 ){
            return;
        }
        else if(target == 0){
            result.push_back(current);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            combination(candidates, target-candidates[i],current,result,i);
            current.pop_back();
           
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        combination(candidates, target,current,result,0);
        return result;
    }
};