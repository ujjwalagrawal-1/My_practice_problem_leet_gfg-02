#define bullet() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define Pai (3.141592653589)
#define M 1000000007
#define in(x) insert(x);
#define pb push_back
#define pp pop_back
#define f first
#define s second
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
#define rtn return;

int powint(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) {result *= base;}return result;}

//Typedef
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vec;
typedef vector<char> vec_ch;
typedef map<ll,ll> mp;
typedef unordered_map<int,int> ump;
typedef vector<vector<ll>> dvec;
typedef vector<pair<ll,ll>> vec_pair;
typedef vector<pair<ll,pair<ll,bool>>> vec_db_pr;
typedef queue<ll> q;
typedef queue<pair<ll,ll>> doq;
typedef vector<char> vch;
typedef set<char> sc;
typedef set<int> si;
typedef set<ll> sl;
typedef set<string> ss;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        bullet()
        sort(all(nums));
        ll mid = (sz(nums)-1)/2; 
        ll ans = 0;
        rep(i,sz(nums)){
            ans += abs(nums[i] - nums[mid]);
        }
        return ans;
    }
};