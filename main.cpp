#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// ----------------------------- PART 1: SEARCH SUBSEQUENCES ----------------------------------
void constructPrefix(const string& pattern, vector<int>& prefix){
    int m = pattern.length();
    int len = 0; 
    prefix[0] = 0;
    int i = 1;
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            prefix[i] = len;
            i++;

        }else{
            if(len!=0){
                len = prefix[len - 1];
            }else{
                prefix[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(const string& pat, const string& text){
    int n = text.length();
    int m = pat.length();
    if(m == 0 || n == 0) return {};
    vector<int>prefix(m);
    vector<int>positions;
    
    constructPrefix(pat, prefix);

    int i = 0, j = 0;
    while(i < n){
        if(text[i] == pat[j]){
            i++;
            j++;
        }

        if(j == m){
            positions.push_back(i-m+1);
            j = prefix[j-1]; 
            
        }
        else if(i < n && pat[j] != text[i]){
            if(j != 0){
                j = prefix[j-1];
            }else{
                i++;
            }

        }   

    }
    return positions;

}
bool findPatterns(const vector<int>& positions){
    if(positions.empty()){
        return false;
    }
    return true;
}

// ----------------------------- PART 2: FIND THE LONGEST PALINDROME ----------------------------------
void startendpos(string s) {

        int n = s.size();
        int palin = 0;
        int largo = 0;
        int index = -1;
        int index2 = -1;

        for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool ispalin = true;
            for (int l = i, r = j; l < r; l++, r--) {
                if (s[l] != s[r]) {
                    ispalin = false;
                    break;
                    }
                }
            if (ispalin) {
                palin++;
                int len = j - i + 1;
                if (len > largo) {
                    largo = len;
                    index = i;
                    index2 = j;
                }
                }
            }
        }
}



string preprocess(const string &s) {
    //CodeForGeeks https://www.geeksforgeeks.org/dsa/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/
    // sentinels: "@#a#b#b#a#$"
    string s2 = "@#";
    for (char c : s) {
        s2 += c;
        s2 += "#";
    }
    s2 += "$";
    return s2;
}
pair<int,int> longestPalindrome(const string &s) {
    if (s.empty()) return {0, 0};      // string vacío
    if (s.size() == 1) return {1, 1}; 
    string s2 = preprocess(s);
    int n = s2.size();
    vector<int> palindrome(n, 0);
    int center = 0, right = 0;
    int len = 0, center_i = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right)
            palindrome[i] = min(right - i, palindrome[mirror]);

        while (s2[i + (1 + palindrome[i])] == s2[i - (1 + palindrome[i])]) {
            palindrome[i]++;
        }

        if (i + palindrome[i] > right) {
            center = i;
            right = i + palindrome[i];
        }

        if (palindrome[i] > len) {
            len = palindrome[i];
            center_i = i;
        }
    }

    int start = (center_i - len) / 2 + 1;
    int end = start + len - 1;
    return {start, end};
}


// ----------------------------- PART 3: LONGEST COMMON SUBSTRINGS ----------------------------------
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
    if (s1.empty() || s2.empty()) return Result();
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    Result largest;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > largest.length) {
                    largest.length = dp[i][j];
                    largest.end1 = i - 1;
                    largest.start1 = i - largest.length;
                    largest.end2 = j - 1;
                    largest.start2 = j - largest.length;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    return largest;
}

int main(){
    string files[] = {"transmission1.txt","transmission2.txt","mcode1.txt","mcode2.txt","mcode3.txt"};
    string stringfiles[5];
    ifstream file;
    stringstream buffer;
    string file_contents;

    for (int i = 0; i < 5; i++) {
        file.open(files[i]);
        buffer.str("");
        buffer.clear();
        buffer << file.rdbuf();
        file_contents = buffer.str();
        file.close();

        file_contents.erase(remove(file_contents.begin(), file_contents.end(), '\n'), file_contents.end());
        stringfiles[i] = file_contents;
    }

    cout << " \n.......................... Search malicious code within transmission files (Part 1).............................."<<endl;
    vector<string> textNames = {"transmission1", "transmission2"};
    vector<string> patternNames = {"mcode1", "mcode2", "mcode3"};

    for (int ti = 0; ti < 2; ti++) {
        for (int pi = 0; pi < 3; pi++) {
            vector<int> pos = KMPSearch(stringfiles[2+pi], stringfiles[ti]);
           if(findPatterns(pos)){
                cout << patternNames[pi] << " in " << textNames[ti] << ":"<< " true" << ", at positions: ";
                for(int p : pos) cout << p << " ";
                cout << endl;
                }else{
                     cout << patternNames[pi] << " in " << textNames[ti] << ":"<< " false"<<endl;
                }
        }
    }

    cout << " \n.......................... Find the longest palindrome in transmission files (Part 2).............................."<<endl<<endl;
    for (int ti = 0; ti < 2; ti++) {
        pair<int,int> p = longestPalindrome(stringfiles[ti]);
        cout << "The longest palindrome in " <<textNames[ti] <<  " starts at position: " << p.first << ", and ends at position: " << p.second << endl;
    }

    cout << " \n...................... Longest Common Substrings between the transmission files (Part 3)........................"<<endl<<endl;
    Result largestCommonSubstring = lcs(stringfiles[0], stringfiles[1]);
    cout << "The longest common substring between the transmissions starts at position: " << largestCommonSubstring.start1+1 << ", and ends at position: " << largestCommonSubstring.end1+1 << endl << endl;
   

}