#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
private:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	const int id;
	static int contor;
public:
#pragma region Constructori
	friend class Student;
	Prajitura() :id(contor++) {
		this->denumire = new char[strlen("Tiramisu") + 1];
		strcpy(denumire, "Tiramisu");
		this->pret = 15;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}
	Prajitura(const char* denumire, float pret) :id(contor++) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->pret = pret;
		this->cantitate = 250;
		this->dePost = true;
		this->nrIngrediente = 3;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "piscoturi";
		this->ingrediente[1] = "vanilie";
		this->ingrediente[2] = "cafea";
	}

	Prajitura(const Prajitura& p) :id(contor++) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);

		this->pret = p.pret;
		this->cantitate = p.cantitate;
		this->dePost = p.dePost;
		this->nrIngrediente = p.nrIngrediente;

		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = p.ingrediente[i];
		}
	}
	~Prajitura();//declarare destructor
	//seminar5: operatorul egal:
	//trb sa stergem memoria inainte sa aloc spatiu:
	Prajitura& operator=(const Prajitura& p1)
	{
		if (this != &p1)
		{
			this->cantitate = p1.cantitate;
			if (this->denumire != NULL)
			{
				delete[] this->denumire;
			}
			this->denumire = new char[strlen(p1.denumire) + 1];
			strcpy(this->denumire, p1.denumire);
			this->dePost = p1.dePost;
			this->nrIngrediente = p1.nrIngrediente;
			this->pret = p1.pret;
			if (this->ingrediente != NULL)
			{
				delete[] this->ingrediente;
			}
			this->ingrediente = new string[this->nrIngrediente];
			for (int i = 0;i < this->nrIngrediente;i++)this->ingrediente[i] = p1.ingrediente[i];
		}
		return *this;

	}
	//253 operatori hahaha clase diferite:)
	// 11 noiembrie test :(
	//cand avem campuri alocate dinamic, trb si dezalocate la operatorul egal

	//relatia "has a"

#pragma endregion

#pragma region geteri si seteri
	int getCantitate() {
		return this->cantitate;
	}
	int getNrIngrediente() {
		return this->nrIngrediente;
	}
	float getPret() {
		return this->pret;
	}
	static int getContor() {
		return contor;
	}

#pragma endregion
	//sem 5 operatorul +
	Prajitura operator+(const Prajitura& p)
	{
		//nu pui &operator ptc result este doar in stiva de memorie a operatorului+
		//p+p, primul p e in this
		Prajitura result = *this;
		result.pret = this->pret + p.pret;
		result.cantitate = this->cantitate + p.cantitate;
		return result;
	}

	void afisare()
	{
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		cout << "Ingredientele sunt: ";
		for (int i = 0;i < this->nrIngrediente;i++)
		{
			cout << this->ingrediente[i] << "; ";
		}
		cout << endl;

	}
	float costMediuGram() {
		if (this->cantitate == 0) {
			return 0;
		}
		else {
			return this->pret / this->cantitate;
		}
	}

	void modificaDenumire(const char* denumire) {
		delete this->denumire;

		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	}


};

int Prajitura::contor = 100;

Prajitura::~Prajitura() {//implementare destructor
	delete[] this->denumire;
	delete[] this->ingrediente;
}
float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;

	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].getCantitate();

	return greutate;
}

float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();

	return 0;
}
//relatia has a:
class Student
{
private:
	string nume;
	Prajitura prajitura;
public:
	Student()
	{
		this->nume = "andrei";
		//ptc e string atunci nu trb sa mai pui this->prajitura:]
	}
	Student(string nume, Prajitura p)
	{
		this->nume = nume;
		this->prajitura = p;//se apeleaza din prajitura p
	}
	string getNume()
	{
		return this->nume;
	}
	Prajitura getPrajitura()
	{
		return this->prajitura;
	}
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setPrajitura(Prajitura p)
	{
		this->prajitura = p;
	}
	//facem o metoda per gram cate calorii are o prajitura
	float calculeazaNrTotalCalorii(float kcalpergram)
	{
		float nrTotal = kcalpergram * this->prajitura.getCantitate();
		return nrTotal;

	}
	//afiseaza studentul popescu mananca o amandina:
	void afisareMasa()
	{
		//trb sa facem prieten clasa student cu clasa prajitura ca sa fie denumirea permisa ptc e privata
		cout << this->nume << " mananca prajitura " << this->prajitura.denumire;

	}
};

void main() {
	Prajitura p;
	Student s1("Cristian", p);
	p.afisare();
	Prajitura::getContor();
	Prajitura p1("amandina", 15);
	//accesezi prin intermediul lui s1 ptc e metoda
	cout << s1.calculeazaNrTotalCalorii(0.5) << endl;
	s1.afisareMasa();
}