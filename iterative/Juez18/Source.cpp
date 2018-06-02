// Alberto Pastor Moreno 2E
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int maxSeq = 0, contSeq = 0, numEndGames = 0;
};
// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	tSol sol, aux;
	sol.numEndGames = v.size();
	int posEndSeq = 0;
	for (int x = 0; x < v.size(); x++)
	{
		if (v[x] > 0)
		{
			aux.maxSeq++;
			posEndSeq = x;
			if (aux.maxSeq > sol.maxSeq)
			{
				sol.maxSeq = aux.maxSeq;
				sol.contSeq = 1;
				sol.numEndGames = v.size() - posEndSeq - 1;
			}
			else if (aux.maxSeq == sol.maxSeq){
				sol.contSeq++;
				sol.numEndGames = v.size() - posEndSeq - 1;
			}
		}
		else
		{
			aux.maxSeq = 0;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (!std::cin)
		return false;
	//std::vector<std::vector<int> > mt(n, std::vector<int>(m));
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) // Lectura Vector
	{
		std::cin >> v[i];
	}
	tSol sol = resolver(v);
	std::cout << sol.maxSeq << " " << sol.contSeq << " " << sol.numEndGames << "\n";
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