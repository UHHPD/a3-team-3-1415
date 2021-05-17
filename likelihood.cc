#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prob(std::vector<int> daten, double mu){
  double product = 1;
  for(int i = 0; i < daten.size() ; ++i){
    product *= poisson(mu, daten[i] );
  }
  return product;
}

double prob2(std::vector<int> daten){
  double product = 1;
  for(int i = 0; i < daten.size() ; ++i){
    product *= poisson(daten[i], daten[i] );
  }
  return product;
}

int main() {
    using namespace std;

    ofstream fout1("likelihood.txt");
    ofstream fout2("nll.txt");
    ofstream fout3("deltanll.txt");
    ifstream fin1("datensumme.txt");
    ofstream fout4("deltanll2.txt");

    int n_i;
    std::vector<int> daten;
    for(int i = 0 ; i < 234 ; ++i) {
        fin1 >> n_i;
        daten.push_back(n_i);
    }
    double lambda;
    double z;
    lambda = prob(daten, 3.11538)/prob2(daten);
    z = (-2*log(lambda)-233)/sqrt(466);
    std::cout << "Likelihood(3.11538): " << prob(daten,3.11538) << std::endl;
    std::cout /*<< "Likelihood-Quotient: "*/ << -2*log(lambda) << std::endl;
    //std::cout << "-2ln lambda: " << -2*log(lambda) << std::endl;
    std::cout /*<< "Relative Abweichung vom Likelihood-Quotienten: "*/ << z << std::endl;
    
    double g = 0;
    for(int i = 0; i < 61; ++i){
      fout1 << g << " " << prob(daten,g) << std::endl;
      fout2 << g << " " << -2*log(prob(daten,g)) << std::endl;
      fout3 << g << " " << -2*(log(prob(daten,g))-log(prob(daten,3.11538))) << std::endl;
      g += 0.1;
    }
    double f = 3;
    for(int i = 0; f < 3.31; ++i){
      fout4 << f << " " << -2*(log(prob(daten,f))-log(prob(daten,3.11538))) << std::endl;
      f += 0.01;
    }

    fin1.close();
    fout1.close();
    fout2.close();
    fout3.close();
    fout4.close();
}

// das Intervall in dem -2 ln(mu) um weniger als 1,0 größer ist kann man abschätzen mit: [3.00 ; 3.24]