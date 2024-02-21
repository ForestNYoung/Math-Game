#include <cmath>
#include <string>

using namespace std;

class ProbabilityProblem {
  private: // Variables
    string t; // Problem type (counting, discreetProbability, geometricProbability)
    double n1; // First number
    double n2; // Second number

  public:
    ProbabilityProblem(string t, double n1, double n2) { // Constructor
      this -> t = t;
      this -> n1 = n1;
      this -> n2 = n2;
  }

  public:
    double ans() { // Calculate answer
      return 0;
    }
    string text() { // Returns problem text
      return "";
    }
};