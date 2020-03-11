class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, avg = 0, found = 0, last_found = 0;

        for (int i : A) sum += i;

        if (sum % 3) return false;
        avg = sum / 3;

        int cur = avg;

        for (int i = 0; i < A.size(); i++) {
            cur -= A[i];
            if (cur == 0) {
                found++;
                if (found == 3) return true;
                cur = avg;
            }
        }

        return false;
    }
};
