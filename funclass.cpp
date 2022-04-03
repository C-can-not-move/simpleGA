#include "funclass.h"
int Fun_default(int x);
int Fun_default(int x)
{
	return x;
}
namespace FUNCLASS
{
	Funclass::Funclass()
	{
		Fun = Fun_default;
		Wanted = 1;
	}
	Funclass::Funclass(int (*fun)(int x), int wanted)
	{
		Fun = fun;
		Wanted = wanted;
	}
	void Funclass::ResetFunclass(int (*fun)(int x), int wanted)
	{
		Fun = fun;
		Wanted = wanted;
	}
	Funclass::~Funclass()
	{

	}
	int Funclass::Funvalue(int x)
	{
		return Fun(x);
	}
	int Funclass::Wantedvalue()
	{
		return Wanted;
	}
	void Funclass::SetFun(int (*fun)(int x))
	{
		Fun = fun;
	}
	void Funclass::SetWanted(int x)
	{
		Wanted = x;
	}


}
