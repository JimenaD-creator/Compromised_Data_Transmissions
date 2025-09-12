#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

<<<<<<< Updated upstream
int main(){
=======

void constructPrefix(const string& pattern, vector<int>& prefix){
    int m = pattern.length();
    int len = 0; // Length of the previous longest prefix suffix
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
    if(m == 0) return {0};
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

bool foundSubsequences(vector<int>& positions){
    if(positions.empty()){
        return false;
    }
    return true;
}

void longestCommonSubstring(const string& t1, const string& t2){
    
}

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

int main(){

>>>>>>> Stashed changes
    string files[] = {"transmission1.txt","transmission2.txt","mscode1.txt","mscode2.txt","mscode3.txt"};
    string stringfiles[5];
    ifstream file;
    stringstream buffer;
    string file_contents;

    int i;
    for (i = 0; i < 5;i++){
        file.open(files[i]);
        cout<<files[i]<<endl;
        buffer.str("");
        buffer.clear();
        buffer << file.rdbuf();

        file_contents = buffer.str();

        cout<<file_contents<<endl;

        stringfiles[i] = file_contents;

        file.close();

        stringfiles[i].erase(remove(stringfiles[i].begin(), stringfiles[i].end(), '\n'), stringfiles[i].end());


    }
<<<<<<< Updated upstream
=======
    vector<string> textNames = {"transmission1", "transmission2"};
    vector<string> patternNames = {"mcode1", "mcode2", "mcode3"};

    vector<vector<int>> transmission1Pos;
    vector<vector<int>> transmission2Pos;


    for (int ti = 0; ti < 2; ti++) {
        for (int pi = 0; pi < 3; pi++) {
            vector<int> pos = KMPSearch(stringfiles[2+pi], stringfiles[ti]);
            int len = stringfiles[2+pi].size(); 
            int n = 0;
           if(foundSubsequences(pos)) {
                cout << textNames[ti] << " contains " << patternNames[pi] << " true";
                for(int p : pos) {
                    if (ti == 0){
                        transmission1Pos.push_back({p,p+len});
                    } else {
                        transmission2Pos.push_back({p,p+len});
                    }
                } 
                cout << endl;
            } else {
                cout << textNames[ti] << " does not contain " << patternNames[pi] << " false" << endl;
            }
        }
    }

    Result LCSResultado = lcs(stringfiles[0], stringfiles[1]);
    cout << "Iterative DP Approach (for verification):" << endl;
    cout << "Length of longest common substring: " << LCSResultado.length << endl;
    cout << "In Transmission 1: positions " << LCSResultado.start1 << " to " << LCSResultado.end1 << endl;
    cout << "In Transmission 2: positions " << LCSResultado.start2 << " to " << LCSResultado.end2 << endl;
    /*string text1 = "A12B34C56D78E9F12345ABCCBA54321FEDCBAABC1234DEF5678ABBA8765FEDCBA123456";
    string text2 = "12345ABCCBA54321FEDCBA9876543210ABCDEFFEDCBA1234567890ABCDEFABBAFEDCBA";
    string pattern1 = "ABCCBA";
    string pattern2 = "123456";
    string pattern3 = "FEDCBA";


    vector<string> textNames = {"text1", "text2"};
    vector<string> texts = {text1, text2};
    vector<string> patternNames = {"pattern1", "pattern2", "pattern3"};
    vector<string> patterns = {pattern1, pattern2, pattern3};

    for (int ti = 0; ti < texts.size(); ++ti) {
        for (int pi = 0; pi < patterns.size(); ++pi) {
            bool found = KMPSearch(patterns[pi], texts[ti]);
            cout << textNames[ti] << " contains " << patternNames[pi] << ": " << (found ? "true": "false") << endl;
        }
    }
    */


>>>>>>> Stashed changes
}