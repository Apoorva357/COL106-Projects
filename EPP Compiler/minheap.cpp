/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "minheap.h"

//Write your code below this line

int depthf(int size){
	if(size == 0){return 0;}
	if(size ==1){return -5;}


	int ans = 0;
	int check = 1;
	while(check <= size){check*=2;ans+=1;}

	if(check - size == 1){return -5;}

	return ans;


}

HeapNode* lastspot(HeapNode* node, int targetlevel, int currentlevel) {
        
          if(targetlevel == -5){
		while(node->right != NULL){node = node->right;}
		return node;
	}


        if (node == NULL) {
            if (currentlevel == targetlevel) {
                return NULL;  
            }
            return NULL;  
        }

        HeapNode* leftresult = lastspot(node->left, targetlevel, currentlevel + 1);
        HeapNode* rightresult = lastspot(node->right, targetlevel, currentlevel + 1);

        if (currentlevel == targetlevel) {
            return node; 
        }

         if (rightresult != NULL){
            return rightresult;
        } 
        else{
            return leftresult;
        }
    }

  HeapNode* freespot(HeapNode* node, int targetlevel, HeapNode* parent, int currentlevel) {
        
         if(targetlevel == -5){
		while(node->left != NULL){node = node->left;}
		return node;
	}

        if (node == NULL){
            if (currentlevel == targetlevel){
                return parent;}
             else{
                return NULL;  
            }
        }

        HeapNode* leftresult = freespot(node->left, targetlevel, node, currentlevel + 1);
        if (leftresult != NULL){
            return leftresult;  
        }

        return freespot(node->right, targetlevel, node, currentlevel + 1);  
    }


MinHeap::MinHeap(){

}

void MinHeap::push_heap(int num){

if(size == 0){root = new HeapNode(num);size++;return;}

// if(size == 1 ){if(root->left == NULL){root->left = new HeapNode(num);size++;root->left->par = root;
// return;}
// else{root->right = new HeapNode(num);size++;root->right->par = root;return;}
// }

else{
int dep = depthf(size);
HeapNode* ad = freespot(root,dep,NULL,1);

if(ad->left == NULL){ad->left = new HeapNode(num);
ad->left->par = ad;ad = ad->left;}

else{
	ad->right = new HeapNode(num);
ad->right->par = ad;ad = ad->right;
}

while(true){//cout<<ad->val<<endl;
	if(ad->par == NULL){break;}
	if(ad->par->val <= ad->val){break;}
	int c = ad->par->val;
	ad->par->val = ad->val;
	ad->val = c;
	ad = ad->par;
}

}


size++;
}

int MinHeap::get_min(){
	if(root!= NULL){
return root->val;}
}

void MinHeap::pop(){

	if(size ==0){return;}
if(size ==1 ){root = NULL;size--;return;}


int dep = depthf(size);
HeapNode* ls = lastspot(root,dep,1);

root->val = ls->val;

if(ls == ls->par->right){ls->par->right = NULL;}
else{ls->par->left = NULL;}

delete ls;
HeapNode* b = root;
while(true){

if(b->right == NULL && b->left == NULL){break;}
if(b->left == NULL){
	if(b->right->val < b->val){
int c = b->val;
	b->val = b->right->val;
	b->right->val = c;
	b = b->right;
}

else{break;}
}

else if(b->right == NULL){
	if(b->left->val < b->val){
int c = b->val;
	b->val = b->left->val;
	b->left->val = c;
	b = b->left;
}

else{break;}

}

else{
	if(b->right->val >= b->left->val){

		if(b->val > b->left->val){
		int c = b->val;
	b->val = b->left->val;
	b->left->val = c;
	b = b->left;}

	else{break;}
	}

	else{if(b->val > b->right->val){
		int c = b->val;
	b->val = b->right->val;
	b->right->val = c;
	b = b->right;
	}

	else{break;}
}
}

}

size--;
}

MinHeap::~MinHeap(){
	if(root!=NULL){
delete root;root = NULL;}
}