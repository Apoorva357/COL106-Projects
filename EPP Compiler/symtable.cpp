/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

//Write your code below this line

//SEE HOW TO REMOVE MEM ADDRESS IN REMOVE
//SEE REMOVAL OF NON EXISTING NODES

int comparer(SymNode* a){
	int hl,hr;
   if(a->right == NULL){hr = -1;}
   else{hr = a->right->height;}

   if(a->left == NULL){hl = -1;}
   else{hl = a->left->height;}
a->height = max(hl+1,hr+1);
   int k = hl - hr;

   if(k >=1){return -1;}
   else if(k<=-1){return 1;}
   else{return 1;}

}

void hbalancer(SymNode* a){

 /*while(a!= NULL){
 	if(a->left == NULL && a->right == NULL){a->height = 0;a = a->par;}
 	else if(a->right == NULL && a->left != NULL){
 		if(c == 0){
       a = a->par;}

       else{int t = a->left->height;
       	if(t == 0){a = a->par;}
       	else{



       	}
       }
 	}

 	else if(a->left == NULL && a->right != NULL){

 	}
 }*/
if(a == NULL){return;}
int cm = comparer(a);

int hl,hr;
   if(a->right == NULL){hr = -1;}
   else{hr = a->right->height;}

   if(a->left == NULL){hl = -1;}
   else{hl = a->left->height;}

int c = hr-hl;

if(c== 0 || c==1 || c ==-1){hbalancer(a->par);}

else if(cm == 1){
	if(comparer(a->right) == 1){
SymNode* ct = a->right->LeftLeftRotation();
		
		ct->left->height = ct->height -1;
hbalancer(ct->par);
		}

		else{
			SymNode* ct = a->right->LeftRightRotation();
ct->height +=1;
		ct->left->height -=1;
		ct->right->height = ct->height -1;
		hbalancer(ct->par);
		}
}

else{
	if(comparer(a->left) == 1){
		SymNode* ct = a->left->RightLeftRotation();
ct->height +=1;
		ct->right->height -=1;
		ct->left->height = ct->height -1;
		hbalancer(ct->par);

	}

	else{

		SymNode* ct = a->left->RightRightRotation();

		ct->right->height = ct->height -1;
		hbalancer(ct->par);
	}
}



}

SymbolTable::SymbolTable(){
size = 0;
root = NULL;
}

void SymbolTable::insert(string k){
//cout<<"s01"<<endl;
	 if(root == NULL){//cout<<"s02"<<endl;
            SymNode* a = new SymNode(k);
            root = a;size++;return;}

            else{//cout<<"s03"<<endl;

        SymNode* b = root;
        


        while(true){

            if(k == b->key){return;}

            if(k > b->key){//cout<<"Hey"<<endl;
                if(b->right == NULL){
                SymNode* a = new SymNode(k);
                b->right = a;a->par = b;b = a;break;}

                else{b = b->right;}

            }

            else{
                if(b->left == NULL){
                SymNode* a = new SymNode(k);
                b->left = a;a->par = b;b=a;break;}

                else{b = b->left;}
            }
        }
        
        //cout<<"Hey"<<endl;
size++;
//cout<<root->key<<" "<<"up"<<endl;
int u,v;

while(b->par != NULL){

if(b== b->par->right){	u = 1;//cout<<"hi"<<endl;
//cout<<b->par->height<<endl;

if(b->par->left == NULL){int l = b->height;

if(l ==0){b->par->height = b->height + 1;b = b->par;v = 1;}

else{break;}

	}

else{

int l = b->height - b->par->left->height;

if(l == 1 || l == -1 || l == 0){b->par->height = max(b->height+1, b->par->height);b = b->par;v =1;}

else{break;}

}

}

else if(b== b->par->left){u = 0;

if(b->par->right == NULL){int l = b->height;

if(l ==0){b->par->height = b->height + 1;b = b->par;v = 0;}

else{break;}

	}

else{

int l = b->height - b->par->right->height;

if(l == 1 || l == -1 || l == 0){b->par->height = max(b->height+1, b->par->height);b = b->par;v = 0;}

else{break;}

}

}

}


if(b->par == NULL){return;}

else{

	if(u ==1 && v ==1){//cout<<"hi"<<endl;
		SymNode* ct = b->LeftLeftRotation();
		
		ct->left->height = ct->height -1;
		//b = ct;
// 		if(b->par == NULL){
// cout<<"nua"<<endl;}
		/*while(b->par != NULL){

if(b== b->par->right){

if(b->par->left == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;


}

}

else if(b== b->par->left){

if(b->par->right == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;



}

}

}*/



	}

	else if(u == 0 && v ==0){

		SymNode* ct = b->RightRightRotation();

		ct->right->height = ct->height -1;
		//b = ct;

		/*while(b->par != NULL){

if(b== b->par->right){

if(b->par->left == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;


}

}

else if(b== b->par->left){

if(b->par->right == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;



}

}

}*/

	}

	else if(u==1 && v ==0){
		//while(root->par != NULL){root = root->par;}
		
		//cout<<b->key<<endl;

		SymNode* ct = b->LeftRightRotation();
		//cout<<"hi"<<endl;
		//while(root->par != NULL){root = root->par;}
		//if(size == 5){
		//cout<<root->right->key<<endl;}
		//cout<<"hi after"<<endl;
		//while(root->par != NULL){root = root->par;}
		//cout<<root->right->right->key<<endl;
		ct->height +=1;
		ct->left->height -=1;
		ct->right->height = ct->height -1;
		b = ct;

	/*	while(b->par != NULL){//cout<<"1"<<endl;

if(b== b->par->right){

if(b->par->left == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;


}

}

else if(b== b->par->left){

if(b->par->right == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;



}

}

}*/



	}

	else{

		SymNode* ct = b->RightLeftRotation();
		//cout<<"hi2"<<endl;
		ct->height +=1;
		ct->right->height -=1;
		ct->left->height = ct->height -1;
		b = ct;

			/*	while(b->par != NULL){

if(b== b->par->right){

if(b->par->left == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;


}

}

else if(b== b->par->left){

if(b->par->right == NULL){

b->par->height = b->height + 1;b = b->par;



	}

else{



b->par->height = max(b->height+1, b->par->height);b = b->par;



}

}

}*/


	}

}
//cout<<"abcd"<<endl;
}

while(root->par != NULL){root = root->par;}

}



void SymbolTable::remove(string k){

	        
SymNode* b = root;
SymNode* parent;
parent = b;
int i = -1;
while(true){if(b == NULL){return;}
    if(b->key == k){break;}
    parent = b;
if(b->key < k){b = b->right;i=1;}
else{b = b->left;i=0;}

}

if(b->left == NULL && b->right == NULL){if(i == -1){
    delete b;root = NULL;size--; return;}

    else if(i == 1){SymNode* p = b->par;
    	
        delete b;
       
        size--;
        parent->right = NULL;
         hbalancer(p);
while(root->par!=NULL){root = root->par;}
        return;
      
    }

    else{SymNode* p = b->par;
    	
 delete b;

        size--;
        parent->left = NULL;

         hbalancer(p);

while(root->par!=NULL){root = root->par;}
        return;
       

    }
}
if(b->right != NULL && b->left != NULL){SymNode* c = b;
c = c->right;
SymNode* prc = b;

int cou = 1;
while(c->left != NULL){c = c->left;
if(cou == 1){prc = prc->right;cou++;}
else{prc = prc->left;}}

b->key = c->key;

b->address= c->address;

if(cou ==1){prc->right = NULL;delete c;hbalancer(prc);}
else{prc->left = NULL;delete c;hbalancer(prc);}
while(root->par!=NULL){root = root->par;}

size--;
return;
}

if(b->right == NULL){
if(parent == b){b = b->left;

    delete root;
root = b;
root->par = NULL;
size--;
return;}

else{

    if(i == 1){
    parent->right = b->left;
    
    delete b; 
    parent->right->par = parent;
    hbalancer(parent);
    while(root->par!=NULL){root = root->par;}
    size--;
    return;
}

else{
    parent->left = b->left;
    parent->left->par = parent;
    delete b; 
    hbalancer(parent);
    while(root->par!=NULL){root = root->par;}
    size--;
    return;
}

}

}

else{

if(parent == b){b = b->right;

    delete root;
root = b;
root->par = NULL;
size--;
return;}

else{

    if(i == 1){
    parent->right = b->right;
    parent->right->par = parent;
    delete b; 
    hbalancer(parent);
    while(root->par!=NULL){root = root->par;}
    size--;
    return;
}

else{
    parent->left = b->right;
   parent->left->par = parent;
    delete b; 
    hbalancer(parent);
    while(root->par!=NULL){root = root->par;}
    size--;
    return;
}

}

}




}


int SymbolTable::search(string k){
    //cout<<"s1"<<endl;
    // cout<<size<<endl;
     //cout<<root->key<<endl;
        SymNode* b = root;
        //cout<<"s2"<<endl;
while(true){if(b == NULL){break;}
// cout<<"s3"<<endl;
// cout<<k<<endl;
// cout<<b->key<<endl;
// cout<<"st"<<endl;
        if(b->key == k){break;}

        else if(b->key < k){
            b = b->right;
        }

        else{b = b->left;}


    }
  // cout<<"s4"<<endl;
         if(b == NULL){return -2;}
        else{

    return b->address;}

}

void SymbolTable::assign_address(string k,int idx){

	SymNode* b = root;
while(true){if(b == NULL){break;}
        if(b->key == k){break;}

        else if(b->key < k){
            b = b->right;
        }

        else{b = b->left;}


    }
   
   b->address = idx;

}

int SymbolTable::get_size(){
return size;
}

SymNode* SymbolTable::get_root(){

	return root;

}

SymbolTable::~SymbolTable(){
if(root!= NULL){delete root; root = NULL;}
}