/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "eppcompiler.h"

//Write your code below this line

vector<string> post(ExprTreeNode* a, SymbolTable* symtable){

 vector<string> trav;
    
    if (a == NULL){
        return trav;
    }

    vector<ExprTreeNode*> s;
    s.push_back(a);

    ExprTreeNode* prev = NULL;
    while (s.size() > 0) {
        ExprTreeNode* cur = s[s.size()-1];
   
        if (prev == NULL || prev->left == cur || prev->right == cur) {
            if (cur->right != NULL){
                s.push_back(cur->right);
            }
            else if (cur->left){
                s.push_back(cur->left);
            }
            else {
                s.pop_back();
                if(cur->type == "VAL"){
                	string ns = to_string(cur->num);
                	string pus = "PUSH " + ns;
               trav.push_back(pus);}

               else if(cur->type == "VAR"){
               	string ns = to_string(symtable->SymbolTable::search(cur->id));
               	string pus = "PUSH mem[" + ns;
               	pus = pus + "]";
               	trav.push_back(pus);

               }

               else if(cur->type == "ADD"){
               	trav.push_back("ADD");

               }

               else if(cur->type == "SUB"){
               	trav.push_back("SUB");

               }

               else if(cur->type == "DIV"){
               	trav.push_back("DIV");

               }

               else{
               	trav.push_back("MUL");

               }



            }
           
        }
 
        else if (cur->right == prev) {
            if (cur->left)
                s.push_back(cur->left);
            else {
                s.pop_back();
              if(cur->type == "VAL"){
                	string ns = to_string(cur->num);
                	string pus = "PUSH " + ns;
               trav.push_back(pus);}

               else if(cur->type == "VAR"){
               	string ns = to_string(symtable->SymbolTable::search(cur->id));
               	string pus = "PUSH mem[" + ns ;
               	pus = pus + "]";
               	trav.push_back(pus);

               }

               else if(cur->type == "ADD"){
               	trav.push_back("ADD");

               }

               else if(cur->type == "SUB"){
               	trav.push_back("SUB");

               }

               else if(cur->type == "DIV"){
               	trav.push_back("DIV");

               }

               else{
               	trav.push_back("MUL");

               }


            }
 
           
        }
        else if (cur->left == prev) {
            s.pop_back();
         if(cur->type == "VAL"){
                	string ns = to_string(cur->num);
                	string pus = "PUSH " + ns;
               trav.push_back(pus);}

               else if(cur->type == "VAR"){
               	string ns = to_string(symtable->SymbolTable::search(cur->id));
               	string pus = "PUSH mem[" + ns ;
               	pus = pus + "]";
               	trav.push_back(pus);

               }

               else if(cur->type == "ADD"){
               	trav.push_back("ADD");

               }

               else if(cur->type == "SUB"){
               	trav.push_back("SUB");

               }

               else if(cur->type == "DIV"){
               	trav.push_back("DIV");

               }

               else{
               	trav.push_back("MUL");

               }


        }
        prev = cur;
    }
    return trav;

}

EPPCompiler::EPPCompiler(){
//targ = Parser();
}

EPPCompiler::EPPCompiler(string out_file,int mem_limit){
	//targ = Parser();
output_file = out_file;
memory_size = mem_limit;
least_mem_loc = MinHeap();
// for(int i =0;i<mem_limit;i++){
// 	mem_loc.push_back(i);
// }

for(int i =0;i<mem_limit;i++){
	least_mem_loc.MinHeap::push_heap(i);
}

}

void EPPCompiler::compile(vector<vector<string>> code){
int k = code.size();
vector<string> writ;

// for(int i =0;i<k;i++){
// int n = code[i].size();

// for(int j = 0;j<n;j++){

// 	cout<<code[i][j];}cout<<endl;} 

for(int i= 0;i<k;i++){
//cout<<"h1"<<endl;
targ.parse(code[i]);

//cout<<"h2"<<" ";
vector<string> temp = generate_targ_commands();
int k1 = temp.size();

for(int j = 0;j<k1;j++){writ.push_back(temp[j]);}
//cout<<endl;
//int k1 = writ.size();
//for(int i =0;i<k1;i++){cout<<writ[i]<<endl;}
//cout<<endl;
//cout<<"h3"<<endl;

}

write_to_file(writ);

}

vector<string> EPPCompiler::generate_targ_commands(){

int i = targ.expr_trees.size() - 1;
//cout<<"h4"<<endl;
	vector<string> coms = post(targ.expr_trees[i]->right,targ.symtable);
	//cout<<"h5"<<endl;
	string typ = targ.expr_trees[i]->left->type;

if(typ == "DEL"){coms.clear();
least_mem_loc.MinHeap::push_heap(targ.last_deleted);
//mem_loc.push_back(targ.symtable->SymbolTable::search(targ.expr_trees[i]->right->id));
		string ns = to_string(targ.last_deleted);
        string pus = "DEL = mem[" + ns + "]";
	coms.push_back(pus);
}
else if(typ == "VAR"){ //cout<<"h6"<<endl;
//cout<<targ.symtable->SymbolTable::search(targ.expr_trees[i]->left->id)<<endl;
//cout<<"h7"<<endl;
	if(targ.symtable->SymbolTable::search(targ.expr_trees[i]->left->id) == -1){//cout<<"h8"<<endl;
		//int l = mem_loc.size() -1;
		//int idx = mem_loc[l];
		int idx = least_mem_loc.MinHeap::get_min();

		least_mem_loc.MinHeap::pop();
		targ.symtable->SymbolTable::assign_address(targ.expr_trees[i]->left->id,idx);
		//cout<<"h9"<<endl;
		string ns = to_string(idx);
		string pus = "mem[" + ns + "] = POP";
	coms.push_back(pus);

	}

	else{//cout<<"h10"<<endl;
		string ns = to_string(targ.symtable->SymbolTable::search(targ.expr_trees[i]->left->id));
        string pus = "mem[" + ns + "] = POP";
	coms.push_back(pus);

	}
	//cout<<"h11"<<endl;
}

else{
	
	coms.push_back("RET = POP");
}	

return coms;

}

void EPPCompiler::write_to_file(vector<string> commands){

fstream file;
file.open(output_file,ios_base::out);

for(int i=0;i<commands.size();i++)
    {
        file<<commands[i]<<endl;
    }
 
    file.close();

}

EPPCompiler::~EPPCompiler(){
  
}
