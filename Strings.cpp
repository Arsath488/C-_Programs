#include <iostream>
#include <string>
#include <utility> // for swap

using namespace std;

int main() {
    string a, b;
    
    
    cin >> a >> b;

   
    cout << a.size() << " " << b.size() << endl;

 
    cout << a + b << endl;

   
    string a_prime = a;
    string b_prime = b;
    
    char temp = a_prime[0];
    a_prime[0] = b_prime[0];
    b_prime[0] = temp;

    cout << a_prime << " " << b_prime << endl;

    return 0;
}
