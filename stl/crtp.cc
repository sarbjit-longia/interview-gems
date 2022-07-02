// Static polymorphism
#include <iostream>

template <typename type>
class Base {
public:
    void fn() {
        static_cast<type *>(this)->fn();
    }
};

class Derived : public Base<Derived>
{
private:
    /* data */
public:
   void fn() { std::cout << "Derived class" << std::endl; }
};

class Derived1 : public Base<Derived1>
{
private:
    /* data */
public:
   void fn() { std::cout << "Derived1 class" << std::endl; }
};

template<typename type>
void callfn(Base<type> bp){
    bp.fn();
}

int main(){

    Derived d1;
    Derived1 d2;
    callfn(d1);
    callfn(d2);
    typedef std::shared_ptr<int> IntSptr;
    auto iiPtr = IntSptr(new int(7));
    auto fptr = std::make_shared<int>(6);
    return 0;
}
