// Alberto Pastor Moreno
// E46
// Coste Lineal

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

/*
method seqBlancos( v: array<string>) returns( ini : int, fin : int)
requires v != null && v.Length > 0
ensures sum(v[ini..fin+1]) == sumMaxima(v[..])
*/
struct tIntervalo
{
	int ini, fin;
};
tIntervalo resolver(std::vector<std::string> const & v) { 
	tIntervalo sol;
	sol.ini = 0;
	sol.fin = -1;
	int iniaux = 0, finaux = -1;
	for (int x = 0; x < v.size(); x++)
	{
		if (v[x] == "FFFFFF")
		{
			finaux = x;
		}
		else
		{
			iniaux = x+1;
		}
		if (sol.fin - sol.ini < finaux - iniaux)
		{
			sol.fin = finaux;
			sol.ini = iniaux;
		}
	}
	return sol; // Sacar ambas posiciones con struct para imprimir fuera de resolver ?
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso(bool endline) {
	int numF, numC;
	std::cin >> numF >> numC;
	if (!std::cin)
		return false;
	if (endline)
	{
		std::cout << "\n";
	}
	for (int i = 0; i < numF;i++)
	{
		std::vector<std::string> v;
		std::string elem;
		for (int j = 0; j < numC; j++)
		{
			std::cin >> elem;
			v.push_back(elem);
		}
		tIntervalo sol = resolver(v);
		std::cout << sol.ini << " " << sol.fin << "\n";
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
	bool endline = false;
	while (resuelveCaso(endline))
	{
		endline = true;
	}
			
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}