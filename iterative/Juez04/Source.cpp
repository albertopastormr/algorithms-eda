// Alberto Pastor Moreno
// E46


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
/*
method problema1 (a: array<int>) returns (v : array<int>)
requires a != null && a.Length > 0
ensures v != null && v.Length > 0 && a.Length == v.Length
ensures forall k :: 0 <= k < a.Length ==> ( v[k] == Sum(a[k..]))
{
v := new int[a.Length];
var i := a.Length - 2;
v[a.Length-1] := a[a.Length-1];
while ( i >= 0)
invariant -1 <= i < a.Length
invariant forall k :: i < k < a.Length ==> ( v[k] == Sum(a[k..]))
invariant v[i+1] == Sum(a[i+1..])
invariant a.Length == v.Length
{
	assume ( Sum( v[i..]) == Sum(v[i+1..]) + v[i]);
	assume ( Sum( v[i+1..]) == Sum(v[i+2..]) + v[i+1]);
	v[i] := a[i] + v[i+1];
	i := i - 1;
}
}


*/

// función que resuelve el problema
void resolver(std::vector<int> const & v, std::vector<int> &sol){
	int i = v.size() - 2;
	sol[v.size() - 1] = v[sol.size()- 1];
	while (i >= 0)
	{
		sol[i]  = v[i] + sol[i + 1];
		i--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num;
	std::vector<int> v;
	std::cin >> num;
	if (num == 0)
		return false;
	while (num != 0)
	{
		v.push_back(num);
		std::cin >> num;
	}
	std::vector<int> sol(v.size()); 
	resolver(v, sol);
	std::cout << sol[0];
	for (int i = 1; i < sol.size(); i++)
	{
		std::cout << " " << sol[i];
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


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}