class Solution {
public:
    
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string str = countAndSay(n-1);
        string ztr = "";
        // int freq = 1;
        // char ch = str[0];
        // char dh;
        // for(int i = 1; i < str.length(); i++){
        //     dh = str[i];
        //     if(ch == dh){
        //         freq++;
        //     }
        //     else{
        //         ztr = ztr + to_string(freq) + ch;
        //         freq = 1;
        //         ch = dh;
        //     }
        // }
        // ztr += to_string(freq) + ch; // bcoz loop doesn't add last freq and its char
        int cnt = 0;
        int i = 0;
        while(i < str.length()){
            char ch = str[i];
            while(i < str.length() && str[i] == ch){
                cnt++;
                i++;
            }
            ztr += to_string(cnt) + ch;
            cnt = 0;
        }
        return ztr;
    }
};