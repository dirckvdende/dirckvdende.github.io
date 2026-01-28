
#pragma once

#include <algorithm>
#include <vector>
#include <random>

/**
 * Randomly shuffle a vector of elements in-place
 * @tparam T The type of the elements in the vector
 * @param v The vector to shuffle
 */
template<typename T>
void shuffle_vector(std::vector<T> &v) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
}