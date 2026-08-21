class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> coeff(n);
        int sum = 0, total = 0;
        for (int j = 0; j < n; j++) {
            sum += satisfaction[n-j-1];
            if(sum < 0 ) return total;
            total += sum;
        }
        if (satisfaction[n - 1] < 0)
                return 0;
        return total;
    }
};