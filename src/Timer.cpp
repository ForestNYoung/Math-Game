#include <chrono>

using namespace std;

class Timer {
  private:
    chrono::steady_clock::time_point start_time; // Start time
  
  public:
    Timer() {
      start_time = chrono::steady_clock::now(); // Setting the start time to when the Timer got initialized
    }
  
    void restart() {
      start_time = chrono::steady_clock::now(); // Restart function to restart time
    }
  
    double elapsed_seconds() {
      return chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - start_time).count(); // How many seconds have passed since start_time
    }
};
