#include <iostream>
#include <iomanip>
#include "src/Utils.hpp"

using namespace std;

int main() {
	ifstream file("data.txt");
	ofstream outputFile("result.txt");
	outputFile << setprecision(2) << fixed;
	vector<double> w ;
	vector<double> r;
    string riga;
	double S;
	double rate_of_return;
	double V;
	vector<string> righe_file = file_per_righe(file);   // Funzione per creare un vettore di stringhe a partire da un file
	int n_righe = righe_file.size();
	for (int j = 0; j < n_righe; j++) {
		vector<char> vettore_caratteri(righe_file[j].begin(), righe_file[j].end());
		int lunghezza_stringa = vettore_caratteri.size();               
		string valore_di_S;
		if (j == 0) {
			for (int k = 0; k < lunghezza_stringa; k++) {
				if (vettore_caratteri[k] != ';' && k > 0) {
					valore_di_S += vettore_caratteri[k];
				}
			}
		S = stod(valore_di_S);
		outputFile << vettore_caratteri[j] << " = " << S << ", ";
		}			
		else if (j == 1) {
			outputFile << vettore_caratteri[0] << " = " << vettore_caratteri[2] << "\n";
		}
		else if (j >= 3) {
			string componente_di_w;
			int i = 0;
			while (vettore_caratteri[i] != ';') {           // Dopo aver stampato nel file in output "result.txt" la sua prima 
				componente_di_w += vettore_caratteri[i];    // riga, creo i vettori w e r stando attento al formato di "data.txt"
				i++;
			}
			i++;
			w.push_back(stod(componente_di_w));
			string componente_di_r;
			while (i < lunghezza_stringa) {
				componente_di_r += vettore_caratteri[i]; 
				i++;
			}
			r.push_back(stod(componente_di_r));
		}
	}
	outputFile << "w = [ ";
	int n_assets = w.size();
	outputFile << defaultfloat;
	for (int i = 0; i < n_assets; i++) {
		outputFile << setprecision(2) << w[i] << " ";
	}
	V = valore_finale_portfolio(r,w,S);  // Funzione per il calcolo del valore finale del portfolio
	rate_of_return = V/S - 1.00;
	outputFile << "]" << "\n" << "r = [ ";             // Stampo le righe mancanti su "result.txt"
	for (int i = 0; i < n_assets; i++) {
		outputFile << setprecision(2) << r[i] << " ";
	}
	outputFile << setprecision(2) << fixed;
	outputFile << "]" << "\n" << "Rate of return of the portfolio: " << setprecision(4) << rate_of_return << "\n" << "V: ";
	outputFile << setprecision(2) << fixed;
	outputFile << V;
	return 0;
}

