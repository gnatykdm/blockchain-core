#pragma once

#include <cstdint>
#include "Types.h"

#define DEF_FACTOR 100000000

template<typename T = u64>
class Amount {
private:
    T value;
public:
    explicit Amount(T val) : value(val) {}

    T raw() const { return value; }

    double to_double(T factor = DEF_FACTOR) const {
        return static_cast<double>(value) / factor;
    }

    Amount operator+(const Amount& other) const { return Amount(value + other.value); }
    Amount operator-(const Amount& other) const { return Amount(value - other.value); }
};