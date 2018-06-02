// Alberto Pastor Moreno	
// E46
// Coste Lineal


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const & v, int window, int & sumMax)
{
	for (int i = 0; i < window; i++)
	{
		sumMax += v[i];
	}
	int ind = 0;
	int sum = sumMax;
	for (int j = 1; j < v.size() - window + 1; j++)
	{
		sum = sum - v[j - 1];
		sum = sum + v[j + window - 1];
		if (sum >= sumMax)
		{
			sumMax = sum;
			ind = j;
		}
	}
	return ind;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> v;
	int numElem, num, window, sumMax = 0;
	std::cin >> numElem >> window;
	for (int i = 0; i < numElem; i++)
	{
		std::cin >> num;
		v.push_back(num);
	} 
	int sol = resolver(v, window, sumMax);
	std::cout << sol << " " << sumMax << "\n";
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