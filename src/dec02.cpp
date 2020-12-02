// Simple C++ program to display "Hello World"

// Header file for input output functions
#include<iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

const int SEARCH_FOR_N = 3;
const int SEARCH_FOR_SUM = 2020;

/*
class SumFinder {
    vector<int> *amounts;
    int n; // number of items to check for sum equals total
    int t; // total to check for
    // int
  public:
    void find ();
    int area() {return width*height;}
};

SumFinder::SumFinder (vector<int> a, int b) {
  amounts = a;
  height = b;
}
*/

/*
Find <n> items from set <amounts> having a sum of <t>
Returns the first answer found, or an empty set
*/
vector<int> findItemsWithSum (vector<int> *amounts, int n, int t)
{

}

int main()
{
    vector<int> amounts;

    ifstream inputFile("_inputs");

    int value;
    while ( inputFile >> value )
        amounts.push_back(value);
    
    inputFile.close();

    sort(amounts.begin(), amounts.end());

    vector<int> items = findItemsWithSum(&amounts, SEARCH_FOR_N, SEARCH_FOR_SUM);
    int product = 1;
    for (auto item : items) 
        product = product * item;

    std::string item_str(items.begin(), items.end());

    cout << SEARCH_FOR_SUM << " is the sum of " << item_str << " and their product is " << product << "\n";

    return 0;
}