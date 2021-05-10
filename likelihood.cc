#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prob(std::vector<int> daten, double mu){
  double produkt = 1;
  for(int i = 0; i < daten.size() ; ++i){
    produkt *= poisson(mu, daten[i] );
  }
  return produkt;
}

int main() {
    using namespace std;


    ifstream fin1("datensumme.txt");
    int n_i;
    std::vector<int> daten;
    for(int i = 0 ; i < 234 ; ++i) {
        fin1 >> n_i;
        daten.push_back(n_i);
    }
    
    std::cout << "Likelihood(3.11538): " << prob(daten,3.11538) << std::endl;
    fin1.close();
}