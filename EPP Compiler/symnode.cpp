/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

//Write your code below this line

SymNode::SymNode(){
height = 0;
}

SymNode::SymNode(string k){
key = k;
height = 0;
}

SymNode* SymNode::LeftLeftRotation(){


	SymNode* p = par;
	SymNode* gp = par->par;

	if(gp == NULL){par = NULL;
	

	p->right = left;

    left = p;

    p->par = this;}

    else{if(par == gp->right){gp->right = this;}
    else{gp->left = this;}


    	par = par->par;
    
    p->right = left;

    left = p;

    p->par = this;
}


    return this;

}

SymNode* SymNode::RightRightRotation(){

	
	SymNode* p = par;
	SymNode* gp = par->par;

	if(gp == NULL){par = NULL;
	

	p->left = right;

    right = p;

    p->par = this;}

    else{if(par == gp->right){gp->right = this;}
    else{gp->left = this;}


    	par = par->par;
    
    p->left = right;

    right = p;

    p->par = this;
}


    return this;
}

SymNode* SymNode::LeftRightRotation(){

/*if(par->par != NULL){
left->par = par->par;}
else{
	left->par = NULL;
}
 par->par = left;
 par->right = left->left;
 
 SymNode* lt = left;
 left = left->right;
 lt->right = this;
 lt->left = par;

 par = lt;*/

SymNode* gp = par->par;

if(gp!=NULL){
if(par == gp->right){gp->right = left;}
    else{gp->left = left;}

}

SymNode* lt = left;

left = left->right;
par->right = lt->left;

	lt->right = this;
	lt->left = par;
	if(par->par != NULL){
lt->par = par->par;}
else{
	lt->par = NULL;
}

par->par = lt;
par = lt;



 return par;

}

SymNode* SymNode::RightLeftRotation(){
/*
if(par->par != NULL){
right->par = par->par;}
else{
	right->par = NULL;
}
 par->par = right;
 par->left = right->right;
 
 SymNode* rt = right;
 right = right->left;
 rt->left = this;
 rt->right = par;

 par = rt;*/

	SymNode* gp = par->par;

if(gp!=NULL){
if(par == gp->right){gp->right = right;}
    else{gp->left = right;}

}

	SymNode* lt = right;

right = right->left;
par->left = lt->right;

	lt->left = this;
	lt->right = par;
	if(par->par != NULL){
lt->par = par->par;}
else{
	lt->par = NULL;
}

par->par = lt;
par = lt;


  return par;

}

SymNode::~SymNode(){
/*
if(par != NULL){delete par; par = NULL;}
if(left != NULL){delete left; left = NULL;}
if(right != NULL){delete right; right = NULL;}
*/

}