#include <bits/stdc++.h>

using namespace std;

struct nodo{
    int x;
    bool visitado;
    set<int> Fx;
    nodo():x(0), visitado(false){}
};

class Grafo{
    private:
        vector<nodo> v;
    public:
        Grafo(int n){
            v.assign(n, nodo());
        }

        void connect(int x, int y){
            v[x].Fx.insert(y);
            v[y].Fx.insert(x);
        }

        int BFS(int x){
            queue<int> cola;
            cola.push(x);
            int aux;
            v[x].x = 0;
            set<int>::iterator it;
            while(!cola.empty()){
                aux = cola.front();
                cola.pop();
                v[aux].visitado = true;
                for(it = v[x].Fx.begin(); it != v[x].Fx.end(); it++){
                    if(v[*it].visitado)
                        continue;
                    cola.push(*it);
                    v[*it].x = v[aux].x + 1;
                }

                v[aux].visitado = false;
            }
        }

        void imprimir(){
            for(int i = 0; i < v.size(); i++)
                cout << i << ' ' << v[i].x << " "; 
        }
        //Deep  Search
        int DFS(int x){
            
        }
};

int main(){

    int n, m, a, b;
    Grafo g(n);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        g.connect(a, b);
    }
    g.BFS(0);
    g.imprimir();

}