#include <iostream>
#include <vector>
#include <string>

#include "FractalCreator.h"
#include "FileWriter.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    
    vector<bool> r1 = { 1,1,1 };
    vector<bool> r2 = { 1,0,1 };
    vector<bool> r3 = { 1,1,1 };

    vector<vector<bool>> base;
    vector<vector<bool>> pattern;
    
    base.push_back(r1);     base.push_back(r2);     base.push_back(r3);
    pattern.push_back(r1);  pattern.push_back(r2);  pattern.push_back(r3);

    int steps = 7;
    for (int i = 0; i < steps; i++)
    {
        pattern = step(base, pattern);
        std::cout << "iteration: " + to_string(i) << endl;
    }

    //printPattern(pattern);
    writeToFile(pattern);

    char c = getchar();
    return 0;
}