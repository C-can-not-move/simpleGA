#include "geneAlgo.h"
#include "funclass.h"
#include "single_unit.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include<cstdlib>
#include<ctime>
using namespace FUNCLASS;
using namespace SINGLE_UNIT;

int my_cmp(Single_unit p1, Single_unit  p2)
{
	return p1.fitValue > p2.fitValue;
}
namespace GENEALGO
{
	void GeneAlgo::set_len(int H)
	{
		int count = 0;
		double x = H;
		while (x >= 1)
		{
			x /= 2;
			count++;
		}
		len = count;
	}
	int GeneAlgo::DeCoding_single(string i)
	{
		int sum = 0;
		for (int j = len; j > 0; j--)
		{
			int pos = j - 1;
			if (i[pos] == '1')
			{
				sum = sum + pow(2, len - j);
			}
		}
		return sum;
	}
	double GeneAlgo::Fitness_single(int i)
	{
		return double(1.0/(abs(Function.Wantedvalue() - Function.Funvalue(i))));
	}
	void GeneAlgo::Coding()
	{
		for (int i = 0; i < numpop; i++)
		{
			string temp_str;
			int temp_int = units[i].value;
			for (int j = 0; j < len; j++)
			{
				char temp_ch = '0';
				if (temp_int % 2 == 1)
				{
					temp_ch = '1';
				}
				temp_int /= 2;
				temp_str.push_back(temp_ch);
			}
			reverse(temp_str.begin(), temp_str.end());
			units[i].Coded_unit = temp_str;
		}

	}
	void GeneAlgo::DeCoding()
	{
		for (int i = 0; i < numpop; i++)
		{
			int sum = 0;
			for (int j = len; j > 0; j--)
			{
				int pos = j - 1;
				if (units[i].Coded_unit[pos] == '1')
				{
					sum = sum + pow(2, len - j);
				}
			}
			units[i].value = sum;
		}
	}
	GeneAlgo::GeneAlgo()
	{
		start = 0;
		end = 100;
		Function = Funclass();
		numpop = 100;
		for (int i = 0; i < numpop; i++)
		{
			Single_unit temp = Single_unit();
			temp.value = i;
			temp.fitValue = Fitness_single(Function.Funvalue(i));
			units.push_back(temp);
		}
		set_len(end);
		Coding();
		CROSSOVERRATE = 100;//100��
		VARIATIONRATE = 0.1;
		SELECTRATE = 0.8;
	}
	GeneAlgo::GeneAlgo(int L, int H, Funclass fun)
	{
		start = L;
		end = H;
		Function = fun;
		numpop = H-L+1;
		for (int i = L; i <= H; i++)
		{
			Single_unit temp = Single_unit();
			temp.value = i;
			units.push_back(temp);
		}
		set_len(end);
		Coding();
		CROSSOVERRATE = 100;
		VARIATIONRATE = 0.1;
		SELECTRATE = 0.2;
	}
	GeneAlgo::~GeneAlgo()
	{

	}
	void GeneAlgo::Crossover()
	{
		srand(time(NULL));
		for (int i = 0; i < CROSSOVERRATE;i++)
		{
			string father = units[rand() % numpop].Coded_unit;//ѡ�Ÿ�����ĸ��
			string mother = units[rand() % numpop].Coded_unit;
            int crossPos = rand() % len;//�������λ��
			father.replace(0, crossPos, mother, 0, crossPos);//�ѽ���λ�ú�Ĳ��ֽ����滻��
			mother.replace(crossPos, len - 1, father, crossPos, len - 1);
			int v_f = DeCoding_single(father);
			units.push_back(Single_unit(v_f, Fitness_single(v_f), father));//�����Ҫ���¼���ֵ����Ӧ��
			int v_m = DeCoding_single(mother);
			units.push_back(Single_unit(v_m, Fitness_single(v_m), mother));
		}
		numpop += 2 * CROSSOVERRATE;
	}
	void GeneAlgo::Variation()
	{
		srand(time(NULL));
		int count = int(numpop * VARIATIONRATE);
		for (int i = 0; i < count; i++)
		{
			int Variation_pos= rand() % len;//ѡȡ����λ��
			int pos = rand() % numpop;//ѡȡ�������
			if (units[pos].Coded_unit[Variation_pos] == '0')//��0����Ϊ1����1����Ϊ0.
			{
				units[pos].Coded_unit[Variation_pos] = '1';
				units[pos].value = DeCoding_single(units[pos].Coded_unit);
				units[pos].fitValue = Fitness_single(Function.Funvalue(units[pos].value));
			}
			else
			{
				units[pos].Coded_unit[Variation_pos] = '0';
				units[pos].value = DeCoding_single(units[pos].Coded_unit);
				units[pos].fitValue = Fitness_single(Function.Funvalue(units[pos].value));
			}
		}
	}
	void GeneAlgo::Select_unit()
	{
		sort(units.begin(), units.end(), my_cmp);//���ȸ�����Ӧ������
		int count = int(numpop * SELECTRATE);
		for (int i = 0; i < count; i++)
		{
			units.pop_back();//����Ӧ��С�ĵ���
		}
	}
	void GeneAlgo::Show_Result()//չ�ֽ��
	{
		sort(units.begin(), units.end(), my_cmp);
		std::cout << "����ֵ��:" << Function.Wantedvalue()<<std::endl;
		std::cout << "ǰʮ�ĸ�����"<<std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "����ֵ��";
			std::cout << units[i].value << " ";
			std::cout << "����ֵΪ��";
			std::cout << Function.Funvalue(units[i].value) << " ";
			std::cout << "��Ӧ��Ϊ��";
			std::cout << units[i].fitValue<< " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
		
	}
}