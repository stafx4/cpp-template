#if !__INCLUDE_LEVEL__
#include __FILE__
//-------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------
// unordered_set
//__builtin_popcountll
//./a.out < in.txt > out.txt
// g++ -std=gnu++23 -O0 -g0 -pipe -I. a.cpp
#else
#ifdef LOCAL
#include "pch.hpp"
#else
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#endif

#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
#endif

// #include <boost/multiprecision/cpp_int.hpp>
// namespace boo = boost::multiprecision;
using mint = modint998244353;
// 1000000007
// 998244353
using pll = pair<long long, long long>;
typedef long long ll;
typedef long double ld;
// #define _GLIBCXX_DEBUG
#define INF (ll)2e18
#define fi first
#define se second
#define R return 0
#define PB push_back
#define stirng string
#define vll vector<ll>
#define mutliset multiset
#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define ANS cout << ans << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dou fixed << setprecision(20)
#define an cout << (ans ? "Yes" : "No")
#define en cout << "------------" << endl
// #define min(x,y) ((x) < (y) ? (x) : (y))
// #define max(x,y) ((x) > (y) ? (x) : (y))
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vv(name, h, w, type, init) \
    std::vector<std::vector<type>> name((h), std::vector<type>((w), (init)))
#define vvv(name, d, h, w, type, init)                    \
    std::vector<std::vector<std::vector<type>>> name((d), \
                                                     std::vector<std::vector<type>>((h), std::vector<type>((w), (init))))
#define vvvv(name, x, y, z, w, type, init)                                                                         \
    std::vector<std::vector<std::vector<std::vector<type>>>> name((x),                                             \
                                                                  std::vector<std::vector<std::vector<type>>>((y), \
                                                                                                              std::vector<std::vector<type>>((z), std::vector<type>((w), (init)))))
#define vvvvv(name, a, b, c, d, e, type, init)                                  \
    std::vector<std::vector<std::vector<std::vector<std::vector<type>>>>> name( \
        (a), std::vector<std::vector<std::vector<std::vector<type>>>>(          \
                 (b), std::vector<std::vector<std::vector<type>>>(              \
                          (c), std::vector<std::vector<type>>(                  \
                                   (d), std::vector<type>((e), (init))))))
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
long long TEN(int x) { return x == 0 ? 1 : TEN(x - 1) * 10; }
template <typename T>
constexpr std::pair<T, T> myminmax(const T& a, const T& b) {
    // 比較に基づいて {min, max} を直接組み立てて返す
    return (b < a) ? std::pair{b, a} : std::pair{a, b};
}
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
auto rle(const T& v) {
    using val_t = typename T::value_type;
    std::vector<std::pair<val_t, ll>> res;
    
    for (const auto& elem : v) {
        if (res.empty() || res.back().first != elem) {
            res.emplace_back(elem, 1);
        } else {
            res.back().second++;
        }
    }
    return res;
}
// ll mod = (ll)1000000007;
ll mod = (ll)998244353;
//  ll inv = 499122177;
vector<ll> f1 = {0, -1, 0, 1}, f2 = {-1, 0, 1, 0};                             // 四方向
vector<ll> f3 = {-1, 0, 1, 0, 1, -1, 1, -1}, f4 = {0, 1, 0, -1, 1, 1, -1, -1}; // ハチ方向
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
long long reduce(const vector<T> &a)
{
    long long s = 0;
    for (auto &x : a)
        s += x;
    return s;
}
void yn(bool ok)
{
    cout << (ok ? "Yes" : "No") << '\n';
}

#define yu_qurid(x, y) ((x) * (x) + (y) * (y))                   // ユークリッド距離 sqrtはしてないなので注意
#define mannhattan(x1, x2, y1, y2) (abs(x1 - x2) + abs(y1 - y2)) // マンハッタン距離 = |x1-x2|+|y1-y2|
// reference @frest
#define vc_cout(v)                   \
    do                               \
    {                                \
        ll nn = v.size();            \
        for (int i = 0; i < nn; i++) \
        {                            \
            cout << v[i] << " ";     \
        }                            \
        cout << endl;                \
    } while (0)

#define vv_cout(v)                                \
    do                                            \
    {                                             \
        ll nn = v.size();                         \
        for (int i = 0; i < nn; i++)              \
        {                                         \
            for (int j = 0; j < v[i].size(); j++) \
                cout << v[i][j] << " ";           \
            cout << endl;                         \
        }                                         \
    } while (0)
// n(10進数)をa進数に
string to_oct(ll n, ll a)
{
    string s;
    while (n)
    {
        s = to_string(n % a) + s;
        n /= a;
    }
    return s;
}

bool bfs_est(ll xx1, ll yy1, ll hhh, ll www)
{
    return (0 <= xx1 && xx1 < hhh && 0 <= yy1 && www > yy1);
}
static const auto fast_io = []()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    return 0;
}();


#define vvl_kaiten(v)                                   \
    {                                                   \
        ll n = size(v);                                 \
        vvl nx(n, vl(n));                               \
        rep(i, n) rep(j, n) nx[j][n - i - 1] = v[i][j]; \
        swap(nx, v);                                    \
    } // 時計回りに90°回転
// #define vvl_kaiten(v) {ll n = size(v);vvl nx(n,vl(n));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//反時計周りに90°回転

#define vs_kaiten(v)                                    \
    {                                                   \
        ll n = v.size();                                \
        vector<string> nx(n, string(n, '.'));           \
        rep(i, n) rep(j, n) nx[j][n - i - 1] = v[i][j]; \
        swap(nx, v);                                    \
    } // 文字列版 時計回りに90°回転
// #define vs_kaiten(v) {ll n = size(v);vs nx(n,string(n,'.'));rep(i,n)rep(j,n)nx[n-j-1][i]=v[i][j];swap(nx,v);}//文字列版　反時計周りに90°回転

bool IsPrime(int num) // 素数判定
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    // 素数である
    return true;
}
long long modpow(long long a, long long n, long long mod)
{ //@Nyaan
    a %= mod;
    long long ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret % mod;
};

vector<ll> enumdiv(ll n)
{ // 約数全列挙
    vector<ll> S;
    for (ll i = 1; 1LL * i * i <= n; i++)
        if (n % i == 0)
        {
            S.push_back(i);
            if (i * i != n)
                S.push_back(n / i);
        }
    //  sort(S.begin(), S.end());
    return S;
}
// struct NewlineGuard {//プログラム終了時に改行
//     ~NewlineGuard() { cout << '\n'; }
// };
// NewlineGuard guard;

struct pair_hash
{ // unodered_mapの時に使う
    // unordered_map<pll,ll, pair_hash> mp;
    size_t operator()(const pair<ll, ll> &p) const
    {
        // 64bit のハッシュ合成
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};
struct VectorHash
{
    size_t operator()(const vector<long long> &v) const
    {
        size_t h = 0;
        for (long long x : v)
        {
            h = h * 31 + std::hash<long long>()(x);
        }
        return h;
    }
};

vector<pair<long long, long long>> prime_factorize(long long n)
{ // 素数全検挙 @drken
    vector<pair<long long, long long>> res;
    for (long long p = 2; p * p <= n; ++p)
    {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0)
        {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
ll LIS(const vector<long long> &a)
{
    int N = (int)a.size();
    vector<long long> dp_(N, INF);
    for (int i = 0; i < N; ++i)
    {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp_.begin(), dp_.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
    }

    // dp[k] < INF となる最大の k に対して k+1 が答え
    // それは dp[k] >= INF となる最小の k に一致する
    return lower_bound(dp_.begin(), dp_.end(), INF) - dp_.begin();
}
static const auto fast_io = []()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    return 0;
}();

bool colinear(ll ax, ll ay, ll bx, ll by, ll cx, ll cy)
{
    // 2つのA,Bを通る直線上にcがのってるかどうか
    long long val1 = (by - ay) * (cx - ax);
    long long val2 = (bx - ax) * (cy - ay);
    return (val1 == val2);
}

template <class T>
bool next_combination(T &bit, int N)
{
    T x = bit & -bit, y = bit + x;
    bit = (((bit & ~y) / x) >> 1) | y;
    return (bit < (1LL << N));
}
//@tatyam
template<class T> using P = pair<T, T>;
#define xxxx first  // pairの第一要素へ
#define yyyy second // pairの第二要素へ
template<class T> P<T> operator+(const P<T>& a, const P<T>& b) { return {a.xxxx + b.xxxx, a.yyyy + b.yyyy}; } // ベクトル加算
template<class T> P<T> operator-(const P<T>& a, const P<T>& b) { return {a.xxxx - b.xxxx, a.yyyy - b.yyyy}; } // ベクトル減算
template<class T> P<T> operator-(const P<T>& a) { return {-a.xxxx, -a.yyyy}; } // 符号の反転
template<class T, class U> P<T> operator*(const P<T>& a, const U& b) { return {a.xxxx * b, a.yyyy * b}; } // スカラー倍
template<class T, class U> P<T> operator/(const P<T>& a, const U& b) { return {a.xxxx / b, a.yyyy / b}; } // スカラー除算
template<class T> P<T>& operator+=(P<T>& a, const P<T>& b) { return a = a + b; } // 加算代入
template<class T> P<T>& operator-=(P<T>& a, const P<T>& b) { return a = a - b; } // 減算代入
template<class T, class U> P<T>& operator*=(P<T>& a, const U& b) { return a = a * b; } // 乗算代入
template<class T, class U> P<T>& operator/=(P<T>& a, const U& b) { return a = a / b; } // 除算代入
template<class T> P<T> rotate(const P<T>& a) { return {-a.yyyy, a.xxxx}; } // 90度回転(反時計)
template<class T> T dot(const P<T>& a, const P<T>& b) { return a.xxxx * b.xxxx + a.yyyy * b.yyyy; } // 内積の計算
template<class T> T cross(const P<T>& a, const P<T>& b) { return dot(rotate(a), b); } // 外積の計算
template<class T> T square(const P<T>& a) { return dot(a, a); } // ベクトルの二乗ノルム
template<class T> ld abs(const P<T>& a) { return hypotl(a.xxxx, a.yyyy); } // ベクトルの絶対値
template<class T> T gcd(const P<T>& a) { return gcd(a.xxxx, a.yyyy); } // 各成分の最大公約数
template<class T> P<T> normalize(P<T> a) { // ベクトルの正規化
    if(a == P<T>{}) return a; // 零ベクトルの判定
    a /= gcd(a); // 公約数で割る
    if(a < P<T>{}) a = -a; // 向きを揃える
    return a; // 正規化後のベクトル
}
// 点 P1, P2 から ax + by + c = 0 の係数を取得
template<class T>
void get_line_equation(P<T> p1, P<T> p2, T &a, T &b, T &c) {
    P<T> v = p2 - p1;
    P<T> normal = rotate(v); // 法線ベクトル (-dy, dx)
    
    a = normal.xxxx;
    b = normal.yyyy;
    c = -(a * p1.xxxx + b * p1.yyyy);
}
//外積が0なら平行→cross
//内積が0なら垂直
//--------------------------------------------------------------------------
struct Edge {
    long long cost; // 辺のコスト
    ll u, v;       // 結ばれている2つの頂点
    ll id;         // 辺の元のインデックス
    //2026.07.24
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

struct UnionFind {
    std::vector<ll> parent;

    UnionFind(ll n) {
        parent.resize(n);
        for (ll i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(ll i, ll j) {
        ll root_i = find(i);
        ll root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};
std::pair<ll, std::vector<ll>> kruskal(ll num_vertices, std::vector<Edge>& edges) {
    std::sort(edges.begin(), edges.end());

    UnionFind uf(num_vertices);
    ll total_cost = 0;
    std::vector<ll> used_edge_ids;
    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            total_cost += edge.cost;
            used_edge_ids.push_back(edge.id);
        }
    }

    return {total_cost, used_edge_ids};
}

// int main() {
//     // サンプルデータの入力例
//     // 頂点数: 4, 辺の数: 5
//     int n = 4;
//     std::vector<Edge> edges = {
//         {2, 0, 1, 0}, // cost=2, u=0, v=1, id=0
//         {1, 0, 2, 1}, // cost=1, u=0, v=2, id=1
//         {4, 1, 2, 2}, // cost=4, u=1, v=2, id=2
//         {3, 1, 3, 3}, // cost=3, u=1, v=3, id=3
//         {5, 2, 3, 4}  // cost=5, u=2, v=3, id=4
//     };

//     auto [min_cost, used_ids] = kruskal(n, edges);

//     std::cout << "最小コスト: " << min_cost << std::endl;
//     std::cout << "使った辺のidx: ";
//     for (int id : used_ids) {
//         std::cout << id << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

template <typename T, size_t N>
class NDPrefixSum {
private:
    std::array<long long, N> shape;
    std::array<long long, N> strides;
    std::vector<T> data;
    bool is_built;

    void compute_strides() {
        long long prod = 1;
        for (long long i = static_cast<long long>(N) - 1; i >= 0; --i) {
            strides[i] = prod;
            prod *= shape[i];
        }
    }

    void accumulate_along_dim(long long current_dim, long long target_dim, std::array<long long, N>& indices) {
        if (current_dim == static_cast<long long>(N)) {
            long long base_idx = 0;
            for (long long i = 0; i < static_cast<long long>(N); ++i) {
                if (i != target_dim) {
                    base_idx += indices[i] * strides[i];
                }
            }
            
            for (long long i = 1; i < shape[target_dim]; ++i) {
                long long prev_idx = base_idx + (i - 1) * strides[target_dim];
                long long curr_idx = base_idx + i * strides[target_dim];
                data[curr_idx] += data[prev_idx];
            }
            return;
        }

        if (current_dim == target_dim) {
            indices[current_dim] = 0;
            accumulate_along_dim(current_dim + 1, target_dim, indices);
        } else {
            for (long long i = 0; i < shape[current_dim]; ++i) {
                indices[current_dim] = i;
                accumulate_along_dim(current_dim + 1, target_dim, indices);
            }
        }
    }

    void query_recursive(long long dim, const std::array<long long, N>& low, const std::array<long long, N>& high, 
                         std::array<long long, N>& current_idx, bool positive, T& sum) const {
        if (dim == static_cast<long long>(N)) {
            long long idx = 0;
            for (long long i = 0; i < static_cast<long long>(N); ++i) {
                idx += current_idx[i] * strides[i];
            }
            if (positive) {
                sum += data[idx];
            } else {
                sum -= data[idx];
            }
            return;
        }

        current_idx[dim] = high[dim];
        query_recursive(dim + 1, low, high, current_idx, positive, sum);

        if (low[dim] > 0) {
            current_idx[dim] = low[dim] - 1;
            query_recursive(dim + 1, low, high, current_idx, !positive, sum);
        }
    }

public:
    explicit NDPrefixSum(const std::array<long long, N>& shape) : shape(shape), is_built(false) {
        compute_strides();
        long long total_size = 1;
        for (long long s : shape) {
            total_size *= s;
        }
        data.assign(total_size, T(0));
    }

    void set(const std::array<long long, N>& indices, const T& value) {
        assert(!is_built);
        long long idx = 0;
        for (long long i = 0; i < static_cast<long long>(N); ++i) {
            assert(indices[i] >= 0 && indices[i] < shape[i]);
            idx += indices[i] * strides[i];
        }
        data[idx] = value;
    }

    void build() {
        if (is_built) return;
        std::array<long long, N> indices{};
        for (long long d = 0; d < static_cast<long long>(N); ++d) {
            accumulate_along_dim(0, d, indices);
        }
        is_built = true;
    }

    T query(const std::array<long long, N>& low, const std::array<long long, N>& high) const {
        assert(is_built);
        for (long long i = 0; i < static_cast<long long>(N); ++i) {
            assert(low[i] <= high[i]);
            assert(high[i] < shape[i]);
        }

        T sum = T(0);
        std::array<long long, N> current_idx{};
        query_recursive(0, low, high, current_idx, true, sum);
        return sum;
    }
};
//２次元累積和
//ARC205 A 2x2 Erasingを参照

// グラフの辺を表す構造体
/*
struct Edge {
    int to;
    long long cost;
};

class DijkstraGraph {
private:
    int n; // 頂点数
    vector<vector<Edge>> adj; // 隣接リスト

public:
    // コンストラクタ（頂点数を指定して初期化）
    DijkstraGraph(int vertices) : n(vertices), adj(vertices) {}

    // 有向辺を追加する関数（無向グラフの場合は両方向に追加してください）
    void add_edge(int from, int to, long long cost) {
        adj[from].push_back({to, cost});
    }

    // ダイクストラ法を実行し、指定した始点からの最短距離を返す
    // 到達不可能な頂点は -1 (またはINF) となる
    vector<long long> solve(int start) {
        vector<long long> dist(n, INF);
        
        // priority_queue はデフォルトで最大ヒープなので、{cost, vertex} の形で最小ヒープにする
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // すでに記録されている最短距離より大きい場合はスキップ
            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                if (dist[u] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.cost;
                    pq.push({dist[edge.to], edge.to});
                }
            }
        }

        return dist;
    }
};
*/
//dijkstra
//ARC205 B


namespace inversion_impl {
    using S = long long;
    S op(S a, S b) { return a + b; }
    S e() { return 0; }
}

/**
 * @brief 転倒数（Inversion Number）を求める関数
 * 
 * @tparam T 配列の要素型
 * @param q 0 ~ n-1 の順列（または値の範囲が 0 <= x < n である要素数nの配列）
 * @return long long 転倒数
 */
template <typename T>
long long inversion_permutation(const std::vector<T>& q) {
    int n = static_cast<int>(q.size());
    if (n <= 1) return 0;

    // 区間和を管理する Point Add Range Sum セグメント木
    atcoder::segtree<inversion_impl::S, inversion_impl::op, inversion_impl::e> seg(n);
    
    long long inversions = 0;

    for (int i = 0; i < n; ++i) {
        int val = static_cast<int>(q[i]);
        
        // val より厳密に大きい値（val + 1 から n - 1）の出現個数を加算
        inversions += seg.prod(val + 1, n);
        
        // val の出現カウントを +1 (初期値 0 に 1 を設定)
        seg.set(val, seg.get(val) + 1);
    }

    return inversions;
}

//転倒数
//適当にやればでる
#endif
