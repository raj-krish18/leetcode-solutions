class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> coeff(n);
        for (int j = 0; j < n; j++) {
            
            int coef = 0;
            int time = 1;
            for (int i = n-j-1; i < n; i++) {
                coef += satisfaction[i] * time;
                time++;
            }
            coeff[j] = coef;
            if ( j!= 0 && coeff[j - 1] > coeff[j] )
                if (coeff[j - 1] > 0)
                return coeff[j-1];
                else return 0;
        }
        if (coeff[n - 1] > 0)
                return coeff[n-1];
        else return 0;
    }
};