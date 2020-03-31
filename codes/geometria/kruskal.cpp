#include <utility>
#include <algorithm>

typedef pair<int,int> ii;
typedef pair<int, ii> arista;

//Necesita de Union Find

int kruskal(int v, vector <arista> &aristas){
	//Funciona con caminos negativos
	int origen, destino, peso, total=0;

	UnionFind mst(v);
	sort(aristas.begin(), aristas.end());
	for(int i=0; i<aristas.size(); i++){
		peso = aristas[i].first;
		origen = aristas[i].second.first;
		destino = aristas[i].second.second;
		if(!mst.isSameSet(origen, destino)){
			total += peso;
			mst.unionSet(origen,destino);
		}
	}

	return total; //Peso del camino minimo
}


