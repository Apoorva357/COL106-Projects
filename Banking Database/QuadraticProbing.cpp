#include "QuadraticProbing.h"
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


int QuadraticProbing::getElement(string id1){
    //if(!doesExist(id)){return -1;}
    int k = hash(id1);
    int l = 0;
    int h=k;

    while(bankStorage1d[h].id != id1){
        
        h = (k + ((l%99999)*(l%99999))%99999)%99999;
        l+=1;
        //if(k >= 100000) k = 0;

    }

    return h;
}

void QuadraticProbing::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    Account ac;
    ac.balance = count;
    ac.id = id;
    size++;

    
    counts.push_back(count);

    int k = hash(id);
int h;
int j =0;
  while(true){
   h = (k + ((j%99999)*(j%99999))%99999)%99999;
    
        if(h%99999+1>bankStorage1d.size()){
            while(h%99999+1>bankStorage1d.size()){
            Account l;
            l.id = "-1";
            bankStorage1d.push_back(l);
           
        }
        }

        if(bankStorage1d[h].id == "1" || bankStorage1d[h].id == "-1") {bankStorage1d[h] = ac; break;}

j++;

}

   
}

std::vector<int> QuadraticProbing::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    vector<int> a;
  int l = counts.size();
  merge_sort(counts,0,l-1);

  for(int i =l-1;i>(l-1)-k;i--){
if(i<0) break;
a.push_back(counts[i]);
  }

    return a; // Placeholder return value
}

int QuadraticProbing::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    if(!doesExist(id)){return -1;}
    else{
        return bankStorage1d[getElement(id)].balance;
    }
    //return 0; // Placeholder return value
}

void QuadraticProbing::addTransaction(std::string id, int count) {
      if(!doesExist(id)){createAccount(id,count);}

    else{int l = getElement(id);
    
    int k = counts.size();
    
    int b = bankStorage1d[l].balance;
        bankStorage1d[l].balance += count;
    
    for(int i =0;i<k;i++){
        
    if(counts[i] == b){
        counts[i] += count;
        break;
    }
}


    }}

bool QuadraticProbing::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
     int k = hash(id);
     int h=k;
     int l = 0;
    while(true){
        if(k+1>bankStorage1d.size()) {return false;}
        if(bankStorage1d[h].id == "-1") {return false;}

        if(bankStorage1d[h].id == id) {return true;}

        h = (k + ((l%99999)*(l%99999))%99999)%99999;
        l++;
    }
    //return false; // Placeholder return value
}

bool QuadraticProbing::deleteAccount(std::string id) {
  // IMPLEMENT YOUR CODE HERE
    //cout<<"Hi"<<endl;
    if(!doesExist(id)) return false;
    //account a = createAccount("-1",-1)
int k = counts.size();
int b =bankStorage1d[getElement(id)].balance;
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

    bankStorage1d[getElement(id)].id = "1";

    return true; // Placeholder return value
}
int QuadraticProbing::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return size;
    //return 0; // Placeholder return value
}

int QuadraticProbing::hash(std::string id) {
unsigned int hash = 5381;

int k = id.size();
for(int i =0;i<k;i++){
        hash = ((hash << 5) + hash) ^ id[i];  
    }

    int ans = static_cast<int>(hash%99999);
    return ans%99999;  
}


