// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> const & v, int d) {
	bool exito = true;
	int x = 0, contNum = 1; 
	while (x < v.size() - 1 && exito){
		if (v[x + 1] - v[x] != 1 && v[x] != v[x + 1]) exito = false; // Condicion para 'por los pelos'
		if (v[x] == v[x + 1]) contNum++;
		else contNum = 1;
		if (contNum > d) exito = false; // Condicion para 'd-divertido'
		x++;
	}
	return exito;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, d;
	std::cin >> d >> numElem;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; i++) std::cin >> v[i];
	bool sol = resolver(v, d);
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