//
// Created by Mohamed Hashim on 2/9/2021.
//
//This is a practice problem for yelp company
// you have vector<Meal> with name : String and ingredients : List<String>
// if two meals have the same ingredients regardless the sort of them so they should be counted

// <-- EXPAND to see the data classes
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Meal
{
    Meal(string n, vector<string> i) { name = n; ingredients = i; }
    string name; vector<string> ingredients;
};

vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    int prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int getUniqueMealCount(const vector<Meal> meals) {
    int count =0, res=0;
    for(int i=0; i < meals.size()-1; i++){
        vector<string> ing1 =meals[i].ingredients;
        sort(ing1.begin(),ing1.end());
        for(int j=i+1; j<meals.size(); j++){
            vector<string> ing2 =meals[j].ingredients;
            sort(ing2.begin(),ing2.end());
            for(int k=0; k<meals.at(j).ingredients.size();k++){
                if(ing2.at(k) == ing1.at(k))
                    count++;
            }
        }
    }
    res =count *2;
    return res;
}

int main() {
    string line;
    vector<Meal> meals;

    while (true) {
        getline(cin, line);
        if (cin.fail()) {
            cout << "A parsing error occurred";
        }

        vector<string> mealIngredients = split(line, " - ");
        vector<string> ingredients = split(mealIngredients[1], ",");
        string name = mealIngredients[0];
        meals.push_back(Meal(name, ingredients));

        if (cin.eof()) {
            break;
        }
    }

    cout << getUniqueMealCount(meals) << endl;
    return 0;
}

