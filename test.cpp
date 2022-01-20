#include <iostream>
#include <unordered_set>

template<class T> 
struct MyIter{
    typedef T value_type;
    T* ptr;
    MyIter(T* p = 0):ptr(p) {}
    T& operator*() const{return *ptr;}
};

template<class I>
typename I::value_type
func(I ite) {
    return *ite;
}

int main() {
    // MyIter<int> ite(new int(1));
    // std::cout<<func(ite)<<std::endl;
    std::unordered_set<int> us;
    us.insert(1);
    us.insert(1);
    for(auto i:us) {
        std::cout<<i<<std::endl;
    }

    return 0;
}