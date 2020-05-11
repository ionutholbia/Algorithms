#include <iostream>
#include <functional>

class Tree {

public:
    Tree* left_;
    Tree* right_;
    int data_;

public:
    Tree(int data) : data_(data), left_(nullptr), right_(nullptr) {}
    
    void dispose() {
        traverse([](Tree* node) { 
            if(node->left_) delete node->left_; 
            if(node->right_) delete node->right_;
        });
    }

    void insert(int data) {
        if(data < data_) {
            if(left_ == nullptr) {
                left_ = new Tree(data);
            } else {
                left_->insert(data);
            }
        } else {
            if(right_ == nullptr) {
                right_ = new Tree(data);
            } else {
                right_->insert(data);
            }
        }
    }


    void print() {
        traverse([](Tree* node) { std::cout<<node->data_ << " "; });
    }

    void traverse(std::function<void (Tree*)> action) {
        if(left_ != nullptr) left_->print();
        action(this);
        if(right_ != nullptr) right_->print();
    }
};

int main(void) {
    Tree tree(3);
    tree.insert(5);
    tree.insert(15);
    tree.insert(10);
    tree.insert(7);
    tree.insert(8);
    tree.insert(1);
    tree.print();
    tree.dispose();
    return 0;
}