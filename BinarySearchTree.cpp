//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

//@WordFreq requires badwords.txt to be in the same directory as this file
//@pre a html file must b in the corect directory
//@post creates a BST of the words in html file
//@param ofstream file - file to be parsed
//@param min_freq_num - number that wods must appear in order to be printed
//@param string words - words to be discluded from the BST
//@returns prints out an inorder traversal of the BST
//@usage WordFreqtestfile.html
int BinarySearchTree::WordFrequency(string file)
{
    int min = 0;
    string word;
    string line;
    ifstream myfile;
    ifstream nextfile;
    myfile.open(file.c_str());
    nextfile.open("badwords.txt");
    //if(myfile.isopen()) cout << "YAY";
    string s ( std::istreambuf_iterator<char>( myfile ),
(std::istreambuf_iterator<char>()) );
    string delimiters = " <>""/\n,._:=!?";
    string limiters = " \f\n\r\t\v";
    int startpos=0;
    int endpos=0;
    endpos = s.find_first_of(delimiters, startpos);
    while (endpos != -1)
    {       
        startpos = endpos+1; //jump past sep
        endpos = s.find_first_of(delimiters, startpos); // find next
        word = s.substr( startpos, endpos - startpos );
        insert(word);
    }
    myfile.close();
    return 0;
}

int BinarySearchTree::WordFrequency(string file, int min_freq_num)
{
    int min = min_freq_num;
    string word;
    string line;
    ifstream myfile;
    ifstream nextfile;
    myfile.open(file.c_str());
    nextfile.open("badwords.txt");
    string s;
     while (!myfile.eof()) 
     {
           getline(myfile, line);
           s.append(line);
     }
    string delimiters = " <>""/\n,._:=!?\n";
    string limiters = " \f\n\r\t\v";
    int startpos=0;
    int endpos=0;
    endpos = s.find_first_of(delimiters, startpos);
    while (endpos != -1)
    {       
        startpos = endpos+1; //jump past sep
        endpos = s.find_first_of(delimiters, startpos); // find next
        word = s.substr( startpos, endpos - startpos );
        insert(word);
    }
    myfile.close();
    return 0;
}

int BinarySearchTree::WordFrequency(string file, int min_freq_num, string words[])
{
    int min = min_freq_num;
    string word;
    string line;
    ifstream myfile;
    ifstream nextfile;
    myfile.open(file.c_str());
    nextfile.open("badwords.txt");
    string s ( std::istreambuf_iterator<char>( myfile ),
(std::istreambuf_iterator<char>()) );
    string delimiters = " <>""/\n,._:=!?";
    string limiters = " \f\n\r\t\v";
    int startpos=0;
    int endpos=0;
    endpos = s.find_first_of(delimiters, startpos);
    while (endpos != -1)
    {       
        startpos = endpos+1; //jump past sep
        endpos = s.find_first_of(delimiters, startpos); // find next
        word = s.substr( startpos, endpos - startpos );
        /*for(int x = 0;x<sizeof(words);x++)
        {
            if(word != words[x]) insert(word);
            else;
        }*/
        insert(word);
    }
    myfile.close();
    return 0;
}

//@insert: inserts new words into tree or increases count if already in tree
//@param word
//@ wordTree.insert("banana")
void BinarySearchTree::insert(string newword)
{
    BTNode* t = new BTNode;
    BTNode* curr = new BTNode;
    BTNode* parent;
    string oldword;
    t->word = newword;
    t->left = NULL;
    t->right = NULL;
    t->num = 0;
    parent = NULL;
    
    // is tree empty?
    if(isEmpty()) root = t;
    // already contains word?
    else
    {
        BTNode* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t->word > curr->word) curr = curr->right;
            else curr = curr->left;
        }
        if(t->word == parent->word)
        {
           parent->num += 1;
        }
        else if(t->word < parent->word)
        {
           parent->left = t;
           parent->left->num = 1;
        }
        else
        {
           parent->right = t;
           parent->right->num = 1;
        }
    }
}

int BinarySearchTree::count(string word)
{
     BTNode* curr = new BTNode;
     curr = root;
     if(curr == NULL) return 0;
     while(curr != NULL)
     {
         
         if(curr->word == word)  
         {
             int num;
             num = curr->num;
             curr = NULL;
             return num;
         }
         else
         {
             if(contains(word, curr->right) == true) curr = curr->right;
             else if(contains(word, curr->left) == true) curr = curr->left;
             else return 0;
         }
     }
}

int BinarySearchTree::count(string word, BTNode* node)
{
     BTNode* curr = new BTNode;
     curr = node;
     if(contains(word, curr->right) == true) 
     {
         return count(word, curr->right);
     }
     else if(contains(word, curr->left) == true)
     {
          return count(word, curr->left);
     }
     else return 0;

}
     

//@ Prints the items in the called BST inorder
//@ tree.printinorder();
void BinarySearchTree::printinorder(int min)
{
  inorder(root, min);
}

void BinarySearchTree::printinorder(int min, string words[])
{
  inorder(root, min, words);
}

void BinarySearchTree::inorder(BTNode* p, int min)
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    if(p != NULL)
    {
        if(p->left) inorder(p->left, min);
        if((p->num >= min) && !bad.contains(p->word)) cout << p->word << "   " << p->num << "\n";
        if(p->right) inorder(p->right, min);
    }
    else return;
}


void BinarySearchTree::inorder(BTNode* p, int min, string words[])
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    int i;
    for(i = 0; i < 2; i++)
    {
        string badword = words[i];
        bad.insert(badword);
        cout << words[i] << "\n";
        i++;
    }
    bad.insert("would");
    if(p != NULL)
    {
        if(p->left) inorder(p->left, min);
        if((p->num >= min) && !bad.contains(p->word)) cout << p->word << "   " << p->num << "\n";
        if(p->right) inorder(p->right, min);
    }
    else return;
}

//@ Prints the items in the called BST preorder
//@ tree.printpreorder();
void BinarySearchTree::printpreorder(int min)
{
    preorder(root, min);
}

void BinarySearchTree::preorder(BTNode* p, int min)
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    if(p != NULL)
    {
        if((p->num >= min) && !bad.contains(p->word)) 
        cout << p->word << "   " << p->num << "\n";
        if(p->left) preorder(p->left, min);
        if(p->right) preorder(p->right, min);
    }
    else return;
}

void BinarySearchTree::preorder(BTNode* p, int min, string words[])
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    for(int i=0; 100; 1)
    {
        bad.insert(words[i]);
    }
    if(p != NULL)
    {
        if((p->num >= min) && !bad.contains(p->word)) 
        cout << p->word << "   " << p->num << "\n";
        if(p->left) preorder(p->left, min);
        if(p->right) preorder(p->right, min);
    }
    else return;
}

//@ Prints the items in the called BST inorder
//@ tree.printpostorder();
void BinarySearchTree::printpostorder(int min)
{
    postorder(root, min);
}

void BinarySearchTree::postorder(BTNode* p, int min)
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    if(p != NULL)
    {
        if(p->left) postorder(p->left, min);
        if(p->right) postorder(p->right, min);
        if((p->num >= min) && !bad.contains(p->word)) 
        cout << p->word << "   " << p->num << "\n";
    }
    else return;
}

void BinarySearchTree::postorder(BTNode* p, int min, string words[])
{
    BinarySearchTree bad;
    string word;
    string line;
    ifstream myfile;
    myfile.open("badwords.txt");
    if (!myfile.eof())
    {
       while ( myfile.good() )
       {
           getline(myfile, word);
           bad.insert(word);   
       }
    }
    for(int i=0; 100; 1)
    {
        bad.insert(words[i]);
    }
    if(p != NULL)
    {
        if(p->left) postorder(p->left, min);
        if(p->right) postorder(p->right, min);
        if((p->num >= min) && !bad.contains(p->word)) 
        cout << p->word << "   " << p->num << "\n";
    }
    else return;
}

bool BinarySearchTree::contains(string word, BTNode* node)
{
     if(node == NULL) return false;
     else if(node->word == word) return true;
     else
     {
         if(contains(word, node->right) == true)
         {
              return true;
         }
         else if(contains(word, node->left) == true)
         {
              return true;
         }
         else 
              return false;
     }
}

bool BinarySearchTree::contains(string word)
{
     BTNode* curr = new BTNode;
     curr = root;
     if(curr == NULL) return false;
     else if(curr->word == word) return true;
     else
     {
         if(contains(word, curr->right) == true) return true;
         else if(contains(word, curr->left) == true) return true;
         return false;
     }
}

void BinarySearchTree::remove(string word)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    
    BTNode* curr;
    BTNode* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->word == word)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(word>curr->word) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Word not found! "<<endl;
        return;
    }


		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        BTNode* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                BTNode* lcurr;
                BTNode* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->word = lcurr->word;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               BTNode* tmp;
               tmp = curr->right;
               curr->word = tmp->word;
	       curr->right = tmp->right;
               delete tmp;
           }
        }
		 return;
    }

}

     
     
     
