// Simple C++ program to display "Hello World"

// Header file for input output functions
#include<iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> amounts;

    ifstream inputFile("_inputs");

    int value;
    while ( inputFile >> value )
        amounts.push_back(value);

    inputFile.close();

    sort(amounts.begin(), amounts.end());

    for (auto i : amounts)
        for (auto j : amounts)
            if(i+j==2020)
                cout << i << " + " << j << " = 2020 and " << i << " * " << j << " = " << i * j << "\n";

    return 0;
}
