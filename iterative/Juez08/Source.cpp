// Alberto Pastor Moreno
// E46
// Coste Lineal
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tIntervalo
{
	int ini, fin;
};
// función que resuelve el problema
tIntervalo resolver(std::vector<int>  const& v, int t) {
	tIntervalo intervalo;
	intervalo.ini = intervalo.fin = 0;
	int len = 0, lenMax = 0;
	for (int x = 0; x < v.size(); x++)
	{
		if (t >= v[x])
		{
			len = 0;
		}
		else
		{
			len++;
		}
		if (lenMax < len)
		{
			intervalo.ini = x + 1 - len;
			intervalo.fin = x;
			lenMax = len;
		}
	}
	return intervalo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::vector<int> v;
	int numElem, t, elem;
	std::cin >> numElem >> t;
	for (int i = 0; i < numElem; i++)
	{
		std::cin >> elem;
		v.push_back(elem);
	}
	tIntervalo sol = resolver(v, t);
	std::cout << sol.ini << " " << sol.fin << "\n";
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