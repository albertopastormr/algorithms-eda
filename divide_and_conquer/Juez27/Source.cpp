// Alberto Pastor Moreno 2E
// E46

/*
Coste O(nlog(n))
Ecuacion recurrencia:
T(n):	- c0			si n = 0, 1
- n + 2*T(n/2) si n>1
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

int bg(std::vector<int> & v, int ini, int fin)
{
	int sol;
	if (ini + 1 >= fin)
	{ // Debe salir ordenado
		sol = 0;
	}
	else
	{
		int mitad = (ini + fin) / 2;
		int inverIz = bg(v, ini, mitad);
		int inverDr = bg(v, mitad, fin);
		sol = inverIz + inverDr;
		int i = ini;
		int j = mitad;
		while (i < mitad && j < fin) {
			if (v[i] > v[j]) {
				sol += mitad - i;
				j++;
			}
			else {
				i++;
			}
		}
		std::vector<int> vaux(fin-ini);
		std::merge(v.begin() + ini, v.begin() + mitad, v.begin() + mitad, v.begin() + fin, vaux.begin() );
		for (int x = 0; x < vaux.size(); x++) {
			v[ini + x] = vaux[x];
		}
	}
	return sol;
}
// función que resuelve el problema
int resolver(std::vector<int> & v) {
	return bg(v, 0, v.size());
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
	for (int i = 0; i < numElem; i++)
	{
		std::cin >> v[i];
	}
	int sol = resolver(v);
	std::cout << sol << "\n";
	// escribir sol
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