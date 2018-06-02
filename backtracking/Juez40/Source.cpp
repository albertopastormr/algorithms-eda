// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
void escribirSol(std::vector<int> const & sol){
	std::cout << sol[0];
	for (int x = 1; x < sol.size(); x++) std::cout << " " << sol[x];
	std::cout << "\n";
}

// función que resuelve el problema
void resolver(std::vector<int> & sol, int k, int n, int d, int e, std::vector<int> & marcas) {
	for (int i = 0; i < n; i++){
		sol[k] = i + e;
		marcas[i]++;
		if ( (sol[k] == sol[k - 1] || sol[k] - sol[k - 1] == 1) &&  marcas[i] <= d){
			if (k + 1 == n) escribirSol(sol);
			else resolver(sol, k + 1, n, d, e, marcas);
		}
		marcas[i]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, d, e;
	std::cin >> n >> d >> e;
	std::vector<int> sol(n), marcas(n, 0);
	sol[0] = e;
	marcas[0] = 1;
	if (n == 1) std::cout << e << "\n";
	else resolver(sol, 1, n, d, e, marcas);
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