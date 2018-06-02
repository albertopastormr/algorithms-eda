// Alberto Pastor Moreno
// E46

/*
Coste O(n)
Ecuacion recurrencia:
T(n):	- c0			si n = 0, 1
- c1 + 2*T(n/2) si n>1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
struct tSol{
	int pos = 0, sum = 0;
};

tSol canicas(std::vector<int> const & v, int ini, int fin){
	tSol sol;
	if (ini + 1 == fin){
		sol.pos = ini;
		sol.sum = v[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		tSol solIz = canicas(v, ini, mitad);
		tSol solDr = canicas(v, mitad, fin);
		if (solIz.sum >= solDr.sum){
			sol.sum = solIz.sum + (solDr.sum / 2);
			sol.pos = solIz.pos;
		}
		else{
			sol.sum = solDr.sum + (solIz.sum / 2);
			sol.pos = solDr.pos;
		}
	}
	return sol;
}
// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	return canicas(v, 0, v.size());
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
	std::vector<std::string> nombres(numElem);
	for (int i = 0; i < numElem; i++){
		std::cin >> nombres[i] >> v[i];
	}
	tSol sol = resolver(v);
	// escribir sol
	std::cout << nombres[sol.pos] << " " << sol.sum << "\n";
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