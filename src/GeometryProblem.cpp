#include <cmath>
#include <string>

using namespace std;

class GeometryProblem {
  private: // Variables
    int s; // Shape (rec = 0, cir = 1, sec = 2, rigtri = 3, pyr = 4)
    bool a; // Area or perimeter (true if area)
    int n1; // First number
    int n2; // Second number

  public:
    GeometryProblem() { // Constructor
      s = rand() % 5; // s
      a = rand() % 2; // a
      n1 = rand() % 10 + 1; // n1
      n2 = rand() % 12 + 1; // n2
  }

  public:
    double ans() { // Calculate answer
      if (s == 0) { // Rectangle
        if (a) return n1 * n2;
        else return 2.0 * (n1 + n2);
      }
      else if (s == 1) { // Circle
        if (a) return round10(M_PI * n1 * n1);
        else return round10(2.0 * M_PI * n1);
      }
      else if (s == 2) { // Sector
        if (a) return round10(M_PI * n1 * n1 * n2 * 30.0 / 360.0);
        else return round10(2.0 * M_PI * n1 * n2 * 30.0 / 360.0 + 2.0 * n1);
      }
      else if (s == 3) { // Right Triangle
        if (a) return 1.0 / 2.0 * n1 * n2;
        else return round10(n1 + n2 + sqrt(n1 * n1 + n2 * n2));
      }
      else { // Pyramid
        if (a) return round10(1.0 / 3.0 * n1 * n2 * n2);
        else return round10(n2 * n2 + n2 * sqrt(n2 * n2 / 4.0 + n1 * n1) + n2 * sqrt(n2 * n2 / 4.0 + n1 * n1));
      }
    }

    double round10(double x) { // Method for rounding to nearest tenth
      return round(10 * x) / 10.0;
    }

    string text() { // Returns problem text
      if (s == 0) { // Rectangle
        if (a) return "Calculate the area of a rectangle whose length is " + to_string(n1) + " and width is " + to_string(n2) + ": ";
        else return "Find the perimeter of a rectangle with dimensions " + to_string(n1) + " by " + to_string(n2) + ": ";
      }
      else if (s == 1) { // Circle
        if (a) return "Determine the area of a circle whose radius is " + to_string(n1) + ": ";
        else return "What is the circumference of a circle that has radius " + to_string(n1) + "? ";
      }
      else if (s == 2) { // Sector
        if (a) return "What is the area of a sector that has a radius of " + to_string(n1) + " and arc angle of " + to_string(n2 * 30) + "°? ";
        else return "What is the total perimeter of a sector with radius " + to_string(n1) + " and arc angle " + to_string(n2 * 30) + "°? ";
      }
      else if (s == 3) { // Right Triangle
        if (a) return "Calculate the area of a right triangle whose vertices lie on the points (" + to_string(n1) + ", " + to_string(n2) + "), (0, 0), and (" + to_string(n1) + ", 0): ";
        else return "What is the perimeter of a right triangle whose vertices lie on the points (" + to_string(n1) + ", " + to_string(n2) + "), (0, 0), and (" + to_string(n1) + ", 0)? ";
      }
      else { // Pyramid
        if (a) return "Find the volume of a square pyramid with height " + to_string(n1) + " and base length " + to_string(n2) + ": ";
        else return "Determine the surface area of a right square pyramid with height " + to_string(n1) + " and base length " + to_string(n2) + ": ";
      }
    }
};