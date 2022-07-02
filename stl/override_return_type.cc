#include <iostream>
#include <string>

using namespace std;

class from_string {
public:
    from_string(unsigned char* d) : data_(d) {}

    template<typename type>
    operator type() {
        if constexpr(std::is_same_v<type, float>)
            return std::stod(std::string(data_));
        else if(std::is_same_v<type, int>)
            return std::stoi(std::string(data_));
    }

private:
    unsigned char *data_;
};


int main(int argc, char* argvp[]) {

    std::cout << from_string((unsigned char*)"123") << std::endl;
    std::cout << from_string((unsigned char*)"123.78") << std::endl;
    return 0;
}