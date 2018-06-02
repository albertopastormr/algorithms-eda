// Alberto Pastor Moreno
// E46

/*
Coste O(log(n))
Ecuacion recurrencia:
T(n):	- c0			si n = 0, 1
- c1 + T(n/2) si n>1
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

char prisionero(std::vector<char> const & v, int ini, int fin)
{
	char sol;
	if (ini + 2 == fin){
		sol = v[ini] + 1;
	}
	else{
		int m = (ini + fin) / 2;
		if (v[m] - v[0] == m){
			sol = prisionero(v, m, fin);
		}
		else{
			sol = prisionero(v, ini, m + 1);
		}
	}
	return sol;
}

// función que resuelve el problema
char resolver(std::vector<char> const & v, char letra1, char letra2) {
	char sol;
	if (v[0] != letra1){
		sol = letra1;
	}
	else if(v[v.size()-1] != letra2){
		sol = letra2;
	}else{
		sol = prisionero(v, 0, v.size());
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char letra1, letra2, let;
	std::cin >> letra1 >> letra2;
	std::vector<char> v(letra2 - letra1);
	for (int i = 0; i < v.size(); i++)
	{
		std::cin >> v[i];
	}
	char sol = resolver(v, letra1, letra2);
	// escribir sol
	std::cout << sol << "\n";
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