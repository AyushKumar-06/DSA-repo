#include <iostream>
#include <algorithm>
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
//Reversal of number
/*
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
*/
//pallindrome number
/*
int reverse(int n){
}

int main(){
    int n;
    cout << "Enter an integer : ";
    cin >> n;
    cout << "The given number is a pallindrome True/False : " << reverse(n);
}
*/
//Armstrong number
/*
int armstrong(int n){
    int last;
    int arm = 0;
    int temp = n;
    while(n>0){
        last = n % 10;
        arm = arm + (last * last * last);
        n = n / 10;
    }
    if(arm==temp){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cout << "Enter an armstrong number : ";
    cin >> n;
    cout << "The number is an armstrong number (True/False) : " << armstrong(n);
}
*/
//divisor of a given number 
/*
int div(int n){
    for(int i=1;i<=n/i;i++){
        if(n % i == 0){
            cout << i ;
            if(n % i != 1){
            cout << n/i;
            }
        }
    }
}
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout <<  "The divisors of " << n << " are " << div(n);
}
    A list can be used to store the divisors and sort them.
*/
//divisor of a given number (sorted is ascending order)
/*
int printdivisor(int n){
    vector<int> ls;

    for(int i = 1;i < n/i;i++){
        if(n%i==0){
            ls.push_back(i);
            if(n/i != 1){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end());
    for(auto it : ls) cout << it << " ";
}
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    printdivisor(n);
}
*/
//check for prime numbers
/*
bool prime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2;i <= n/i;i++){
        if(n % i == 0){
            return false;
        }
    }
}
int main(){
    int n;
    cout << "Enter a number : ";
    cin >> n;
    if (prime(n)){
        cout << n << " is a prime number";
    }
    else{
        cout << n << " is not a prime number";
    }
}
*/
//GCD of 2 numbers
/*
int GCD(int n1,int n2){
    for(int i=1;i<= min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            cout << i << " ";
        }
    }
}
int main(){
    int n1,n2;
    cout << "Enter 2 numbers : ";
    cin >> n1 >> n2;
    GCD(n1,n2);
}
*/
//GCD using Euclidean algorithm
int eucGCD(int n1,int n2){
    while(n1>0 && n2>0){
        if(n1>n2){
            n1=n1%n2;
        }
        else{
            n2=n2%n1;
        }
    }
    if(n1==0){
        return n2;
    }
    else{
        return n1;
    }
}
int main(){
    int n1,n2;
    cout << "Enter 2 numbers : ";
    cin >> n1 >> n2;
    cout << "The GCD of " << n1 << " and " << n2 << " is " << eucGCD(n1,n2);
}             