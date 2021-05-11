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

    ofstream fout1("likelihood.txt");
    ofstream fout2("nll.txt");
    ofstream fout3("deltanll.txt");
    ifstream fin1("datensumme.txt");
    int n_i;
    std::vector<int> daten;
    for(int i = 0 ; i < 234 ; ++i) {
        fin1 >> n_i;
        daten.push_back(n_i);
    }

    std::cout << "Likelihood(3.11538): " << prob(daten,3.11538) << std::endl;
    
    double g = 0;
    for(int i = 0; i < 61; ++i){
      fout1 << g << " " << prob(daten,g) << std::endl;
      fout2 << g << " " << -2*log(prob(daten,g)) << std::endl;
      fout3 << g << " " << -2*(log(prob(daten,g))-log(prob(daten,3.11538))) << std::endl;
      g += 0.1;
    }
    fin1.close();
    fout1.close();
    fout2.close();
    fout3.close();
}