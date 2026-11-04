#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Telefon
{
	float rezolutie;
	float memorie;
	string model;
	char *producator;
	float pret;
	int nrAplicatii;
	float* memorieAplicatii;
	const int id;
	static int contor;
	public:
	//constructor fara parametri
		Telefon():id(contor++)
		{
			this->rezolutie=5.3;
			this->memorie=64;
			this->model="iph11";
			this->producator=new char[strlen("apple")+1];
			strcpy(this->producator,"apple");
			this->pret=400;
			this->nrAplicatii=5;
			this->memorieAplicatii=new float[this->nrAplicatii];
				this->memorieAplicatii[0]=2;
				this->memorieAplicatii[1] = 3;
				this->memorieAplicatii[2] = 4;
				this->memorieAplicatii[3] = 5;
				this->memorieAplicatii[4] = 2.4;
		}
		//cu parametrii
		Telefon(float rezolutie, float memorie) :id(contor++)
		{	this->rezolutie=rezolutie;
			this->memorie=memorie;
			this->model = "Iphone 17";
			this->producator = new char[strlen("Apple") + 1];
			strcpy_s(producator, strlen("Apple") + 1, "Apple");
			this->pret = 4000;
			this->nrAplicatii = 5;
			this->memorieAplicatii = new float[this->nrAplicatii];
			this->memorieAplicatii[0] = 2;
			this->memorieAplicatii[1] = 3;
			this->memorieAplicatii[2] = 1.4;
			this->memorieAplicatii[3] = 1.6;
			this->memorieAplicatii[4] = 2.4;

		}
	//constructor de copiere
	Telefon(const Telefon& t):id(t.contor++)
	{
		this->rezolutie=t.rezolutie;
		this->memorie=t.memorie;
		this->model=t.model;
		this->producator=new char[strlen(t.producator)+1];
		strcpy(this->producator,t.producator);
		this->pret=t.pret;
		this->nrAplicatii=t.nrAplicatii;
		this->memorieAplicatii=new float[t.nrAplicatii];
		if (t.nrAplicatii > 0 && t.memorieAplicatii != nullptr)
		{	for (int i=0;i<this->nrAplicatii;i++)
		{
			this->memorieAplicatii[i] = t.memorieAplicatii[i];
		}

		}
		else
		{
			this->nrAplicatii=0;
			this->memorieAplicatii=nullptr;
		}
	}
	~Telefon()
	{
		delete[] this->producator;
		delete[] this->memorieAplicatii;
	}
//op =
	Telefon& operator=(const Telefon& t)
	{
		if (this != &t)
		{
			this->rezolutie = t.rezolutie;
			this->memorie = t.memorie;
			this->model = t.model;
			if (this->producator != NULL)
				delete[] this->producator;
			this->producator = new char[strlen(t.producator) + 1];
			strcpy_s(producator, strlen(t.producator) + 1, t.producator);
			this->pret = t.pret;
			this->nrAplicatii = t.nrAplicatii;
			if (this->memorieAplicatii != NULL)
				delete[] memorieAplicatii;
			this->memorieAplicatii = new float[this->nrAplicatii];
			for (int i = 0;i < this->nrAplicatii;i++)
			{
				this->memorieAplicatii[i] = t.memorieAplicatii[i];
			}
		}

		return *this;
	}
	//getteri si setteri
	float getPret(){return this->pret;}
	void setPret(float pret);
	float getNrAplicatii() { return this->nrAplicatii; }
	char* getProducator(){return this->producator;}
	void setProducator(const char* producator)
	{
		delete[] this->producator;
		this->producator=new char[strlen(producator)+1];
		strcpy(this->producator,producator);
	}
	//op+
	Telefon operator+(const Telefon& t)
	{
		Telefon rez=*this;
		rez.pret=this->pret+ t.pret;//primu parametru este pointerul this iar al doilea este parametru
		return rez;
	}
	Telefon operator+(float crestere)const
	{ Telefon rez=*this;
		rez.pret=this->pret+ crestere;
		return rez;
	}
	friend Telefon operator+(float crestere, Telefon t)
	{
		Telefon rez=t;
		t.setPret(t.getPret()+crestere);
		return rez;
	}
	//seminar 6
	//operator cast:
	explicit operator float()
	{
		float suma=0;
		if (this->nrAplicatii > 0)
		{
			for (int i = 0;i < this->nrAplicatii;i++)
			{
				suma+=this->memorieAplicatii[i];
			}
			return suma/this->nrAplicatii;
		}
		else return 0;
	}
	explicit operator int()
	{
		return this->nrAplicatii;
	}
	//pre decrementare
	Telefon& operator--()
	{
		this->pret--;
		return *this;
	}
	//post decrementare
	Telefon operator--(int)
	{	Telefon copie=*this;
	this->pret--;
	return copie;

	}
	//<<
	friend ostream& operator<<(ostream& out, const Telefon& a)
	{
		out << "Id: " << a.id << endl
			<< "Producator" << a.producator << endl
			<< "Pret: " << a.pret << endl
			<< "Memorie: " << a.memorie << endl
			<< "Nr aplicatii : " << a.nrAplicatii << endl;
		for (int i = 0;i < a.nrAplicatii;i++)out << a.memorieAplicatii[i] << ", ";
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Telefon& a)
	{
	cout<<"Producator: ";//ptc ai o functie de tip char trb sa alocam niste spatiu pt noua functie pe care o vom citi
	char buffer[100];
	in>>buffer;
	if (a.producator) {
		delete[] a.producator;
	}
	a.producator=new char[strlen(buffer)+1];
	strcpy(a.producator, buffer);
	cout << "memorie: "; in >> a.memorie;
	cout << "nr aplicatii: "; in >> a.nrAplicatii;
	if (a.memorieAplicatii)
	{
		delete[] a.memorieAplicatii;
	}
	a.memorieAplicatii = new float[a.nrAplicatii];
	cout << "introdu memoria de aplicatii: ";
	for (int i = 0;i < a.nrAplicatii;i++)
	{
		in >> a.memorieAplicatii[i];
	}
	return in;

	}
	//operator functie:returneaza pret/nraplicatii
	float operator()()
	{
		if(this->nrAplicatii>0){return this->pret/this->nrAplicatii;}
		else return 0;
	}
	float operator()(float TVA)
	{
		if (this->nrAplicatii > 0) {
			return (this->pret + this->pret * TVA) / this->nrAplicatii;
		}
		else return 0;
	}
	//primeasca un discount de 20%
	float operator()(int discout)
	{

		if (this->nrAplicatii > 0) {
			return ((this->pret - (discout / 100.0 * this->pret)) / this->nrAplicatii);
		}
		else return 0;

	}
	//operator ==
	bool operator==(Telefon t)
	{
		//comparam mai multe atribute:
		/*float rezolutie;
		float memorie;
		string model;
		char* producator;*/
		if(strcmp(this->producator,t.producator)!=0){return false;}
		if (this->rezolutie != t.rezolutie) { return false; }
		if (this->memorie != t.memorie) { return false; }
		if (this->model != t.model) { return false; }
		return true;
	}
	//operator >=

	void afisare() {
		cout << "Rezolutie: " << this->rezolutie << "\n";
		cout << "Memorie: " << this->memorie << "\n";
		cout << "Model: " << this->model << "\n";
		cout << "Producator: " << this->producator << "\n";
		cout << "Pret: " << this->pret << "\n";
		cout << "Numar aplicatii: " << this->nrAplicatii << "\n";
		cout << "Memorie ocupata: ";
		for (int i = 0; i < this->nrAplicatii; i++)
			cout << this->memorieAplicatii[i] << "; ";
		cout << endl;
	}

	float calculeazaMemorieOcupata() {
		float sumaMemorie = 0;
		for (int i = 0; i < this->nrAplicatii; i++)
			sumaMemorie += memorieAplicatii[i];
		return sumaMemorie;
	}

	float calculeazaMemorieLibera() {
		return memorie - calculeazaMemorieOcupata();
	}

	void modificaProducator(const char* producatorNou) {
		delete[]this->producator;
		producator = new char[strlen(producatorNou) + 1];
		strcpy_s(producator, strlen(producatorNou) + 1, producatorNou);
	}
	friend class Student;
};

int Telefon::contor = 1000;



float calcularePretTotal(Telefon* v, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0;i < nrTelefoane;i++)
		suma += v[i].getPret();
	return suma;
}
float calculeazaMemorieDisponibila(Telefon* g, int nrTelefoane)
{
	float suma = 0;
	for (int i = 0;i < nrTelefoane;i++)
		suma += g[i].calculeazaMemorieLibera();
	return suma;

}

float calculeazaPretPerAplicatie(Telefon x)
{
	if (x.getNrAplicatii() == 0)
	{
		return 0;
	}
	else
	{
		return x.getPret() / x.getNrAplicatii();
	}
}

void Telefon::setPret(float pret)
{
	this->pret = pret;
}

class Student {
	string nume;
	Telefon telefon;
public:
	Student() {
		nume = "Popescu";
	}
	Student(string nume, Telefon telefon) {
		this->nume = nume;
		this->telefon = telefon;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	Telefon getTelefon() {
		return this->telefon;
	}

	void setTelefon(const Telefon& t) {
		this->telefon = t;
	}

	bool poateInstalaAplicatia(float memorieNecesara) {
		return (memorieNecesara <= this->telefon.calculeazaMemorieLibera());
	}

	void afisareInformatii() {
		cout << "\n" << this->nume << " are un telefon cu " << this->telefon.memorie << " Giga memorie" << endl;
	}

};
//seminar6
//cast <<,>>, --, (),+= aplicatii



void main() {

	Telefon t;
	Telefon t2(6.3, 512);
	Telefon t3 = t;
	float memorieMedie;
	memorieMedie = (float)t;
	t3 = --t;
	t3 = t--;
	//cin >> t;
	cout << t;
	cout << "pretul per aplicatie= " << t3() << endl;
	cout << "pret cu tot cu tva per aplicatie " << t3(0.21f) << endl;
	cout << "pretul cu discount per aplicatie " << t3(21) << endl;
	if (t == t2)cout << "telefoane asemanatoare" << endl;
	else cout << "telefoane diferite" << endl;
	/*cout << t2.getProducator();
	cout << calculeazaPretPerAplicatie(t);
	Student student("Andrei", t2);
	cout << student.getNume();
	cout << student.getTelefon().getProducator();
	student.afisareInformatii();

	int a = 10;
	int b = a + 3;
	cout << a;*/
}