#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int MAXN = 2e5+5, INF = 1e18;
int n;

// Standard point-update range-sum-query segtree.
struct ST {
    int st[4*MAXN];
    
    // Set position p to value v.
    void upd(int p, int v, int i = 1, int l = 1, int r = n) {
        if (l == r) return void(st[i] = v);
        int mid = (l+r)/2;
        if (p <= mid) upd(p, v, 2*i, l, mid);
        else upd(p, v, 2*i+1, mid+1, r);
        st[i] = st[2*i] + st[2*i+1]; // In general, any merge function.
    }
    // Query the sum of [lq...rq].
    int qry(int lq, int rq, int i = 1, int l = 1, int r = n) {
        if (lq <= l && r <= rq) return st[i];
        int mid = (l+r)/2, ret = 0;
        if (lq <= mid) ret += qry(lq, rq, 2*i, l, mid);
        if (rq >= mid+1) ret += qry(lq, rq, 2*i+1, mid+1, r);
        return ret;
    }
} st;

// Sparse segtree - make nodes only when necessary.
struct SP_ST {
    struct N {
        int v, lc, rc;
    } st[80*MAXN];
    int ptr = 1; // Current # nodes allocated

    void crt(int i) {
        if (!st[i].lc) st[i].lc = ++ptr;
        if (!st[i].rc) st[i].rc = ++ptr;
    }
    // Set position p to value v.
    void upd(int p, int v, int i = 1, int l = 1, int r = n) {
        if (l == r) return void(st[i].v = v);
        crt(i);
        int mid = (l+r)/2;
        if (p <= mid) upd(p, v, 2*i, l, mid);
        else upd(p, v, 2*i+1, mid+1, r);
        st[i].v = st[2*i].v + st[2*i+1].v;
    }
    // Query the sum of [lq...rq].
    int qry(int lq, int rq, int i = 1, int l = 1, int r = n) {
        if (lq <= l && r <= rq) return st[i].v;
        crt(i);
        int mid = (l+r)/2, ret = 0;
        if (lq <= mid) ret += qry(lq, rq, 2*i, l, mid);
        if (rq >= mid+1) ret += qry(lq, rq, 2*i+1, mid+1, r);
        return ret;
    }
} sp_st;

// Range updates, point queries.
struct ST {
    int st[4*MAXN];
    
    // Add v to all elements in [lq...rq].
    void upd(int lq, int rq, int v, int i = 1, int l = 1, int r = n) {
        if (lq <= l && r <= rq) return void(st[i] += v);
        int mid = (l+r)/2;
        if (lq <= mid) upd(lq, rq, v, 2*i, l, mid);
        if (rq >= mid+1) upd(lq, rq, v, 2*i+1, mid+1, r);
    }
    // Find value stored at position p.
    int qry(int p, int i = 1, int l = 1, int r = n) {
        if (l == r) return st[i];
        int mid = (l+r)/2;
        if (p <= mid) return st[i] + qry(p, 2*i, l, mid);
        else return st[i] + qry(p, 2*i+1, mid+1, r);
    }
} st;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int x, i = 1; i <= n; i++) {
        cin >> x;
        st.upd(i, x); // O(N log N) build
    }
}