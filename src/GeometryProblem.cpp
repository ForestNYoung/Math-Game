#include <cmath>
#include <string>

using namespace std;

class GeometryProblem {
  private: // Variables
    string s; // Shape (rectangle, parallelogram, circle, ellipse, triangle, angleRightTriangle, lengthRightTriangle)
    double n1; // First number
    double n2; // Second number

  public:
    GeometryProblem(string s, double n1, double n2) { // Constructor
      this -> s = s;
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