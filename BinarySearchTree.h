//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    private:
        struct BTNode
        {
           BTNode* left;
           BTNode* right;
           string word;
           int num;
        };
        BTNode* root;
    
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
        void printinorder(int);
        void printinorder(int, string[]);
        void inorder(BTNode*, int);
        void inorder(BTNode*, int, string[]);
        void printpreorder(int);
        void printpreorder(int, string[]);
        void preorder(BTNode*, int);
        void preorder(BTNode*, int, string[]);
        void printpostorder(int);
        void printpostorder(int, string[]);
        void postorder(BTNode*, int);
        void postorder(BTNode*, int, string[]);
        void insert(string);
        void remove(string);
        bool contains(string);
        bool contains(string, BTNode*);
        int count (string);
        int count(string, BTNode*);
        int WordFrequency(string);
        int WordFrequency(string, int);
        int WordFrequency(string, int, string[]);
};
