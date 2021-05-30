#include <iostream>
#include <iterator>


/******************************************************************************
 * This class implements the basic dynamic array for integer type
 *
 * The design will reallocate the entire array to different memory location in
 * case its filled. User of the class shall use the optimal value for the
 * initial size to make optimum use of the container.
 *
 * ***************************************************************************/
#define INITIAL_ARRAY_SIZE 10

class DynamicArray final
{
public:
    explicit DynamicArray(size_t initial_size = INITIAL_ARRAY_SIZE);
    ~DynamicArray();

    /******************************************************************************
     * Pushes the value in the array. Reallocated in case the array is at capacity
     *
     * @param value: Value to insert
     *
     * Throws exception in case there is no more memory
     * ***************************************************************************/
    void push_back(int value);
    /******************************************************************************
     * Gets the value at particular location
     *
     * @param index: Index to insert
     *
     * returns: the value at index
     * Throws exception in case invalid index is specified
     * ***************************************************************************/
    int get_value(int index);
    int* data();
    void print(std::ostream& stream);
private:
    int*    data_;
    size_t  capacity_;
    size_t  size_;
};
/*****************************************************************************/
DynamicArray::DynamicArray(size_t initial_size)
        : capacity_(initial_size),
          size_(0)
{
    data_ = new int[initial_size];
}
/*****************************************************************************/
DynamicArray::~DynamicArray()
{
    delete[](data_);
}
/*****************************************************************************/
void DynamicArray::push_back(int value)
{
    if(size_ == capacity_)
    {
        // Reallocate the array to different memory location
        int* temp = new int[capacity_ * 2];
        std::copy(data_, data_ + size_, temp);
        delete[](data_);
        data_ = temp;
        capacity_ *= 2;
    }
    data_[size_++] = value;
}
/*****************************************************************************/
int DynamicArray::get_value(int index)
{
    if(index >= size_ || index < 0)
    {
        throw std::runtime_error("out of bounds error");
    }
    return data_[index];
}
/*****************************************************************************/
int* DynamicArray::data()
{
    return data_;
}
/*****************************************************************************/
void DynamicArray::print(std::ostream& stream)
{
    std::copy(data_, data_ + size_, std::ostream_iterator<int>(stream, ", "));
    stream << std::endl;
}
/*****************************************************************************/
// Test case for dynamic array
int test_dynamic_array()
{
    DynamicArray a(2);

    a.push_back(2);
    a.push_back(3);
    a.print(std::cout);

    for (int i = 0; i < 10; i++)
    {
        a.push_back(10);
    }
    a.print(std::cout);

    for (int i = 0; i < 20; i++){
        try{
            std::cout << i<<". "<<  a.get_value(i) << std::endl;
        }
        catch(...)
        {
            std::cout << "Exception.."<<std::endl;
        }
    }
    return 0;
}
/*****************************************************************************/