// Alberto Pastor Moreno 2E
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int suma = 0;
	bool ok = true;
};

tSol movil()
{
	tSol sol;
	int pI, pD, dI, dD;
	std::cin >> pI >> dI >> pD >> dD;
	if (pI != 0 && pD != 0)
	{
		sol.suma = pI + pD;
		sol.ok = (pI * dI == pD*dD);
	}
	else
	{
		if (pI == 0 && pD == 0)
		{
			tSol solIz = movil();
			tSol solDer = movil();
			sol.ok = solDer.ok && solIz.ok && (solDer.suma * dD == solIz.suma * dI);
			sol.suma = solIz.suma + solDer.suma;
		}
		else
		{
			if (pI == 0)
			{
				tSol solIz = movil();
				sol.ok = solIz.ok && (solIz.suma * dI == pD * dD);
				sol.suma = solIz.suma + pD;
			}
			else
			{
				if (pD == 0)
				{
					tSol solDer = movil();
					sol.ok = solDer.ok && (solDer.suma * dD == pI * dI);
					sol.suma = solDer.suma + pI;
				}
			}
		}
	}
	return sol;
}
// función que resuelve el problema
tSol resolver() {
	return movil();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tSol sol = resolver();
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

	int numCasos, q = 0;
	std::cin >> numCasos;
	while (q < numCasos){ resuelveCaso(); q++; }


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}