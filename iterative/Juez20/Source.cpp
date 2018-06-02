// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> & v) {
	bool zero = false;
	int x = 0;
	while (x < v.size() && !zero) {
		if (v[x] == 0){
			std::swap(v[0], v[x]);
			zero = true;
		}
		x++;
	}
	if (zero && v.size() > 1){
		int i = 1, k = 1;
		while (i < v.size()){
			if (v[i] % 2 == v[k - 1] % 2) i++;
			else{
				std::swap(v[i], v[k]);
				k++;
			}
		}
		if (k % 2 == 1)	v.resize(k - 1);
		else  v.resize(k);
	}
	else{
		v.resize(0);
	}
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
	resolver(v);
	// escribir sol
	for (int j = 0; j < v.size(); j++){
		std::cout << v[j] << " ";
	}
	std::cout << "\n";
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