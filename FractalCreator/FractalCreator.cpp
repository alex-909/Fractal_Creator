#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream> 

#include "FractalCreator.h"

using namespace std;

vector<vector<bool>> step(vector<vector<bool>> base, vector<vector<bool>> current)
{
    int index = 0;
    int c_w = current[0].size();
    int c_h = current[0].size();
    int n_w = c_w * 3;
    int n_h = c_h * 3;
    std::cout << "cur dimensions: " << to_string(c_w) << " x " << to_string(c_h) << endl;
    std::cout << "new dimensions: " << to_string(n_w) << " x " << to_string(n_h) << endl;
    std::cout << "\n";


    vector<vector<bool>> newPattern;
    vector<bool> emptyRow;

    emptyRow.assign(n_w, true);
    newPattern.assign(n_h, emptyRow);

    vector<int> v1;
    v1.assign(7, 100);

    //a is the row of the new fractal
    for (int a = 0; a < n_h; a++)
    {
        vector<bool> row;
        row.assign(n_w, true);

        //b is the collumn part of the new fractal
        int index = 0;
        for (int b = 0; b < base[0].size(); b++)
        {
            if (base[a / c_h][b] == 0)
            {
                //add empty row
                for (int i = 0; i < c_w; i++)
                {
                    row[index] = 0;
                    index++;
                }
            }
            else
            {
                //add elements of row
                for (int i = 0; i < c_w; i++)
                {
                    //change i accordingly to index
                    row[index] = current[a % c_h][i];
                    index++;
                    //cout << "pushing back";
                }
            }
        }
        if (a % 100 == 0)
        {
            cout << "a: " << to_string(a) << endl;
        }
        newPattern[a] = row;
    }

    return newPattern;
}
