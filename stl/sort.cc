#include <iostream>
#include <vector>
#include <ctime>

struct Student{
    Student(int g) : grades(g){}
    int grades;

    bool operator<(const Student& rhs) const {
        return this->grades < rhs.grades;
    }
};

int main(){
    std::srand(time(nullptr));
    std::vector<Student> students;
    for (int i = 0; i < 10; i++) {
        students.push_back(Student(std::rand() % 100));
    }
    std::sort(students.begin(), students.end(), [](Student &a, Student &b)
              { return a.grades < b.grades; });

    std::sort(students.begin(), students.end());
    for (int i = 0; i < 10; i++)
    {
        std::cout << students[i].grades << std::endl;
    }
    return 0;
}