#include <iostream>
using namespace std;

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