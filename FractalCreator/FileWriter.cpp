#include "FileWriter.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream> 

using namespace std;

void writeToFile(vector<vector<bool>> vect)
{
    int width = vect[0].size();
    int height = vect.size();
    cout << width << endl;
    cout << height << endl;

    ofstream img("picture.ppm");
    img << "P1" << endl;
    img << width << " " << height << endl;

    int i = 0;
    for (vector<bool> v : vect)
    {
        for (bool b : v)
        {
            img << b;
        }
        img << endl;
        i++;

        if (i % 100 == 0)
        {
            std::cout << "image row: " + to_string(i) + " / " + to_string(width) << endl;
        }

    }
    std::cout << "\n image created!";
}
