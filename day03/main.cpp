#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Bootstrap reads inputs from file
*/
int main() {
    vector<string> lines;

    ifstream inputFile("./input.txt");
    if (!inputFile.good()) {
        cout << "Failed to load file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
        lines.push_back(line);
    inputFile.close();

    return 0;
}
