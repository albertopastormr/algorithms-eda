// Alberto Pastor Moreno 2E
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
	int suma = 0;
	bool ok = true;
};

tSol degradado(std::vector<int> const & v, int ini, int fin)
{
	tSol sol;
	if (ini + 1 == fin)
	{
		sol.ok = true;
		sol.suma = v[ini];
	}
	else
	{
		int mitad = (ini + fin + 1) / 2;
		tSol solIz = degradado(v, ini, mitad);
		tSol solDer = degradado(v, mitad, fin);
		sol.suma = solIz.suma + solDer.suma;
		sol.ok = solIz.ok && solDer.ok && (solIz.suma < solDer.suma);
	}
	return sol;
}
// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	return degradado(v, 0, v.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	std::cin >> n >> m;
	if (!std::cin)
		return false;
	std::vector<std::vector<int> > mt(n, std::vector<int>(m));
	for (int i = 0; i < n; i++) // Lectura Matriz
	{
		for (int j = 0; j < m; j++)
		{
			std::cin >> mt[i][j];
		}
	}
	int t = 0;
	tSol sol;
	while (t < n && sol.ok)
	{
		sol = resolver(mt[t]);
		t++;
	}
	// escribir sol
	if (sol.ok)
	{
		std::cout << "SI" << "\n";
	}
	else
	{
		std::cout << "NO" << "\n";
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