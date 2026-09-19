class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sort(nums.begin(), nums.end(),greater<int>());
        int n = nums.size();
        // vector<int> sum(n);
        // sum[0] = nums[0];
        // for(int i = 1; i < n; i++){
        //     sum[i] = sum[i-1] + nums[i];
        // }
        int i = 0; 
        int j = 0;
        int sum = 0;
        int len = 0;
        while(i < n){
            if(sum < target){
                sum += nums[i];
            }
            else break;
            i++;
        }
        if(i == n && sum < target ) return 0;
        len = i;
        if(len == n){
            while(sum >=target){
                sum-=nums[j];
                j++;
                len = min(len,i-j+1);
            }
        }
        while( i < n){
            sum+= nums[i];
            i++;
            while(sum >=target){
                sum-=nums[j];
                j++;
                len = min(len,i-j+1);
            }
        }
        return len;
    }
};