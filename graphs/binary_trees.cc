#include <iostream>
#include <vector>
#include <limits>

struct Node {
    Node(int x) : val_(x){
        left_ = nullptr;
        right_ = nullptr;
    }
    int val_;
    Node* left_;
    Node* right_;
};

class BinaryTree final {
public:
    BinaryTree() {
        root_ = nullptr;
    }
    void insertNode(int x);
    bool lookup(int x);
    int size();
    int maxDepth();
    int minValue();
    void printInOrder();
    void printPostOrder();
private:
    Node* insert(Node *root, int x);
    bool lookup(Node *root, int x);
    void size(Node *root, int &count);
    int maxDepth(Node *root);
    int minValue(Node *root);
    void printInOrder(Node *root);
    void printPostOrder(Node *root);
    Node *root_;
};

void BinaryTree::insertNode(int x){
    root_ = insert(root_, x);
}

Node* BinaryTree::insert(Node* root, int x){
    if(root  == nullptr){
        root = new Node(x);
        return root;
    }
    if(x < (root)->val_){
        (root)->left_ = insert((root)->left_, x);
    }
    else{
        (root)->right_ = insert((root)->right_, x);
    }
    return root;
}

bool BinaryTree::lookup(int v){
    return lookup(root_, v);
}

bool BinaryTree::lookup(Node* root, int v){
    if(root == nullptr)
        return false;
    if(root->val_ == v)
        return true;
    if(v < root->val_)
        return lookup(root->left_, v);
    return lookup(root->right_, v);
}

int BinaryTree::size(){
    int count = 0;
    size(root_, count);
    return count;
}

void BinaryTree::size(Node* root, int& count){
    if(root == nullptr)
        return;
    count++;
    size(root->left_, count);
    size(root->right_, count);
}

int BinaryTree::maxDepth(){
    return maxDepth(root_);
}

int BinaryTree::maxDepth(Node* root){
    if(root == nullptr)
        return 0;
    return 1 + std::max(maxDepth(root->left_), maxDepth(root->right_));
}

int BinaryTree::minValue(){
    return minValue(root_);
}

int BinaryTree::minValue(Node* root){
    if(root->left_ ==  nullptr)
        return root->val_;
    return minValue(root->left_);
}

void BinaryTree::printInOrder(){
    printInOrder(root_);
    std::cout << "\n";
}

void BinaryTree::printInOrder(Node* root){
    if(root == nullptr)
        return;
    printInOrder(root->left_);
    std::cout << root->val_ << ", ";
    printInOrder(root->right_);
}

void BinaryTree::printPostOrder(){
    printPostOrder(root_);
    std::cout << "\n";
}

void BinaryTree::printPostOrder(Node* root){
    if(root == nullptr)
        return;
    printInOrder(root->left_);
    printInOrder(root->right_);
    std::cout << root->val_ << ", ";
}

int main(){

    BinaryTree tree;
    tree.insertNode(2);
    tree.insertNode(1);
    tree.insertNode(5);
    tree.insertNode(4);
    tree.insertNode(7);

    std::cout << "Finding existing value 4 : " << tree.lookup(4) << std::endl;
    std::cout << "Finding non existing value 100 : " << tree.lookup(100)<< std::endl;
    std::cout << "Size: " << tree.size() << std::endl;
    std::cout << "MaxDepth: " << tree.maxDepth() << std::endl;
    std::cout << "MinValue: " << tree.minValue() << std::endl;
    tree.printInOrder();
    tree.printPostOrder();
    return 0;
}