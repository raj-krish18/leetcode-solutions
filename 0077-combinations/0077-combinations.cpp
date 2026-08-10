class Solution {
public:
    void combination(vector<int> &current,vector<vector<int>> &result,int n, int k,int idx){
        if(current.size() == k){
            result.push_back(current);
            return ;
        }
        for(int i = idx; i <= n; i++){
            
            current.push_back(i);
            combination(current,result,n,k,i+1);
            current.pop_back();
           
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        combination(current,result,n,k,1);
        return result;
    }
};