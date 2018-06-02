// Alberto Pastor Moreno
// E46
// Coste Lineal

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const & v) {
	int sum = v[0];
	int max = v[0];
	int contMax = 1;
	for (int j = 1; j < v.size(); j++)
	{
		sum += v[j];
		if (v[j] > max)
		{
			max = v[j];
			contMax = 1;
		}
		else if (v[j] == max){
			contMax++;
		}
	}
	sum = sum - (max*contMax);
	return sum;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> v;
	int len, elem;
	std::cin >> len;
	std::cin >> elem;
	v.push_back(elem);
	int max = elem;
	int posMax = 0;
	for (int i = 1; i < len; i++)
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