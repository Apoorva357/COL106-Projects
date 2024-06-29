/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"


//finish the int constructor
//check array indices of the addition and multiplication

//replace sign, size etc with get sign, get size etc.

//copy sigsn of i1 and i2 in add and sub

string actual_string(string s){
	string ans = "";

	int k = s.size();
int i;
	for(i = 0;i<k;i++){if(s[i] != '0'){break;}}
		for(int j = i;j<k;j++){ans.push_back(s[j]);}
			return ans;
}

int compare(UnlimitedInt* a,UnlimitedInt* b){
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


UnlimitedInt* same_digit_comparer(UnlimitedInt* i1, UnlimitedInt* i2){

int* arr1 = i1->get_array();
int* arr2 = i2->get_array();

int* arr1f = new int[i1->get_capacity()];
int* arr2f = new int[i2->get_capacity()];

for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}

for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}

UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),1,i1->get_size());
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),1,i2->get_size());

UnlimitedInt* ans = new UnlimitedInt("");
UnlimitedInt* one = new UnlimitedInt("1");

while(true){
UnlimitedInt* prevans = ans;
UnlimitedInt* prevutemp1 = utemp1;

	utemp1 = UnlimitedInt::sub(utemp1,utemp2);
	ans = UnlimitedInt::add(ans,one);
	delete prevans;
	delete prevutemp1;
	

int cmp = compare(utemp1,utemp2);

if(cmp == 0 || cmp == 4){break;}

}

delete utemp1;
delete utemp2;
delete one;

return ans;

}

int actual_size(int* arr,int n){



int ans = 0;

for(int i =0;i<n;i++){
	if(arr[i] != 0){break;}

	else{ans++;}
}

return n - ans;


}



UnlimitedInt::UnlimitedInt(){
	size = 0;
	sign = 1;
	capacity = 0;
	
	 
}

UnlimitedInt::UnlimitedInt(string s){
	int k = s.size();
	if(k ==0){size = 0;capacity =0;unlimited_int = new int[0];sign =0;}
else{
	if(s[0] == '-'){
	capacity =k-1;
	size = capacity;
	
	unlimited_int = new int[k-1];
	sign = -1;

	
	
	for(int i =0;i<capacity;i++){
		unlimited_int[i] = s[i+1] -'0';
	}

}


	else{sign = 1;
capacity =k;
	size = capacity;
	
unlimited_int = new int[k];

for(int i =0;i<capacity;i++){
		unlimited_int[i] = s[i] - '0';
	}

}
}
}


UnlimitedInt::UnlimitedInt(int i){

if(i ==0){size = 0;capacity =0;unlimited_int = new int[0];sign =0;}
else{
		string s = std::to_string(i);
		int k = s.size();

	if(s[0] == '-'){
	capacity =k-1;
	size = capacity;
	
	unlimited_int = new int[k-1];
	sign = -1;

	
	
	for(int i =0;i<capacity;i++){
		unlimited_int[i] = s[i+1] - '0';
	}

}


	else{sign = 1;
capacity =k;
	size = capacity;
	
unlimited_int = new int[k];

for(int i =0;i<capacity;i++){
		unlimited_int[i] = s[i] - '0';
	}

}
}
}


UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){

	unlimited_int = ulimited_int;
	capacity = cap;
	sign = sgn;
	size = sz;

}

UnlimitedInt::~UnlimitedInt(){
	if(unlimited_int != nullptr){delete unlimited_int;unlimited_int = nullptr;}
	
}

int UnlimitedInt::get_size(){
	return size;
}

int UnlimitedInt::get_sign(){
	return sign;
}

int UnlimitedInt::get_capacity(){
	return capacity;
}

int* UnlimitedInt::get_array(){
	return unlimited_int;
}

UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){

if(i1->get_sign() == 0){int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),i2->get_sign(),i2->get_size());
return utemp2;
}


if(i2->get_sign() == 0){int* arr1 = i1->get_array();
int* arr1f = new int[i1->get_capacity()];
for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}
UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),i1->get_sign(),i1->get_size());
return utemp1;} 
int k1,k2;
//k1 =1;
//k2 = 1;
k1 = i1->get_sign();
k2 = i2->get_sign();
//cout<<k1<<" "<<k2<<endl;
//cout<<i1->get_sign();
//cout<<k1*k2<<endl;
int* arr1 = i1->get_array();
int* arr2 = i2->get_array();

if(k2 * k1> 0){

	int s1 = i1->get_size();
	int s2 = i2->get_size();
	
	

	if(s1>=s2){
int* newarr = new int[s1+1];

int carry = 0;
for(int i =s2-1;i>=0;i--){
int temp = arr1[i-s2 + s1] + arr2[i] + carry;

if(temp>=10){carry = 1;
temp-=10;
newarr[s1 - s2 + 1 + i] = temp;}

else{
	carry = 0;
	newarr[s1 - s2 + 1 + i] = temp;
}

}

for(int i = s1-s2;i>0;i--){
	int temp = arr1[i-1] + carry;


if(temp>=10){carry = 1;
temp-=10;
newarr[i] = temp;}

else{
	carry = 0;
	newarr[i] = temp;
}
}
newarr[0] = carry;

int as = actual_size(newarr,s1+1); 

int* finarr = new int[as];
//cout<<as<<endl;
for(int i =as-1;i>=0;i--){
	finarr[i] = newarr[i + s1 + 1-as];
	//cout<<i<<" ";
	//cout<<finarr[i]<<endl;
}
delete newarr;


UnlimitedInt* ans = new UnlimitedInt(finarr, as,k1,as);
return ans;
}


else{

int* newarr = new int[s2+1];

int carry = 0;
for(int i =s1-1;i>=0;i--){
int temp = arr1[i] + arr2[i-s1+s2] + carry;

if(temp>=10){carry = 1;
temp-=10;
newarr[s2 - s1 + 1 + i] = temp;}

else{
	carry = 0;
	newarr[s2 - s1 + 1 + i] = temp;
}

}

for(int i = s2-s1;i>0;i--){
	int temp = arr2[i-1] + carry;


if(temp>=10){carry = 1;
temp-=10;
newarr[i] = temp;}

else{
	carry = 0;
	newarr[i] = temp;
}
}
newarr[0] = carry;

int as = actual_size(newarr,s2+1); 

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = newarr[i + s2 + 1-as];
}
delete newarr;


UnlimitedInt* ans = new UnlimitedInt(finarr, as,k1,as);
return ans;


}   

}


else{int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),-1 * i2->get_sign(),i2->get_size());




UnlimitedInt* utemp = sub(i1,utemp2);
delete utemp2;

return utemp;

}


}


UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){

if(i1->get_sign() == 0){
int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),-1 * i2->get_sign(),i2->get_size());
return utemp2;}

if(i2->get_sign() == 0){int* arr1 = i1->get_array();
int* arr1f = new int[i1->get_capacity()];
for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}
UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),i1->get_sign(),i1->get_size());
return utemp1;}

int k1 = i1->get_sign();
int k2 = i2->get_sign();

int* arr3 = i1->get_array();
int* arr4 = i2->get_array();



if(k2*k1<0){
	int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),-1 * i2->get_sign(),i2->get_size());


	
	UnlimitedInt* utemp = add(i1,utemp2);
	delete utemp2;

	return utemp;

}

else{
	int s1 = i1->get_size();
	int s2 = i2->get_size();

	int* arr1 = new int[s1];
	int* arr2 = new int[s2];

	for(int i =0;i<s1;i++){arr1[i] = arr3[i];}
	for(int i =0;i<s2;i++){arr2[i] = arr4[i];}

	if(compare(i1,i2) == 2){
		int* arr = new int[0];
		UnlimitedInt* ans = new UnlimitedInt(arr,0,0,0);
		delete arr1;
delete arr2;
		return ans;
	}

	else if(compare(i1,i2) == 1){
		int* arr = new int[s1];

		for(int i =s2-1;i>=0;i--){

if(arr1[i-s2+s1] <0){
arr1[i-s2+s1 -1] -=1;
arr1[i-s2+s1] +=10;
}

int temp = arr1[i-s2 + s1] - arr2[i];

if(temp<0){
temp+=10;
arr[i-s2+s1] = temp;
arr1[i-s2+s1 -1] -= 1;
}
else{arr[i-s2+s1] = temp;}
}

for(int i = s1-s2-1;i>=0;i--){
	if(arr1[i] <0){
arr1[i-1] -=1;
arr1[i] +=10;
}

arr[i] = arr1[i];

}

int as = actual_size(arr,s1); 

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = arr[i + s1 -as];
}

delete arr;
delete arr1;
delete arr2;
UnlimitedInt* ans = new UnlimitedInt(finarr, as,k1,as);
return ans;

}

else if(compare(i1,i2) == 0){

		int* arr = new int[s2];

		for(int i =s1-1;i>=0;i--){

if(arr2[i-s1+s2] <0){
arr2[i-s1+s2 -1] -=1;
arr2[i-s1+s2] +=10;
}

int temp = arr2[i-s1 + s2] - arr1[i];

if(temp<0){
temp+=10;
arr[i-s1+s2] = temp;
arr2[i-s1+s2 -1] -= 1;
}

else{arr[i-s1+s2] = temp;}

}

for(int i = s2-s1-1;i>=0;i--){
	if(arr2[i] <0){
arr2[i-1] -=1;
arr2[i] +=10;
}

arr[i] = arr2[i];

}

int as = actual_size(arr,s2); 

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = arr[i + s2 -as];
}

delete arr;
delete arr1;
delete arr2;
UnlimitedInt* ans = new UnlimitedInt(finarr, as,-1 * k2,as);

return ans;


}


else if(compare(i1,i2) == 3){

			int* arr = new int[s1];

		for(int i =s1-1;i>=0;i--){

if(arr1[i] <0 && i!= 0){
arr1[i-1] -=1;
arr1[i] +=10;
}

int temp = arr1[i] - arr2[i];

if(temp<0){
temp+=10;
arr[i] = temp;
arr1[i -1] -= 1;
}
else{arr[i] = temp;}

}


int as = actual_size(arr,s1); 

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = arr[i + s1 -as];
}

delete arr;
delete arr1;
delete arr2;
UnlimitedInt* ans = new UnlimitedInt(finarr, as,k1,as);
return ans;
}

else{
				int* arr = new int[s1];

		for(int i =s1-1;i>=0;i--){

if(arr2[i] <0 && i!= 0){
arr2[i-1] -=1;
arr2[i] +=10;
}

int temp = arr2[i] - arr1[i];

if(temp<0){
temp+=10;
arr[i] = temp;
arr2[i-1] -= 1;
}

else{arr[i] = temp;}
}


int as = actual_size(arr,s1); 

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = arr[i + s1 -as];
}

delete arr;
delete arr1;
delete arr2;
UnlimitedInt* ans = new UnlimitedInt(finarr, as,-1 *k2,as);
return ans;
}


}

}


UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){

if(i1->get_sign() == 0 || i2->get_sign() == 0){int* a = new int[0];
UnlimitedInt* ans = new UnlimitedInt(a,0,0,0);

	return ans;}


	int m = i1->get_capacity();
	int n = i2->get_capacity();

	int k1 = i1->get_sign();
	int k2 = i2->get_sign();

	int* arr1 = i1->get_array();
	int* arr2 = i2->get_array();


	int* newarr = new int[m+n];

	for(int i =0;i<m+n;i++){newarr[i] = 0;}


	
if(m>=n){
for(int i =n-1;i>=0;i--){
for(int j =m-1;j>=0;j--){
newarr[i+j+1] += arr1[j] * arr2[i];
}
}
int carry = 0;
for(int i = m+n-1;i>=1;i--){
	if(newarr[i] >=10){carry = newarr[i]/10;
newarr[i-1]+=carry;
newarr[i] -= (newarr[i]/10) * 10;
}

}

int sgn = k1 * k2;

int as = actual_size(newarr,m+n);

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = newarr[i + m+n-as];
}


delete newarr;



	UnlimitedInt* ans = new UnlimitedInt(finarr, as,sgn,as);
return ans;

}

else{

for(int i =m-1;i>=0;i--){
for(int j =n-1;j>=0;j--){
newarr[i+j+1] += arr1[i] * arr2[j];
}
}
int carry = 0;
for(int i = m+n-1;i>=1;i--){
	if(newarr[i] >=10){carry = newarr[i]/10;
newarr[i-1]+=carry;
newarr[i] -= (newarr[i]/10) * 10;}

}

int sgn = k1 * k2;

int as = actual_size(newarr,m+n);

int* finarr = new int[as];

for(int i =as-1;i>=0;i--){
	finarr[i] = newarr[i + m+n-as];
}


delete newarr;


	UnlimitedInt* ans = new UnlimitedInt(finarr, as,sgn,as);
return ans;

}



}
/*UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

int fsign = i1->get_sign()* i2->get_sign();

int* d = new int[1];
d[0] = 1;

int* d0 = new int[0];


UnlimitedInt* ut1 = new UnlimitedInt(d, 1, fsign, 1);
UnlimitedInt* ut0 = new UnlimitedInt(d0, 0, 0, 0);

int* arr1 = i1->get_array();
int* arr2 = i2->get_array();

int* arr1f = new int[i1->get_capacity()];
int* arr2f = new int[i2->get_capacity()];

for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}

for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}

UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),1,i1->get_size());
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),1,i2->get_size());


while(utemp1->get_sign() > 0){
	utemp1 = sub(utemp1,utemp2);
	if(utemp1->get_sign() <0){break;}
	ut0 = add(ut0,ut1);
	//cout<<ut1->to_string()<<" "<<ut0->to_string()<<endl;
}
delete d0;
delete d;
delete ut1;
delete utemp1;
delete utemp2;
delete arr1f;
delete arr2f;

return ut0;

}*/


string UnlimitedInt::to_string(){
string s;

if(size == 0){return "0";}

if(sign == -1){
s.push_back('-');
for(int i =0;i<size;i++){

	char c = '0' + unlimited_int[i];
	s.push_back(c);
}

}

else{

for(int i =0;i<size;i++){

	char c = '0' + unlimited_int[i];
	s.push_back(c);
}

}
return s;
}


/*UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){

	int* arr1 = i1->get_array();
int* arr1f = new int[i1->get_capacity()];
for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}
UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),1,i1->get_size());

int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),1,i2->get_size());



while(utemp1->get_sign() > 0){

	utemp1 = sub(utemp1,utemp2);
	if(utemp1->get_sign() == 0){break;}
if(utemp1->get_sign() <0){utemp1 = add(utemp1,utemp2);
	break;}
}

delete utemp2;
return utemp1;

}*/

UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){

int* arr1 = i1->get_array();
int* arr1f = new int[i1->get_capacity()];
for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}
UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),1,i1->get_size());

int* arr2 = i2->get_array();
int* arr2f = new int[i2->get_capacity()];
for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),1,i2->get_size());

UnlimitedInt* quo = div(utemp1,utemp2);
UnlimitedInt* pro = mul(utemp2,quo);

UnlimitedInt* ans = sub(utemp1,pro);

delete utemp1;
delete utemp2;
delete quo;
delete pro;

return ans;

}

UnlimitedInt* UnlimitedInt::div(UnlimitedInt* i1, UnlimitedInt* i2){

	if(i1->get_sign() == 0){
		UnlimitedInt* ans = new UnlimitedInt("");
		return ans;
	}

int* arr1 = i1->get_array();
int* arr2 = i2->get_array();

int* arr1f = new int[i1->get_capacity()];
int* arr2f = new int[i2->get_capacity()];

for(int i =0;i<i1->get_capacity();i++){
arr1f[i] = arr1[i];
}

for(int i =0;i<i2->get_capacity();i++){
arr2f[i] = arr2[i];
}

UnlimitedInt* utemp1 = new UnlimitedInt(arr1f,i1->get_capacity(),1,i1->get_size());
UnlimitedInt* utemp2 = new UnlimitedInt(arr2f,i2->get_capacity(),1,i2->get_size());

int divider = utemp2->get_size();
UnlimitedInt* ans = new UnlimitedInt("");

while(true){
int comp = compare(utemp1,utemp2);

//cout<<utemp1->to_string()<<" "<<comp<<endl;
//cout<<utemp1->to_string()<<" "<<comp<<endl;

if(comp == 0 || comp == 4){
	break;
}
//cout<<"hi"<<endl;

string s = utemp1->to_string();
int sl = s.size();
string r;
string l;

for(int i = 0;i<divider;i++){
	l.push_back(s[i]);
}

UnlimitedInt* cmp = new UnlimitedInt(l);

int comp1 = compare(cmp,utemp2);
delete cmp;

if(comp1 == 0 || comp1 == 4){
	l.push_back(s[divider]);

for(int i = divider+1;i<sl;i++){
	r.push_back(s[i]);
}


UnlimitedInt* temp = new UnlimitedInt(l);
UnlimitedInt* sdc = same_digit_comparer(temp,utemp2);

string power;
power.push_back('1');
for(int i = 0;i<sl-divider-1;i++){
	power.push_back('0');
} 

UnlimitedInt* ten = new UnlimitedInt(power);
UnlimitedInt* prevans = ans;
UnlimitedInt* mul1 = mul(sdc,ten);
ans = add(ans,mul1);
delete mul1;
delete prevans;
delete ten;
UnlimitedInt* mult = mul(utemp2,sdc);

UnlimitedInt* leftstr = sub(temp,mult);

//cout<<utemp2->to_string()<<" "<<sdc->to_string()<<endl;
//cout<<mult->to_string()<<endl;

delete mult;
delete temp;
delete sdc;
string finalstr = leftstr->to_string();
finalstr = actual_string(finalstr);
string rf = r;
if(finalstr == ""){
rf = actual_string(r);}
finalstr = finalstr + rf;
//cout<<finalstr<<endl;
delete leftstr;
UnlimitedInt* final = new UnlimitedInt(finalstr);
UnlimitedInt* ttemp = utemp1;
utemp1 = final;
delete ttemp;

}




else{
for(int i = divider;i<sl;i++){
	r.push_back(s[i]);
}


UnlimitedInt* temp = new UnlimitedInt(l);
UnlimitedInt* sdc = same_digit_comparer(temp,utemp2);

string power;
power.push_back('1');
for(int i = 0;i<sl-divider;i++){
	power.push_back('0');
} 

UnlimitedInt* ten = new UnlimitedInt(power);
UnlimitedInt* prevans = ans;
UnlimitedInt* mul1 = mul(sdc,ten);
ans = add(ans,mul1);
delete mul1;
delete prevans;
delete ten;
UnlimitedInt* mult = mul(utemp2,sdc);

UnlimitedInt* leftstr = sub(temp,mult);

//cout<<utemp2->to_string()<<" "<<sdc->to_string()<<endl;
//cout<<mult->to_string()<<endl;

delete mult;
delete temp;
delete sdc;
string finalstr = leftstr->to_string();
finalstr = actual_string(finalstr);
string rf = r;
if(finalstr == ""){
rf = actual_string(r);}

finalstr = finalstr + rf;
//cout<<finalstr<<endl;
delete leftstr;
UnlimitedInt* final = new UnlimitedInt(finalstr);
UnlimitedInt* ttemp = utemp1;
utemp1 = final;
delete ttemp;



}

}


delete utemp1;
delete utemp2;


int* arr0 = ans->get_array();

int* arr0f = new int[ans->get_capacity()];

for(int i =0;i<ans->get_capacity();i++){
arr0f[i] = arr0[i];
}

int k1 = i1->get_sign();
int k2 = i2->get_sign();

UnlimitedInt* copy = new UnlimitedInt(arr0f,ans->get_capacity(),k1*k2,ans->get_size());


delete ans;
return copy;
//return ans;

}

