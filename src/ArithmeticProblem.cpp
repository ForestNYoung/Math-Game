#include <cmath>
#include <string>

using namespace std;

class ArithmeticProblem {
  private: // Variables
    double n1; // First number
    double n2; // Second number
    string o; // Operation ("+", "-", "✕", "/")
    int mode; // Variety of problem (Integer = 0, Decimal = 1)

  public:
    ArithmeticProblem() { // Constructor
      mode = rand() % 2; // mode
      
      int temp = rand() % 4;
      if (temp == 0) o = "+"; // o
      else if (temp == 1) o = "-"; // o
      else if (temp == 2) o = "✕"; // o
      else o = "/"; // o

      if (mode == 0) {
        n1 = rand() % 20; // n1 as int
        n2 = rand() % 19 + 1; // n2 as int
      }
      else { // Generates n1 and n2 as decimals with only a tenths place
        n1 = rand() % 10 + 0.1 * (rand() % 10); // n1 as decimal
        n2 = rand() % 10 + 0.1 * (rand() % 10); // n2 as decimal
      }
  }

  public:
    double ans() { // Calculate answer (int) (10 * n + 0.5) / 10.0 rounds a number to the tenths place
      if (o == "+") return round10(n1 + n2);
      if (o == "-") return round10(n1 - n2);
      if (o == "✕") return round10(n1 * n2);
      return round10(n1 / n2);
    }

    double round10(double x) { // Method for rounding to nearest tenth
      return round(10 * x) / 10.0;
    }
    
    string text() { // Returns problem text
      if (mode == 0) return "Evaluate: " + to_string((int) n1) + " " + o + " " + to_string((int) n2) + " = ";
      return "Evaluate: " + to_string(n1).substr(0, 3) + " " + o + " " + to_string(n2).substr(0, 3) + " = ";
    }
};