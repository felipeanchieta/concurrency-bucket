#include <iostream>
#include <thread>
#include <vector>

int accum = 0;

void square(int x) {
  accum += x * x;
}

int main() {
  std::vector<std::thread> threads;

  for (int i = 1; i <= 20; ++i) {
    threads.push_back(std::thread(&square, i));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  std::cout << "accum = " << accum << std::endl;
  return 0;
}
