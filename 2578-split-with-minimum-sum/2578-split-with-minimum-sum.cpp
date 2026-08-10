class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());

        string s1="",s2="";
        for(int i = 0; i < s.size(); i++){
            if(i % 2){
                s1 += s[i];
            }else{
                s2 += s[i];
            }
        }
        int x = stoi(s1);
        int y = stoi(s2);

        return x + y;
    }
};