#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if(root == nullptr) return nullptr;
        
        Node* iter = root;
        while(iter != nullptr) {
            if(data < iter->data) {
                if(iter->left == nullptr) {
                    iter->left = new Node(data);
                    break;
                } else {
                    iter = iter->left;
                }
            } else {
                if(iter->right == nullptr) {
                    iter->right = new Node(data);
                    break;
                } else {
                    iter = iter->right;
                }
            }
        }

        return root;
    }

};

int main(void) {
    Solution solution;

    
    solution.insert(    )
    return 0;
}