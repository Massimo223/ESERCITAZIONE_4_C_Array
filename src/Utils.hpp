#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Prendo le righe di un file (che sono stringhe) e con queste creo
// un vettore di stringhe 
vector<string> file_per_righe (ifstream& file);

// Calcolo il valore finale del portafoglio per un numero di investimenti 
// pari alla lunghezza dei vettori, che nella posizione i-esima contengono
// il tasso di ritorno e la frazione dell'investimento totale c allocata per quel
// determinato asset
double valore_finale_portfolio(vector<double> a, 
                               vector<double> b, 
                               double c);