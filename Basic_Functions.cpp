#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    cout << "string is: " << s << endl;

    int n = s.size(); // size of the string
    cout << "size of the string is: " << n << endl;

    string c = s;
    sort(c.begin(), c.end()); // sort the string
    cout << "sorted string is: " << c << endl;

    c = s;
    reverse(c.begin(), c.end()); // reverse the string
    cout << "reversed string is: " << c << endl;

    c = s.substr(0, 3); // substring of the string
    cout << "substring of the string from 1st character to 3rd character: " << c << endl;

    string text;
    getline(cin, text); // read a line of text
    cout << "text is: " << text << endl;

    for (int i = 0; i < text.size(); i++) {
        // text[i] = tolower(text[i]); // convert to lowercase
        text[i] = toupper(text[i]); // convert to uppercase
    }
    cout << text << endl;

    vector<string> words;
    istringstream iss(text);
    string word;
    while (iss >> word) {
        words.push_back(word); // split the text into words
    }
    cout << "words are: ";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    cout << endl;

    s.erase(s.begin() + 2); // erase the 3rd character
    cout << "string after erasing 3rd character: " << s << endl;

    s.erase(s.begin() + 2, s.begin() + 4); // erase the 3rd and 4th character
    cout << "string after erasing 3rd and 4th character: " << s << endl;

    s.push_back('a'); // add a character at the end of the string
    cout << "string after adding a character at the end: " << s << endl;

    s.pop_back(); // remove the last character
    cout << "string after removing the last character: " << s << endl;

    s.insert(s.begin() + 2, 'b'); // insert a character at the 3rd position
    cout << "string after inserting a character at the 3rd position: " << s << endl;
    

    return 0;
}