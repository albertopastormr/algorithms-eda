// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int sum = 0, ind = -1, len = 0;
};


// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	tSol sol;
	int auxSum = 0, auxLen = 0, auxInd = 0;
	for (int x = 0; x < v.size(); x++){
		auxSum += v[x];
		if (auxSum <= 0){
			auxInd = x + 1;
			auxSum = 0;
		}
		else {
			auxLen = x - auxInd;
			if (auxSum > sol.sum){
				sol.sum = auxSum;
				sol.ind = auxInd;
				sol.len = auxLen;
			}
			else if (auxSum == sol.sum && auxLen < sol.len){
				sol.sum = auxSum;
				sol.ind = auxInd;
				sol.len = auxLen;
			}
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	if (!std::cin)
		return false;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; i++){
		std::cin >> v[i];
	}
	tSol sol = resolver(v);
	// escribir sol
	std::cout << sol.sum << " " << sol.ind << " " << sol.len << "\n";
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