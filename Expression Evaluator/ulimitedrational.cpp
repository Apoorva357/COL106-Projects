/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"

//HANDLE CASES OF SIGN IN NUMERATOR AND DENOMENATOR IN CONSTRUCTOR, ALSO HANDLE GCD.

//FINISH GCD

//FINISH COMPARE

int compare1(UnlimitedInt* a,UnlimitedInt* b){
    int k1 = a->get_size();
    int k2 = b->get_size();

int* arr1 = a->get_array();
int* arr2 = b->get_array();

    if(k1>k2){
        return 1;}
    else if(k2 > k1){
        return 0;}
    else{
        bool c = true;
        bool hold = true;
        //if(c == true){cout<<"true"<<endl;}
        bool d = true;
        for(int i =0;i<k1;i++){
            if(arr1[i] != arr2[i]){c = false;}
            if(arr1[i] > arr2[i]){hold = false;}
            if(hold && d && arr1[i] < arr2[i]){d = false;}
        }

        //cout<<"true"<<endl;
        //if(d == false){cout<<"false"<<endl;}

        if(c){
            return 2;}
        else if(d){
            return 3;}
        else{
//cout<<"yes";
            return 4;}
    }
}

/*UnlimitedInt* gcd(UnlimitedInt* i1, UnlimitedInt* i2){

    int k1 = i1->UnlimitedInt::get_sign();
    int k2 = i2->UnlimitedInt::get_sign();
    //cout<<k1<<" "<<k2<<"BLOCK";
   // cout<<compare(i1,i2)<<"BLOCK2"<<endl;

    int* arr1 = i1->UnlimitedInt::get_array();
    int* arrf1 = new int[i1->UnlimitedInt::get_capacity()];
    for(int i =0;i<i1->UnlimitedInt::get_capacity();i++){
        arrf1[i] = arr1[i];
    }

    int* arr2 = i2->UnlimitedInt::get_array();
    int* arrf2 = new int[i2->UnlimitedInt::get_capacity()];
    for(int i =0;i<i2->UnlimitedInt::get_capacity();i++){
        arrf2[i] = arr2[i];
    }

int* d = new int[1];
d[0] = 1;
UnlimitedInt* ut1 = new UnlimitedInt(d, 1, 1, 1);

UnlimitedInt* copy1 = new UnlimitedInt(arrf1,i1->UnlimitedInt::get_capacity(),1,i1->UnlimitedInt::get_size());
UnlimitedInt* copy2 = new UnlimitedInt(arrf2,i2->UnlimitedInt::get_capacity(),1,i2->UnlimitedInt::get_size());

if(compare1(i1,i2) == 2){delete ut1;
  delete copy2;
    return copy1;}

if(compare1(i1,ut1) == 2){
delete copy2;
delete copy1;

return ut1;
}

if(compare1(i2,ut1) == 2){
//cout<<"YES"<<endl;
delete copy1;
delete copy2;
//cout<<ut1->UnlimitedInt::to_string()<<endl;
return ut1;
}



else if(compare1(i1,i2) == 1 || compare1(i1,i2) == 3){
    delete ut1;
    delete copy1;
    delete copy2;
    // k1 = i1->UnlimitedInt::get_sign();
    // k2 = i2->UnlimitedInt::get_sign();
//cout<<k1<<" "<<k2<<endl;
    if(k1*k2 > 0){
    
    //UnlimitedInt* temp;
    //temp = UnlimitedInt::sub(i1,i2);
    //cout<<temp->UnlimitedInt::to_string()<<endl;

    return gcd(UnlimitedInt::sub(i1,i2),i2);}

    else{
          
    return gcd(UnlimitedInt::add(i1,i2),i2);
    }

}

else{delete ut1;
     //int k1 = i1->UnlimitedInt::get_sign();
    //int k2 = i2->UnlimitedInt::get_sign();
delete copy1;
    delete copy2;
    
    if(k1*k2 > 0){
    

    return gcd(UnlimitedInt::sub(i2,i1),i1);}

    else{
         
    return gcd(UnlimitedInt::add(i2,i1),i1);
    }
}

}*/


UnlimitedInt* gcd(UnlimitedInt* i1, UnlimitedInt* i2){

    int k1 = i1->UnlimitedInt::get_sign();
    int k2 = i2->UnlimitedInt::get_sign();
    //cout<<k1<<" "<<k2<<"BLOCK";
   // cout<<compare(i1,i2)<<"BLOCK2"<<endl;

    int* arr1 = i1->UnlimitedInt::get_array();
    int* arrf1 = new int[i1->UnlimitedInt::get_capacity()];
    for(int i =0;i<i1->UnlimitedInt::get_capacity();i++){
        arrf1[i] = arr1[i];
    }

    int* arr2 = i2->UnlimitedInt::get_array();
    int* arrf2 = new int[i2->UnlimitedInt::get_capacity()];
    for(int i =0;i<i2->UnlimitedInt::get_capacity();i++){
        arrf2[i] = arr2[i];
    }

int* d = new int[1];
d[0] = 1;
UnlimitedInt* ut1 = new UnlimitedInt(d, 1, 1, 1);

UnlimitedInt* copy1 = new UnlimitedInt(arrf1,i1->UnlimitedInt::get_capacity(),1,i1->UnlimitedInt::get_size());
UnlimitedInt* copy2 = new UnlimitedInt(arrf2,i2->UnlimitedInt::get_capacity(),1,i2->UnlimitedInt::get_size());

if(k1 == 0){delete ut1;
delete copy1;
return copy2;
}

if(k2 == 0){delete ut1;
delete copy2;
return copy1;
}

if(compare1(i1,i2) == 2){delete ut1;
  delete copy2;
    return copy1;}

if(compare1(i1,ut1) == 2){
delete copy2;
delete copy1;

return ut1;
}

if(compare1(i2,ut1) == 2){
//cout<<"YES"<<endl;
delete copy1;
delete copy2;
//cout<<ut1->UnlimitedInt::to_string()<<endl;
return ut1;
}



else if(compare1(i1,i2) == 1 || compare1(i1,i2) == 3){
    delete ut1;
    delete copy1;
    delete copy2;
    // k1 = i1->UnlimitedInt::get_sign();
    // k2 = i2->UnlimitedInt::get_sign();
//cout<<k1<<" "<<k2<<endl;

    
    //UnlimitedInt* temp;
    //temp = UnlimitedInt::sub(i1,i2);
    //cout<<temp->UnlimitedInt::to_string()<<endl;
   // cout<<"ho"<<endl;
UnlimitedInt* modu = UnlimitedInt::mod(i1,i2);
//cout<<modu->UnlimitedInt::to_string()<<endl;
//cout<<"hi"<<endl;
    UnlimitedInt* ans =  gcd(modu,i2);
delete modu;
return ans;

  

}

else{delete ut1;
     //int k1 = i1->UnlimitedInt::get_sign();
    //int k2 = i2->UnlimitedInt::get_sign();
delete copy1;
    delete copy2;
    
    
   

   UnlimitedInt* modu = UnlimitedInt::mod(i2,i1);

    UnlimitedInt* ans =  gcd(modu,i1);
delete modu;
return ans;

  
}

}



UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){


if(num == nullptr || den == nullptr){}

    else{

int k1 = num->UnlimitedInt::get_sign();
int k2 = den->UnlimitedInt::get_sign();

if(k1 == 0 && k2 == 0){UnlimitedInt* nn = new UnlimitedInt("");
UnlimitedInt* dd = new UnlimitedInt("");
p = nn;
q = dd;}

else if(k2 == 0){
    UnlimitedInt* nn = new UnlimitedInt("");
UnlimitedInt* dd = new UnlimitedInt("");
p = nn;
q = dd;}

else if(k1 == 0){UnlimitedInt* nn = new UnlimitedInt("");
    p = nn;

    string s = den->UnlimitedInt::to_string();
    UnlimitedInt* dd = new UnlimitedInt(s);
    q = dd;
}

else if(k1*k2 >0){

    UnlimitedInt* gc = gcd(num,den);

UnlimitedInt* p1 = UnlimitedInt::div(num,gc);
UnlimitedInt* q1 = UnlimitedInt::div(den,gc);
delete gc;

int* arr1 = p1->get_array();
int* arr2 = q1->get_array();

int* arr1f = new int[p1->get_capacity()];
int* arr2f = new int[q1->get_capacity()];

for(int i =0;i<p1->get_capacity();i++){
arr1f[i] = arr1[i];
}

for(int i =0;i<q1->get_capacity();i++){
arr2f[i] = arr2[i];
}

 p = new UnlimitedInt(arr1f,p1->UnlimitedInt::get_capacity(),1,p1->UnlimitedInt::get_size());
 q = new UnlimitedInt(arr2f,q1->UnlimitedInt::get_capacity(),1,q1->UnlimitedInt::get_size());

delete p1;
delete q1;

//p = num;
//q = den;
}

else{
    UnlimitedInt* gc = gcd(num,den);

UnlimitedInt* p1 = UnlimitedInt::div(num,gc);
UnlimitedInt* q1 = UnlimitedInt::div(den,gc);
delete gc;

int* arr1 = p1->get_array();
int* arr2 = q1->get_array();

int* arr1f = new int[p1->get_capacity()];
int* arr2f = new int[q1->get_capacity()];

for(int i =0;i<p1->get_capacity();i++){
arr1f[i] = arr1[i];
}

for(int i =0;i<q1->get_capacity();i++){
arr2f[i] = arr2[i];
}

 p = new UnlimitedInt(arr1f,p1->UnlimitedInt::get_capacity(),-1,p1->UnlimitedInt::get_size());
 q = new UnlimitedInt(arr2f,q1->UnlimitedInt::get_capacity(),1,q1->UnlimitedInt::get_size());

delete p1;
delete q1;
}}

}

    UnlimitedRational::~UnlimitedRational(){
        if(p != nullptr){delete p;p = nullptr;}
        
        if(q != nullptr){delete q;q = nullptr;}
       
    }

    UnlimitedInt* UnlimitedRational::get_p(){
        if(p!=nullptr){
        return p;}
    }

    UnlimitedInt* UnlimitedRational::get_q(){if(q!= nullptr){
        return q;}
    }

    string UnlimitedRational::get_p_str(){
        if(p!= nullptr){
    return p->UnlimitedInt::to_string();}}

    string UnlimitedRational::get_q_str(){ if(q!= nullptr){
    return q->UnlimitedInt::to_string();}}
    
    string UnlimitedRational::get_frac_str(){string s1 = get_p_str();
string s2 = get_q_str();
return s1+"/"+s2;}

    
     UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
        if(i1 ==nullptr || i2 == nullptr){}
            else{

        if(i1->get_frac_str() == "0/0" || i2->get_frac_str() == "0/0"){
            int* a = new int[0];
            UnlimitedInt* temp = new UnlimitedInt(a,0,0,0);
            UnlimitedRational* ans = new UnlimitedRational(temp,temp);
            delete temp;
            return ans;
        }


        UnlimitedInt* p1 = i1->get_p();
        UnlimitedInt* p2 = i2->get_p();

        UnlimitedInt* q1 = i1->get_q();
        UnlimitedInt* q2 = i2->get_q();

        UnlimitedInt* mul1 = UnlimitedInt::mul(p1,q2);
        UnlimitedInt* mul2 = UnlimitedInt::mul(p2,q1);

        UnlimitedInt* pf = UnlimitedInt::add(mul1,mul2);
        UnlimitedInt* qf = UnlimitedInt::mul(q1,q2);

      UnlimitedRational* ans = new UnlimitedRational(pf,qf);
   delete mul1;
   delete mul2;
       delete pf;
        delete qf;

        return ans;}


     }
     UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
          if(i1 ==nullptr || i2 == nullptr){}
            else{
           if(i1->get_frac_str() == "0/0" || i2->get_frac_str() == "0/0"){
            int* a = new int[0];
            UnlimitedInt* temp = new UnlimitedInt(a,0,0,0);
            UnlimitedRational* ans = new UnlimitedRational(temp,temp);
            delete temp;
            return ans;
        }

        UnlimitedInt* p1 = i1->get_p();
        UnlimitedInt* p2 = i2->get_p();

        UnlimitedInt* q1 = i1->get_q();
        UnlimitedInt* q2 = i2->get_q();

               UnlimitedInt* mul1 = UnlimitedInt::mul(p1,q2);
        UnlimitedInt* mul2 = UnlimitedInt::mul(p2,q1);

        UnlimitedInt* pf = UnlimitedInt::sub(mul1,mul2);
        UnlimitedInt* qf = UnlimitedInt::mul(q1,q2);

      UnlimitedRational* ans = new UnlimitedRational(pf,qf);
   delete mul1;
   delete mul2;
       delete pf;
        delete qf;

        return ans;}
     }


     UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
          if(i1 ==nullptr || i2 == nullptr){}
            else{
          if(i1->get_frac_str() == "0/0" || i2->get_frac_str() == "0/0"){
            int* a = new int[0];
            UnlimitedInt* temp = new UnlimitedInt(a,0,0,0);
            UnlimitedRational* ans = new UnlimitedRational(temp,temp);
            delete temp;
            return ans;
        }

        UnlimitedInt* p1 = i1->get_p();
        UnlimitedInt* p2 = i2->get_p();

        UnlimitedInt* q1 = i1->get_q();
        UnlimitedInt* q2 = i2->get_q();

        UnlimitedInt* pf = UnlimitedInt::mul(p1,p2);
        UnlimitedInt* qf = UnlimitedInt::mul(q1,q2);

        UnlimitedRational* ans = new UnlimitedRational(pf,qf);
  
        delete pf;
        delete qf;

        return ans;}
     }
     UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
          if(i1 ==nullptr || i2 == nullptr){}
            else{
           if(i1->get_frac_str() == "0/0" || i2->get_frac_str() == "0/0"){
            int* a = new int[0];
            UnlimitedInt* temp = new UnlimitedInt(a,0,0,0);
            UnlimitedRational* ans = new UnlimitedRational(temp,temp);
            delete temp;
            return ans;
        }

        if(i2->get_p_str() == "0"){
            int* a = new int[0];
            UnlimitedInt* temp = new UnlimitedInt(a,0,0,0);
            UnlimitedRational* ans = new UnlimitedRational(temp,temp);
            delete temp;
            return ans;

        }

        UnlimitedInt* p1 = i1->get_p();
        UnlimitedInt* p2 = i2->get_p();

        UnlimitedInt* q1 = i1->get_q();
        UnlimitedInt* q2 = i2->get_q();

        UnlimitedInt* pf = UnlimitedInt::mul(p1,q2);
        UnlimitedInt* qf = UnlimitedInt::mul(p2,q1);

        UnlimitedRational* ans = new UnlimitedRational(pf,qf);
      
        delete pf;
        delete qf;

        return ans;}
     }
