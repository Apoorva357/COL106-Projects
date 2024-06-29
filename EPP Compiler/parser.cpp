/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"

//Write your code below this line

//SEE LAST DELETD INT FOR MEMORY

Parser::Parser(){
   expr_trees = {};
symtable = new SymbolTable();
}

ExprTreeNode* prec(string s){

      int l = s.length();

      if(s[0] != '('){

         if( (int(s[0]) < 48 || int(s[0]) > 57) && s[0] != '-'){
string name; 
          
for(int i = 0;i<l;i++){name.push_back(s[i]);}

   ExprTreeNode* ans = new ExprTreeNode();
ans->id = name;
ans->type = "VAR";

return ans;

         }

         else{string number; 
for(int i = 0;i<l;i++){number.push_back(s[i]);}

      ExprTreeNode* ans = new ExprTreeNode();
int ans1 = stoi(number);

ans->type = "VAL";
      ans->num = ans1;

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

void Parser::parse(vector<string> expression){

int k = expression.size();
ExprTreeNode* root = new ExprTreeNode();
root->id = expression[1];

         root->type = "VAR";

         ExprTreeNode* lef = new ExprTreeNode();
         if(expression[0] == "ret"){lef->type = "RET";}
         else if(expression[0] == "del"){lef->type = "DEL";
         last_deleted = symtable->SymbolTable::search(expression[2]);
          symtable->SymbolTable::remove(expression[2]);}

         else{//cout<<"p1"<<endl;
         lef->type = "VAR";
         //cout<<"p2"<<endl;

         lef->id = expression[0];
         //cout<<"p3"<<endl;
         symtable->SymbolTable::insert(expression[0]);
         //cout<<"p4"<<endl;
         //cout<<symtable->SymbolTable::get_root()->key<<endl;
         //cout<<symtable->SymbolTable::get_size()<<endl;
      }

         root->left = lef;

        
string str = "";
         for(int i =2;i<k;i++){
            str = str + expression[i];
         }
         //cout<<"p5"<<endl;
 root->right = prec(str);
//cout<<"p6"<<endl;
         expr_trees.push_back(root);

}

Parser::~Parser(){
  delete symtable;

}