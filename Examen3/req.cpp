#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;


int phi(){
        
    return 0;
}

struct PST { //Persistent Segment Tree
    PST *izq, *der;
    int cn;

    PST () : izq(0), der(0), cn(0) {}
    PST (int cn) : izq(0), der(0), cn(cn) {}
    PST (PST *_izq, PST *_der) {
        izq = _izq, der = _der;
        cn = izq->cn + der->cn;
    }

    void build (int i, int j) {
        if (i == j) return;

        izq = new PST;
        der = new PST;

        int m = (i+j)/2;
        izq->build(i, m);
        der->build(m+1, j);
    }

    int query (int i, int j, int a, int b) {
        if (j < a || b < i) return 0;
        if (a <= i && j <= b) return cn;

        int m = (i+j)/2;
        return izq->query(i, m, a, b) + der->query(m+1, j, a, b);
    }

    PST *update (int i, int j, int p) {
        if (p < i || j < p) return this;
        if (i == j) return new PST(cn+1);

        int m = (i+j)/2;
        return new PST(
            izq->update(i, m, p),
            der->update(m+1, j, p));
    }
};

PST *st[MX+5];
int n, a[MX+5], q, L, R, A, B;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    st[0] = new PST;
    st[0]->build(1, MX);

    for (int i = 1; i <= n; i++)
        st[i] = st[i-1]->update(1, MX, a[i]);

    while (q--) {
        cin >> L >> R >> A >> B;
        cout << st[R]->query(1, MX, A, B) - st[L-1]->query(1, MX, A, B) << endl;
    }

    return 0;
}   

int main(){
    
    return 0;
}
