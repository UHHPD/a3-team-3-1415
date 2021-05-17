#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

//Definition der Funktion poisson:
double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

int main() {
    using namespace std;
    ofstream fout1("hist.txt");
    ofstream fout2("histpoi.txt");
    ifstream fin("datensumme.txt");
    int n_i;
    std::vector<int> zaehler(11);
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
      zaehler[n_i] += 1;
    }
    for(int i = 0; i < 11 ; ++i){
       std::cout << i << ": " <<zaehler[i] << std::endl;
      fout1 << i << " " << zaehler[i] << " " << std::endl;
      fout2 << i << " " << zaehler [i] << " " << 234*poisson(3.11538,i) << std::endl;
    }
  fin.close();
  fout1.close();
  fout2.close();
}