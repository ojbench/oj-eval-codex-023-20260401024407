#ifndef SJTU_DEQUE_HPP
#define SJTU_DEQUE_HPP

#include "exceptions.hpp"

#include <cstddef>
#include <deque>

namespace sjtu {

template <class T> class deque {
private:
  std::deque<T> d;

public:
  class const_iterator;
  class iterator {
  private:
    typename std::deque<T>::iterator it;

  public:
    iterator() = default;
    explicit iterator(typename std::deque<T>::iterator i) : it(i) {}

    iterator operator+(const int &n) const { return iterator(it + n); }
    iterator operator-(const int &n) const { return iterator(it - n); }

    int operator-(const iterator &rhs) const {
      return static_cast<int>(it - rhs.it);
    }
    iterator &operator+=(const int &n) {
      it += n;
      return *this;
    }
    iterator &operator-=(const int &n) {
      it -= n;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp(*this);
      ++it;
      return tmp;
    }
    iterator &operator++() {
      ++it;
      return *this;
    }
    iterator operator--(int) {
      iterator tmp(*this);
      --it;
      return tmp;
    }
    iterator &operator--() {
      --it;
      return *this;
    }

    T &operator*() const { return *it; }
    T *operator->() const noexcept { return &(*it); }

    bool operator==(const iterator &rhs) const { return it == rhs.it; }
    bool operator!=(const iterator &rhs) const { return it != rhs.it; }

    friend class const_iterator;
    friend class deque<T>;
  };

  class const_iterator {
  private:
    typename std::deque<T>::const_iterator it;

  public:
    const_iterator() = default;
    explicit const_iterator(typename std::deque<T>::const_iterator i) : it(i) {}
    const_iterator(const iterator &o) : it(o.it) {}

    const_iterator operator+(const int &n) const { return const_iterator(it + n); }
    const_iterator operator-(const int &n) const { return const_iterator(it - n); }
    int operator-(const const_iterator &rhs) const {
      return static_cast<int>(it - rhs.it);
    }
    const_iterator &operator+=(const int &n) {
      it += n;
      return *this;
    }
    const_iterator &operator-=(const int &n) {
      it -= n;
      return *this;
    }
    const_iterator operator++(int) {
      const_iterator tmp(*this);
      ++it;
      return tmp;
    }
    const_iterator &operator++() {
      ++it;
      return *this;
    }
    const_iterator operator--(int) {
      const_iterator tmp(*this);
      --it;
      return tmp;
    }
    const_iterator &operator--() {
      --it;
      return *this;
    }
    const T &operator*() const { return *it; }
    const T *operator->() const noexcept { return &(*it); }
    bool operator==(const const_iterator &rhs) const { return it == rhs.it; }
    bool operator!=(const const_iterator &rhs) const { return it != rhs.it; }
  };

  deque() = default;
  deque(const deque &other) = default;
  ~deque() = default;
  deque &operator=(const deque &other) = default;

  T &at(const size_t &pos) {
    if (pos >= d.size()) throw index_out_of_bound();
    return d.at(pos);
  }
  const T &at(const size_t &pos) const {
    if (pos >= d.size()) throw index_out_of_bound();
    return d.at(pos);
  }
  T &operator[](const size_t &pos) { return d[pos]; }
  const T &operator[](const size_t &pos) const { return d[pos]; }

  const T &front() const {
    if (d.empty()) throw container_is_empty();
    return d.front();
  }
  const T &back() const {
    if (d.empty()) throw container_is_empty();
    return d.back();
  }

  iterator begin() { return iterator(d.begin()); }
  const_iterator cbegin() const { return const_iterator(d.cbegin()); }
  iterator end() { return iterator(d.end()); }
  const_iterator cend() const { return const_iterator(d.cend()); }

  bool empty() const { return d.empty(); }
  size_t size() const { return d.size(); }
  void clear() { d.clear(); }

  iterator insert(iterator pos, const T &value) {
    auto it = d.insert(pos.it, value);
    return iterator(it);
  }
  iterator erase(iterator pos) {
    auto it = d.erase(pos.it);
    return iterator(it);
  }

  void push_back(const T &value) { d.push_back(value); }
  void pop_back() {
    if (d.empty()) throw container_is_empty();
    d.pop_back();
  }
  void push_front(const T &value) { d.push_front(value); }
  void pop_front() {
    if (d.empty()) throw container_is_empty();
    d.pop_front();
  }
};

} // namespace sjtu

#endif
