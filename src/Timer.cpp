// AI-generated code!
#include <chrono>

using namespace std;

class Timer {
  private:
    chrono::steady_clock::time_point start_time;
  
  public:
    Timer() {
      start_time = chrono::steady_clock::now();
    }
  
    void restart() {
      start_time = chrono::steady_clock::now();
    }
  
    double elapsed_seconds() {
      return std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start_time).count();
    }
};
