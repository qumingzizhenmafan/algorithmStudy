#include <cstddef>
#include <iostream>
#include <vector>

template<typename vT, typename T>
class PrintContentOfvector{
private:
    //* 打印单个元素
    void printElement(const T& elem){
        std::cout << elem;
    }

    //* 打印嵌套向量
    void printElement(const std::vector<T>& elem){
        print(elem);
    }

public:
    //* 向量类型的打印
    void print(const vT& v){
        std::cout << "[";

        for (size_t i = 0; i < v.size(); ++i){
            printElement(v[i]); 
            if (i < v.size() - 1) std::cout << ",";
        }
        std::cout << "]";
        
    }

    //* 基本类型的打印
    void print(const std::vector<T>& v){
        std::cout << "[";

        for (size_t i = 0; i < v.size(); ++i){
            printElement(v[i]); 
            if (i < v.size() - 1) std::cout << ",";
        }
        std::cout << "]";
    }

};