class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> position;
        vector<int> ans;

        for(int i=0; i<s.size(); i++){
            if(s[i] == c){
                position.push_back(i);
            }
        }

        for(int i=0; i<s.size(); i++){
            int dist = INT_MAX;

            for(int j=0; j<position.size(); j++){
                dist = min(dist, abs(i-position[j]));
            }
            ans.push_back(dist);
        }

        return ans;
    }
};