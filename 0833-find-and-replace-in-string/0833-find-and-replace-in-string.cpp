class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        const string original = s;  

        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;

        sort(order.begin(), order.end(), [&](int a, int b) {
            return indices[a] > indices[b];
        });

        for (int i : order) {
            int idx = indices[i];
            string& src = sources[i];
            string& tgt = targets[i];

            if (original.substr(idx, src.size()) == src) {
                s.replace(idx, src.size(), tgt);
            }
        }

        return s;
    }
};