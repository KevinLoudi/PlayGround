#include <iostream>
#include "Place.h"
#include "basicPlaces.h"
#include "commonMethods.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void printInfo(const Place &site);//dynamic binding
bool InitCityList(City &acity);
bool ReadListFiletoCity(City cities[],const int num);
//Initialize a group of cities through file reading
//bool CreateCitiesviaFile(City *pcities, const int num);

int main(int argc, char** argv) 
{		
		//city group
		const UINT citynum=3;
		City* pcities= new City[citynum];
		ReadListFiletoCity(pcities,citynum);
		
		Ranking cityrank;
		cityrank.push_city(pcities[0]);
		
		delete[] pcities;
		return 0;
}

void printInfo(const Place &site,ostream &os)
{
	 cout<<site.GetInfo(os);
}
