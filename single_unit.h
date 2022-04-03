//引入这个类保证选择时的配套问题
#ifndef SINGLE_UNIT_H_
#define SINGLE_UNIT_H_
#include<string>
using std::string;
namespace SINGLE_UNIT
{
	class Single_unit//还有一个重点是对个体的定义。（良好的数据结构是算法的基础）
	{
	private:
		
	public:
		int value;
		double fitValue;
		string Coded_unit;
		Single_unit();
		Single_unit(int va, double fi,string Cu);
		~Single_unit();
	};
}
#endif
