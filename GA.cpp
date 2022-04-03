// GA.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "geneAlgo.h"
using namespace GENEALGO;
int qwer(int x);
int qwer(int x)
{
    return x/ 2;
}
int main()
{
    GeneAlgo Test = GeneAlgo();
    Test.Crossover();
    Test.Variation();
    Test.Select_unit();
    Test.Show_Result();
}

