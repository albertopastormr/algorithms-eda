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

struct tSol
{
	int num = -1;
	bool ok = false;
};
tSol bongo(std::vector<int> const & v, int cantado, int ini, int fin)
{
	tSol sol;
	int mitad = (ini + fin) / 2;
	if (v[mitad] == cantado + mitad)
	{
		sol.num = v[mitad];
		sol.ok = true;
	}
	else{
		if (ini + 1 == fin)
		{
			sol.num = -1;
			sol.ok = false;
		}
		else
		{
			if (v[mitad] > mitad + cantado)
			{
				sol = bongo(v, cantado, ini, mitad);
			}
			else
			{
				sol = bongo(v, cantado, mitad, fin);
			}
		}
	}
	return sol;
}

// función que resuelve el problema
tSol resolver(std::vector<int> const & v, int cantado) {
	return bongo(v, cantado, 0, v.size() );
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numElem, cantado;
	std::cin >> numElem >> cantado;
	std::vector<int> v(numElem);
	for (int i = 0; i < numElem; i++)
	{
		std::cin >> v[i];
	}
	tSol sol = resolver(v, cantado);
	// escribir sol
	if (sol.ok){
		std::cout << sol.num << "\n";
	}
	else{
		std::cout << "NO" << "\n";
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