 #include <iostream>
 #include <string.h>
 using namespace std;
 
 //Print name n times using recursion
 /*
void recur(int i,int n){
    if(i>n){
        return;
    }
    cout << "Ayush" << endl;
    recur(i+1,n);
}
 int main(){
    int n;
    int i=1;
    cout << "Enter how many times you want to repeat : ";
    cin >> n;
    recur(i,n);
}
*/

//printing a custom word or scentence n number of times
/*
void rec2(int n,string a){
    if(n == 0){
        return;
    }
    cout << a << endl;
    rec2(n-1,a);
}
int main(){
    int n;
    string a;
    cout << "Enter a word or a scentence : ";
    getline(cin,a);
    cout << "The word or scentence repeated is : " << a << endl;
    cout << "Enter the number of times you want it to repeat : ";
    cin >> n;
    rec2(n,a);
}
*/
//Print linearly from 1 to N
/*
void lin(int i,int n){
    if(i>n){
        return;
    }
    cout << i << endl;
    lin(i+1,n);
}
int main(){
    int n;
    int i = 1;
    cout << "Enter the number to be linearly printed : ";
    cin >> n;
    lin(i,n);
}
*/
//Print linearly from N to 1
/*
void revlin(int n){
    if(n<1){
        return;
    }
    cout << n << endl;
    revlin(n-1);
}
int main(){
    int n;
    cout << "Enter the number to be linearly printed : ";
    cin >> n;
    revlin(n);
}
*/
//print linearly from 1 to N (by using trackback)
/*
void lin(int i,int n){
    if(i<1){
        return;
    }
    lin(i-1,n);
    cout << i << endl;
}
int main(){
    int n;
    cout << "Enter the the number you want to linearly print : ";
    cin >> n;
    lin(n,n);
}
*/
//print linearly from N to 1 (by using trackback)
void revlin(int i,int n){
    if(i>n){
        return;
    }
    revlin(i+1,n);
    cout << i << endl;
}
int main(){
    int n;
    cout << "Enter the number you want to print towards 1 : ";
    cin >> n;
    revlin(1,n);
}