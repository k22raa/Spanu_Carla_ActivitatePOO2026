#include <iostream>
using namespace std;
//seminar2
struct Ghiozdan
{
	float lungime;
	int nrBuzunare;
	bool laptop;
	char* producator;

};

Ghiozdan citire()
{
	char nume[10];
	Ghiozdan g;
	cout << "lungime= ";cin >> g.lungime;
	cout << "buzunare = ";cin >> g.nrBuzunare;
	cout << "pt laptop 0/1= ";cin >> g.laptop;
	cout << "producator= ";cin >> nume;
	g.producator = new char[strlen(nume) + 1];
	strcpy_s(g.producator, strlen(nume) + 1, nume);
	return g;
}
void afisare(Ghiozdan g)
{
	cout << "lungime:" << g.lungime << endl;
	cout << "buzunare:" << g.nrBuzunare << endl;
	cout << "laptop:" << g.laptop << endl;
	cout << "nume producator:" << g.producator << endl;
}
void modificare(Ghiozdan* g, float lungime1)
{
	(*g).lungime = lungime1;
}
int calculeazaNrBuzunareTotal(Ghiozdan* ghiozdane, int nrghiozdane)
{
	int s = 0;
	for (int i = 0;i < nrghiozdane;i++)
	{
		s += ghiozdane[i].nrBuzunare;

	}
	return s;
}
void main()
{
	/*Ghiozdan g=citire();
	afisare(g);
	modificare(&g, 12);
	afisare(g);*/

	int nrghiozdan = 3;
	Ghiozdan* ghiozdane;
	ghiozdane = new Ghiozdan[3];
	for (int i = 0;i < nrghiozdan;i++)ghiozdane[i] = citire();

	//for (int i = 0;i < nrghiozdan;i++)afisare(ghiozdane[i]);
	cout << "nr total de buzunare:" << calculeazaNrBuzunareTotal(ghiozdane, nrghiozdan);


}