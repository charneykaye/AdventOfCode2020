#include<iostream>
#include <bits/stdc++.h>

using namespace std;

/**
Board repeats tiling horizontally and vertically,
so if a get() for X is sought past width, it will get X % width
and similarly for Y % height
 */
class Board {
    int width, height;
    vector<vector<char>> board;
public:
    Board(vector<string> *lines);

    int getWidth() { return width; }

    int getHeight() { return height; }

    char get(int x, int y) {
        return board.at(y % height).at(x % width);
    }
};

/**
build 2d array of characters
@param lines
 */
Board::Board(vector<string> *lines) {
    width = lines->at(0).size();
    height = lines->size();
    for (int y = 0; y < height; y++) {
        vector<char> line;
        for (int x = 0; x < width; x++) {
            line.push_back(lines->at(y).at(x));
        }
        board.push_back(line);
    }
}

/**
Solve: Seek a vector until we leave the bottom of the board
 */
void solve(Board *board, int vX, int vY) {
    cout << endl << "Solve vector x+" << vX << ", y+" << vY << endl;
    int pX = 0, pY = 0, trees = 0;
    while (pY < board->getHeight()) {
        if (board->get(pX, pY) == '#')
            trees++;
        pX += vX;
        pY += vY;
    }
    cout << "Encountered " << trees << " trees" << endl;
}

/**
Bootstrap reads inputs from file
*/
int main() {
    vector<string> lines;

    ifstream inputFile("input.txt");
    if (!inputFile.good()) {
        cout << "Failed to load file!" << endl;
        return 1;
    }

    // read file to vector of strings
    string line;
    while (getline(inputFile, line))
        lines.push_back(line);
    inputFile.close();

    // construct board
    Board board(&lines);

    // solutions
    solve(&board, 3, 1);

    return 0;
}
