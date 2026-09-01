class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = count(arr.begin(), arr.end(), 0);
        int i = n - 1;
        int j = n + zeros - 1;

        while(i >= 0){
            if(j < n) arr[j] = arr[i];
            if(arr[i] == 0){
                j--;
                if(j < n) arr[j] = 0;
            }
            i--;
            j--;
        }
    }
};