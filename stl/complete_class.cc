#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>


class Student final
{
  public:
    explicit Student(std::string name, std::string last, int marks); // constructor
    Student(const Student& rhs);        // Copy constructor
    Student(const Student&& rhs);       // Move constuctor

    Student& operator=(const Student& rhs);     // Assignment operator
    Student& operator=(const Student&& rhs);    // Move assignment operator

    bool operator==(const Student& rhs);        // Equality operator
    bool operator<(const Student& rhs);         // Comparison operator

    friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
//  private:
    std::string m_name;
    std::string m_lastName;
    int m_marks;
};

struct QueueMinHeapComp
{
  bool operator()(const Student& first, const Student& second)
  {
    return first.m_marks < second.m_marks;
  }
};

namespace std
{
  template<>
  struct hash<Student>
  {
    size_t operator()(const Student& s)
    {
      return hash<string>()(s.m_name);
    }
  };
}

Student::Student(std::string name, std::string last, int marks) : m_name(name), m_lastName(last), m_marks(marks)
{
  std::cout<<"Called constructor"<<std::endl;
}

Student::Student(const Student& rhs)
{
  std::cout<<"Called copy constructor"<<std::endl;
  this->m_name = rhs.m_name;
  this->m_lastName = rhs.m_lastName;
  this->m_marks = rhs.m_marks;
}

Student::Student(const Student&& rhs)
  :m_name(std::move(rhs.m_name)),
   m_lastName(std::move(rhs.m_lastName)),
   m_marks(std::move(rhs.m_marks))
{
  std::cout<<"Called move constructor"<<std::endl;
}

Student& Student::operator=(const Student& rhs)
{
  std::cout<<"Called assignment operator"<<std::endl;
  if(this == &rhs) return *this;

  this->m_name = rhs.m_name;
  this->m_lastName = rhs.m_lastName;
  this->m_marks = rhs.m_marks;
  return *this;
}

Student& Student::operator=(const Student&& rhs)
{
  std::cout<<"Called move assignment"<<std::endl;
  if(this != &rhs)
  {
    this->m_name = rhs.m_name;
    this->m_lastName = rhs.m_lastName;
    this->m_marks = rhs.m_marks;

    rhs.m_name = "n/a";
    rhs.m_lastName = "n/a";
    rhs.m_marks = -1;
  }
  return *this;
}

bool Student::operator==(const Student& rhs)
{
  return this->m_name == rhs.m_name && this->m_lastName == rhs.m_lastName && this->m_marks == rhs.m_marks;
}

bool Student::operator<(const Student& rhs)
{
  return this->m_name < rhs.m_name;

}

std::ostream& operator<<(std::ostream& os, const Student& rhs)
{
  os<<"Name: "<< rhs.m_name <<" "<< rhs.m_lastName<<", marks: " << rhs.m_marks<<std::endl;
  return os;
}


int main(int argc, char* argv[])
{
  Student s1("Sarbjit", "Singh", 99);
  std::cout<<s1;

  Student s2(s1);

  Student s3("", "", 0);
  s3 = s2;

  s3 = std::move(s2);
  Student s4(std::move(s3));

  std::cout<<s1;
  std::cout<<s2;
  std::cout<<s3;
  std::cout<<s4;

  return 0;
}
