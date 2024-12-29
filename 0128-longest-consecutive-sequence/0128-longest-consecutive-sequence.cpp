// 2024-12-29 09:24:50",
// Author Ujjwal_Agrawal
#include <bits/stdc++.h>
using namespace std;

//Speed
#define bullet() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define Pai (3.141592653589)
#define M 1000000007
#define in(x) insert(x);
#define pb push_back
#define pp pop_back
#define fir first
#define sec second
#define feach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rfeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) feach(i,0,j,1)
#define rrep(i,j) rfeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define sz(s) (int)(s.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define os(x) cout << x << " ";
#define out(x) cout << x << endl;
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x,u) count(all(x), u)
#define B break
#define C continue
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define cm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define rtn return

//Typedef
typedef long long ll;typedef pair<ll, ll> pll;typedef pair<int, int> pii;typedef pair<char, int> pci;typedef pair<char, ll> pcl;typedef pair<string, ll> psl;typedef pair<char, char> pcc;typedef vector<ll> vecl;typedef vector<int> vec;typedef map<ll,ll> mpl;typedef map<int,int> mp;typedef unordered_map<ll,ll> umpl;typedef unordered_map<int,int> ump;typedef vector<vector<ll>> dvecl;typedef vector<vector<int>> dvec;typedef vector<pair<ll,ll>> vecpll;typedef vector<pair<ll,pair<ll,bool>>> vecpllb;typedef vector<pair<int,pair<int,bool>>> vecpiib;typedef queue<ll> ql;typedef queue<pair<ll,ll>> qpll;typedef vector<char> vch;typedef set<char> sch;typedef set<int> si;typedef set<ll> sl;typedef set<string> ss;

// debug Outlet
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

template <typename T>
void _print(T t) {
    cerr << t;
}
template <>
void _print(bool t) {
    cerr << (t ? "true" : "false");
}
template <typename T>
void _print(vector<T> v) {    cerr << "[ ";    for (T i : v) {        _print(i);        cerr << " ";    }    cerr << "]";}
template <typename T>
void _print(set<T> s) {    cerr << "{ ";    for (T i : s) {        _print(i);        cerr << " ";    }    cerr << "}";}
template <typename T, typename U>
void _print(map<T, U> m) {    cerr << "{ ";    for (auto &p : m) {        cerr << "(";        _print(p.first);        cerr << ", ";        _print(p.second);        cerr << ") ";    }    cerr << "}";}
template <typename T>
void _print(multiset<T> ms) {    cerr << "{ ";    for (T i : ms) {        _print(i);        cerr << " ";    }    cerr << "}";}
template <typename T>
void _print(priority_queue<T> pq) {    cerr << "[ ";    priority_queue<T> temp = pq;    while (!temp.empty()) {        _print(temp.top());        cerr << " ";        temp.pop();    }    cerr << "]";}
template <typename T>
void _print(priority_queue<T, vector<T>, greater<T>> pq) {    cerr << "[ ";    priority_queue<T, vector<T>, greater<T>> temp = pq;    while (!temp.empty()) {        _print(temp.top());        cerr << " ";        temp.pop();    }    cerr << "]";}
template <typename T1,typename T2>void _print(const std::vector<std::pair<T1, T2>>& vec) {    std::cerr << "[";    for (size_t i = 0; i < vec.size(); ++i) {        std::cerr << "(" << vec[i].first << ", " << vec[i].second << ")";        if (i != vec.size() - 1) {            std::cerr << ", ";        }    }    std::cerr << "]";}


// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,T>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
//Constants
vector <ll> primes;
vector <bool> is_prime;
// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b %     m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool isPowerOfFour(int n) { return !(n&(n-1)) && (n&0x55555555);}
ll modinv(ll p,ll q){ll ex;ex=M-2;while (ex) {if (ex & 1) {p = (p * q) % M;}q = (q * q) % M;ex>>= 1;}return p;}
ll ncr(ll n,ll r){ll sum = 1;for(ll i = 1; i <= r; i++){    sum = sum * (n - r + i) / i;}    return (ll)sum;}
ll pov(ll a,ll b){if(a == 1){return 1;}ll ans = 1;while(b){if(b&1){ans = (ans * a)%M;}a = (a*a)%M;b >>=1;}return ans;}
struct dsu{
    map<ll,ll> size;
    map<ll,ll> parent;

    dsu(vector<int> &veci){
        for(int i = 0;i<veci.size();i++){
            parent[veci[i]] = veci[i];
            size[veci[i]] = 1;
        }
    }

    ll find_parent(ll node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }

    void connect(ll a,ll b){
        a = find_parent(a);
        b = find_parent(b);
        if(a != b){
            if(size[a] > size[b]){
                parent[b] = a;
                size[a] += size[b];
            }
            else{
                parent[a] = b;
                size[b] += size[a];
            }
        }
        
    }

};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        dsu temp(nums);
        for(int i = 0;i<nums.size();i++){
            if(temp.parent.count(nums[i] + 1)){
                temp.connect(nums[i]+1,nums[i]);
            }
            if(temp.parent.count(nums[i] - 1)){
                temp.connect(nums[i]-1,nums[i]);
            }
        }
        int ans = 0;
        for(auto itr : temp.size){
            ans = max(itr.sec,ans*1ll);
        }

        return ans;
    }
};