#include <bits/stdc++.h>
#include "deque.hpp"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Simple interactive interpreter to exercise deque
  sjtu::deque<long long> dq;
  int q;
  if (!(std::cin >> q)) return 0;
  while (q--) {
    std::string op;
    std::cin >> op;
    if (op == "push_back") {
      long long x; std::cin >> x; dq.push_back(x);
    } else if (op == "push_front") {
      long long x; std::cin >> x; dq.push_front(x);
    } else if (op == "pop_back") {
      try { dq.pop_back(); } catch (...) { std::cout << "error\n"; }
    } else if (op == "pop_front") {
      try { dq.pop_front(); } catch (...) { std::cout << "error\n"; }
    } else if (op == "front") {
      try { std::cout << dq.front() << "\n"; } catch (...) { std::cout << "error\n"; }
    } else if (op == "back") {
      try { std::cout << dq.back() << "\n"; } catch (...) { std::cout << "error\n"; }
    } else if (op == "size") {
      std::cout << dq.size() << "\n";
    } else if (op == "at") {
      size_t i; std::cin >> i; try { std::cout << dq.at(i) << "\n"; } catch (...) { std::cout << "error\n"; }
    } else if (op == "get") {
      size_t i; std::cin >> i; try { std::cout << dq[i] << "\n"; } catch (...) { std::cout << "error\n"; }
    } else if (op == "insert") {
      size_t i; long long x; std::cin >> i >> x;
      auto it = dq.begin(); it += static_cast<int>(i);
      dq.insert(it, x);
    } else if (op == "erase") {
      size_t i; std::cin >> i; auto it = dq.begin(); it += static_cast<int>(i); dq.erase(it);
    }
  }
  return 0;
}

