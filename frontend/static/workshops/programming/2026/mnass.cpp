#include<bits/stdc++.h>
using namespace std;
#define int long long

constexpr int MAXN = 2e5+5, INF = 1e18;
int n, q, a[MAXN];

struct ST {
    struct N {
        int vl, vr, vlr, v0;
    } st[4*MAXN];

    N merge(N l, N r) {
        return {
            max({l.vl + r.vl, l.vlr + r.v0, l.vl + r.v0}),
            max({l.vr + r.vr, l.v0 + r.vlr, l.v0 + r.vr}),
            max({l.vlr + r.vr, l.vl + r.vlr, l.vl + r.vr}),
            max({l.v0 + r.v0, l.vr + r.v0, l.v0 + r.vl})
        };
    }

    void upd(int p, int v, int i = 1, int l = 1, int r = n) {
        if (l == r) return void(st[i] = {-INF, -INF, v, 0});
        int mid = (l+r)/2;
        if (p <= mid) upd(p, v, 2*i, l, mid);
        else upd(p, v, 2*i+1, mid+1, r);
        st[i] = merge(st[2*i], st[2*i+1]);
    }
    N _qry(int lq, int rq, int i = 1, int l = 1, int r = n) {
        if (lq <= l && r <= rq) return st[i];
        int mid = (l+r)/2;
        if (rq < mid+1) return _qry(lq, rq, 2*i, l, mid); // Left only
        if (lq > mid) return _qry(lq, rq, 2*i+1, mid+1, r); // Right only
        return merge(_qry(lq, rq, 2*i, l, mid), _qry(lq, rq, 2*i+1, mid+1, r));
    }
    int qry(int lq, int rq) {
        N ret = _qry(lq, rq);
        return max({ret.v0, ret.vl, ret.vr, ret.vlr});
    }
} st;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.upd(i, a[i]);
    }
    for (int x, y, i = 1; i <= q; i++) {
        char ch; cin >> ch >> x >> y;
        if (ch == 'U') st.upd(x, y);
        else cout << st.qry(x, y) << "\n";
    }
}