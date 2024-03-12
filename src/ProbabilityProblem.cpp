#include <cmath>
#include <string>

using namespace std;

class ProbabilityProblem {
  private: // Variables
    int t; // Problem type (cou = 0, pro = 1, rec = 2, per = 3, com = 4)
    int n1; // First number
    int n2; // Second number

  public:
    ProbabilityProblem() { // Constructor
      t = rand() % 5; // t
      n1 = rand() % 3 + 1; // n1
      n2 = n1 + rand() % 7 + 1; // n2
  }

  public:
    double ans() { // Calculate answer
      if (t == 0) return n1 * n2;
      else if (t == 1) return round10(n1 / (n1 + n2));
      else if (t == 2) return n1 * (n1 + 1) * n2 * (n2 + 1) / 4;
      else if (t == 3) return fact(n2) / fact(n2 - n1);
      else return fact(n2) / (fact(n1) * fact(n2 - n1));
    }

    int fact(int x) {
      int f = 1;
      for (int i = 1; i <= x; i++) {
        f *= i;
      }
      return f;
    }

    double round10(double x) { // Method for rounding to nearest tenth
      return round(10 * x) / 10.0;
    }

    string text() { // Returns problem text
      if (t == 0) return "How many different meals consisting of 1 main dish and 1 dessert can you eat if " + to_string(n1) + " main dishes are offered and " + to_string(n2) + " desserts are offered? ";
      else if (t == 1) return "Find the probability of drawing a black marble from a bag of " + to_string(n1) + " black marbles and " + to_string(n2) + " white marbles: ";
      else if (t == 2) return "Determine the number of distinct rectangles in a " + to_string(n1) + " by " + to_string(n2) + " grid: ";
      else if (t == 3) return "How many ways are there to order " + to_string(n1) + " books in a bookshelf out of a stack of " + to_string(n2) + " books? ";
      else return "How many ways are there to choose an unordered set of " + to_string(n1) + " rocks from a basket of " + to_string(n2) + " distinct rocks? ";
    }
};