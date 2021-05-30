/*************************************
Requirements:

1. Complexity < N^2
2. Output sorted lexicographically
3. start and end codon are required for any encoding
4. Assume the file size is very large for processing


Design:

1. Need a container class to mimic map<string, string>
2. Need sorting logic, might be able to use sort in algorithm library
3. Need a file reader which can read the file and spit out characters.
   1. shall convert to uppercase
   2. shall remove all invalid characters
4. Need vector container to store the position of found stop codons.
5. write test cases for each class
**************************************/

#include <iostream>
#include <iterator>
#include <functional>
#include <string>
#include <fstream>
#include <memory>
#include <sstream>
#include <algorithm>

/******************************************************************************
 * This class implements the basic dynamic array
 *
 * The design will reallocate the entire array to different memory location in
 * case its filled. User of the class shall use the optimal value for the
 * initial size to make optimum use of the container.
 *
 * ***************************************************************************/
#define INITIAL_ARRAY_SIZE 10
//#define _DEBUG_

template<typename T>
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
    void push_back(T value);
    /******************************************************************************
     * Gets the value at particular location
     *
     * @param index: Index to insert
     *
     * returns: the value at index
     * Throws exception in case invalid index is specified
     * ***************************************************************************/
    T get_value(int index);
    size_t size();
    T *data();
    void print(std::ostream& stream);
private:
    T*      data_;
    size_t  capacity_;
    size_t  size_;
};
/*****************************************************************************/
template< typename T>
DynamicArray<T>::DynamicArray(size_t initial_size)
        : capacity_(initial_size),
          size_(0)
{
    data_ = new T[initial_size];
}
/*****************************************************************************/
template< typename T>
DynamicArray<T>::~DynamicArray()
{
    if(data_ != nullptr)
        delete[](data_);
    data_ = nullptr;
}
/*****************************************************************************/
template <typename T>
void DynamicArray<T>::push_back(T value)
{
    if(size_ == capacity_)
    {
        // Reallocate the array to different memory location
        T* temp = new T[capacity_ * 2];
        std::copy(data_, data_ + size_, temp);
        delete[](data_);
        data_ = temp;
        capacity_ *= 2;
    }
    data_[size_++] = value;
}
/*****************************************************************************/
template< typename T>
T DynamicArray<T>::get_value(int index)
{
    if(index >= size_ || index < 0)
    {
        throw std::runtime_error("out of bounds error");
    }
    return data_[index];
}
/*****************************************************************************/
template< typename T>
T* DynamicArray<T>::data()
{
    return data_;
}
/*****************************************************************************/
template< typename T>
size_t DynamicArray<T>::size()
{
    return size_;
}
/*****************************************************************************/
template< typename T>
void DynamicArray<T>::print(std::ostream& stream)
{
    std::copy(data_, data_ + size_, std::ostream_iterator<T>(stream, ", "));
    stream << std::endl;
}
/*****************************************************************************/
// Test case for dynamic array
int test_dynamic_array()
{
    DynamicArray<int> a(2);

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
/******************************************************************************
 * This class implements the basic key value pair
 *
 *
 * ***************************************************************************/
#define TABLE_MAX_SIZE 1007

template<typename KeyType, typename ValueType>
class KeyValuePair final
{
private:
    struct Node
    {
        Node() : next(nullptr) {}
        Node(KeyType k, ValueType v) : key(k), value(v), next(nullptr) {}

        KeyType key;
        ValueType value;
        Node* next;
    };
public:
    KeyValuePair();
    ~KeyValuePair();

    ValueType& operator[](const KeyType key);
    /******************************************************************************
     * Pushes the value in the array. Reallocated in case the array is at capacity
     *
     * @param value: Value to insert
     *
     * Throws exception in case there is no more memory
     * ***************************************************************************/
    void insert(KeyType key, ValueType value);

    /******************************************************************************
     * Gets the value at particular location
     *
     * @param index: Index to insert
     *
     * returns: the value at index
     * Throws exception in case invalid index is specified
     * ***************************************************************************/
    ValueType* find(KeyType key);
    DynamicArray<KeyType> keys();

private:
    void deleteNodes(Node *root);
    void insertNode(Node *root, Node *leaf);
    Node* findNode(KeyType k);
private:
    Node*    data_[TABLE_MAX_SIZE];
};
/*****************************************************************************/
template<typename KeyType, typename ValueType>
KeyValuePair<KeyType, ValueType>::KeyValuePair()
{
    for (int i = 0; i < TABLE_MAX_SIZE + 1; i++)
    {
        data_[i] = nullptr;
    }
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
KeyValuePair<KeyType, ValueType>::~KeyValuePair()
{
    // Delete all nodes
    for (int i = 0; i < TABLE_MAX_SIZE; i++)
    {
        if(data_[i] != nullptr)
        {
            deleteNodes(data_[i]);
        }
    }
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
void KeyValuePair<KeyType, ValueType>::deleteNodes(Node* root)
{
    while(root != nullptr)
    {
        auto temp = root->next;
        delete (root);
        root = temp;
    }
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
void KeyValuePair<KeyType, ValueType>::insertNode(Node* root, Node* leaf)
{
    while(root->next != nullptr) root = root->next;
    root->next = leaf;
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
typename KeyValuePair<KeyType, ValueType>::Node* KeyValuePair<KeyType, ValueType>::findNode(KeyType k)
{
    //TODO: Refactor into a function later
    // Find the hash value of the key
    std::hash<KeyType> hash_func;
    size_t hash_value = hash_func(k);
    // Find location in table using the module funciton
    size_t position = hash_value % TABLE_MAX_SIZE;
#ifdef _DEBUG_
        std::cout << "findNode - position using the hash: " << position << std::endl;
#endif
    auto root = data_[position];

    while(root != nullptr)
    {
        if(root->key == k)
            return root;
        root = root->next;
    }
#ifdef _DEBUG_
        std::cout << "findNode - Could not find key: " << k << std::endl;
#endif
    return nullptr;
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
void KeyValuePair<KeyType, ValueType>::insert(KeyType key, ValueType value)
{
    // Find the hash value of the key
    std::hash<KeyType> hash_func;
    size_t hash_value = hash_func(key);
    // Find location in table using the module funciton
    size_t position = hash_value % TABLE_MAX_SIZE;
#ifdef _DEBUG_
        std::cout << "insert - position using the hash: " << position << std::endl;
#endif

    if(data_[position] == nullptr)
    {
#ifdef _DEBUG_
        std::cout << "insert - Found empty slot without collision: " << position << std::endl;
#endif
        // Lucky, found the empty spot
        data_[position] = new Node(key, value);
    }
    else
    {
#ifdef _DEBUG_
        std::cout << "insert - Collision, inserting at end of link list: " << position << std::endl;
#endif
        // Insert into the linked list
        insertNode(data_[position], new Node(key, value));
    }
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
ValueType* KeyValuePair<KeyType, ValueType>::find(KeyType key)
{
    auto node = findNode(key);
    if(node == nullptr)
        return nullptr;

    return  &node->value;
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
DynamicArray<KeyType> KeyValuePair<KeyType, ValueType>::keys()
{
    DynamicArray<KeyType> result;

    for (int i = 0; i < TABLE_MAX_SIZE; i++)
    {
        if(data_[i] != nullptr)
        {
            auto root = data_[i];
            while(root != nullptr)
            {
                result.push_back(root->key);
                root = root->next;
            }
        }
    }
    return result;
}
/*****************************************************************************/
template<typename KeyType, typename ValueType>
ValueType&KeyValuePair<KeyType, ValueType>::operator[](const KeyType key)
{
    auto node = findNode(key);
    if(node == nullptr)
    {
#ifdef _DEBUG_
        std::cout << "operator[] - Key not found so adding it now... "<<std::endl;
#endif
        ValueType value;
        insert(key, value);
        node = findNode(key);
    }
    return node->value;
}
/*****************************************************************************/
// Test case for dynamic array
int test_map()
{
    KeyValuePair<std::string, DynamicArray<std::string> > m;

    m["ABC"].push_back("ABCD");
    m["ABC"].push_back("XYZA");

    auto res = m.find("ABC");
    res->print(std::cout);
    return 0;
}
/*****************************************************************************/
class FileReader
{
public:
    FileReader(std::string filePath);
    std::string getNextCodon(bool find_start);

private:
    std::shared_ptr<std::ifstream> stream_;
};
/*****************************************************************************/
FileReader::FileReader(std::string filepath)
{
    auto ptr = new std::ifstream(filepath, std::ios::in);
    stream_ = std::shared_ptr<std::ifstream>(ptr);
}
/*****************************************************************************/
std::string FileReader::getNextCodon(bool find_start)
{
    static const int CODON_SIZE = 3;
    std::stringstream ss;
    //TODO: Duplicated code here will fix and refactor
    if(find_start == false)
    {
        int count = 0;
        while(count < CODON_SIZE)
        {
            char ch;
            if(!stream_->get(ch))
                return std::string();

            ch = ::toupper(ch);
            if(ch == 'G' || ch == 'A' || ch == 'T' || ch == 'C')
            {
                ss << ch;
                count++;
            }
        }
    }
    else
    {
        // Read until we find "ATG"
        auto temp = ss.str();
        while(temp.find("ATG") == std::string::npos)
        {
            char ch;
            if(!stream_->get(ch))
                return std::string();

            ch = ::toupper(ch);
            if(ch == 'G' || ch == 'A' || ch == 'T' || ch == 'C')
            {
                ss << ch;
            }
            temp = ss.str();
        }
        return "ATG";
    }

    return ss.str();
}
/*****************************************************************************/
class Processor final
{
public:
    Processor(std::string filepath);
    void run();

private:
    void getAllProteins();
    void printProteins();
    void createAminoAcidMap();

private:
    std::shared_ptr<FileReader> reader_;
    KeyValuePair < std::string, KeyValuePair <std::string, int> > result_;
    KeyValuePair < std::string, std::string>  amino_map_;
};
/*****************************************************************************/
Processor::Processor(std::string filepath)
{
    reader_ = std::make_shared<FileReader>(filepath);
    createAminoAcidMap();
}
/*****************************************************************************/
void Processor::createAminoAcidMap()
{
    amino_map_["ATT"] = "I";
    amino_map_["ATC"] = "I";
    amino_map_["ATA"] = "I";

    amino_map_["CTT"] = "L";
    amino_map_["CTC"] = "L";
    amino_map_["CTA"] = "L";
    amino_map_["CTG"] = "L";
    amino_map_["TTA"] = "L";
    amino_map_["TTG"] = "L";

    amino_map_["GTT"] = "V";
    amino_map_["GTC"] = "V";
    amino_map_["GTA"] = "V";
    amino_map_["GTG"] = "V";

    amino_map_["TTT"] = "F";
    amino_map_["TTC"] = "F";

    amino_map_["ATG"] = "M";

    amino_map_["TGT"] = "C";
    amino_map_["TGC"] = "C";

    amino_map_["GCT"] = "A";
    amino_map_["GCC"] = "A";
    amino_map_["GCA"] = "A";
    amino_map_["GCG"] = "A";

    amino_map_["GGT"] = "G";
    amino_map_["GGC"] = "G";
    amino_map_["GGA"] = "G";
    amino_map_["GGG"] = "G";

    amino_map_["CCT"] = "P";
    amino_map_["CCC"] = "P";
    amino_map_["CCA"] = "P";
    amino_map_["CCG"] = "P";

    amino_map_["ACT"] = "T";
    amino_map_["ACC"] = "T";
    amino_map_["ACA"] = "T";
    amino_map_["ACG"] = "T";

    amino_map_["TCT"] = "S";
    amino_map_["TCC"] = "S";
    amino_map_["TCA"] = "S";
    amino_map_["TCG"] = "S";
    amino_map_["AGT"] = "S";
    amino_map_["AGC"] = "S";

    amino_map_["TAT"] = "Y";
    amino_map_["TAC"] = "Y";

    amino_map_["TGG"] = "W";

    amino_map_["CAA"] = "Q";
    amino_map_["CAG"] = "Q";

    amino_map_["AAT"] = "N";
    amino_map_["AAC"] = "N";

    amino_map_["CAT"] = "H";
    amino_map_["CAC"] = "H";

    amino_map_["GAA"] = "E";
    amino_map_["GAG"] = "E";

    amino_map_["GAT"] = "D";
    amino_map_["GAC"] = "D";

    amino_map_["AAA"] = "K";
    amino_map_["AAG"] = "K";

    amino_map_["CGT"] = "R";
    amino_map_["CGC"] = "R";
    amino_map_["CGA"] = "R";
    amino_map_["CGG"] = "R";
    amino_map_["AGA"] = "R";
    amino_map_["AGG"] = "R";
}
/*****************************************************************************/
void Processor::run()
{
    getAllProteins();
    printProteins();
}
/*****************************************************************************/
void Processor::getAllProteins()
{
    auto codon = reader_->getNextCodon(true);
    if(codon.length() == 0)
        return;


    bool started = true;

    while(codon.length() > 0)
    {
        std::stringstream geneSeq;
        std::stringstream proteinSeq;
        geneSeq << codon;

        codon = reader_->getNextCodon(false);
        while(codon.length() > 0)
        {
            geneSeq << codon;
            if (codon == "TAA" || codon == "TAG" || codon == "TGA") // stop codon
            {
                auto protein = proteinSeq.str();

                KeyValuePair<std::string, int>* entry = result_.find(protein);
                if(entry != nullptr)
                {
                    int* count = entry->find(geneSeq.str());
                    if(count != nullptr)
                    {
                        (*count)++;
                    }
                    else
                    {
                        entry->insert(geneSeq.str(), 1);
                    }
                }
                else
                {
                    result_[protein][geneSeq.str()]  = 1;
                }
                break;
            }
            else
            {
                std::string* protein = amino_map_.find(codon);
                proteinSeq << *protein;
            }
            codon = reader_->getNextCodon(false);
        }
        codon = reader_->getNextCodon(true);
    }
}
/*****************************************************************************/
void Processor::printProteins()
{
    auto keys = result_.keys();

    // Create local array and sort
    std::string *temp = new std::string[keys.size()];
    for (int i = 0; i < keys.size(); i++)
    {
        temp[i] = keys.get_value(i);
    }
    std::sort(temp, temp + keys.size());


    for (int i = 0; i < keys.size(); i++)
    {

        std::cout << temp[i] << std::endl;
        KeyValuePair<std::string, int>* sequences = result_.find(temp[i]);

        auto sub_keys = sequences->keys();

        std::string *sub_keys_temp = new std::string[sub_keys.size()];
        for (int k = 0; k < sub_keys.size(); k++)
        {
            sub_keys_temp[k] = sub_keys.get_value(k);
        }
        std::sort(sub_keys_temp, sub_keys_temp + sub_keys.size());

        for (int j = 0; j < sub_keys.size(); j++)
        {
            int* value = sequences->find(sub_keys_temp[j]);

            std::cout << "  " << sub_keys_temp[j] << " "<< *value << std::endl;
        }
    }
    delete[](temp);
}
/*****************************************************************************/
int main(int argc, char* argv[])
{
    std::string filepath(argv[1]);
    Processor p(filepath);
    p.run();
    return 0;
}
/*****************************************************************************/