    #include "Chaining.h"
using namespace std;

void merge(vector<int>& a,int p,int q,int r) {
  int a1 = q-p+1;
  int a2 = r-q;

  vector<int> m,n;

  for(int i =0;i<a1;i++){
    m.push_back(a[p+i]);
  }
  for(int i =0;i<a2;i++){
    n.push_back(a[q+i+1]);
  }

int i =0;
int j =0;
int ind = p;

while(i<a1 && j<a2){
  if(m[i] <= n[j]){
    a[ind] = m[i];i++;
  }

  else{
    a[ind] = n[j];j++;
  }
  ind++;
}

while(i<a1){
  a[ind] = m[i];
  ind++;
  i++;
}

while(j<a2){
  a[ind] = n[j];
  ind++;
  j++;
}
}

void merge_sort(vector<int>& a,int left,int right){
int middle;
  if(left<right){
middle = (right-left)/2 + left;
merge_sort(a,left,middle);
merge_sort(a,middle + 1, right);
merge(a,left, middle,right);
}
}


int Chaining::getElement(string id1){
    //if(!doesExist(id)){return -1;}
    int k = hash(id1);
    int l = bankStorage2d.size();int i = 0;
    while(bankStorage2d[k][i].id != id1){
        i++;

    }

    return i;
}

void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    Account l;
    l.id = id;
    l.balance = count;
     counts.push_back(count);

    int k = hash(id);

    if(k%99999+1>bankStorage2d.size()){
       
        while(k%99999+1!=bankStorage2d.size()) {vector<Account> v;bankStorage2d.push_back(v);}
    }
bankStorage2d[k].push_back(l);
size++;

}

std::vector<int> Chaining::getTopK(int k) {
    
       // IMPLEMENT YOUR CODE HERE
  int l = counts.size();
 merge_sort(counts,0,l-1);
  vector<int> a;
  for(int i =l-1;i>(l-1)-k;i--){
if(i<0) break;
a.push_back(counts[i]);
  }

    return a; // Placeholder return value    

}

int Chaining::getBalance(std::string id) {
   // IMPLEMENT YOUR CODE HERE
    if(!doesExist(id)){return -1;}
    else{
        return bankStorage2d[hash(id)][getElement(id)].balance;
    }

    //return i; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    if(!doesExist(id)){createAccount(id,count);}

    else{int l = getElement(id);
    
    int k = counts.size();
    int k1 = hash(id);
    int b = bankStorage2d[k1][l].balance;
        bankStorage2d[k1][l].balance += count;
    
    for(int i =0;i<k;i++){
        
    if(counts[i] == b){
        counts[i] += count;
        break;
    }
}


    }
}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    int k = hash(id);
    int i =0;
    while(true){
        if(k+1>bankStorage2d.size()) {return false;}
        if(i +1> bankStorage2d[k].size()) {return false;}
        if(bankStorage2d[k][i].id == "-1") {return false;}

        if(bankStorage2d[k][i].id == id) {return true;}

     i+=1;
    }
    //return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
  // IMPLEMENT YOUR CODE HERE
    //cout<<"Hi"<<endl;
    if(!doesExist(id)) return false;
    //account a = createAccount("-1",-1)
int k = counts.size();
int k1 = hash(id);
int b =bankStorage2d[k1][getElement(id)].balance;
int ind;
for(int i =0;i<k;i++){
    if(counts[i] == b){
        ind = i;
        break;
    }
}

auto it = counts.begin()+ind;
counts.erase(it);
   
  
    size--;

    bankStorage2d[k1][getElement(id)].id = "1";

    return true; // Placeholder return value
}

int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return size; // Placeholder return value
}

int Chaining::hash(std::string id) {
unsigned int hash = 5381;

int k = id.size();
for(int i =0;i<k;i++){
        hash = ((hash << 5) + hash) ^ id[i];  
    }

    int ans = static_cast<int>(hash%99999);
    return ans%99999;  
}
