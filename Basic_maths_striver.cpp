#include <iostream>
using namespace std;

//extraction of digits 
/*
int countdigits(int n){
    int count = 0;
    int lastdigit;
    while(n>0){
        lastdigit = n % 10;
        count ++;
        n = n / 10;
    }
    return count;
}
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout << countdigits(n);
}
*/
//Counting digits better version.
/*
int count(int n){
    int cnt = log10(n) + 1;
    return cnt;
}

int main(){
    int n;
    cout << "Enter an integer : ";
    cin >> n;
    cout << "The number of integers are : " << count(n) << endl;
}
*/

int reverse(int n){
    int last;
    int reverse;
    while(n>0){
        last= n %10;
        n = n / 10;
        reverse = reverse * 10 + last;
    }
    return reverse;
}
int main(){
    int n;
    cout << "enter an integer : ";
    cin >> n;
    cout << "The reversed integer is : " << reverse(n);
}