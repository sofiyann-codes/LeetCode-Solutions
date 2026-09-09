class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> st1;    
        stack<int> st2;       
        string curr = "";
        int num = 0;
        for (char c : s) 
        {
            if (isdigit(c)) 
            {
                num = num*10 + (c -'0');  
            } 
            else if (c == '[') 
            {
                st2.push(num);
                st1.push(curr);
                num = 0;
                curr = "";
            } 
            else if (c == ']') 
            {
                string temp = curr;
                curr = st1.top();
                st1.pop();
                int repeat = st2.top();
                st2.pop();
                while (repeat--) curr += temp;
            } 
            else 
            {
                curr += c;  
            }
        }
        return curr;
    }
//please upvote...
};