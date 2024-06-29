// Do NOT add any other includes
#include "search.h"
  

SearchEngine::SearchEngine(){
    
}

SearchEngine::~SearchEngine(){}


 struct Sentence {
    int mybookcode;
    int mypage;
    int myparagraph;
    int mysentencenumber;
    string mysentence;
};
 
vector<Sentence> sentences;


void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
   
    Sentence newsentence ;
    newsentence.mybookcode = book_code;
    newsentence.mypage = page ;
    newsentence.myparagraph = paragraph;
    newsentence.mysentencenumber = sentence_no;
    newsentence.mysentence = sentence;

    sentences.push_back(newsentence);
  
}



string decap(string s){
    string d = s;
    int k = s.length();

    for(int i = 0;i<k;i++){
        if(int(s[i])<=90 && int(s[i] >=65)){int c = int(s[i])+32;d[i] = char(c);}
    }

    return d;
}





Node* SearchEngine::search(string pattern, int& n_matches){

    string k = decap(pattern);
    int n = pattern.length();
    vector<int> sus(n, 0);
    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j > 0 && k[i] != k[j]) {
            j = sus[j - 1];
           
        }
        if (k[i] == k[j]) {    
            j++;
        
        }
        sus[i] = j;
    }
    
        Node* head = NULL;
        Node* tail = NULL;
 
      int g = sentences.size();
     for (int i = 0; i < g; i++) {
      
        string text = sentences[i].mysentence;
        string jack = decap(text);
        
        int d = jack.length();
        int j = 0;  
            for (int x = 0; x <d; x++) {
                while (j > 0 && jack[x] != k[j]) {
                    j = sus[j - 1];
                }
                if (jack[x] == k[j]) {
                    j++;
                }
                 if (j == k.length()) {
                   
                    Node* ournode = new Node();
                    ournode->book_code = sentences[i].mybookcode;
                    ournode->page = sentences[i].mypage;
                    ournode->paragraph = sentences[i].myparagraph;
                    ournode->sentence_no = sentences[i].mysentencenumber;
                    ournode->offset = x - j + 1;



                    if (head == NULL) {
                        head = ournode;
                        tail = ournode;
                    } else {
                        ournode->left = tail;
                        tail->right = ournode;
                        tail = ournode;
                    }
                     j = sus[j - 1];
                    }
                    
                }
            }
                

   
        Node* current = head;
        for (Node* current = head; current != nullptr; current = current->right) {
           n_matches++;
        }
        return head;
        }



