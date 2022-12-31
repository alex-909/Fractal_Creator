#include <iostream>
#include <vector>
#include <string>

#include "FractalCreator.h"
#include "FileWriter.h"

using namespace std;

vector<bool> getRow() 
{
    string s;
    vector<bool> row;
    cout << "enter row: " << endl;
    cin >> s;
    for (int i = 0; i < 3; i++) 
    {
        if (s[i] == '0')    { row.push_back(0); }
        else                { row.push_back(1); }
    }
    return row;
}

int main()
{
    std::cout << "Hello World!\n";
    

    vector<bool> r1 = getRow();
    vector<bool> r2 = getRow();
    vector<bool> r3 = getRow();

    vector<vector<bool>> base;
    vector<vector<bool>> pattern;
    
    base.push_back(r1);     base.push_back(r2);     base.push_back(r3);
    pattern.push_back(r1);  pattern.push_back(r2);  pattern.push_back(r3);

    int steps = 5;
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