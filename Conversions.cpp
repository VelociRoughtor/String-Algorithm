#include<bits/stdc++.h>
using namespace std;

// Function to convert string to integer
int stringToInteger(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        n = n * 10 + (s[i] - '0'); // convert character to integer
    }
    return n;
}

// Function to convert integer to string
string integerToString(int n) {
    string s = "";
    while (n > 0) {
        s += (n % 10) + '0'; // convert integer to character
        n /= 10; // divide by 10
    }
    reverse(s.begin(), s.end()); // reverse the string
    return s;
}

int main(){
    string s; cin >> s;
    cout << "string is: " << s << endl;

    // string to integer and integer to string conversion
    int num = stringToInteger(s); // convert string to integer
    cout << "string to integer is: " << num << endl;

    string copy = integerToString(num); // convert integer to string
    cout << "integer to string is: " << copy << endl;


    // Alternatively, you can use the built-in functions like stoi and to_string

    int n = stoi(s); // convert string to integer
    cout << "string to integer is: " << n << endl;

    string c = to_string(n); // convert integer to string
    cout << "integer to string is: " << c << endl;


    return 0;
}