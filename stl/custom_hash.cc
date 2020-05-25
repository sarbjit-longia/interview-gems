#include <iostream>
#include <unordered_map>
#include <map>

class Student
{
  public:

    bool operator<(const Student& rhs)
    {
      return this->name < rhs.name;
    }

    long hash()
    {

      return 13;
    }


    std::string name;
    int marks;
};

struct Hasher
{
  long operator()(const Student& rhs)
  {
    return 0;
  }
};

namespace std
{
template<>
struct hash<Student>
{
  size_t operator()(const Student& s)
  {
    return hash<string>()(s.name);
  }
};
}

int main(int argc, char* argv[])
{
  std::map<Student, int> myMap;
  std::unordered_map<Student, int> myMap2;

  return 0;
}
