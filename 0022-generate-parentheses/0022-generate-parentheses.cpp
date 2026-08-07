class Solution {
public:
    void generate(string current, int ob,int cb,int n, vector<string>&result){
        if(cb == n){
            result.push_back(current);
            return;
        }
        if(ob<n){
            generate(current+'(',ob+1,cb,n,result);
        }
        
        if(cb<ob){
            generate(current+')',ob,cb+1,n,result);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",0,0,n,result);
        return result;
    }
};