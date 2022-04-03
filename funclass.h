#ifndef FUNCLASS_H_
#define FUNCLASS_H_
namespace FUNCLASS
{
	class Funclass
	{
	private:
		int (*Fun)(int x);
		int Wanted;
	public:
		Funclass();
		Funclass(int (*fun)(int x), int wanted);
		void ResetFunclass(int (*fun)(int x), int wanted);
		~Funclass();
		int Funvalue(int x);
		int Wantedvalue();
		void SetFun(int (*fun)(int x));
		void SetWanted(int x);
	};
}
#endif // !FUNCLASS_H_

