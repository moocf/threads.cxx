#include <thread>
#include <sstream>
#include <iostream>

using namespace std;


// Thread function to calculate sum.
void threadFunction(int& sum, int a, int b) {
  thread::id id = this_thread::get_id();
  stringstream ss; ss << id;
  string idx = ss.str();
  sum = a + b;
  printf("[%s] Hello! Finding sum of %d and %d\n", idx.c_str(), a, b);
  printf("[%s] Sum: %d\n", idx.c_str(), sum);
}


// Main function.
int main(int argc, char **argv) {
  int sum1, sum2;
  thread t1(threadFunction, ref(sum1), 5, 10);
  thread t2(threadFunction, ref(sum2), 15, 20);
  t1.join();
  t2.join();
  printf("Final Sums: %d, %d\n", sum1, sum2);
}
