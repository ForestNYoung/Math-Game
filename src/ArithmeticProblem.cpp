#include <cmath>
#include <string>

using namespace std;

class ArithmeticProblem {
  private: // Variables
    double n1; // First number
    double n2; // Second number
    char o; // Operation

  public:
    ArithmeticProblem(double n1, double n2, double o) { // Constructor
      this -> n1 = n1;
      this -> n2 = n2;
      this -> o = o;
  }

  public:
    double ans() { // Calculate answer
      return 0;
    }
    string text() { // Returns problem text
      return "";
    }
};