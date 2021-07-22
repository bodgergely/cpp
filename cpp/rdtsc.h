/*
 * rdtsc.h
 *
 *  Created on: Mar 28, 2017
 *      Author: geri
 */

#ifndef RDTSC_H_
#define RDTSC_H_

#include <numeric>
#include <vector>

typedef unsigned long long ull;

#ifdef _WIN32
#include <Windows.h>
#endif  // _WIN32

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

// static unsigned long long rdtsc(void)
// {
//     unsigned hi, lo;
//     __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
//     return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
// }

unsigned long long estimate_tsc_per_sec()
{
    unsigned long long s = __rdtsc();
#ifdef __gnu_linux__
    usleep(1000000);
#elif _WIN32
    Sleep(1000);
#endif
    unsigned long long e = __rdtsc();
    return e - s;
}

double avg_cycles_per_microsec(int iterCount)
{
    std::vector<double> s;
    for (int i = 0; i < iterCount; i++) {
        double cycles_per_micro_sec = estimate_tsc_per_sec() / (double)1000000;
        s.push_back(cycles_per_micro_sec);
    }
    return std::accumulate(s.begin(), s.end(), 0.0) / s.size();
}

#endif /* RDTSC_H_ */
