//��������ౣ֤ѡ��ʱ����������
#ifndef SINGLE_UNIT_H_
#define SINGLE_UNIT_H_
#include<string>
using std::string;
namespace SINGLE_UNIT
{
	class Single_unit//����һ���ص��ǶԸ���Ķ��塣�����õ����ݽṹ���㷨�Ļ�����
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
