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
*/