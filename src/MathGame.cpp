#include <iostream>
#include "ArithmeticProblem.cpp"
#include "GeometryProblem.cpp"
#include "ProbabilityProblem.cpp"
#include "CalculusProblem.cpp"
#include "Timer.cpp"

using namespace std;

int main() {
  int a, g, p, c;
  cout << "Welcome to MathGame! Please enter how many arithmetic problems you would like: ";
  cin >> a;
  cout << "Please enter how many geometric problems you would like: ";
  cin >> g;
  cout << "Please enter how many probability problems you would like: ";
  cin >> p;
  cout << "Please enter how many calculus problems you would like: ";
  cin >> c;
}

/* Timer sample code
  Timer timer; 
  cout << "Timer started\n";
  int stoch;
  cin >> stoch;
  cout << "Elapsed time in seconds: " << timer.elapsed_seconds();
Timer sample code */

/* Code for GUI Mockup
  string temp;
  cout << "\nTimer has started! Round all decimals to the tenth place. NO CALCULATOR ALLOWED.\n";
  cout << "Evaluate: 3.5 + 0.9 = ";
  cin >> temp;
  cout << "Evaluate: 50 - 33 = ";
  cin >> temp;
  cout << "\nWhat is the hypotenuse length of a right triangle with leg lengths 8 and 15? ";
  cin >> temp;
  cout << "Find the perimeter of a parallelogram with side lengths 7 and 8. ";
  cin >> temp;
  cout << "\nFind the probability of finding a black marble in a bag of 4 black marbles and 5 white marbles. ";
  cin >> temp;
  cout << "How many different combinations of 4 rocks are there in a set of 5 distinct rocks? ";
  cin >> temp;
  cout << "\nWhat is the slope at x = 3 of the function f(x) = 3x^4 + x^2 + 3? ";
  cin >> temp;
  cout << "What is the area under the curve from x = 0 to 1 of the function g(x) = x^3 + 5? ";
  cin >> temp;
  cout << "Congratulations! Your score is 100% and you completed 8 problems in 67.2 seconds!";
Code for GUI Mockup */