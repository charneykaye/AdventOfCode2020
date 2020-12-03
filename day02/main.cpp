#include<iostream>
#include <bits/stdc++.h>

using namespace std;

regex rgxPassword("\\s([a-z]+)$");
regex rgxLetter("([a-z]):");
regex rgxMin("(\\d+)\\-");
regex rgxMax("\\-(\\d+)");

/*
Get password from <theorem>
*/
string getPassword(string theorem) {
    smatch match;
    regex_search(theorem, match, rgxPassword);
    return match[1].str();
}

/*
Get required letter from <theorem>
*/
char getLetter(string theorem) {
    smatch match;
    regex_search(theorem, match, rgxLetter);
    return match[1].str()[0];
}

/*
Get minimum occurrences of required letter from <theorem>
*/
int getNumOne(string theorem) {
    smatch match;
    regex_search(theorem, match, rgxMin);
    return stoi(match[1].str());
}

/*
Get maximum occurrences of required letter from <theorem>
*/
int getNumTwo(string theorem) {
    smatch match;
    regex_search(theorem, match, rgxMax);
    return stoi(match[1].str());
}

/*
Get number of occurrences of a given <letter> in <password>
*/
int getOccurrences(string password, char letter) {
    int r = 0;
    for (int i = 0; i < password.size(); i++)
        if (password[i] == letter)
            r++;
    return r;
}

/*
Part 1 using <theorems>
*/
void part1(vector<string> *theorems) {
    cout << endl << "Part 1" << endl;
    int totalValid = 0;
    for (auto theorem : *theorems) {
        string password = getPassword(theorem);
        char letter = getLetter(theorem);
        int min = getNumOne(theorem);
        int max = getNumTwo(theorem);
        int occurrences = getOccurrences(password, letter);
        if (min <= occurrences && occurrences <= max)
            totalValid++;

    }
    cout << "Found " << totalValid << " theorems to be valid." << endl;
}

/*
Part 2 using <theorems>
*/
void part2(vector<string> *theorems) {
    cout << endl << "Part 2" << endl;
    int totalValid = 0;
    for (auto theorem : *theorems) {
        string password = getPassword(theorem);
        char letter = getLetter(theorem);
        int posA = getNumOne(theorem);
        int posB = getNumTwo(theorem);
        if ((password[posA - 1] == letter && password[posB - 1] != letter) ||
            (password[posA - 1] != letter && password[posB - 1] == letter))
            totalValid++;
    }
    cout << "Found " << totalValid << " theorems to be valid" << endl;
}

/*
Bootstrap reads inputs from file
*/
int main() {
    vector<string> theorems;

    vector<int> amounts;
    string line;
    while (std::getline(std::cin, line))
        theorems.push_back(line);

    part1(&theorems);
    part2(&theorems);
    cout << endl;

    return 0;
}
