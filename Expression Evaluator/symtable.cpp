/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

//FINISH REMOVE

    SymbolTable::SymbolTable(){
    	size = 0;
    	root = nullptr;


    }

    SymbolTable::~SymbolTable(){
        if(root != nullptr){delete root;root = nullptr;}

    }

    // Insert a key value pair in the symbol table
    void SymbolTable::insert(string k, UnlimitedRational* v){
//cout<<"Hey"<<endl;
        if(root == nullptr){//cout<<"Hey"<<endl;
            SymEntry* a = new SymEntry(k,v);
            root = a;}

            else{

        SymEntry* b = root;
        


        while(true){

            if(k == b->key){delete b->val;b->val = v;size--;break;}

            if(k > b->key){//cout<<"Hey"<<endl;
                if(b->right == nullptr){
                SymEntry* a = new SymEntry(k,v);
                b->right = a;break;}

                else{b = b->right;}

            }

            else{
                if(b->left == nullptr){
                SymEntry* a = new SymEntry(k,v);
                b->left = a;break;}

                else{b = b->left;}
            }
        }
        }
        //cout<<"Hey"<<endl;
size++;
    }

    // Remove a key (and value) in the symbol table
    void SymbolTable::remove(string k){
        if(root == nullptr){return;}
SymEntry* b = root;
SymEntry* parent;
parent = b;
int i = -1;
while(true){if(b == nullptr){return;}
    if(b->key == k){break;}
    parent = b;
if(b->key < k){b = b->right;i=1;}
else{b = b->left;i=0;}

}

if(b->left == nullptr && b->right == nullptr){if(i == -1){
    delete b;root = nullptr;size--;return;}

    else if(i == 1){
        delete b;
        size--;
        parent->right = nullptr;
        return;
    }

    else{
 delete b;
        size--;
        parent->left = nullptr;
        return;

    }
}
if(b->right != nullptr && b->left != nullptr){SymEntry* c = b;
c = c->right;
SymEntry* prc = b;

int cou = 1;
while(c->left != nullptr){c = c->left;
if(cou == 1){prc = prc->right;cou++;}
else{prc = prc->left;}}

b->key = c->key;
UnlimitedInt* p1 = c->val->get_p();
string str = p1->to_string();
UnlimitedInt* pf = new UnlimitedInt(str);

UnlimitedInt* q1 = c->val->get_q();
string str1 = q1->to_string();
UnlimitedInt* qf = new UnlimitedInt(str1);

UnlimitedRational* ans = new UnlimitedRational(pf,qf);
b->val= ans;

if(cou ==1){prc->right = nullptr;}
else{prc->left = nullptr;}

delete c;
size--;
return;
}

if(b->right == nullptr){
if(parent == b){b = b->left;
    delete root;
root = b;
size--;
return;}

else{

    if(i == 1){
    parent->right = b->left;
    delete b; 
    size--;
    return;
}

else{
    parent->left = b->left;
    delete b; 
    size--;
    return;
}

}

}

else{

if(parent == b){b = b->right;
    delete root;
root = b;
size--;
return;}

else{

    if(i == 1){
    parent->right = b->right;
    delete b; 
    size--;
    return;
}

else{
    parent->left = b->right;
    delete b; 
    size--;
    return;
}

}

}

    }

    // Find the val corresponding to the key in the symbol table
    UnlimitedRational* SymbolTable::search(string k){//cout<<"Hi"<<endl;
        if(root == nullptr){}
else{
        SymEntry* b = root;
while(true){if(b == nullptr){break;}
        if(b->key == k){break;}

        else if(b->key < k){
            b = b->right;
        }

        else{b = b->left;}


    }
    if(b == nullptr){}
        else{

    return b->val;}
}
    }

    // Get size
    int SymbolTable::get_size(){
        return size;
    }

    // Get root 
    SymEntry* SymbolTable::get_root(){
        return root;
    }