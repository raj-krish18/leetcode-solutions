class Solution {
public:
    bool isPrime (int n){
        if(n==1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i ==0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            bool check1 = isPrime(nums[i][i]);
            bool check2 = isPrime(nums[i][n-i-1]);
            if(check1== 1) maxi = max(maxi,nums[i][i]);
            if(check2== 1) maxi = max(maxi,nums[i][n-i-1]);
        }
        return maxi;
    }
};