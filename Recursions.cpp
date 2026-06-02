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
/*
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
*/


//Recursion : 3


//Sum of N numbers
//Parameterised way
/*
void summation(int i,int s){
    if(i<1){
        cout << s << endl;
        return;
    }
    summation(i-1,s+i);
}
int main(){
    int n;
    cout << "Enter the number upto which you want to print the sum of : ";
    cin >> n;
    summation(n,0);
}
*/
//functional recursion
/*
int func(int n){
    if(n==0){
        return 0;
    }
    return n + func(n-1);
}
int main(){
    int n;
    cout << "Enter the number upto which you want the sum of : ";
    cin >> n;
    cout << func(n) << endl;
}
*/
//Factorial of n numbers
/*
int factorial(int n){
    if(n==1){
        return 1;
    }
    return n * factorial(n-1);
}
int main(){
    int n;
    cout << "Enter the number you want factorical of : ";
    cin >> n;
    cout << factorial(n) << endl;
}
*/

#include <utility>
//Reverse an array
/*
void revarr(int arr[],int n,int i){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    revarr(arr,n,i+1);
}
int main(){
    int n;
    cout << "Enter the number of integers in array : ";
    cin >> n;
    int arr[n];
    int i;
    cout << "Enter the integers in array : ";
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    revarr(arr,n,0);
    for(i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
//Check for pallindrome 
/*
void pal(int n,string word){
    int cnt = 0;
    for(int i=0;i<n/2;i++){
        if(word[i] != word[n-i-1]){
            cnt ++;
        }
    }
    if(cnt > 0){
        cout << "The word is not a pallindrome";
    }
    else{
        cout << "The word is a pallindrome";
    }
}
int main(){
    string word;
    cout << "Enter a word to check for pallindrome : ";
    cin >> word;
    int n = word.length();
    pal(n,word);
}
*/
//Fibonnaci Number 
int fibonnaci(int n){
    if(n<=1){
        return n;
    }
    int last = fibonnaci(n-1);
    int slast = fibonnaci(n-2);
    return last + slast;
}
int main(){
    int n;
    cout << "Enter the number for which fibonnaci is required : ";
    cin >> n;
    cout << fibonnaci(n) << endl;
}