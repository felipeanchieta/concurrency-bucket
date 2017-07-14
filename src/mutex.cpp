#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int accum = 0;
std::mutex accum_mutex;

void square(int x) {
  const int temp = x * x;

  accum_mutex.lock();
  accum += temp;
  accum_mutex.unlock();
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
