#pragma once

#include <chrono>
#include <map>
#include <ostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& cont);

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<T>& cont);

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& cont);

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os,
                         const std::unordered_map<K, V>& cont);

/////////////////////////////////////////////////////////////
/// Time
/////////////////////////////////////////////////////////////

namespace utils
{
namespace time
{
std::chrono::high_resolution_clock::time_point getTime();

int64_t microseconds(std::chrono::high_resolution_clock::time_point after,
                     std::chrono::high_resolution_clock::time_point before);
}  // namespace time

/////////////////////////////////////////////////////////////
/// CircularQueue
/////////////////////////////////////////////////////////////

class CircularQueue
{
public:
    CircularQueue(int capacity);
    bool enQueue(int value);
    bool deQueue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();

private:
    const size_t _capacity;
    std::vector<int> _arr;
    size_t _head;
    size_t _tail;
};

/////////////////////////////////////////////////////////////
/// Misc
/////////////////////////////////////////////////////////////

void endianness_test();

template <class T>
std::string bin(const T& num, int byteCount, bool littleEndian = true)
{
    std::string res{};
    res.reserve(byteCount * 8);
    const char mask = 0x80;
    for (size_t i = 0; i < byteCount; i++) {
        std::string buf{};
        buf.reserve(8);
        char* pnum = ((char*)&num) + i;
        char currbyte = *pnum;
        for (size_t j = 0; j < 8; j++) {
            char b = currbyte & mask;
            if (b) {
                buf.push_back('1');
            } else {
                buf.push_back('0');
            }
            currbyte <<= 1;
        }
        if (littleEndian) {
            res = buf + res;
        } else {
            res += buf;
        }
    }
    return res;
}

}  // namespace utils
