class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<int> pos(n * 2); // Store the position of each person
        for (int i = 0; i < row.size(); ++i) {
            pos[row[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int partner = row[i] ^ 1; // Get the partner of the current person
            if (row[i + 1] != partner) {
                // Swap the partner with the next person
                swap(row[i + 1], row[pos[partner]]);
                swap(pos[row[i + 1]], pos[partner]);
                ++swaps;
            }
        }

        return swaps;
    }
};