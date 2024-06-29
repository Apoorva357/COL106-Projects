/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"


    ExprTreeNode::ExprTreeNode(){
    	left = nullptr;
    	right = nullptr;
    }

    ExprTreeNode::ExprTreeNode(string t, UnlimitedInt* v){
    	type = t;

    	
    	int* d = new int[1];
    	d[0] = 1;
    	UnlimitedInt* ut1 = new UnlimitedInt(d,1,1,1);
    	UnlimitedRational* ans = new UnlimitedRational(v,ut1);
    	val = ans;

    	left = nullptr;
    	right = nullptr;



    }

    ExprTreeNode::ExprTreeNode(string t, UnlimitedRational* v){type = t;
    val = v;

}
    ExprTreeNode::~ExprTreeNode(){

       if(val != nullptr){delete val;val = nullptr;}
      
        if(evaluated_value != nullptr){delete evaluated_value;evaluated_value= nullptr;}
       
        

        
    }
