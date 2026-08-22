class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int always = 0; // always satisfied sum
        int n = customers.size();
        for(int i = 0; i < n; i++){
            always += customers[i] *(1-grumpy[i]);
        }
        int sum = 0;
        
        for(int i = 0; i < minutes; i++){
            sum += customers[i]*grumpy[i];
        }
        int maxsaved = sum;
        int right = minutes;
        int left = 0;
        while(right < n){
           
            // if(grumpy[right] == 1)
            sum += customers[right]* grumpy[right] - customers[left]* grumpy[left] ;
            left++;
            right++;
             maxsaved = max(sum,maxsaved);
        }
        return always + maxsaved;
    }
};