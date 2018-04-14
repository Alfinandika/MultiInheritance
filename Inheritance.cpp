/*

Multi Inheritance
@Author : Alfin Andika Pratama
TWFrYXNpaCBiYW55YWsgbG9oIHlhIDopIA==
:) :) :) :)

*/
#include <iostream>
using namespace std;

//Deklarasi Class Print Data
class PrintData {
	public:
		PrintData() {} //Constructor

		void printOutput(string data) { //Deklarasi Method printOutput yang menerima parameter data dengan type string
			cout << data << endl; //langsung menampilkan data yang dikirim dari parameter
		}
		void printOutput(float data) { //Deklarasi Method printOutput yang menerima parameter data dengan type float
			cout << data << endl; //langsung menampilkan data yang dikirim dari parameter
		} 

		void printOutput(int data) { //Deklarasi Method printOutput yang menerima parameter data dengan type integer
			cout << data << endl; //langsung menampilkan data yang dikirim dari parameter
		}

		~PrintData() {} //Destructor
};

//Deklarasi Class student
class Student {
	//Access Modifiers protected nim, name, genger
	protected:
		string nim; //deklasari property nim dengan type data string
		string name; //deklasari property name dengan type data string
		string gender; //deklasari property gender dengan type data string

	//Access Modifiers public
	public : 
		Student() {} //constructor
		Student(string cNim, string cName, string cGender): nim{cNim}, name{cName}, gender{cGender} {} //constructor yang menerima parameter
		string getName() {return name;} //Getter yang mengambil data dari variable name
		void setName(string cName) {name = cName;} // Setter yang mengset data di variable name
		~Student() {} //Destructor
};


//Deklarasi Kelas Staff yang mewarisi sifat-sifat dari kelas PrintData
class Staff: public PrintData {
	private:
		string name; //deklasari property name dengan type data string
	public:
		Staff() {} //constructor
		string getName() {return name;} //getter name
		void setName(string cName) {name = cName;} //setter name
		~Staff() {}
};


//Deklarasi Kelas AcadResult yang mewarisi 2 buah class sekaligus yaitu dari kelas PrintData dan Kelas Student
class AcadResults: public Student, public PrintData {

	//Access Modifiers public untuk variabel ipk dan sks
	private:
		float ipk; //deklarasi property ipk dengan type data float
		int sks; //deklarasi property sks dengan type data sks
	public:
		AcadResults() {} //contrustor
		AcadResults(float cIpk, int cSks): ipk{cIpk}, sks{cSks} {} //contrustor yang memiliki parameter
		AcadResults(string cNim, string cName, string cGender, float cIpk, int cSks): Student(cNim, cName, cGender), ipk{cIpk}, sks{cSks} {}
		/*Code diatas Adalah Contrustor dari kelas AcadResult yang mana terdapat parameter dan telah mewarisi dari kelas student Dan Print Data dengan maksud sebagai berikut :
		- cNim yang mana mengset variable yang ada pada kelas Student
		- cName yang mana mengset variable yang ada pada kelas Student
		- cGender yang mana mengset variable yang ada pada kelas Student
		- cIPk yang mana mengset variable yang ada pada kelas AcadResults itu sendiri
		- sks yang mana mengset variable yang ada pada kelas AcadResults itu sendiri

		*/
		float getIpk() {return ipk;} //Getter IPK
		void setIpk(float cIpk) {ipk = cIpk;} //Setter IPK
		~AcadResults() {} //Destruktor
};

int main() {
	AcadResults result("17.11.1123", "Alfin Keren", "M", 3.25, 36); // Deklarasi object yang mereference dari class AcadResult dengan memasukan parameter NIM, Nama, Genger, IPK, dan SKS
	result.printOutput(result.getName()); // Pemanggilan object result dengan nama method PrintOut yang mana adalah milik kelas PrintData yang sifatnya telah diwariskan, dan mengoper parameter getName dengan tipe data string yang mana milik kelas Student yang telah diwariskan
	result.printOutput(result.getIpk()); // Pemanggilan object result dengan nama method PrintOut yang mana adalah milik kelas PrintData yang sifatnya telah diwariskan, dan mengoper parameter getIpk dengan tipe data float yang mana milik kelas AcadResult itu sendiri
	
	Staff staff; //deklarasi object Staff yang mereference class staff
	staff.printOutput("Another Name"); // Pemanggilan object staff dengan nama method PrintOut yang mana adalah milik kelas PrintData yang sifatnya telah diwariskan, dan mengoper parameter "Another Name" dengan tipe data string
	return 0;

	/*
	kesimpulan : 
	Pada kode program di atas terlihat  sebuah kelas yang diwarisi oleh dua buah kelas. Pemrogramman berorientasi objek pada C++ memang mengijinkan hal itu terjadi. oleh sebab itu kelas “AcadResults” dapat mengakses member yang ada pada kelas “PrintData” dan “Student”. sedangkan kelas “PrintData” memiliki dua buah kelas turunan yaitu “AcadResults” dan “Staff”.
	*/ 
}