//#include <iostream>
//using namespace std;
//
//struct Colectie
//{
//	char* denumire;
//	int nrElem;
//	float pret;
//	bool finit;
//	char categorie;
//};
//void afisare_colectie(Colectie c)
//{
//	cout << c.denumire << " " << c.nrElem << " " << c.pret << " " << c.finit << " " << c.categorie << endl;
//}
//void main()
//{
//	Colectie c;
//	cout<<"hey"<<endl;
//	//citire variabila reala.
//	c.categorie = 'A';
//	c.finit = true;
//	c.nrElem = 245;
//	c.pret=22.2;
//	c.denumire = new char[strlen("Ceai") + 1];
//	strcpy_s(c.denumire,strlen("Ceai") + 1, "Ceai");
//	afisare_colectie(c);
//	delete []c.denumire;
//}