//
// Created by Mohamed Hashim on 10/19/2020.
//
#include"bits/stdc++.h"

using namespace std;

vector<string> splitToMatrix(string str) {
    vector<string> matrix;
    string word = "";
    for (int i = 0; i < str.size(); i++) {
        char x = str[i];
        if (x == ',') {
            matrix.push_back(word);
            word = "";
            i++;
        } else {
            word = word + x;
        }
    }
    matrix.push_back(word);
    return matrix;
}

vector<string> splitToWords(string str) {
    vector<string> words;
    string word = "";
    for (int i = 0; i < str.size(); i++) {
        char x = str[i];
        if (x == ',') {
            words.push_back(word);
            word = "";
        } else {
            word = word + x;
        }
    }
    words.push_back(word);
    return words;
}

string MatrixChallenge(string strArr[], int arrLength) {
    string word, diagonal_1 = "", diagonal_2 = "";
    vector<string> matrix = splitToMatrix(strArr[0]);
    vector<string> allMatrix = matrix;
    vector<string> words = splitToWords(strArr[1]);
    cout << "WORDS>>>" << endl;
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << endl;
    }
    for (int i = 0; i < matrix.size(); ++i) {
        word = "";
        for (int j = 0; j < matrix.size(); ++j) {
            word += matrix[j][i];
        }
        allMatrix.push_back(word);
    }
    diagonal_1 += matrix[0][0];
    diagonal_1 += matrix[1][1];
    diagonal_1 += matrix[2][2];
    diagonal_1 += matrix[3][3];

    diagonal_2 += matrix[0][3];
    diagonal_2 += matrix[1][2];
    diagonal_2 += matrix[2][1];
    diagonal_2 += matrix[3][0];

    allMatrix.push_back(diagonal_1);
    allMatrix.push_back(diagonal_2);

    string res = "";
    for (int i = 0; i < words.size(); ++i) {
        bool found = false;
        for (int j = 0; j < allMatrix.size(); ++j) {
            if (allMatrix[j].find(words[i])!= string::npos) {
                found = true;
                break;
            }
        }
        if (!found)
            res += words[i] + ",";
    }
    if (res == "")
        return "true";
    else
        return res;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    string arr[2] = {"aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,rumk,tall,true,trum,yes"};
    cout << MatrixChallenge(arr, 2) << endl;

    return 0;
}