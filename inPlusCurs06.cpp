//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//class Smartphone
//{
//private:
//	char* model;
//	int memorieRAM;
//	int nrMasuratori;//br de el din vectorul de baterie
//	int* nivelBaterie;
//	bool icsNFC;
//	const int anFabricatie;
//	static int TVA;
//public:
//	//constructor fara parametri:
//	Smartphone() :anFabricatie(2020)
//	{
//		this->model = new char[strlen("Nokia") + 1];
//		strcpy(this->model, "Nokia");
//		this->memorieRAM = 8;
//		this->nrMasuratori = 0;
//		this->nivelBaterie = new int[3] {100, 85, 60};
//		this->icsNFC = true;
//
//	}
//	//constructor cu parametri
//	Smartphone(const char* model, int memorieRAM, int nrMasuratori, const int* nivelBaterie, bool icsNFC, int anFabricatie) :anFabricatie(anFabricatie)
//	{
//		this->model = new char[strlen(model) + 1];
//		strcpy(this->model, model);
//		this->memorieRAM = memorieRAM;
//		this->icsNFC = icsNFC;
//		this->nrMasuratori = nrMasuratori;
//		this->nivelBaterie = new int[this->nrMasuratori];
//		if (nrMasuratori > 0 && nivelBaterie != nullptr)
//		{
//			for (int i = 0;i < this->nrMasuratori;i++) { this->nivelBaterie[i] = nivelBaterie[i]; }
//		}
//		else
//		{
//			this->nrMasuratori = 0;
//			this->nivelBaterie = nullptr;
//		}
//	}
//	//constructor de copiere
//	Smartphone(const Smartphone& s) :anFabricatie(s.anFabricatie)
//	{
//		this->model = new char[strlen(s.model) + 1];
//		strcpy(this->model, s.model);
//		this->memorieRAM = s.memorieRAM;
//		this->nrMasuratori = s.nrMasuratori;
//		this->icsNFC = s.icsNFC;
//		this->nivelBaterie = new int[s.nrMasuratori];
//		if (s.nrMasuratori > 0 && s.nivelBaterie != nullptr)
//		{
//			for (int i = 0;i < this->nrMasuratori;i++) { this->nivelBaterie[i] = s.nivelBaterie[i]; }
//		}
//		else
//		{
//			this->nrMasuratori = 0;
//			this->nivelBaterie = nullptr;
//		}
//	}
//	//operator =
//	Smartphone& operator=(const Smartphone& s)
//	{
//		if (this != &s)
//		{
//			if (this->model != nullptr) { delete[] this->model; }
//			if (this->nivelBaterie != nullptr) { delete[] this->nivelBaterie; }
//			this->model = new char[strlen(s.model) + 1];
//			strcpy(this->model, s.model);
//			this->memorieRAM = s.memorieRAM;
//			this->nrMasuratori = s.nrMasuratori;
//			this->icsNFC = s.icsNFC;
//			this->nivelBaterie = new int[this->nrMasuratori];
//			if (s.nrMasuratori > 0 && s.nivelBaterie != nullptr)
//			{
//				for (int i = 0;i < this->nrMasuratori;i++) { this->nivelBaterie[i] = s.nivelBaterie[i]; }
//			}
//			else
//			{
//				this->nrMasuratori = 0;
//				this->nivelBaterie = nullptr;
//			}
//
//		}
//		return *this;
//	}
//	//destructor
//	~Smartphone()
//	{
//		delete[] this->model;
//		delete[] this->nivelBaterie;
//	}
//	//getteri
//	int getMemorieRAM() const { return this->memorieRAM; }
//	void setMemorieRAM(int ram) { this->memorieRAM = ram; }
//	const char* getModel() const { return this->model; }
//	int getNrMasuratori() const { return this->nrMasuratori; }
//	bool getIcsNFC() const { return this->icsNFC; }
//	//supraincarcarea operatorului binar + in doua forme obiect+valoare, valoare + obiect, pt a mari memoria ram
//	Smartphone operator+(int valoare) const
//	{
//		Smartphone copie = *this;
//		copie.memorieRAM = this->memorieRAM + valoare;
//		return copie;
//	}
//	friend Smartphone operator+(int valoare, const Smartphone& s)
//	{
//		Smartphone aux = s;
//		aux.memorieRAM = s.memorieRAM + valoare;
//		return aux;
//	}
//	//operator unar ++ prefixat:
//	Smartphone& operator++()
//	{
//		this->memorieRAM++;
//		return *this;
//	}
//	//operator unar postfixat
//	Smartphone operator++(int)
//	{
//		Smartphone copie = *this;
//		this->memorieRAM++;
//		return copie;
//	}
//	//operator de indexare[]
//	int& operator[](int index)
//	{
//		if (index > 0 && index < this->nrMasuratori)
//		{
//			return this->nivelBaterie[index];
//		}
//		throw "Index in afara limitelor!";
//	}
//	//operator de cast implicit la int
//	operator int() const
//	{
//		return this->memorieRAM;
//	}
//	//operator !
//	Smartphone operator!()const
//	{
//		Smartphone copie = *this;
//		copie.icsNFC = !this->icsNFC;
//		return copie;
//	}
//	//operator functie calculeaza media nivelului de baterie
//	float operator()()
//	{
//		if (this->nrMasuratori == 0)return 0;
//		float s = 0;
//		for (int i = 0;i < this->nrMasuratori;i++) {
//			s += this->nivelBaterie[i];
//		}
//		return s / this->nrMasuratori;
//	}
//	//operatori << si >>
//	friend ostream& operator<<(ostream& out, const Smartphone& s)
//	{
//		out
//			<< "Model: " << s.model
//			<< ", RAM: " << s.memorieRAM
//			<< ", NFC" << (s.icsNFC ? "DA" : "NU")
//			<< ", An: " << s.anFabricatie
//			<< ", TVA: " << s.TVA << "%"
//			<< ",  nr masuratori baterie: " << s.nrMasuratori << endl;
//		out << "Nivel baterie: ";
//		for (int i = 0;i < s.nrMasuratori;i++) {
//			out << s.nivelBaterie[i] << "% ";
//		}
//		out << endl;
//		return out;
//	}
//	friend istream& operator>>(istream& in, Smartphone& s)//fara const prc il vom modifica
//	{
//		cout << "introdu model: ";
//		char modelNou[100];
//		in >> modelNou;
//		delete[] s.model;
//		s.model = new char[strlen(modelNou) + 1];
//		strcpy(s.model, modelNou);
//		cout << "introdu memoria RAM :";
//		in >> s.memorieRAM;
//		cout << "introdu nr de baterie";
//		in >> s.nrMasuratori;
//		delete[] s.nivelBaterie;
//		s.nivelBaterie = new int[s.nrMasuratori];
//		for (int i = 0; i < s.nrMasuratori; i++) {
//			cout << "Nivel baterie masuratoare " << i + 1 << ": ";
//			in >> s.nivelBaterie[i];
//		}
//		return in;
//	}
//
//};
//int Smartphone::TVA=21;
//void main() {
//
//	int istoricBaterie[] = { 90, 75, 50, 30 };
//	Smartphone s1("iPhone 15", 6, 4, istoricBaterie, true, 2023);
//
//	cout << "Afisare" << endl;
//	cout << s1 << endl;
//
//	//testare operator+ obiect + valoare si valoare + obiect
//	Smartphone s2 = s1 + 4;
//	Smartphone s3 = 10 + s1;
//	cout << "RAM dupa s1 + 4: " << s2.getMemorieRAM() << endl;
//	cout << "RAM dupa 10 + s1: " << s3.getMemorieRAM() << endl;
//
//	//testare operatori++
//	++s1;
//	cout << "RAM dupa ++s1 pre: " << s1.getMemorieRAM() << endl;
//	s1++;
//	cout << "RAM dupa s1++ post: " << s1.getMemorieRAM() << endl;
//
//	//testare operator[] 
//	cout << "Nivelul bateriei la indexul 0: " << s1[0] << "%" << endl;
//	s1[0] = 95; // modif datorita &
//	cout << "Nivelul bateriei modificat la indexul 0: " << s1[0] << "%" << endl;
//
//	//testare operator de cast implicit
//	int ramImplicit = s1; //int
//	cout << "Memorie RAM prin cast implicit: " << ramImplicit << "GB" << endl;
//
//	//testare operator!
//	Smartphone s4 = !s1;
//	cout << "Stare NFC initiala: " << s1.getIcsNFC() << ", stare NFC dupa operator !: " << s4.getIcsNFC() << endl;
//
//	// Testare operator funcție ()
//	cout << "Media nivelului bateriei: " << s1() << "%" << endl;
//
//}