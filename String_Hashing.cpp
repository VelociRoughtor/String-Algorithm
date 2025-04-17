#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef uint64_t ull;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)

struct pair_hash {
    size_t operator()(const pair<ll, ll>& p) const {
        return p.first ^ (p.second + 0x9e3779b97f4a7c15ULL + (p.first << 6) + (p.first >> 2));
    }
};

struct RollingHash {
    static const ll MOD1 = 1e9 + 7;
    static const ll MOD2 = 1e9 + 9;
    static const ll BASE1 = 911;
    static const ll BASE2 = 3571;

    vector<ll> hash1, hash2, pow1, pow2;

    RollingHash(const string &s) {
        build(s);
    }

    void build(const string &s) {
        int n = s.size();
        hash1.resize(n + 1, 0);
        hash2.resize(n + 1, 0);
        pow1.resize(n + 1, 1);
        pow2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int x = s[i] + 1;
            hash1[i + 1] = (hash1[i] * BASE1 + x) % MOD1;
            hash2[i + 1] = (hash2[i] * BASE2 + x) % MOD2;
            pow1[i + 1] = pow1[i] * BASE1 % MOD1;
            pow2[i + 1] = pow2[i] * BASE2 % MOD2;
        }
    }

    pair<ll, ll> get(int l, int r) {
        ll x1 = (hash1[r] - hash1[l] * pow1[r - l] % MOD1 + MOD1) % MOD1;
        ll x2 = (hash2[r] - hash2[l] * pow2[r - l] % MOD2 + MOD2) % MOD2;
        return {x1, x2};
    }

    void insert(char c) {
        int n = hash1.size() - 1;
        int x = c + 1;
        hash1.push_back((hash1[n] * BASE1 + x) % MOD1);
        hash2.push_back((hash2[n] * BASE2 + x) % MOD2);
        pow1.push_back(pow1[n] * BASE1 % MOD1);
        pow2.push_back(pow2[n] * BASE2 % MOD2);
    }

    pair<ll, ll> get_full_hash() {
        return {hash1.back(), hash2.back()};
    }
};

// Example usage:
// RollingHash rh("initial_string");
// auto hash = rh.get(0, 5); // hash of s[0...5]
// rh.insert('c'); // Insert a new character at the end
// auto full_hash = rh.get_full_hash(); // Get full hash of current string

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, b; cin >> s >> b;
    ll n = s.size(), k; cin >> k;

    RollingHash sh(s);

    unordered_set<pair<ll,ll>, pair_hash> st;
    for (ll i = 0; i < n; i++) {
        ll cnt = 0;
        for (ll j = i; j < n; j++) {
            if (b[s[j] - 'a'] == '0') cnt++;
            if (cnt > k) break;
            pair<ll,ll> h = sh.get(i, j + 1);
            if (!st.count(h)) st.insert(h);
        }
    }

    cout << st.size() << endl;
    
    return 0;
}