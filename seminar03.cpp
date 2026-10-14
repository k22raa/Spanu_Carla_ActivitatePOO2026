#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Prajitura
{
public:
	char* denumire;
	float pret;
	float cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	//const int id;
	Prajitura()
	{
		this->denumire = new char[strlen("tiramisu") + 1];
		strcpy(denumire, "tiramisu");
		this->pret = 15;
		this->cantitate = 4;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "cafea";
		this->ingrediente[2] = "mascarpone";
	}

	Prajitura(const char* denumire, float pret)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 4;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "cafea";
		this->ingrediente[2] = "mascarpone";
	}

	void afisare()
	{
		cout << "denumire:" << this->denumire << endl;
		cout << "pret:" << this->pret << endl;
		cout << "cantitate:" << this->cantitate << endl;
		cout << "de post:" << (this->dePost ? "DA" : "NU") << endl;
		cout << "nr ingrediente:" << this->nrIngrediente << endl;
		cout << "ingredientele sunt:";
		for (int i = 0;i < this->nrIngrediente;i++)cout << this->ingrediente[i] << ", ";
		cout << endl;
	}
	//calculati pretul mediu per gram;
	float copstMediuPerGram()
	{
		if (cantitate == 0) { return 0; }
		else
		{
			return this->pret / this->cantitate;
		}
	}
	//modificare denumirea prajiturii respective
	void modificaDenumire(const char* denumire)
	{
		delete this->denumire;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}
};
float calcCantTotala(Prajitura* prajituri, int nr_prajituri)
{
	float greutate = 0;
	for (int p = 0;p < nr_prajituri;p++)greutate += prajituri[p].cantitate;
	return greutate;
}




void main()
{
	Prajitura p1;
	Prajitura p2("amandina", 40);
	p1.afisare();
	cout << p1.copstMediuPerGram();
	Prajitura* prajituri;
	prajituri = new Prajitura[3];
	prajituri[2].afisare();
	prajituri[1].pret = 50;
	prajituri[2].cantitate = 70;
	prajituri[0].modificaDenumire("tort");
	prajituri[1].modificaDenumire("amandina");
	for (int i = 0;i < 3;i++)
	{
		cout << prajituri[i].denumire << " " << prajituri[i].copstMediuPerGram() << endl;

	}
	float greutate_totala = calcCantTotala(prajituri, 3);
	cout << "total:" << greutate_totala << endl;

}