#include <iostream>
using namespace std;
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