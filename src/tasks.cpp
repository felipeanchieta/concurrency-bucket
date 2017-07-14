#include <chrono>
#include <future>
#include <iostream>

int square(int x) {
  return x * x;
}

int main() {
  auto a = std::async(&square, 10);
  int v = a.get();

  std::cout << "the thread returned = " << v << std::endl;
  return 0;
}
