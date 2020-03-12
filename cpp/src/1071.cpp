class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int sub = str1.size() - str2.size();

        if (sub == 0) {
            for (int i = 0; i < str1.size(); i++) {
                if (str1[i] != str2[i]) {
                    return "";
                }
            }
            return str1;
        }

        string gcd = "";

        int limit = 0;

        if (sub > 0) {
            gcd.append(str1, str1.size() - sub, sub);
            limit = str2.size();    
        } else {
            gcd.append(str2, str2.size() + sub, 0 - sub);
            limit = str1.size();
        }

        for (int i = 0; i < limit; i++) {
            int idx = i < gcd.size() ? i : i % gcd.size();
            if (gcd[idx] != str1[i] || gcd[idx] != str2[i]) return "";
        }

        if (str1.size() % gcd.size() || str2.size() % gcd.size()) {
            return gcdOfStrings(sub > 0 ? str2 : str1, gcd);
        }
        else {
            return gcd;
        } 
    }
};
