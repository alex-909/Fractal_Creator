#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream> 

using namespace std;

vector<vector<bool>> step(vector<vector<bool>> base, vector<vector<bool>> current)
{
    int index = 0;
    vector<vector<bool>> newPattern;
    
    //a is the row of the new fractal
    for (int a = 0; a < (current.size() * 3); a++) 
    {
        vector<bool> row;
        //b is the collumn part of the new fractal
        for (int b = 0; b < base[0].size(); b++)
        {
            if (base[a/current.size()][b] == 0)
            {
                //add empty row
                for (int i = 0; i < current[0].size(); i++)
                {
                    row.push_back(0);
                }
            }
            else 
            {
                //add elements of row
                for (int i = 0; i < current[0].size(); i++)
                {
                    row.push_back(current[a % current.size()][i]);
                    //cout << "pushing back";
                }
            }
            cout << "creating row " + to_string(a) + " / " + to_string(current.size() * 3) << endl;
        }
        newPattern.push_back(row);
    }
    
    return newPattern;
}

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
void writeToFile(vector<vector<bool>> vect)
{
    int width = vect[0].size();
    int height = vect.size();

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
        cout << "image row: " + to_string(i) + " / " + to_string(width) << endl;
    }
    cout << "\n image created!";
}

int main()
{
    cout << "Hello World!\n";
    
    vector<vector<bool>> base;
    vector<bool> r1 = {1,1,1};
    vector<bool> r2 = {0,1,0};
    vector<bool> r3 = {1,1,1};
    base.push_back(r1);
    base.push_back(r2);
    base.push_back(r3);
    vector<vector<bool>> pattern;
    pattern.push_back(r1);
    pattern.push_back(r2);
    pattern.push_back(r3);

    int steps = 6;
    for (int i = 0; i < steps; i++)
    {
        pattern = step(base, pattern);
        cout << "iteration: " + to_string(i) << endl;
    }

    //printPattern(pattern);
    writeToFile(pattern);


    //end
    char c = getchar();
    return 0;
}