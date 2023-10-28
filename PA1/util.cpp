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

// what you see is what you get
void load(char *filename)
{
    ifstream fin;
    fin.open(filename);
    Assert(fin.is_open(), "Error: cannot open file %s", filename);

    string line; // to hold stuff

    getline(fin, line);
    num_of_points = stoi(line); // number of cords

    while (getline(fin, line))
    {
        if (line == "0") // end of file
        {
            break;
        }
        size_t space = line.find(' '); // locate the space
        int var1 = stoi(line.substr(0, space));
        int var2 = stoi(line.substr(space + 1));
        pair_map[var1] = var2;
        pair_map[var2] = var1;
    }
    fin.close();
}

// initializing the max_subsets array
void init_max_subsets()
{
    max_subsets = new int *[num_of_points];
    for (int i = 0; i < num_of_points; i++)
    {
        max_subsets[i] = new int[num_of_points];
        for (int j = 0; j < num_of_points; j++)
        {
            max_subsets[i][j] = 0;
        }
    }
}

/*
    arguments: argc, argv[]
    return: void
    description: initialize the program, including loading the input file, initializing the max_subsets array
*/
void init(int argc, char *argv[])
{
    Assert(argc == 3, "Usage: %s <input file> <output file>", get_program_name(argv).c_str());
    load(argv[1]);
    init_max_subsets();
}

// save the result
void save(char *filename)
{
    ofstream fout;
    fout.open(filename);
    Assert(fout.is_open(), "Error: cannot open file %s", filename);

    fout << best_score << endl;
    for (int i = 0; i < best_route.size(); i++)
    {
        fout << best_route[i].lower << " " << best_route[i].upper << endl;
    }
    fout.close();
}

// clean up memory
void clean()
{
    for (int i = 0; i < num_of_points; i++)
    {
        delete[] max_subsets[i];
    }
    delete[] max_subsets;
}
