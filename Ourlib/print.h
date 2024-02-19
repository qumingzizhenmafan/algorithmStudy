#include <type_traits>
#include <vector>
#include <iostream>

// 特征萃取，用于检查一个类型是否为 std::vector 的任意实例
template <typename T>
struct is_vector : std::false_type {};

template <typename T, typename A>
struct is_vector<std::vector<T, A>> : std::true_type {};

class Print{
    //单个数据的打印
    template<typename T>
    typename std::enable_if<!is_vector<T>::value>::type  //对于函数重载的禁用
    vals_print(const T& v) {
        std::cout << v;
    }
    public:
    //* 基本类型的打印
    template<typename T>
    void vals_print(const std::vector<T>& v){
        std::cout << "[";
        if(is_vector<T>::value){
            for(size_t i = 0; i < v.size(); ++i){
                vals_print(v[i]);
                if(i < v.size() - 1) std::cout << std::endl;
            }
        }
        else{
            for (size_t i = 0; i < v.size(); ++i){
                vals_print(v[i]);
                if (i < v.size() - 1) std::cout << " , ";
            }
        }
        std::cout << "]";
    }
};

int main(){
    std::vector<int> nums ={ 1,2,3,4,5,6,7,8,9,10,100 };
    //PrintContentOfvector<std::vector<int>, int> p; 
    //p.print(nums);
    Print p;
    if(is_vector<decltype(nums)>::value) std::cout << "i'm coming" << std::endl; 
    p.vals_print(nums);
}