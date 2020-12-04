#include<iostream>
#include <bits/stdc++.h>

using namespace std;


/**
Processor parses one theorem and provides computed results
 */
class Processor {
    regex rgxKVPair;
public:
    Processor();

    map<string, string> parseKeyValues(const string &theorem) {
        map<string, string> keyValues;
        auto t_begin = std::sregex_iterator(theorem.begin(), theorem.end(), rgxKVPair);
        auto t_end = std::sregex_iterator();
        for (std::sregex_iterator i = t_begin; i != t_end; ++i) {
            smatch match = *i;
            keyValues[match[1].str()] = match[2].str();
        }
        return keyValues;
    }

};

bool isValid(const map<string, string> &map) {
    if (0 == map.count("byr")) return false; // (Birth Year)
    if (0 == map.count("iyr")) return false; // (Issue Year)
    if (0 == map.count("eyr")) return false; // (Expiration Year)
    if (0 == map.count("hgt")) return false; // (Height)
    if (0 == map.count("hcl")) return false; // (Hair Color)
    if (0 == map.count("ecl")) return false; // (Eye Color)
    if (0 == map.count("pid")) return false; // (Passport ID)
// ignore  if (!map.contains("cid")) return false; // (Country ID)
    return true;
}

/**
Construct regexes
@param lines
 */
Processor::Processor() {
    rgxKVPair = regex(R"(\b([a-z]+):([^\s]+))");
}

/**
Solve: Seek a vector until we leave the bottom of the processor
 */
unsigned int solve(Processor *processor, vector<string> *theorems) {
    int valid = 0;
    map<string, string> keyValues;
    for (const auto &theorem : *theorems) {
        keyValues = processor->parseKeyValues(theorem);
        if (isValid(keyValues))
            valid++;
    }
    cout << "Processor found " << valid << " theorems to be valid." << endl << endl;
    return valid;
}

/**
 Is this an empty line
 @param line to test for emptiness
 @return  true if line is empty
 */
bool isEmpty(const string &line) {
    return line.empty();
}

/*
Bootstrap reads inputs from file
*/
int main() {
    vector<string> theorems;

    ifstream inputFile("input.txt");
    if (!inputFile.good()) {
        cout << "Failed to load file!" << endl;
        return 1;
    }

    string theorem;
    string line;
    while (getline(inputFile, line)) {
        if (isEmpty(line)) {
            theorems.push_back(theorem);
            theorem = "";
        } else theorem += " " + line;
    }
    inputFile.close();

    Processor processor;

    solve(&processor, &theorems);
    cout << endl;

    return 0;
}
