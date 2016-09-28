#include<vector>
#include<iostream>

using namespace std;

class Lista
{
	public:
		Lista();
		vector<int> vizinhos;
};
Lista::Lista()
{
	
}

class Grafo
{
    private:
        vector<Lista> adj;
        int vertices;
        int arestas;

    public:
        Grafo(int);
        void AddAresta(int, int);
        void DelAresta(int, int);
        Lista getAdj();
        void print();
        //void destroy();
};

Grafo::Grafo(int n)
{
	if(n != 0)
	{
		//destroy();
	}
	vertices = n;
	for(int i = 1 ; i <= n ; i++)
	{
		Lista l;
		adj.push_back(l);
	}
}
void Grafo::AddAresta(int u, int v)
{
	adj[u].vizinhos.push_back(v);
}

