class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix(n+1);
        vector<int> sufix(n+1);
        prefix[0] = 0;
        int Ncount = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'N') Ncount++;
            prefix[i+1] = Ncount;
        }
        sufix[n] = 0;
        int Pcounter = 0;
        for(int i = n-1; i >= 0; i--){
            if(customers[i] == 'Y') Pcounter++;
            sufix[i] = Pcounter;   
        }
        vector<int> pen(n+1);
        for(int i = 0; i <= n ; i++){
            pen[i] = prefix[i] + sufix[i];
        }
        int mini = pen[0];
        int minPen = 0;
        for(int i = 0; i <=n; i++){
            if(pen[i] < mini){
                mini = pen[i];
                minPen = i;
            }
        }
        return minPen;
    }
};