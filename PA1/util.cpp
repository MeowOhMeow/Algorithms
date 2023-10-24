#include "util.h"

// simply get the program name, I use both '/' and '\' to support both Windows and Linux
string get_program_name(char *argv[])
{
    string program_name = argv[0];
    size_t last_slash = program_name.find_last_of('\\');
    if (last_slash != string::npos)
    {
        program_name = program_name.substr(last_slash + 1);
    }
    last_slash = program_name.find_last_of('/');
    if (last_slash != string::npos)
    {
        program_name = program_name.substr(last_slash + 1);
    }
    return program_name;
}

// initialize the vector
vector<Pair> init(int argc, char *argv[])
{
    Assert(argc == 3, "Usage: %s <input file> <output file>", get_program_name(argv).c_str());
    return load(argv[1]);
}

// what you see is what you get
vector<Pair> load(char *filename)
{
    ifstream fin;
    fin.open(filename);
    Assert(fin.is_open(), "Error: cannot open file %s", filename);

    string line; // to store stuff

    getline(fin, line);
    vector<Pair> arr = vector<Pair>(stoi(line) / 2); // reserve space

    int counter = 0;
    while (getline(fin, line))
    {
        if (line == "0") // this is kinda useless, but it's in the original data
        {
            break;
        }
        size_t space = line.find(' '); // locate the space
        int var1 = stoi(line.substr(0, space));
        int var2 = stoi(line.substr(space + 1));
        arr[counter++] = Pair(var1, var2);
    }
    fin.close();

    return arr;
}

// save it!!!!!!!
void save(char *filename, vector<Pair> &arr, int the_best_score, int the_best_index)
{
    ofstream fout;
    fout.open(filename);
    Assert(fout.is_open(), "Error: cannot open file %s", filename);

    fout << the_best_score << endl;
    vector<Pair> best_route = arr[the_best_index].get_my_best_route();
    for (int i = 0; i < best_route.size(); i++)
    {
        fout << best_route[i].get_lower() << " " << best_route[i].get_upper() << endl;
    }
    fout.close();
}
