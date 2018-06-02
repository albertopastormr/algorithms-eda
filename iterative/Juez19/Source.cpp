// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
struct tSol{
	int lenSeq = 0, numLlanos = 0;
};

// función que resuelve el problema
tSol resolver(std::vector<int> const & v, std::vector<int> & vaux, int minBuild) {
	tSol sol;
	int auxInd = v.size() - 1, auxLen = 1;
	int maxDr = v[v.size() - 1];
	bool guardado = false;
	for (int x = v.size() - 1; x > 0; x--){
		if (v[x] > maxDr){ // Obtener el maximo segun recorre el vector
			maxDr = v[x];
		}
		if (v[x] == v[x - 1] && v[x] >= maxDr){ // Pregunta si v[x] esta en una secuencia valida
			auxLen++;
			if (auxLen >= minBuild){
				if (auxLen > sol.lenSeq){
					sol.lenSeq = auxLen;
				}
				if (!guardado){
					sol.numLlanos++;
					vaux.push_back(auxInd);
					guardado = true;
				}
			}
		}
		else{ // Se pasa el indice auxiliar a la siguiente posible secuencia y se reinicia la secuencia
			auxInd = x - 1;
			auxLen = 1;
			guardado = false;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, minBuild;
	std::cin >> numElem >> minBuild; // Lectura numero de elementos y el minimo necesario para construir
	if (!std::cin)
		return false;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; i++){ // Lectura datos enunciado
		std::cin >> v[i];
	}
	std::vector<int> vaux;
	tSol sol = resolver(v, vaux, minBuild);
	// escribir sol
	std::cout << sol.lenSeq << " " << sol.numLlanos;
	for (int k = 0; k < vaux.size(); k++){
		std::cout << " " << vaux[k];
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