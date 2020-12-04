#include<iostream>
#include <bits/stdc++.h>

using namespace std;


/**
Processor parses one theorem and provides computed results
 */
class Processor {
    regex rgxKVPair;
    regex rgxHeightCm;
    regex rgxHeightIn;
    regex rgxHairColor;
    regex rgxPassportId;
    vector<string> validEyeColors;
public:
    Processor();

    /**
     * Parse KV pairs from a theorem into a map
     * @param theorem to parse
     * @return  map of keys to values
     */
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

    /**
     Test if fields are present
     @param map  to test
     @return  true if fields are present
     */
    static bool hasFields(const map<string, string> &map) {
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
     Test if fields are present and valid
     @param map  to test
     @return  true if fields are present
     */
    bool hasValidFields(const map<string, string> &map) {
        // byr (Birth Year) - four digits; at least 1920 and at most 2002.
        int byr = stoi(map.at("byr"));
        if (!(byr >= 1920 && byr <= 2002))
            return false;

        // iyr (Issue Year) - four digits; at least 2010 and at most 2020.
        int iyr = stoi(map.at("iyr"));
        if (!(iyr >= 2010 && iyr <= 2020))
            return false;

        // eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
        int eyr = stoi(map.at("eyr"));
        if (!(eyr >= 2020 && eyr <= 2030))
            return false;

        // hgt (Height) - a number followed by either cm or in:
        // If cm, the number must be at least 150 and at most 193.
        // If in, the number must be at least 59 and at most 76.
        if (!isValidHeight(map.at("hgt")))
            return false;

        // hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
        if (!isValidHairColor(map.at("hcl")))
            return false;

        // ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
        if (find(validEyeColors.begin(), validEyeColors.end(), map.at("ecl")) == validEyeColors.end())
            return false;

        // pid (Passport ID) - a nine-digit number, including leading zeroes.
        if (!isValidPassportId(map.at("pid")))
            return false;

        // cid (Country ID) - ignored, missing or not.

        return true;
    }

    /**
     Test if passportId is valid
     pid (Passport ID) - a nine-digit number, including leading zeroes.

     @param passportId  to test
     @return  true if valid passportId
     */
    bool isValidPassportId(const string &passportId) {
        smatch match;
        regex_search(passportId, match, rgxPassportId);
        return !match.empty();
    }

    /**
     Test if hairColor is valid
     hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.

     @param hairColor  to test
     @return  true if valid hairColor
     */
    bool isValidHairColor(const string &hairColor) {
        smatch match;
        regex_search(hairColor, match, rgxHairColor);
        return !match.empty();
    }

    /**
     Test if height is valid
     hgt (Height) - a number followed by either cm or in:
     If cm, the number must be at least 150 and at most 193.
     If in, the number must be at least 59 and at most 76.

     @param height  to test
     @return  true if valid height
     */
    bool isValidHeight(const string &height) {
        smatch match;

        // If cm, the number must be at least 150 and at most 193.
        regex_search(height, match, rgxHeightCm);
        if (!match.empty()) {
            int h = stoi(match[1].str());
            return h >= 150 && h <= 193;
        }

        // If in, the number must be at least 59 and at most 76.
        regex_search(height, match, rgxHeightIn);
        if (!match.empty()) {
            int h = stoi(match[1].str());
            return h >= 59 && h <= 76;
        }

        return false;
    }

};

/**
Construct regexes
@param lines
 */
Processor::Processor() {
    rgxKVPair = regex(R"(\b([a-z]+):([^\s]+))");
    rgxHeightCm = regex(R"(([0-9]+)cm)");
    rgxHeightIn = regex(R"(([0-9]+)in)");
    rgxHairColor = regex(R"(#([a-f0-9]{6}))");
    rgxPassportId = regex(R"(^([0-9]{9})$)");
    validEyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
}

/**
Solve Part 1
 */
void solvePart1(Processor *processor, vector<string> *theorems) {
    cout << "Part 1: Are fields present?" << endl;
    int valid = 0, invalid = 0;
    map<string, string> keyValues;
    for (const auto &theorem : *theorems) {
        keyValues = processor->parseKeyValues(theorem);
        if (Processor::hasFields(keyValues))
            valid++;
        else
            invalid++;
    }
    cout << "Processor found " << valid << " theorems to be valid and " << invalid << " invalid." << endl << endl;
}

/**
Solve Part 2
 */
void solvePart2(Processor *processor, vector<string> *theorems) {
    cout << "Part 2: Are fields present and valid?" << endl;
    int valid = 0, invalid = 0;
    map<string, string> keyValues;
    for (const auto &theorem : *theorems) {
        keyValues = processor->parseKeyValues(theorem);
        if (Processor::hasFields(keyValues) && processor->hasValidFields(keyValues))
            valid++;
        else
            invalid++;
    }
    cout << "Processor found " << valid << " theorems to be valid and " << invalid << " invalid." << endl << endl;
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

    solvePart1(&processor, &theorems);
    solvePart2(&processor, &theorems);
    cout << endl;

    return 0;
}
