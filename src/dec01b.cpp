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

string display(vector<int> items)
{
}

/*
Find <n> items from set <amounts> having a sum of <t>
Returns the first answer found, or an empty set
*/
vector<int> findItemsWithSum (vector<int> *amounts, int num, int total)
{
  for (auto a : *amounts) {
    if (num > 2) {
      int remainder = total - a;
      vector<int> items = findItemsWithSum(amounts, num - 1, remainder);
      if (!items.empty()) {
        items.push_back(remainder);
        return items;
      }

    } else 
      for (auto b : *amounts)
        if (a + b == total) 
          return {a, b};
  }
}

string display(vector<int> *items)
{
  std::string str;
  str.append("[");
  bool first = true;
  for (auto item : *items)  
  if (first) {
    first = false;
    str.append(to_string(item));
  } else {
    str.append(",");
    str.append(to_string(item));
  }
  str.append("]");
  return str;
}

int main()
{
    vector<int> amounts;

    ifstream inputFile("_inputs");
    if (!inputFile.good()) {
        cout << "Failed to load file!\n";
        return 1;
    }

    int value;
    while ( inputFile >> value )
        amounts.push_back(value);
    
    inputFile.close();

    sort(amounts.begin(), amounts.end());

    vector<int> items = findItemsWithSum(&amounts, SEARCH_FOR_N, SEARCH_FOR_SUM);
    int product = 1;
    for (auto item : items) 
        product = product * item;

    cout << SEARCH_FOR_SUM << " is the sum of " << display(&items) << " and their product is " << product << "\n";

    return 0;
}