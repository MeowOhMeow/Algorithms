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

// i build the paths from the buttom to the peak(?), so I need to sort the array first
void sort(vector<Pair> &arr)
{
    QuickSort<Pair> qs;
    qs.sort(arr); // sort by the upper value, this is achieved by overloading the <= operator
}

// this is the core function, it takes O(n^2) time
void build_best_paths(vector<Pair> &arr)
{
    for (int i = 0; i < arr.size(); i++) // iterate through the array from the beginning
    {
        int best_score = 0;  // the best score of the previous pairs
        int best_index = -1; // set to -1 to indicate that there is no previous pair
        for (int j = 0; j < i; j++)
        {
            if (arr[i].get_lower() > arr[j].get_upper()) // whether the 2 pairs are compatible
            {
                if (arr[j].get_my_best_score() > best_score) // whether the previous pair has a better score
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
        else // there is no previous pair, the best route is itself
        {
            vector<Pair> best_route;
            best_route.push_back(arr[i]);
            arr[i].set_my_best_route(best_route);
        }

        // update the best score and index
        if (arr[i].get_my_best_score() > the_best_score)
        {
            the_best_score = arr[i].get_my_best_score();
            the_best_index = i;
        }
    }
}