#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State{
    kEmpty,
    kObstacle,
    KClosed
};

//function to Parse string line
vector <State> ParseLine(string line)
{
    istringstream line_str(line);
    int i;
    char c;
    vector<State> v;
    while (line_str >> i >> c && c == ',')
    {
        if(i == 0)
        {
            v.push_back(State::kEmpty);
        }
        else
        {
            v.push_back(State::kObstacle);
        }
        
    } 
    return v;
}

// function to read board file

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    vector<State> row;
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            row = ParseLine(line);
            board.push_back(row);
        }
    }

    return board;
}

// func to represent obstacles and free postions
string cellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰   ";
        break;
    
    default:
        return "0   ";
        break;
    }
}

// print board function
void printBoard(vector<vector<State>> v)
{
    for (int count =0; count < v.size(); count++)
    {
        for (int j =0; j < v[count].size(); j++)
        {
            cout<< cellString(v[count][j]);
        }
        cout<<"\n";
    }

}

int main ()
{
    auto board = ReadBoardFile("1.board");
    printBoard(board);


    return 0;
}