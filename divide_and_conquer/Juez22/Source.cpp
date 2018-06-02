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
	int min = 0, max = 0;
	bool ok = true;
};
tSol pOrd(std::vector<int> const & v, int ini, int fin)
{
	tSol sol;
	if (ini + 1 == fin)
	{
		sol.min = v[ini];
		sol.max = v[ini];
		sol.ok = true;
	}
	else
	{
		int mitad = (ini + fin + 1) / 2;
		tSol solIz = pOrd(v, ini, mitad);
		tSol solDer = pOrd(v, mitad, fin);
		if (solDer.max >= solIz.max){
			sol.max = solDer.max;
		}
		else{
			sol.max = solIz.max;
		}
		if (solDer.min <= solIz.min){
			sol.min = solDer.min;
		}
		else{
			sol.min = solIz.min;
		}
		sol.ok = (  solIz.ok && solDer.ok && (solDer.max >= solIz.max) && (solIz.min <= solDer.min)  ); 
	}
	return sol;
}
// función que resuelve el problema
tSol resolver(std::vector<int> const & v) {
	return pOrd(v, 0, v.size());
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	std::vector<int> v;
	while (n != 0)
	{
		v.push_back(n);
		std::cin >> n;
	}
	tSol sol = resolver(v);
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