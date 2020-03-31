#include <tuple>

using namespace std;

int main(){
	tuple<int,string,double,long long int> t;

	//Asignando otra tupla
	t = make_tuple(1,"tupla",23.4927,-243243);
	//Obteniendo un valor de tupla
	int t_int = get<1>(t); //get< index > (tupla)
	//Asingnando un valor a un elemento de la tupla
	get<2>(t) = "tuple";


	return 0;
}
