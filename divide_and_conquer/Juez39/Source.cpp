// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool porlospelos(std::vector<int> const & v, int ini, int fin){
	if (ini + 2 == fin){
		if (v[ini] == v[ini + 1] || v[ini + 1] - v[ini] == 1) return true;
		else return false;
	}
	else{
		int mitad = (ini + fin) / 2;
		return porlospelos(v, ini, mitad + 1) && porlospelos(v, mitad, fin);
	}
}
// función que resuelve el problema
bool resolver(std::vector<int> const & v) {
	return porlospelos(v, 0, v.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; i++) std::cin >> v[i];
	bool sol = resolver(v);
	// escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}