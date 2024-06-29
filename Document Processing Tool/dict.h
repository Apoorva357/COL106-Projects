// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Node{
public:

    char letter;
    int count;

    vector<Node*> children;

    Node(char let);

    ~Node();

};

class Dict {
private:
    // You can add attributes/helper functions here

    Node* root;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/

    void insert(string s);
};