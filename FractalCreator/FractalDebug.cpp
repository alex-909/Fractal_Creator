#include "FractalDebug.h"
#include <vector>
#include <iostream>

using namespace std;

void printPattern(vector<vector<bool>> vect)
{
    for (vector<bool> v : vect)
    {
        for (bool b : v)
        {
            if (b) { cout << b; }
            else { cout << " "; }
        }
        cout << "\n";
    }
}
