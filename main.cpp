#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Result {
    int length;
    int start1;
    int end1;
    int start2;
    int end2;
    
    Result() : length(0), start1(-1), end1(-1), start2(-1), end2(-1) {}
    Result(int len, int s1, int e1, int s2, int e2) 
        : length(len), start1(s1), end1(e1), start2(s2), end2(e2) {}
};

Result lcs(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    Result best;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > best.length) {
                    best.length = dp[i][j];
                    best.end1 = i - 1;
                    best.start1 = i - best.length;
                    best.end2 = j - 1;
                    best.start2 = j - best.length;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    return best;
}

int main() {
    string s1 = "A12B34C56D78E9F12345ABCCBA54321FEDCBAABC1234DEF5678ABBA8765FEDCBA123456";
    string s2 = "12345ABCCBA54321FEDCBA9876543210ABCDEFFEDCBA1234567890ABCDEFABBAFEDCBA";
    
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << endl;

    Result largestCommonSubstring = lcs(s1, s2);
    cout << "Length of longest common substring: " << largestCommonSubstring.length << endl;
    cout << "In String 1: positions " << largestCommonSubstring.start1 << " to " << largestCommonSubstring.end1 
         << " (substring: '" << s1.substr(largestCommonSubstring.start1, largestCommonSubstring.length) << "')" << endl;
    cout << "In String 2: positions " << largestCommonSubstring.start2 << " to " << largestCommonSubstring.end2 
         << " (substring: '" << s2.substr(largestCommonSubstring.start2, largestCommonSubstring.length) << "')" << endl;
}