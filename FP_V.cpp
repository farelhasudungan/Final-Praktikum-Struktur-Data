/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 * 
 * Implementasi untuk Bahasa C++
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key, depth = 1;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    int findDepth(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return -1;
        
        if (temp->key == value)
            return temp->depth;
        else
            return -1;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        int depth = 1;
        if (!find(value)) {
            _root = __insert(_root, value, depth);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value, int newDepth) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->depth = newDepth;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value, int depth) {
        if (root == NULL)
            return __createNode(value, depth);
        
        if (value < root->key)
            root->left = __insert(root->left, value, ++depth);
        else if (value > root->key)
            root->right = __insert(root->right, value, ++depth);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int N;
    std::cin >> N;

    while(N--){
        std::string inputN;
        std::cin >> inputN;
        if(inputN == "INSERT"){
            int value;
            std::cin >> value;
            if(!set.find(value)) set.insert(value);
        } else if(inputN == "DELETE"){
            int value;
            std::cin >> value;
            if(set.find(value)) set.remove(value);
        } else if(inputN == "SEARCH"){
            int value;
            std::cin >> value;
            std::cout << set.findDepth(value) << std::endl;
        } else if(inputN == "PRINT"){
            if(!set.isEmpty()) set.traverseInorder();
            else std::cout << "EMPTY";
            std::cout << std::endl;
        }
    }

    return 0;
}