// Alberto Pastor Moreno	
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
std::vector<long int> acumula(std::vector<std::vector<long int> > const & m){
	std::vector<long int> minimos(m.size());
	for (int i = 0; i < m.size(); i++){ // Este vector llena el vector de los minimos de cada nivel de la matriz , es decir, el tiempo minimo de cada funcionario en alguna tarea
		int mini = m[i][0];
		for (int j = 0; j < m[0].size(); j++) if (m[i][j] < mini) mini = m[i][j];
		minimos[i] = mini;
	}
	// Acumulo todos los tiempos minimos de cada funcionario de n-1 a 0
	for (int y = m.size()-1; y > 0; y--) 
		minimos[y - 1] += minimos[y];
	return minimos;
}

long int iniciarSumMin(std::vector<std::vector<long int> > const & m){
	long int sol = 0;
	for (int p = 0; p < m.size(); p++) sol += m[p][p];
	return sol;
}
// función que resuelve el problema
void funcionarios(std::vector<std::vector<long int> > const & m, int k, std::vector<bool> & marcas, long int & sumMin, long int & sum, std::vector<long int> const & vAcum) {
	// Recibe el vector de acumulados desde n-1  a 0 con los minimos de cada nivel, es decir, los casos ideales para cada nivel, cada funcionario
	for (int t = 0; t < m[0].size(); t++){
		sum += m[k][t];
		if (!marcas[t]){
			if (k + 1 == marcas.size()){
				if (sum < sumMin) sumMin = sum;
			}
			else{
				marcas[t] = true; // Marcaje
				if (sum + vAcum[k+1] < sumMin)	funcionarios(m, k + 1, marcas, sumMin, sum, vAcum); // La estimacion se realiza en base a lo actual + lo ideal de lo siguiente
				marcas[t] = false; // Desmarcaje
			}
		}
		sum -= m[k][t];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	std::cin >> numElem;
	if (numElem == 0)
		return false;
	std::vector<std::vector<long int> > m(numElem, (std::vector<long int> (numElem)));
	long int sum  = 0;
	for (int x = 0; x < numElem; x++) // Entrada en la matriz
		for (int y = 0; y < numElem; y++) 
			std::cin >> m[x][y];
	long int sumMin = iniciarSumMin(m);
	std::vector<bool> marcas(numElem); // Vector para controlar el marcaje de los trabajadores
	for (int i = 0; i < numElem; i++) // Inicializacion del vector de marcas a falsos
		marcas[i] = false;
	std::vector<long int> vAcum = acumula(m);
	funcionarios(m, 0, marcas, sumMin, sum, vAcum);
	std::cout << sumMin << "\n";
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