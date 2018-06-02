// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const & v, int p) {
	bool encontrado = true;
	int numMaxIzq = v[0];
	for (int k = 1; k <= p; k++)
	{
		if (v[k] > numMaxIzq)
		{
			numMaxIzq = v[k];
		}
	}
	int numMenDer = numMaxIzq + 1;
	for (unsigned int k = p + 1; k < v.size(); k++)
	{
		if (v[k] < numMenDer)
		{
			numMenDer = v[k];
		}
	}
	return (numMaxIzq < numMenDer);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, n, p;
	std::cin >> numElem >> p;
	std::vector<int> v;
	for (int i = 0; i < numElem; i++)
	{
		std::cin >> n;
		v.push_back(n);
	}
	
	bool sol = resolver(v, p);
	if (sol)
	{
		std::cout << "SI" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}

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