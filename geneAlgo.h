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
	class GeneAlgo//遗传算法，，模拟自然界生物进化的过程，其核心在与对二进制数字编码的交换
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
	public://公共方法
		GeneAlgo();
		GeneAlgo(int L,int H,Funclass fun);
		~GeneAlgo();
		void Crossover();//交叉，对交叉过程详述
		void Variation();//变异
		void Select_unit();//选择
		void Show_Result();
	};
}
#endif // !GENEALGO_H_

