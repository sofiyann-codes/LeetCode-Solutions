/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

class Solution {
public:
    // Count matching characters at the same positions
    int matchCount(const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) cnt++;
        }
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> candidates(words.begin(), words.end());

        while (!candidates.empty()) {
            // Pick an arbitrary word from the set
            string guessWord = *candidates.begin();

            // Make a guess using Master's API
            int matched = master.guess(guessWord);

            // Filter words that have the same match count
            for (auto it = candidates.begin(); it != candidates.end();) {
                if (matchCount(*it, guessWord) != matched)
                    it = candidates.erase(it);
                else
                    ++it;
            }

            // Remove the used word
            candidates.erase(guessWord);
        }
    }
};