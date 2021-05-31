#include <iostream>


class Processor final{
public:
    static Processor& getInstance(){
        std::call_once(once_flag, &Processor::initSingleton);
        return *instance_;
    }

private:
    static void initSingleton(){
        instance_ = new Processor();
        std::cout << "Creating...\n";
    }
    static std::once_flag once_flag;
    static Processor *instance_;
};

Processor* Processor::instance_= nullptr;
std::once_flag Processor::once_flag;


int main(){
    std::cout << &Processor::getInstance() << std::endl;
    std::cout << &Processor::getInstance() << std::endl;
    return 0;
}