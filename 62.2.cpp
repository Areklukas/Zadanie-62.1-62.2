#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

const int SIZE = 1000;

void zadanie1() 
{
  	ifstream liczby("liczby1.txt");
  	int tab[SIZE];
  	for (int i=0; i<SIZE; i++) liczby>>tab[i];
  	liczby.close();
  	int min=9999999;
  	int max=0;
  	for (int i=0; i<SIZE; i++) 
  	{
    	if(tab[i]<min) min=tab[i];
    	if(tab[i]>max) max=tab[i];
  	}
  	cout << "Najmniejsza: "<<min<<endl;
  	cout << "Najwieksza: "<<max<<endl;
}
void zadanie2() 
{
  	int tab[SIZE];
  	ifstream zbior("liczby2.txt");
  	for (int i=0; i<1000; i++) zbior>>tab[i];
  	zbior.close();
  	int lacznie=0, maxlacznie=0, pierwszy=0;
  	int maxpierwszy;
  	for (int i=1; i<SIZE; i++) 
	{
    	if (tab[i]>=tab[i-1]) 
		{
      		lacznie++;
      		if(pierwszy==0) 
			{
        		pierwszy=tab[i-1];
        		lacznie++;
      		}
    	}
    	else 
		{
      	if (lacznie>maxlacznie) 
		{
        	maxlacznie=lacznie;
        	maxpierwszy=pierwszy;
      	}
      	pierwszy=0;
      	lacznie=0;
    	}
  	}
  	cout<<"Pierwszy element: "<<maxpierwszy<<endl;
  	cout<<"Iloœæ elementow: "<<maxlacznie<<endl;
}
int main(int argc, char** argv) {
	zadanie1();
	zadanie2();
	return 0;
}
