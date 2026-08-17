class Solution {
public:
    
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string str = countAndSay(n-1);
        int freq = 1;
        string ztr = "";
        char ch = str[0];
        char dh;
        for(int i = 1; i < str.length(); i++){
            dh = str[i];
            if(ch == dh){
                freq++;
            }
            else{
                ztr = ztr + to_string(freq) + ch;
                freq = 1;
                ch = dh;
            }
        }
        ztr += to_string(freq) + ch;
        return ztr;
    }
};