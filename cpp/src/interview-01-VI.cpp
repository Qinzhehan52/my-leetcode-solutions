class Solution {
public:
    string compressString(string S) {
        string s_copy = "";
        char tmp_c = '0';
        int tmp = 1;

        for (char c : S)
        {
            if (tmp_c == c) {
                tmp++;
            } else if (tmp_c != '0') {
                s_copy += tmp_c;
                s_copy += to_string(tmp);
                tmp  = 1;
            }

            tmp_c = c;
        }
        s_copy += tmp_c;
        s_copy += to_string(tmp);

        return s_copy.length() >= S.length() ? S : s_copy;
    }
};
