/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"

UnlimitedRational* eval_node(ExprTreeNode* node, SymbolTable* symtable){
   string t = node->type;
//cout<<"YES"<<endl;
   if(t =="VAL"){//cout<<"HI"<<endl;
      /*int* d = new int[1];
      d[0] = 1;
      UnlimitedInt* ut1 = new UnlimitedInt(d,1,1,1);
      UnlimitedRational* ans = new UnlimitedRational(v,ut1);
      node->val = ans;*/
      node->evaluated_value = node->val;
      return node->evaluated_value;}

      else if(t == "ADD"){//cout<<"HI"<<endl;
         node->evaluated_value = UnlimitedRational::add(eval_node(node->left,symtable),eval_node(node->right,symtable));
      return node->evaluated_value;}

      else if(t == "SUB"){
         node->evaluated_value = UnlimitedRational::sub(eval_node(node->left,symtable),eval_node(node->right,symtable));
      return node->evaluated_value;}

      else if(t == "MUL"){
         node->evaluated_value = UnlimitedRational::mul(eval_node(node->left,symtable),eval_node(node->right,symtable));
      return node->evaluated_value;}

      else if(t == "DIV"){
         node->evaluated_value = UnlimitedRational::div(eval_node(node->left,symtable),eval_node(node->right,symtable));
      return node->evaluated_value;}

     // else if(t == "MOD"){
     //    node->evaluated_value = UnlimitedRational::mod(eval_node(node->right,symtable),eval_node(node->left,symtable));
     // }

      else{
         node->evaluated_value = symtable->SymbolTable::search(node->id);
      return node->evaluated_value;}

}


 Evaluator::Evaluator(){symtable = new SymbolTable();
 }

    Evaluator::~Evaluator(){
      
     
      if(symtable != nullptr){delete symtable;symtable = nullptr;}
      
    }

    // Read an input vector of tokens (strings)
    // Parse it and convert it to a parse tree
    // Push the root of the tree in the expr_trees
  /*  void Evaluator::parse(vector<string> code){
      int k = code.size();
      for(int i =0;i<k;i++){
         int s = code[i].size();
         ExprTreeNode* root = new ExprTreeNode();
         root->id = code[i][1];

         root->type = "VAR";

         ExprTreeNode* lef = new ExprTreeNode();
         lef->type = "VAL";
         lef->id = code[i][0];
         root->left = lef;

         ExprTreeNode* exroot = new ExprTreeNode();
         ExprTreeNode* ind = exroot;
         

         vector<ExprTreeNode*> parent_holder;

         for(int j=3;j<s;j++){

            if(code[i][j] == '('){
               ExprTreeNode* temp = new ExprTreeNode();
               ind->left = temp;
               parent_holder.push_back(ind);
            
               ind = temp;
            }

            else if(code[i][j] == '+' || code[i][j] == '-' || code[i][j] == '*' || code[i][j] == '/' || code[i][j] == '%'){
               int ps = parent_holder.size();
               ind = parent_holder[ps-1];
               parent_holder.pop_back();

               if(code[i][j] == '+'){ind->type = "ADD";}
               if(code[i][j] == '-'){ind->type = "SUB";}
               if(code[i][j] == '*'){ind->type = "MUL";}
               if(code[i][j] == '/'){ind->type = "DIV";}
               //if(code[i][j] == '%'){ind->type = "MOD";}

               ExprTreeNode* temp = new ExprTreeNode();
               ind->right = temp;
               parent_holder.push_back(ind);
            
               ind = temp;


            }

            else if(code[i][j] == ')'){

               int ps = parent_holder.size();
               ind = parent_holder[ps-1];
               parent_holder.pop_back();

            }

            else{

               string number;
               while(code[i][j] == '0' || code[i][j] == '1' || code[i][j] == '2' || code[i][j] == '3' || code[i][j] == '4' || code[i][j] == '5' || code[i][j] == '6' || code[i][j] == '7' ||code[i][j] == '8' || code[i][j] == '9')
               {number.push_back(code[i][j]);
                  j++;
               }
               j--;
               ind->type = "VAL";
               int* d = new int[1];
      d[0] = 1;
      UnlimitedInt* ut1 = new UnlimitedInt(d,1,1,1);
      UnlimitedInt* v = new UnlimitedInt(number);
      UnlimitedRational* ans = new UnlimitedRational(v,ut1);
      ind->val = ans;

      int ps = parent_holder.size();
               ind = parent_holder[ps-1];
               parent_holder.pop_back();


            }

         }
      }
    }*/

    ExprTreeNode* prec(string s){

      int l = s.length();

      if(s[0] != '('){

         if(int(s[0]) < 48 || int(s[0]) > 57){
string name; 
            /*while(s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
            {name.push_back(s[i]);
         i++;

            }
*/
for(int i = 0;i<l;i++){name.push_back(s[i]);}

   ExprTreeNode* ans = new ExprTreeNode();
ans->id = name;
ans->type = "VAR";

return ans;

         }

         else{string number; 
for(int i = 0;i<l;i++){number.push_back(s[i]);}
//cout<<"HI"<<endl;
//cout<<number<<endl;
   UnlimitedInt* ut1 = new UnlimitedInt("1");
//cout<<ut1->UnlimitedInt::to_string()<<endl;
      UnlimitedInt* v = new UnlimitedInt(number);
      //UnlimitedInt* gc = gcd(v,ut1);
     // UnlimitedRational* obj;
      //obj->UnlimitedRational::gcd(v,ut1);
      UnlimitedRational* ans1 = new UnlimitedRational(v,ut1);
      delete ut1;
      delete v;
      ExprTreeNode* ans = new ExprTreeNode();
//cout<<gc->UnlimitedInt::to_string()<<endl;

ans->type = "VAL";
      ans->val = ans1;

      return ans;

         }

      }

      else{

         int counter = 0;
         int i = 0;

        for(i =0;i<l;i++){

            if(counter ==1){
               if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){

               break;}
            }

            if(s[i] == '('){counter++;}
            if(s[i] == ')'){counter--;}
           

         }
//cout<<"Hi";
         string ls;
         string rs;

         for(int j =1;j<i;j++){ls.push_back(s[j]);}
         for(int j = i+1;j<l-1;j++){rs.push_back(s[j]);}

            ExprTreeNode* ans = new ExprTreeNode();
         if(s[i] == '+'){ans->type = "ADD";}
         if(s[i] == '-'){ans->type = "SUB";}
         if(s[i] == '*'){ans->type = "MUL";}
         if(s[i] == '/'){ans->type = "DIV";}

ans->left = prec(ls);
ans->right = prec(rs);

return ans;


      }
   }

/*void Evaluator::parse(vector<string> code){
   int k = code.size();

   for(int i =0;i<k;i++){

      int l = code[i].size();
int m = 0;
      for(int m1 = 0;m1<l;m1++){if(code[i][m1] == ':'){m = m1;break;}}

      string str;
      for(int j=m+2;j<l;j++){str.push_back(code[i][j]);}

ExprTreeNode* root = new ExprTreeNode();
         root->id = ":=";

         root->type = "VAR";

         ExprTreeNode* lef = new ExprTreeNode();
         lef->type = "VAR";
         string lefstr;

         for(int j = 0;j<m;j++){lefstr.push_back(code[i][j]);}
         lef->id = lefstr;
         root->left = lef;

         root->right = prec(str);

         expr_trees.push_back(root);

   }
}*/

void Evaluator::parse(vector<string> code){
int k = code.size();
ExprTreeNode* root = new ExprTreeNode();
root->id = code[1];

         root->type = "VAR";

         ExprTreeNode* lef = new ExprTreeNode();
         lef->type = "VAR";

         lef->id = code[0];

         root->left = lef;

        
string str;
         for(int i =2;i<k;i++){
            str = str + code[i];
         }
 root->right = prec(str);

         expr_trees.push_back(root);


    }

    // Evaluate the last element of the expr_trees
    // This function is guaranteed to be called immediately 
    // after a call to parse, and will be only called ONCE
    // for a tree
    // Also populate the symbol tables
    void Evaluator::eval(){
      int k = expr_trees.size();
      
//cout<<"BLOCK"<<endl;
         eval_node(expr_trees[k-1]->right,symtable);
         
//cout<<"??"<<endl;
         //UnlimitedRational* r = expr_trees[i]->right->evaluated_value;
       //cout<<r->UnlimitedRational::get_frac_str()<<endl;
         symtable->SymbolTable::insert(expr_trees[k-1]->left->id,expr_trees[k-1]->right->evaluated_value);
         expr_trees[k-1]->left->evaluated_value = expr_trees[k-1]->right->evaluated_value;
         expr_trees[k-1]->left->val = expr_trees[k-1]->right->evaluated_value;
         expr_trees[k-1]->evaluated_value = expr_trees[k-1]->right->evaluated_value;
         expr_trees[k-1]->val = expr_trees[k-1]->right->evaluated_value;
      }

    

