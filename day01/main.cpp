#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Version 1 using <amounts>
*/
void v1(vector<int> *amounts)
{
    cout << endl << "Version 1" << endl;

    // product of the 2 items having sum of 2020
    for (auto i : *amounts)
        for (auto j : *amounts)
            if(i+j==2020)
                cout << i << " + " << j << " = 2020 and " << i << " * " << j << " = " << i * j << endl;

    // product of the 3 items having sum of 2020
    for (auto i : *amounts)
        for (auto j : *amounts)
            for (auto k : *amounts)
                if(i+j+k==2020)
                    cout << i << " + " << j << " + " << k << " = 2020 and " << i << " * " << j << " * " << k << " = " << i * j * k << endl;
}

/*
Find <num> items having a sum of <total> from set <amounts>
Returns the first answer found, or an empty set
*/
vector<int> findItemsWithSum (vector<int> *amounts, int num, int total)
{
    for (auto a : *amounts)
        if (num > 2) {
            int remainder = total - a;
            vector<int> items = findItemsWithSum(amounts, num - 1, remainder);
            if (!items.empty()) {
                items.push_back(total - remainder);
                return items;
            }
        } else
            for (auto b : *amounts)
                if (a + b == total) {            
                    return {a, b};
                }

    return {};
}

/*
Join a set of <items> with <separator>
*/
string join(vector<int> *items, string separator)
{
    std::string str;
    bool first = true;
    for (auto item : *items)  
    if (first) {
        first = false;
        str.append(to_string(item));
    } else {
        str.append(separator);
        str.append(to_string(item));
    }
    return str;
}

/*
Product of a set of <items>
*/
int product(vector<int> *items)
{
    int product = 1;
    for (auto item : *items) 
        product = product * item;
    return product;
}

/*
Version 2 subroutine solves <amounts> for <num> members with sum <total>
*/
void v2(vector<int> *amounts, int num, int total)
{
    cout << endl << "Version 2: Solve for " << num << " items having sum of " << total << endl;
    vector<int> items = findItemsWithSum(amounts, num, total);
    cout << join(&items, " + ") << " = " << total << " and " << join(&items, " * ") << " = " << product(&items) << endl;
}

/*
Bootstrap reads inputs from file
*/
int main()
{
    vector<int> amounts;

    ifstream inputFile("input.txt");
    if (!inputFile.good()) {
        cout << "Failed to load file!\n";
        cout << "Failed to load file!" << endl;
        return 1;
    }

    int value;
    while ( inputFile >> value )
        amounts.push_back(value);
    inputFile.close();

    v1(&amounts);
    v2(&amounts, 2, 2020);
    v2(&amounts, 3, 2020);
    cout << endl;

    return 0;
}
