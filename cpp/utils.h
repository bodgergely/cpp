#pragma once

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

/*
    For pair hashing.
*/
template <class T1, class T2>
struct pair_hash
{
    std::size_t operator()(std::pair<T1, T2> const& pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

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

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p1);

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
    if (vec.size() > 0) {
        res.pop_back();
        res.pop_back();
    }
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
    if (cont.size() > 0) {
        res.pop_back();
        res.pop_back();
    }
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
    if (cont.size() > 0) {
        res.pop_back();
        res.pop_back();
    }
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
    }
    auto res = buf.str();
    if (cont.size() > 0) {
        res.pop_back();
        res.pop_back();
    }
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
    }
    auto res = buf.str();
    if (cont.size() > 0) {
        res.pop_back();
        res.pop_back();
    }
    res.push_back('}');
    os << res;
    return os;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p1)
{
    std::stringstream buf;
    buf << "(";
    buf << p1.first;
    buf << ", ";
    buf << p1.second;
    buf << ")";
    os << buf.str();
    return os;
}

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

/*
    #########################
    String utilities.
    #########################
*/
namespace string
{
// trim from start (in place)
static inline void ltrim(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
}

// trim from end (in place)
static inline void rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         [](unsigned char ch) { return !std::isspace(ch); })
                .base(),
            s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s)
{
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s)
{
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s)
{
    trim(s);
    return s;
}

std::vector<std::string> split(const std::string& str, char delimiter = ' ')
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string toLower(const std::string& str)
{
    auto cp = str;
    std::transform(cp.begin(), cp.end(), cp.begin(),
                   [](unsigned char ch) { return std::tolower(ch); });
    return cp;
}

void toLowerInPlace(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char ch) { return std::tolower(ch); });
}

std::string toUpper(const std::string& str)
{
    auto cp = str;
    std::transform(cp.begin(), cp.end(), cp.begin(),
                   [](unsigned char ch) { return std::toupper(ch); });
    return cp;
}

void toUpperInPlace(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char ch) { return std::toupper(ch); });
}
}  // namespace string

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
    if (isFull())
        return false;
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
    if (isEmpty())
        return false;
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

bool CircularQueue::isEmpty()
{
    return _head == _capacity;
}

bool CircularQueue::isFull()
{
    return ((_tail + 1) % _capacity) == _head;
}

/////////////////////////////////////////////////////////////
/// Misc
/////////////////////////////////////////////////////////////

void endianness_test();
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

void permutate(int n, std::vector<std::vector<int>>& res)
{
    static std::unordered_set<int> included;
    static std::vector<int> vv;

    if (vv.size() == n) {
        res.push_back(vv);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (included.find(i) != included.end())
            continue;
        included.insert(i);
        vv.push_back(i);
        permutate(n, res);
        included.erase(i);
        vv.pop_back();
    }
}

std::vector<std::vector<int>> permutations(int n)
{
    std::vector<std::vector<int>> res;
    permutate(n, res);
    return res;
}

void subset(int n, int k, std::vector<std::vector<int>>& res)
{
    std::cout << "Calling with: " << k << std::endl;
    static std::vector<int> ss;
    if (n + 1 == k) {
        std::cout << "Reached subset with count: " << ss.size() << std::endl;
        res.push_back(ss);
        return;
    }
    // include k in the subset
    ss.push_back(k);
    subset(n, k + 1, res);
    // do not include k in the subset
    ss.pop_back();
    subset(n, k + 1, res);
}

std::vector<std::vector<int>> subsets(int n)
{
    std::vector<std::vector<int>> res;
    subset(n, 1, res);
    return res;
}

void floatingPoint()
{
    unsigned int res = 0;
    char* p = (char*)&res;
    p = p + 3;
    // *p |= 0x7F;
    *p |= 0x00;
    p--;
    *p |= 0x7F;
    p--;
    *p |= 0xFF;
    p--;
    *p |= 0xFF;

    float* fp = (float*)&res;
    std::cout << *fp << ":" << utils::bin(*fp, sizeof(*fp), true) << std::endl;
}

}  // namespace utils
