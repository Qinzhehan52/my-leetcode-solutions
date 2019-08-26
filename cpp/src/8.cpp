#include<iostream>
#include <cassert>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long num = 0;
		int flag = -1;
		for (char c : str) {
			if (flag == -1) {
				if (c == ' ') continue;
				if (c == '-') {
					flag = 1; continue;
				}
				if (c == '+') {
					flag = 0; continue;
				}
				else flag = 0;
			}

			if (isNum(c)) {
				num = num * 10 + c - '0';
				if (num > INT_MAX) break;

			}
			else {
				break;
			}

		}
		if (flag) num *= -1;
		num = (num > INT_MAX) ? INT_MAX : num;
		num = (num < INT_MIN) ? INT_MIN : num;
		return num;
	}

	bool isNum(char c) {
		return c >= '0' && c <= '9';
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}