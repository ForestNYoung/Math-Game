#include <iostream>
#include <fstream>
#include "ArithmeticProblem.cpp"
#include "GeometryProblem.cpp"
#include "ProbabilityProblem.cpp"
#include "CalculusProblem.cpp"
#include "Timer.cpp"

using namespace std;

bool invalid(string s);

int main() {
  unsigned seed = time(0); // Generating seed for rand()

  double score = 0; // score
  double accuracy = 0; // accuracy
  double time = 0; // time
  string hs = ""; // HIGH SCORE

  string t = ""; // Temporary string
  bool valid = false; // If input is a valid integer
  int a = 0, g = 0, p = 0, c = 0; // Read inputs
  
  cout << "Welcome to MathGame! Please enter how many arithmetic problems you would like: ";
  cin >> t;
  if (!invalid(t)) {
    if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
  }
  while (!valid) {
      cout << "Invalid number! Please enter how many arithmetic problems you would like: ";
      cin >> t;
      if (!invalid(t)) {
        if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
      }
  }
  a = (int) stod(t);

  valid = false;
  cout << "Please enter how many geometric problems you would like: ";
  cin >> t;
  if (!invalid(t)) {
    if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
  }
  while (!valid) {
    cout << "Invalid number! Please enter how many geometric problems you would like: ";
    cin >> t;
    if (!invalid(t)) {
      if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
    }
  }
  g = (int) stod(t);

  valid = false;
  cout << "Please enter how many probability problems you would like: ";
  cin >> t;
  if (!invalid(t)) {
    if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
  }
  while (!valid) {
    cout << "Invalid number! Please enter how many probablity problems you would like: ";
    cin >> t;
    if (!invalid(t)) {
      if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
    }
  }
  p = (int) stod(t);

  valid = false;
  cout << "Please enter how many calculus problems you would like: ";
  cin >> t;
  if (!invalid(t)) {
    if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
  }
  while (!valid) {
    cout << "Invalid number! Please enter how many calculus problems you would like: ";
    cin >> t;
    if (!invalid(t)) {
      if (stod(t) != 0 && floor(stod(t)) == stod(t)) valid = true;
    }
  }
  c = (int) stod(t);

  ArithmeticProblem ap[a]; // Arithmetic problems
  double aa[a]; // Arithmetic answers
  GeometryProblem gp[g]; // Geometry problems
  double ga[g]; // Geometry answers
  ProbabilityProblem pp[p]; // Probability problems
  double pa[p]; // Probability answers
  CalculusProblem cp[c]; // Calculus problems
  double ca[c]; // Calculus answers
  
  for (int i = 0; i < a; i++) {
    srand(seed + 2000 + i * 2); // Use a different seed each time
    ap[i] = ArithmeticProblem(); // Then make new ArithmeticProblem
  }

  for (int i = 0; i < g; i++) {
    srand(seed + 4000 + i * 4); // Use a different seed each time
    gp[i] = GeometryProblem(); // Then make new GeometryProblem
  }

  for (int i = 0; i < p; i++) {
    srand(seed + 5000 + i * 5); // Use a different seed each time
    pp[i] = ProbabilityProblem(); // Then make new ProbabilityProblem
  }

  for (int i = 0; i < c; i++) {
    srand(seed + 9000 + i * 9); // Use a different seed each time
    gp[i] = GeometryProblem(); // Then make new CalculusProblem
  }
  
  string answer; // Answer for each question
  cout << "\nTimer has started! Round all decimals to the tenth place. Don't type spaces. NO CALCULATOR ALLOWED.\n";
  Timer timer; // Timer!
  
  for (int i = 0; i < a; i++) {
    cout << ap[i].text();
    cin >> answer;
    while (invalid(answer)) {
      cout << "Invalid answer!\n" << ap[i].text();
      cin >> answer;
    }
    aa[i] = stod(answer);
  }
  cout << endl;
  
  for (int i = 0; i < g; i++) {
    cout << gp[i].text();
    cin >> answer;
    while (invalid(answer)) {
      cout << "Invalid answer!\n" << gp[i].text();
      cin >> answer;
    }
    ga[i] = stod(answer);
  }
  cout << endl;

  for (int i = 0; i < p; i++) {
    cout << pp[i].text();
    cin >> answer;
    while (invalid(answer)) {
      cout << "Invalid answer!\n" << pp[i].text();
      cin >> answer;
    }
    pa[i] = stod(answer);
  }
  cout << endl;

  for (int i = 0; i < c; i++) {
    cout << cp[i].text();
    cin >> answer;
    while (invalid(answer)) {
      cout << "Invalid answer!\n" << cp[i].text();
      cin >> answer;
    }
    ca[i] = stod(answer);
  }
  cout << endl;
  
  time = timer.elapsed_seconds();
  
  for (int i = 0; i < a; i++)
    if (ap[i].ans() == aa[i]) {
      score += 2;
      accuracy++;
    }
  for (int i = 0; i < g; i++) 
    if (gp[i].ans() == ga[i]) {
      score += 4; 
      accuracy++;
    }
  for (int i = 0; i < p; i++) 
    if (pp[i].ans() == pa[i]) {
      score += 5; 
      accuracy++;
    }
  for (int i = 0; i < c; i++) 
    if (cp[i].ans() == ca[i]) {
      score += 9; 
      accuracy++;
    }

  accuracy /= a + g + p + c;
  score = score / time * accuracy * accuracy * accuracy * accuracy * sqrt(a + g + p + c) * 1000;
  
  cout << "Congratulations! Your score is " << to_string(score).substr(0, 6) << " and you completed in " << to_string(time).substr(0, 4) << " seconds with a " << to_string(accuracy * 100).substr(0, 5) << "% accuracy! ";

  ifstream iF;
  iF.open("highscore.txt", ios::in); // Opening input stream
  if (iF.is_open()) { // Checking if opening is successful
    getline(iF, hs);
  }
  cout << "The previous high score was " << hs.substr(0, 6) << ". ";

  if (score > stod(hs)) {
    cout << "Congratulations! You beat the high score!!!";
    ofstream oF;
    oF.open("highscore.txt", ios::trunc); // Open output stream
    oF << to_string(score);
  }
}

bool invalid(string s) { // Checks if input is invalid
  bool inv = false;

  // Check 1 for invalid characters
  string nums = "-0123456789.";
  for (int i = 0; i < s.size(); i++) {
    if (nums.find(s[i]) == string::npos) inv = true; // If the character right now isn't a number
  }

  // Check 2 for multiple decimal points
  int points = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') { // If the character right now is a decimal
        points++;
        if (points > 1) { // If there is more than 1 decimal point
          inv = true;
          break;
        }
    }
  }

  // Check 3 for misplaced signs
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '-') {
      inv = true;
      break;
    }
  }

  // Check 4 for bad decimals
  if (s == "." || s == "-.") inv = true;

  return inv;
};

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