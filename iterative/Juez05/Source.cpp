// Alberto Pastor Moreno 2E
// E46
#include <iostream>
#include <iomanip>
/*
method Fibonacci (n : int) returns (f : int)
requires n >= 0
ensures f == Fib(n)
{
f := 2;
var antf := 1;
var antr := 1;
var i := 3;
if( n < 2)
{
	f := n;
}
else if(n == 2){
	f := 1;
}else
{
while( i < n)
invariant 0<= i <= n;
invariant f == Fib(i);
invariant antf == Fib(i-1);
invariant antr == Fib(i-2);
{
	antr := antf;
	antf := f;
	f := antf + antr;
	i := i + 1;
}
}
}
*/
bool resuelveCaso() {
	long long int f, antf, antr;
	f = antf = antr = 1;
	int n, i = 2;
	std::cin >> n;
	if (n == -1)
	{
		return false;
	}
	if (n < 2)
	{
	f = n;
	}
	else if (n == 2){
	f = 1;
	}
	else
	{
		while (i < n)
		{
		antr = antf;
		antf = f;
		f = antf + antr;
		i++;
		}
	}
	std::cout << f << "\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}