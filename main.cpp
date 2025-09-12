#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

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

        cout << "cantidad de palindromos "<<palin << " el mas largo fue de  " << largo <<" caracteres, con indeces del " << index <<" al " <<index2<< endl;
    return ;
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
void longestPalindrome(const string &s) {
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
    int start = (center_i - len) / 2;
    cout << "Palindrome length: " << len
         << " from index " << start
         << " to " << (start + len - 1)
         << endl;
}



int main()
{
    string files[] = {"transmission1.txt","transmission2.txt","mcode1.txt","mcode2.txt","mcode3.txt"};
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

        buffer << file.rdbuf();


        file_contents = buffer.str();

        cout<<file_contents<<endl;

        stringfiles[i] = file_contents;

        file.close();

        stringfiles[i].erase(remove(stringfiles[i].begin(), stringfiles[i].end(), '\n'), stringfiles[i].end());


    }

    for (i = 0; i < 5;i++){
        cout<<stringfiles[i]<<endl;
    }

    longestPalindrome(stringfiles[0]);
    longestPalindrome(stringfiles[1]);


    return 0;


}
