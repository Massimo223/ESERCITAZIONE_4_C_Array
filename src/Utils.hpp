#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> file_per_righe (ifstream& file);
double valore_finale_portfolio(vector<double> a, 
                               vector<double> b, 
                               double c);