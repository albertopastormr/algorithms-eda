// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
int resolver(std::vector<int> & v) {
	int sol = 0;
	int i = 0, j = v.size() - 1;
	while (i < j){
		if (v[i] >= 0) i++;
		if (v[j] < 0) j--;
		if (v[i] < 0 && v[j] >= 0 && i < j){
			std::swap(v[i], v[j]);
			i++;
			j--;
		}
	}
	for (int t = 0; t < v.size(); t++) if (v[t] >= 0) sol = t + 1;
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i];    
    int sol = resolver(v);
    // escribir sol
	std::cout << v[0];
	for (int j = 1; j < n; j++) std::cout << " " << v[j];
	std::cout << "\n"  << sol << "\n";
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