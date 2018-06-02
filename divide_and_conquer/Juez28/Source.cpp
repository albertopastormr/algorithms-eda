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

struct tSol{
	bool ok;
	float max;
	float sum;
	float min;
};
tSol trenes(std::vector<int> const & v, int ini, int fin){
	tSol sol;
	if (ini + 1 == fin){ // Caso base
		sol.ok = true;
		sol.min = sol.max = sol.sum = v[ini];
	}
	else{
		int mitad = (ini + fin) / 2;
		tSol solIz = trenes(v, ini, mitad); // Resuelvo el problema para ambos lados tras partir por la mitad el vector
		tSol solDr = trenes(v, mitad, fin);
		if (solIz.max >= solDr.max){ // Me quedo el maximo entre la solucion de la izquierda y de la derecha para sol
			sol.max = solIz.max;
		}
		else{
			sol.max = solDr.max;
		}
		if (solIz.min <= solDr.min){ // Me quedo el minimo entre la solucion de la izquierda y de la derecha para sol
			sol.min = solIz.min;
		}
		else{
			sol.min = solDr.min;
		}
		sol.sum = solIz.sum + solDr.sum;
		float media = sol.sum / (fin-ini);
		sol.ok = solIz.ok && solDr.ok && (sol.max <= media + media / 2) && (sol.min >= media - media / 2); // Reuno todas las condiciones para que se cumpla sol.ok
	}
	return sol;
}
// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	return trenes(v, 0, v.size());
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
	if (sol.ok){
		std::cout << "SI\n";
	}
	else{
		std::cout << "NO\n";
	}
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