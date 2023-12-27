#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    string s;
    int size;

    string expand_from_center(int left, int right) {
        while (left >= 0 && right < size && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        string maxStr = s.substr(0, 1);
        this->s = s;
        size = s.size();
        for (int i = 0; i < size; i++) {
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i + 1);
            if (odd.size() > maxStr.size())
                maxStr = odd;
            if (even.size() > maxStr.size())
                maxStr = even;
        }

        return maxStr;
    }
};

int main() {
    Solution s;
    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << res << endl;
    return 0;
}