#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//
//using namespace std;
//
//class Restaurant {
//public:
//	char* denumire;
//	float* salarii;
//	int nrStele;
//	int nrAngajati;
//	const int codFiscal;
//	static int TVA;
//
//	// 1. Constructor fără parametri
//	Restaurant() : codFiscal(0) {
//		this->denumire = new char[strlen("McDonalds") + 1];
//		strcpy(this->denumire, "McDonalds");
//		this->nrAngajati = 0;
//		this->nrStele = 4;
//		this->salarii = nullptr;
//	}
//
//	// 2. Constructorul cu parametri
//	Restaurant(const char* denumire, int nrStele, int nrAngajati, const float* salarii, int codFiscal) : codFiscal(codFiscal) {
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy(this->denumire, denumire); // <-- Corectat: adăugat strcpy
//
//		this->nrStele = nrStele;
//		this->nrAngajati = nrAngajati;
//
//		if (nrAngajati > 0 && salarii != nullptr) {
//			this->salarii = new float[nrAngajati];
//			for (int i = 0; i < nrAngajati; i++) {
//				this->salarii[i] = salarii[i];
//			}
//		}
//		else {
//			this->salarii = nullptr;
//			this->nrAngajati = 0;
//		}
//	}
//
//	// 3. Constructor de copiere
//	Restaurant(const Restaurant& r) : codFiscal(r.codFiscal) {
//		this->denumire = new char[strlen(r.denumire) + 1];
//		strcpy(this->denumire, r.denumire); // <-- Corectat: adăugat strcpy
//
//		this->nrStele = r.nrStele;
//		this->nrAngajati = r.nrAngajati;
//
//		if (r.nrAngajati > 0 && r.salarii != nullptr) { // <-- Corectat: folosit r.nrAngajati și r.salarii
//			this->salarii = new float[r.nrAngajati];
//			for (int i = 0; i < r.nrAngajati; i++) {
//				this->salarii[i] = r.salarii[i]; // <-- Corectat: folosit r.salarii[i]
//			}
//		}
//		else {
//			this->salarii = nullptr;
//			this->nrAngajati = 0;
//		}
//	}
//
//	// 4. Operatorul = (Atribuire)
//	Restaurant& operator=(const Restaurant& r) {
//		if (this != &r) {
//			if (this->denumire != NULL) {
//				delete[] this->denumire;
//			}
//			this->denumire = new char[strlen(r.denumire) + 1];
//			strcpy(this->denumire, r.denumire);
//
//			this->nrStele = r.nrStele;
//			this->nrAngajati = r.nrAngajati;
//
//			if (this->salarii != NULL) {
//				delete[] this->salarii; // Recomandat: eliberăm și vectorul vechi de salarii înainte de alocare nouă!
//			}
//
//			if (r.nrAngajati > 0 && r.salarii != nullptr) {
//				this->salarii = new float[r.nrAngajati];
//				for (int i = 0; i < r.nrAngajati; i++) {
//					this->salarii[i] = r.salarii[i];
//				}
//			}
//			else {
//				this->salarii = nullptr;
//				this->nrAngajati = 0;
//			}
//		}
//		return *this;
//	}
//
//	// 5. Destructorul 
//	~Restaurant() {
//		delete[] denumire;
//		delete[] salarii;
//	}
//
//	// Metodă de afișare
//	void afisare() {
//		cout << "Restaurant: " << (this->denumire ? this->denumire : "N/A")
//			<< ", Stele: " << this->nrStele
//			<< ", Cod Fiscal: " << this->codFiscal
//			<< ", TVA: " << TVA << "%" << endl;
//		cout << "Salarii angajati: ";
//		for (int i = 0; i < this->nrAngajati; i++) {
//			cout << this->salarii[i] << " ";
//		}
//		cout << endl;
//	}
//
//	// Calculul mediei salariale
//	float calculMedieSalariale() {
//		if ((this->nrAngajati == 0) || (this->salarii == nullptr)) return 0;
//		float s = 0;
//		for (int i = 0; i < nrAngajati; i++) {
//			s += this->salarii[i];
//		}
//		return s / nrAngajati;
//	}
//};
//
//// Inițializarea membrului static
//int Restaurant::TVA = 21;
//
//void main() {
//	float salariir1[] = { 3500, 4200, 3100 };
//	Restaurant r1("McDonalds", 4, 3, salariir1, 12025);
//	r1.afisare();
//	cout << "Media salariala: " << r1.calculMedieSalariale() << endl;
//
//	// Testăm și constructorul de copiere:
//	Restaurant r2 = r1;
//	cout << "\n--- Test Restaurant Copiat (r2) ---" << endl;
//	r2.afisare();
//}
class EchipaDeFotbal
{
	private:
	char *denumire;
	float *salariiJucatori;
	int nrJucatori;
	bool activ;
	const int anInfintare;
	static float primaMeci;
	public:
	//constructor fara parametri
		EchipaDeFotbal():anInfintare()
		{
			this->denumire=new char[strlen("FCSB")+1];
			strcpy(denumire,"FCSB");
			this->salariiJucatori= nullptr;
			this->activ=true;

		}
		//constructor cu parametri
		EchipaDeFotbal(char* denumire, float* salariiJucatori,int nrJucatori,bool activ) :anInfintare()
		{
			this->denumire=new char[strlen(denumire)+1];
			strcpy(denumire,this->denumire);
			this->nrJucatori=nrJucatori;
			if (salariiJucatori != nullptr && nrJucatori > 0)
			{
			this->salariiJucatori=new float [nrJucatori];
			for(int i=0;i<=nrJucatori;i++)this->salariiJucatori[i]=salariiJucatori[i];
			}
			else
			{
				this->nrJucatori=0;
				this->salariiJucatori=nullptr;
			}
		}
		//constrcuctor de copiere
		EchipaDeFotbal(const EchipaDeFotbal& e) :anInfintare()
		{
			this->denumire=new char[strlen(e.denumire)+1];
			strcpy(this->denumire,e.denumire);
			this->nrJucatori=e.nrJucatori;
			this->activ=e.activ;
			if (e.nrJucatori > 0 && e.salariiJucatori != nullptr)
			{	this->salariiJucatori=new float[nrJucatori];
				for(int i=0;i<nrJucatori;i++)this->salariiJucatori[i]=e.salariiJucatori[i];
			}
			else
			{
				nrJucatori=0;
				salariiJucatori=nullptr;
			}

		}
		//operatorul =:
		EchipaDeFotbal& operator=(const EchipaDeFotbal& e)
		{
			if (this != &e)
			{
				if(this->denumire!=NULL)delete[] this->denumire;
				this->denumire=new char[strlen(e.denumire)+1];
				strcpy(this->denumire,e.denumire);
				this->activ=e.activ;
				if(this->salariiJucatori!=nullptr)delete[] this->salariiJucatori;
				if (e.salariiJucatori != nullptr && e.nrJucatori != 0)
				{
					this->salariiJucatori=new float[nrJucatori];
					for(int i=0;i<=nrJucatori;i++)
					this->salariiJucatori[i]=e.salariiJucatori[i];

				}
				else
				{
					this->salariiJucatori=nullptr;
					this->nrJucatori=0;
				}

			}
			return *this;
		}
		//destructorul:
		~EchipaDeFotbal()
		{
			delete[] denumire;
			delete[] salariiJucatori;
		}
		//metoda de afisare
		void afisare()
		{
			cout<<"Denumirea echipei de fotbal este: "<<this->denumire<<endl;
			cout<<"Echipa are un nr de jucatori: "<<this->nrJucatori<<endl;
			cout<<"Salariile jucatorilor sunt:"<<endl;
			for(int i=0;i<nrJucatori;i++)cout<<this->salariiJucatori[i]<<" ";
			cout<<endl;
			cout<<"echipa este activa?"<<this->activ<<endl;
			cout<<"anul de infintare este "<<this->anInfintare<<endl;
		}
		//calc fondul total de salarii al echipei
		float suma()
		{
			int s=0;
			if(this->salariiJucatori==nullptr && this->nrJucatori==0)return 0;
			for(int i=0;i<nrJucatori;i++)s+=this->salariiJucatori[i];
			return s;
		}
		const char* getDenumire() const
		{
			return this->denumire;

		}
		const float* getSalarii()const
		{
			return this->salariiJucatori;

		}
		int getNrJucatori() const {
			return this->nrJucatori;
		}
		int getActiv() const {
			return this->activ;
		}
		int getAnInfiintare() const {
			return this->anInfintare;
		}
		
		static float getPrimaMeci() {
			return primaMeci;
		}
		//int EchipaDeFotbal::anInfintare=2003;

};
void main()
{
EchipaDeFotbal e;


}