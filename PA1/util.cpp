#include "util.h"

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

vector<Pair> init(int argc, char *argv[])
{
    Assert(argc == 3, "Usage: %s <input file> <output file>", get_program_name(argv).c_str());
    ifstream fin;
    fin.open(argv[1]);
    Assert(fin.is_open(), "Error: cannot open file %s", argv[1]);
    vector<Pair> arr;
    load(fin, arr);
    fin.close();

    return arr;
}

void load(ifstream &fin, vector<Pair> &arr)
{
    string line;

    getline(fin, line);

    int counter = 0;
    while (getline(fin, line))
    {
        if (line == "0")
        {
            break;
        }
        size_t space = line.find(' ');
        int var1 = stoi(line.substr(0, space));
        int var2 = stoi(line.substr(space + 1));
        arr.push_back(Pair(var1, var2));
    }
}

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

void sort(vector<Pair> &arr)
{
    QuickSort<Pair> qs;
    qs.sort(arr);
}

void build_best_paths(vector<Pair> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int best_score = 0;
        int best_index = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i].get_lower() > arr[j].get_upper())
            {
                if (arr[j].get_my_best_score() > best_score)
                {
                    best_score = arr[j].get_my_best_score();
                    best_index = j;
                }
            }
        }
        arr[i].set_my_best_score(best_score + 1);
        if (best_index != -1)
        {
            vector<Pair> best_route = arr[best_index].get_my_best_route();
            best_route.push_back(arr[i]);
            arr[i].set_my_best_route(best_route);
        }
        else
        {
            vector<Pair> best_route;
            best_route.push_back(arr[i]);
            arr[i].set_my_best_route(best_route);
        }

        if (arr[i].get_my_best_score() > the_best_score)
        {
            the_best_score = arr[i].get_my_best_score();
            the_best_index = i;
        }
    }
}