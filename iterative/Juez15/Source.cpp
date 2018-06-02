// Alberto Pastor Moreno	
// E46
// Coste Cuadratico


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector< std::vector<int> > const & m, int window)
{
	int sumMax = 0, sumIni = 0;
	// Ventana inicial
	for (int x = 0; x < window; x++)
	{
		for (int y = 0; y < window; y++)
		{
			sumIni += m[x][y];
		}
	}
	sumMax = sumIni;
	// Ventana deslizante por matriz
	for (int k = 0; k <= m.size() - window; k++)
	{
		int sum = sumIni;
		for (int u = 0; u < window && k+window < m.size(); u++)
		{
			sumIni -= m[k][u];
			sumIni += m[k + window][u];
		}
		if (sum > sumMax)
		{
			sumMax = sum;
		}
		for (int l = 0; l < m[0].size() - window; l++)
		{
			for (int p = k; p < k + window; p++)
			{
				sum -= m[p][l];
				sum += m[p][l + window];
			}
			if (sum > sumMax)
			{
				sumMax = sum;
			}
		}
	}
	return sumMax;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam, window;
	std::cin >> tam >> window;
	if (!std::cin)
	{
		return false;
	}
	std::vector< std::vector<int> > m(tam, std::vector<int>(tam));
	/*std::cin >> m[0][0];
	for (int x = 1; x < tam; x++)
	{
		std::cin >> m[0][x];
		m[0][x] += m[0][x - 1];
	}
	for (int i = 1; i < tam; i++)
	{
		std::cin >> m[i][0];
		m[i][0] += m[i - 1][0];
		for (int j = 1; j < tam; j++)
		{
			std::cin >> m[i][j];
			m[i][j] = m[i][j] + m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
		}
	} Entrada de una matriz directamente con suma acumulada de los cuadrantes anteriores */
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			std::cin >> m[i][j];
		}
	}
	int sol = resolver(m, window);
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