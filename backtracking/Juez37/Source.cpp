// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void navidades(std::vector<int> const & costes, std::vector<int> const & superficies,int k, int & sup, int & maxSup, int presupuesto, int & coste) {
	// Cogiendo el objeto en el nivel k
	coste += costes[k];
	sup += superficies[k];
	if (coste <= presupuesto){
		if (k + 1 == costes.size()){
			if (sup > maxSup) maxSup = sup;
		}
		else navidades(costes, superficies, k + 1, sup, maxSup, presupuesto, coste);
	}
	coste -= costes[k];
	sup -= superficies[k];
	// No cogiendo el objeto del nivel k
	if (k + 1 == costes.size()){
		if (sup > maxSup) maxSup = sup;
	}
	else navidades(costes, superficies, k + 1, sup, maxSup, presupuesto, coste);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numObj, presupuesto;
	std::cin >> numObj >> presupuesto;
	if (!std::cin)
		return false;
	std::vector<int> costes(numObj), superficies(numObj);
	//std::vector< bool> sol(numObj);
	for (int i = 0; i < numObj; i++) std::cin >> costes[i]; // Entrada del coste de cada objeto
	for (int j = 0; j < numObj; j++) std::cin >> superficies[j]; // Entrada de la superficie de cada objeto
	// Inicializar a falsos sol
	int sup = 0, maxSup = 0, coste = 0;
	navidades(costes, superficies, 0, sup, maxSup, presupuesto, coste);
	// escribir sol
	std::cout << maxSup << "\n";
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