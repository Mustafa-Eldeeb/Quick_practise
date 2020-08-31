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

// read board file

