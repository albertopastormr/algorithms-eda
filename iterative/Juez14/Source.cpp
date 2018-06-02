// Alberto Pastor Moreno	
// E46
// Coste Cuadratico


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector< std::vector<int> > const & m, int franja, int mincol, int minceros)
{
	int validfranjas = 0;
	std::vector<int> vaux(m[0].size()); // Un vector auxiliar que almacena el contceros de cada columna
	for (int y = 0; y < m[0].size(); y++)
	{
		int contceros = 0;
		for (int x = 0; x < m.size(); x++) // Recorro las columnas contando cuantos ceros tiene cada una
		{
			if (m[x][y] == 0)
			{
				contceros++;
			}
		}
		vaux[y] = contceros; // Almaceno el contceros de cada columna en vaux
	}
	// Una vez que tengo el vector auxiliar, compruebo con un algoritmo de ventana cuantas franjas
	// cumplen la condicion del problema
	int validcol = 0;
	for (int t = 0; t < franja; t++) // Compruebo la primera franja sobre vaux
	{
		if (vaux[t] >= minceros)
		{
			validcol++;
		}
	}
	if (validcol >= mincol)
	{
		validfranjas++;
	}
	for (int k = 0; k < vaux.size() - franja; k++)
	{
		if (vaux[k] >= minceros) // Si el anterior era una columna valida , la resto
		{
			validcol--;
		}
		if (vaux[k + franja] >= minceros) // Si la siguiente columna es valida, la sumo
		{
			validcol++;
		}
		if (validcol >= mincol) // Si la franja es valida, la sumo al contador de franjas validas
		{
			validfranjas++;
		}
	}
	return validfranjas;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas, columnas, franja, mincol, minceros;
	std::cin >> filas >> columnas >> franja >> mincol >> minceros;
	if (!std::cin)
	{
		return false;
	}
	std::vector< std::vector<int> > m(filas, std::vector<int>(columnas));
	for (int i = 0; i < filas; i++) // Lectura matriz
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cin >> m[i][j];
		}
	}
	int sol = resolver(m, franja, mincol, minceros);
	std::cout << sol << "\n";
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