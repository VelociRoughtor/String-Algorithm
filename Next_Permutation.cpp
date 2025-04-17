#include<bits/stdc++.h>
using namespace std;

int main(){
    // string s; cin >> s;
    // sort(s.begin(), s.end());
    // while (next_permutation(s.begin(), s.end())){
    //     cout << s << endl;
    // }
    // cout << "No more permutations" << endl;

    vector<int> v = {4, 2, 7, 1};
    sort(v.begin(), v.end());
    while(next_permutation(v.begin(), v.end())){
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    cout << "No more permutations" << endl;

    return 0;
}