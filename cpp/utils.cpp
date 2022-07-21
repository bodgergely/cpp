#include "utils.h"

#include <cstdio>
#include <map>
#include <sstream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    std::stringstream buf;
    buf << "[";
    for (int i = 0; i < vec.size(); i++) {
        buf << vec[i];
        buf << ", ";
    }
    auto res = buf.str();
    res.pop_back();
    res.pop_back();
    res.push_back(']');
    os << res;
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& cont)
{
    std::stringstream buf;
    buf << "[";
    for (auto it = cont.begin(); it != cont.end(); it++) {
        buf << *it;
        buf << ", ";
    }
    auto res = buf.str();
    res.pop_back();
    res.pop_back();
    res.push_back(']');
    os << res;
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& cont)
{
    std::stringstream buf;
    buf << "{";
    for (auto it = cont.begin(); it != cont.end(); it++) {
        buf << *it;
        buf << ", ";
    }
    auto res = buf.str();
    res.pop_back();
    res.pop_back();
    res.push_back('}');
    os << res;
    return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& cont)
{
    std::stringstream buf;
    buf << "{";
    for (auto it = cont.begin(); it != cont.end(); it++) {
        buf << it->first;
        buf << ": ";
        buf << it->second;
        buf << ", ";
    }
    auto res = buf.str();
    res.pop_back();
    res.pop_back();
    res.push_back('}');
    os << res;
    return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& cont)
{
    std::stringstream buf;
    buf << "{";
    for (auto it = cont.begin(); it != cont.end(); it++) {
        buf << it->first;
        buf << ": ";
        buf << it->second;
        buf << ", ";
    }
    auto res = buf.str();
    res.pop_back();
    res.pop_back();
    res.push_back('}');
    os << res;
    return os;
}

namespace utils
{
namespace time
{
std::chrono::high_resolution_clock::time_point getTime()
{
    return std::chrono::high_resolution_clock::now();
}

int64_t microseconds(std::chrono::high_resolution_clock::time_point after,
                     std::chrono::high_resolution_clock::time_point before)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(after - before)
        .count();
}
}  // namespace time

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////

CircularQueue::CircularQueue(int k)
    : _capacity((size_t)k),
      _arr((size_t)k),
      /* We mark an empty queue by setting head (and tail) to capacity. */
      _head(_capacity),
      _tail(_capacity)
{
}

bool CircularQueue::enQueue(int value)
{
    if (isFull()) return false;
    if (isEmpty()) {
        _head = 0;
        _tail = 0;
    } else {
        _tail = (_tail + 1) % _capacity;
    }

    _arr[_tail] = value;
    return true;
}

bool CircularQueue::deQueue()
{
    if (isEmpty()) return false;
    if (_head == _tail) {
        _head = _capacity;
        _tail = _capacity;
    } else {
        _head = (_head + 1) % _capacity;
    }

    return true;
}

int CircularQueue::Front()
{
    if (isEmpty())
        return -1;
    else
        return _arr[_head];
}

int CircularQueue::Rear()
{
    if (isEmpty())
        return -1;
    else
        return _arr[_tail];
}

bool CircularQueue::isEmpty() { return _head == _capacity; }

bool CircularQueue::isFull() { return ((_tail + 1) % _capacity) == _head; }

/////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////

void endianness_test()
{
    union Test
    {
        uint32_t i;
        uint8_t c[2];
    };

    union Test a = {0x89ABCDEF};
    if ((a.c[0] == 0x89) && (a.c[1] == 0xAB)) {
        printf("BIG ENDIAN\n");
    } else if ((a.c[0] == 0xEF) && (a.c[1] == 0xCD)) {
        printf("LITTLE ENDIAN\n");
    } else {
        printf("NOT IMPLEMENTED\n");
    }
}

}  // namespace utils
