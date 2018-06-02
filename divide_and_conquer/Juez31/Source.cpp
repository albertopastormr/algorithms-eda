// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
struct tSol{
	int sol = 0, ronda = 0;
	bool presentado = false;
};
// función que resuelve el problema
tSol resolver(std::vector<std::string> const & v, int ini, int fin, int rondMax) {
	tSol sol;
	if (ini + 2 == fin){
		if (v[ini] == "NP" && v[ini + 1] == "NP"){
			sol.sol = 0;
			sol.presentado = false;
		}
		else if (v[ini] != "NP" && v[ini + 1] != "NP"){
			sol.sol++;
			sol.presentado = true;
		}
		else{
			sol.sol = 0;
			sol.presentado = true;
		}
		sol.ronda = 1;
	}
	else{
		int mitad = (ini + fin) / 2;
		tSol solIz = resolver(v, ini, mitad, rondMax);
		tSol solDr = resolver(v, mitad, fin, rondMax);
		sol.ronda = solDr.ronda + 1;
		if (sol.ronda <= rondMax) 	if (solIz.presentado && solDr.presentado) sol.sol++;
		sol.presentado = solIz.presentado || solDr.presentado;
		sol.sol += solIz.sol + solDr.sol;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, rondMax, rondNum = 0;
	std::cin >> n >> rondMax;
	if (!std::cin)
		return false;
	std::vector<std::string> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i];
	tSol sol = resolver(v, 0, n, rondMax);
	std::cout << sol.sol << "\n";
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