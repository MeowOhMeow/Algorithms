#include "utility.h"

using namespace std;

Graph graph;

vector<string> split(string str, char delim)
{
    vector<string> res;
    string tmp;
    for (auto ch : str)
    {
        if (ch == delim)
        {
            res.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(ch);
        }
    }
    res.push_back(tmp);
    return res;
}

void _load(char *filename)
{
    ifstream fin(filename);
    Perror(fin, "Failed to open file %s", filename);
    string line;
    // grid col row
    getline(fin, line);
    vector<string> tmp = split(line, ' ');
    Assert(tmp.size() == 3, "Invalid input file");
    int col = stoi(tmp[1]);
    int row = stoi(tmp[2]);
    // capacity #
    getline(fin, line);
    tmp = split(line, ' ');
    Assert(tmp.size() == 2, "Invalid input file");
    int capacity = stoi(tmp[1]);
    // num net #
    getline(fin, line);
    tmp = split(line, ' ');
    Assert(tmp.size() == 3, "Invalid input file");
    num_nets = stoi(tmp[2]);
    // nets
    for (int i = 0; i < num_nets; i++)
    {
        getline(fin, line);
        tmp = split(line, ' ');
        Assert(tmp.size() == 5, "Invalid input file");
        int x1 = stoi(tmp[1]);
        int y1 = stoi(tmp[2]);
        int x2 = stoi(tmp[3]);
        int y2 = stoi(tmp[4]);
        nets.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    }

    graph = Graph(col, row, capacity);
}

void init(int argc, char *argv[])
{
    Assert(argc == 2, "Usage: %s <filename>", argv[0]);
    char *filename = argv[1];
    _load(filename);
}

void sovle()
{
    graph.solve();
}

void print_path()
{
    graph.print_path();
}

void clear()
{
    graph.reset();
}
