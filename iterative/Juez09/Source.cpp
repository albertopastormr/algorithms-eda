// Alberto Pastor Moreno
// E46
// Coste Lineal

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const & v) {
	int p = -1;
	int numCeros = 0, numUnos = 0;
	int x = 0;
	while (x < v.size())
	{
		if (v[x] == 1)
		{
			numUnos++;
		}
		else
		{
			if (v[x] == 0)
			{
				numCeros++;
			}
		}
		if (numCeros == numUnos)
		{
			p = x;
		}
		x++;
	}
	return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> v;
	int len, elem;
	std::cin >> len;
	for (int i = 0; i < len; i++)
	{
		std::cin >> elem;
		v.push_back(elem);
	}
	int sol = resolver(v);
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