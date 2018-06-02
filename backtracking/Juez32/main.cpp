// Alberto Pastor Moreno
// E46

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tCubos
{
	int r = 0;
	int a = 0;
	int v = 0;
};

void escribir(std::vector<int> const & sol) {
		for (int j : sol) {
			switch (j)
			{
			case 0:
				std::cout << "azul" << " ";
				break;
			case 1:
				std::cout << "rojo" << " ";
				break;
			case 2:
				std::cout << "verde" << " ";
				break;
			}
		}
		std::cout << "\n";
}

bool esValida(std::vector<int> & sol, int k, tCubos cubos, tCubos usadas) {
	bool ok = true;

	if (sol[k] == 0) {
		if (cubos.a <= usadas.a)
			ok = false;
	}
	else if (sol[k] == 1) {
		if (cubos.r <= usadas.r)
			ok = false;
	}
	else if (sol[k] == 2) {
		if (cubos.v <= usadas.v)
			ok = false;
		else if (sol[k - 1] == 2)
			ok = false;
		else if (usadas.v + 1 > usadas.a)
			ok = false;
	}
	return ok;
}

void torre(tCubos cubos, std::vector<int> & sol, int k, tCubos & usadas, bool & exito) {
	for (int i = 0; i < 3 ; i++) {
		sol[k] = i;
		if (esValida(sol, k, cubos, usadas)){
			if (i == 0) usadas.a++;
			else if(i == 1) usadas.r++;
			else if(i == 2) usadas.v++;
			
			if (k == sol.size() - 1) {
				if (usadas.r > usadas.a + usadas.v)
				{
					escribir(sol);
					exito = true;
				}
			}
			else torre(cubos, sol, k + 1, usadas, exito);

			if (i == 0) usadas.a--;
			else if (i == 1) usadas.r--;
			else if (i == 2) usadas.v--;
		}
	}
}

bool resuelveCaso() {
	
	tCubos cubos, usadas;
	int numElem = 0;
	bool exito = false;

	std::cin >> numElem;
	std::vector<int> sol(numElem);

	std::cin >> cubos.a; 
	std::cin >> cubos.r; 
	std::cin >> cubos.v;

	if(numElem == 0 && cubos.a == 0 && cubos.r == 0 && cubos.v == 0)
		return false;

	if (cubos.r == 0 || numElem < 2){
		std::cout << "SIN SOLUCION" << "\n";
	}
	else{
		sol[0] = 1;
		usadas.r++;
		torre(cubos, sol, 1, usadas, exito);
		if (!exito) std::cout << "SIN SOLUCION" << "\n";
	}

	std::cout << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}