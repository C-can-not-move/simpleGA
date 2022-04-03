#include "single_unit.h"
#include<string>
using std::string;
namespace SINGLE_UNIT
{
	Single_unit::Single_unit()
	{
		value = 0;
		fitValue = 0;
		Coded_unit = "\0";
	}
	Single_unit::Single_unit(int va, double fi,string cu)
	{
		value = va;
		fitValue = fi;
		Coded_unit = cu;
	}
	Single_unit::~Single_unit()
	{

	}
}