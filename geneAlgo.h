#ifndef GENEALGO_H_
#define GENEALGO_H_
#include<string>
#include <algorithm>
#include <vector>
#include<cstdlib>
#include<ctime>
#include "funclass.h"
#include "single_unit.h"
using FUNCLASS::Funclass;
using SINGLE_UNIT::Single_unit;
using std::string;
using std::vector;
namespace GENEALGO
{
	class GeneAlgo//�Ŵ��㷨����ģ����Ȼ����������Ĺ��̣����������Զ��������ֱ���Ľ���
	{
	private:
		int start;
		int end;
		Funclass Function;
		int numpop;
		vector<Single_unit>units;
		int len;	
		int CROSSOVERRATE;
		int VARIATIONRATE;
		int SELECTRATE;	
		void set_len(int H);
		int DeCoding_single(string i);
		double Fitness_single(int i);
		void Coding();
		void DeCoding();
	public://��������
		GeneAlgo();
		GeneAlgo(int L,int H,Funclass fun);
		~GeneAlgo();
		void Crossover();//���棬�Խ����������
		void Variation();//����
		void Select_unit();//ѡ��
		void Show_Result();
	};
}
#endif // !GENEALGO_H_

