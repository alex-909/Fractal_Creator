#include "FractalDebug.h"
#include <vector>

using namespace std;

void printPattern(vector<vector<bool>> vect)
{
    for (vector<bool> v : vect)
    {
        for (bool b : v)
        {
            if (b) { std::cout << b; }
            else { std::cout << " "; }
        }
        std::cout << "\n";
    }
}
