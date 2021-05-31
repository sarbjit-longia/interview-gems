#include <iostream>
#include <vector>

template<typename T>
class Container {
public:
    Container(int size);
    T GetFirst();
    int size();

private:
    std::vector<T> data_;
};

template<typename T>
Container<T>::Container(int s){
    data_.resize(s);
}

template<typename T>
T Container<T>::GetFirst(){
    return data_[0];
}

template<typename T>
int Container<T>::size(){
    return data_.size();
}


int main() {
    Container<char> cc(10);
    std::cout << cc.GetFirst() << std::endl;
    return 0;
}