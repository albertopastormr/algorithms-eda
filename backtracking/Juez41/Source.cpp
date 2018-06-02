// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector<int> const & sol, int k){
	if (k >= 2 && sol[k - 2] == sol[k - 1] && sol[k - 1] == sol[k]) return false;
	else return true;
}

// función que resuelve el problema
void resolver(std::vector<int> const & consumo, std::vector<int> & marcas, int k, int & numPosib, int & consumoActual, int consumoMax, int n, std::vector<int> & sol) {
	for (int x = 0; x < consumo.size(); x++){
		marcas[x]++;
		consumoActual += consumo[x];
		sol[k] = x;
		if (consumoActual <= consumoMax && marcas[x] <= k + 2 - marcas[x] && esValida(sol, k) ){
			if (k + 1 == n) numPosib++;
			else resolver(consumo, marcas, k + 1, numPosib, consumoActual, consumoMax, n, sol);
		}
		marcas[x]--;
		consumoActual -= consumo[x];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, numCol, consMax, numPosib = 0, consumoActual = 0;
	std::cin >> n >> numCol >> consMax;
	if (!std::cin)
		return false;
	std::vector<int> consumo(numCol), marcas(numCol), sol(n);
	for (int i = 0; i < numCol; i++) std::cin >> consumo[i];
	resolver(consumo, marcas, 0 , numPosib, consumoActual, consMax, n, sol);
	std::cout << numPosib << "\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}