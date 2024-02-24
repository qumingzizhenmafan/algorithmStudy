#ifndef PRINT_H
#define PRINT_H

#include <type_traits>
#include <iostream>
#include <vector>

using index = std::vector<int>::size_type;

template<typename T>
struct is_vector : std::false_type {};

template<typename T>
struct is_vector<std::vector<T>> : std::true_type {};

// 一维数组打印
template<typename T>
typename std::enable_if<!is_vector<T>::value>::type
print(const std::vector<T>& v) {
    std::cout << "[";
    for (index i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) std::cout << v[i] << ", ";
        else std::cout << v[i];
    }
    std::cout << "]";
    std::cout << '\n';
}

// 二维数组打印
template<typename T>
typename std::enable_if<is_vector<T>::value>::type
print(const std::vector<T>& v) {
    for (const auto& subv : v) {
        std::cout << "[";
        for (index i = 0; i < subv.size(); i++) {
            if(i != subv.size() - 1) std::cout << subv[i] << ", ";
            else std::cout << subv[i];
        }
        std::cout << "]";
        std::cout << '\n';
    }
}


#endif // PRINT_DP_H
