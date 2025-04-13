#include "Utils.hpp"

using namespace std;

vector<string> file_per_righe (ifstream& file) {
	vector<string> r_f;
	string riga;
	while (getline(file,riga)) {       // Prendo le righe di un file (che sono stringhe) e con queste creo
	r_f.push_back(riga);                   // un vettore di stringhe (r_f)
	}
	return r_f;
}

double valore_finale_portfolio(vector<double> a, vector<double> b, double c) {
	double V = 0.0;
	int n_assets = a.size();
	for (int i = 0; i < n_assets; i++) {   // Calcolo il valore finale del portafoglio per un numero di investimenti 
		V += (1 + a[i]) * b[i] * c;       // pari alla lunghezza dei vettori, che nella posizione i-esima contengono
	}                                    // il tasso di ritorno e la frazione dell'investimento totale c allocata per quel
	return V;                           // determinato asset
}



