#include<iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

regex rgxPassword ("\\s([a-z]+)$");
regex rgxLetter ("([a-z]):");
regex rgxMin ("(\\d+)\\-");
regex rgxMax ("\\-(\\d+)");

/*
Get password from <theorem>
*/
string getPassword(string theorem)
{
    smatch match;
    regex_search(theorem, match, rgxPassword);
    return match[1].str();
}

/*
Get required letter from <theorem>
*/
char getLetter(string theorem)
{
    smatch match;
    regex_search(theorem, match, rgxLetter);
    return match[1].str()[0];
}

/*
Get minimum occurrences of required letter from <theorem>
*/
int getMin(string theorem)
{
    smatch match;
    regex_search(theorem, match, rgxMin);
    return stoi(match[1].str());
}

/*
Get maximum occurrences of required letter from <theorem>
*/
int getMax(string theorem)
{
    smatch match;
    regex_search(theorem, match, rgxMax);
    return stoi(match[1].str());
}

/*
Get number of occurences of a given <letter> in <password>
*/
int getOccurences(string password, char letter)
{
    int r = 0;
    for (int i=0; i< password.size(); i++)
        if (password[i]==letter) 
            r++;
    return r;
}

/*
Is <theorem> valid?
*/
bool isValid(string theorem)
{
    string password = getPassword(theorem);
    char letter = getLetter(theorem);
    int min = getMin(theorem);
    int max = getMax(theorem);
    int occurences = getOccurences(password, letter);
    return min <= occurences && occurences <= max;
}

/*
Version 1 using <theorems>
*/
void v1(vector<string> *theorems)
{
    cout << endl << "Version 1" << endl;
    int totalValid = 0;
    for (auto theorem : *theorems)
        if (isValid(theorem))
            totalValid++;
    cout << "Found " << totalValid << " theorems to be valid.";
}

/*
Bootstrap reads inputs from file
*/
int main()
{
    vector<string> theorems;

    ifstream inputFile("./day02-input.txt");
    if (!inputFile.good()) {
        cout << "Failed to load file!" << endl;
        return 1;
    }

    string theorem;
    while (getline(inputFile,theorem))
        theorems.push_back(theorem);
    inputFile.close();

    v1(&theorems);
    cout << endl;

    return 0;
}
