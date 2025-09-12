#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


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
bool findPatterns(const vector<int>& positions){
    if(positions.empty()){
        return false;
    }
    return true;
}
int main(){

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

        file_contents = buffer.str();

        stringfiles[i] = file_contents;

        file.close();

        stringfiles[i].erase(remove(stringfiles[i].begin(), stringfiles[i].end(), '\n'), stringfiles[i].end());


    cout << " \n.......................... Search Malicious Code (Part 1).............................."<<endl;
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
}
}