#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void startendpos(string s) {

    for (int f = 0; f < 3; f++) {


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
    }

    return ;
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

    startendpos(stringfiles[0]);
    startendpos(stringfiles[1]);


    return 0;


}

