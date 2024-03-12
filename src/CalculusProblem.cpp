#include <cmath>
#include <string>

using namespace std;

class CalculusProblem {
  private: // Variables
    int t; // Problem type (der = 0, int = 1)
    double n1; // First number
    double n2; // Second number
    int f[4]; // Function (f(x) = ax^3 + bx^2 + cx + d)

  public:
    CalculusProblem() { // Constructor
      t = rand() % 2; // t
      n1 = rand() % 3; // n1
      n2 = n1 + rand() % 3 + 1; // n2
      for (int i = 0; i < 4; i++) {
        f[i] = rand() % 7 - 3; // f[]
      }
  }

  public:
    double ans() { // Calculate answer
      if (t == 0) return 3 * f[0] * n1 * n1 + 2 * f[1] * n1 + f[3];
      else return round10(f[0] / 4 * n2 * n2 * n2 * n2 + f[1] / 3 * n2 * n2 * n2 + f[2] / 2 * n2 * n2 + f[3] * n2 - f[0] / 4 * n1 * n1 * n1 * n1 + f[1] / 3 * n1 * n1 * n1 + f[2] / 2 * n1 * n1 + f[3] * n1);
    }

    double round10(double x) { // Method for rounding to nearest tenth
      return round(10 * x) / 10.0;
    }

    string ftext() { // Returns text for f[]
      string ft = "f(x) = ";

      if (f[0] == 1) ft = ft + "x^3"; // First term
      else if (f[0] == -1) ft = ft + "-x^3";
      else if (f[0] == 0) ft = ft + "x^3";
      else ft = ft + to_string(f[0]) + "x^3";
      
      for (int i = 1; i < 3; i++) { // Middle terms
        if (f[i] == 1) ft = ft + " + x^" + to_string(3 - i);
        else if (f[i] == -1) ft = ft + " - x^" + to_string(3 - i); 
        else if (f[i] > 0) ft = ft + " + " + to_string(f[i]) + "x^" + to_string(3 - i);
        else if (f[i] < 0) ft = ft + " - " + to_string(-f[i]) + "x^" + to_string(3 - i);
      }

      if (f[3] > 0) ft = ft + " + " + to_string(f[3]);
      else if (f[3] < 0) ft = ft + " - " + to_string(-f[3]);

      return ft;
    }

    string text() { // Returns problem text
      if (t == 0) return "What is the slope of the function " + ftext() + " at x = " + to_string(n1).substr(0, 1) + "? ";
      else return "What is the area under the function " + ftext() + " from x = " + to_string(n1).substr(0, 1) + " to x = " + to_string(n2).substr(0, 1) + "? ";
    }
};