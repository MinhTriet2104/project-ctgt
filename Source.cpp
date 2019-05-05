/*
PROJECT Cau truc du lieu
*/

//khai bao thu vien
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;
#define MAX 10
struct Administrators
{
	string sAcount_Admin;
	string sPassword_Admin;
};

struct Employee
{
	string sAccount_user;
	string sPassword_user;
};
struct User
{
	string sAccount;
	string sPassword;
	string sName;
	int nAge;
	string sAddress;
	string nNumberPhone;
	string sMailAddress;
};
struct Node
{
	User xData;
	Node *pNext;
};
struct AdminNode
{
	Administrators xData;
	AdminNode *pNext;
};
struct AdminList
{
	AdminNode *pHead;
	AdminNode *pTail;
	AdminList()
	{
		pHead = pTail = NULL;
	}
};
struct EmployeeNode
{
	Employee xData;
	EmployeeNode *pNext;
};
struct EmployeeList
{
	EmployeeNode *pHead;
	EmployeeNode *pTail;
	EmployeeList()
	{
		pHead = pTail = NULL;
	}
};
struct List
{
	Node *pHead;
	Node *pTail;
	List()
	{
		pHead = pTail = NULL;
	}
};
//khai bao nguyen mau ham con
Node *CreateNode(User xUS);
AdminNode *CreateNodeAdmin(Administrators xAdmin);
EmployeeNode *CreateNodeEmployee(Employee xEmployee);
void addTail(List &L, User xUS);
void addTailAdmin(AdminList &L, Administrators xAdmin);
void addTailEmployee(EmployeeList &L, Employee xEmployee);
void login(User xUS);
void outputUser(List L);
void outputUsers(List L);
void docFileUsers(List &L);
void docFileAdmins(AdminList &L);
void docFileEmployees(EmployeeList &L);
void SetColor(int ForgC);
void menuAdmin();
void menuEmployee(string sUser);
void login(AdminList aL, EmployeeList eL);
void loading();
int checkUsername(string sUser, string sPass, AdminList aL, EmployeeList eL);
//ham main
void main()
{
	List userL;
	AdminList AdminL;
	EmployeeList EmployeeL;
	
	docFileAdmins(AdminL);
	docFileEmployees(EmployeeL);
	docFileUsers(userL);
	
	//outputUsers(userL);

	login(AdminL, EmployeeL);

	system("pause");
}
//dinh nghia ham con
void loading(int iTime) {
	for (int i = 0; i < iTime; i++) {
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(200);
    }
	cout << endl;
}

int checkUsername(string sUser, string sPass, AdminList aL, EmployeeList eL) {
	AdminNode *p = aL.pHead;
	EmployeeNode *q = eL.pHead;
	while (p != NULL) {
		if (p->xData.sAcount_Admin == sUser) {
			if (p->xData.sPassword_Admin == sPass) {
				return 1;
			}
		}
		p = p->pNext;
	}
	while (q != NULL) {
		if (q->xData.sAccount_user == sUser) {
			if (q->xData.sPassword_user == sPass) {
				return 2;
			}
		}
		q = q->pNext;
	}
	return 0;
}

void login(AdminList aL, EmployeeList eL) {
	int limit = 0;
	
	while(limit < 3) {
		SetColor(10);
		cout << "\t\t*************************************************" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*                    ";
		SetColor(14);
		cout << "SIGN IN";
		SetColor(10);
		cout <<"                    *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*************************************************" << endl;
		cout << endl;
		SetColor(13);
		string sUsername = "";
		cout << "\t\t\t-  Username:   ";
		SetColor(15);
		rewind(stdin);
		getline(cin, sUsername);

		SetColor(13);
		string sPass = "";
		char ch;
		cout << "\t\t\t-  Password:   ";
		SetColor(15);
		ch = _getch();
		while(ch != 13){
			sPass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		if (checkUsername(sUsername, sPass, aL, eL) == 1){
			SetColor(10);
			cout << "\n\t\t\t      Dang nhap thong cong!!!\n";
			cout << "\n\t\t\t\t\t\t";
			loading(3);
			system("cls");
			menuAdmin();
		}
		else if (checkUsername(sUsername, sPass, aL, eL) == 2) {
			SetColor(10);
			cout << "\n\t\t\t      Dang nhap thong cong!!!\n";
			cout << "\n\t\t\t\t\t\t";
			loading(3);
			system("cls");
			menuEmployee(sUsername);
		}
		else if (checkUsername(sUsername, sPass, aL, eL) == 0) {
			SetColor(12);
			cout << "\n\t\t\t      Sai ten hoac mat khau!\n";
			limit++;
			if (limit == 1) {
				cout << "\n\t\t\t      *Chu y: con 2 lan thu!\n" << endl;
			}
			if (limit == 2) {
				cout << "\n\t\t\t      *Chu y: con 1 lan thu!\n" << endl;
			}
			if (limit == 3) {
				cout << "\n\t\t\t      Qua so lan dang nhap!!!\n" << endl;
				break;
			}
			system("pause");
			system("cls");
		}
	}
}

void menuEmployee(string sUser) {
	ifstream fcin;
	fcin.open(sUser + ".dat");

	User xUS;
	rewind(stdin);
	getline(fcin, xUS.sName, '#');
	fcin>>xUS.nAge;
	fcin.ignore(1);
	rewind(stdin);
	getline(fcin, xUS.sAddress, '#');
	rewind(stdin);
	getline(fcin, xUS.nNumberPhone, '#');
	rewind(stdin);
	getline(fcin,xUS.sMailAddress);

	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                 ";
	SetColor(14);
	cout << "EMPLOYEE LOGIN";
	SetColor(10);
	cout <<"                *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. View my profile";SetColor(12); cout << "              =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Change password";SetColor(12); cout << "              =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Exit Application";SetColor(12); cout << "             =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	cin >> iOption;
	switch (iOption) {
	case 1:
		cout << "\n\n\t\tName: \t\t" << xUS.sName << endl;
		cout << "\t\tAge: \t\t" << xUS.nAge << endl;
		cout << "\t\tAddress: \t" << xUS.sAddress << endl;
		cout << "\t\tPhone: \t\t" << xUS.nNumberPhone << endl;
		cout << "\t\tMail: \t\t" << xUS.sMailAddress << endl << endl << endl;
		system("pause");
		system("cls");
		menuEmployee(sUser);
	case 2:
		break;
	default:
		break;
	}
}

void menuAdmin() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                   ";
	SetColor(14);
	cout << "ADMIN LOGIN";
	SetColor(10);
	cout <<"                 *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Create new employee";SetColor(12); cout << "          =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Find employee";SetColor(12); cout << "                =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Edit employee";SetColor(12); cout << "                =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. View employee";SetColor(12); cout << "                =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t5. Exit Application";SetColor(12); cout << "             =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	cin >> iOption;
}

void SetColor(int ForgC) 
{ 
    WORD wColor; 

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     CONSOLE_SCREEN_BUFFER_INFO csbi; 

         //We use csbi for the wAttributes word. 
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    { 
       //Mask out all but the background attribute, and add in the forgournd  color 
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
      SetConsoleTextAttribute(hStdOut, wColor); 
    } 
    return; 
} 

AdminNode *CreateNodeAdmin(Administrators xAdmin) {
	AdminNode *p = new AdminNode;
	if (p == NULL)
		exit(1);
	p->xData = xAdmin;
	p->pNext = NULL;
	return p;
}
EmployeeNode *CreateNodeEmployee(Employee xEmployee) {
	EmployeeNode *p = new EmployeeNode;
	if (p == NULL)
		exit(1);
	p->xData = xEmployee;
	p->pNext = NULL;
	return p;
}
Node *CreateNode(User xUS)
{
	Node *p = new Node;
	if (p == NULL)
		exit(1);
	p->xData = xUS;
	p->pNext = NULL;
	return p;
}
void login(User xUS)
{
	cout<<"\n Account: ";
	rewind(stdin);
	getline(cin, xUS.sAccount);
	cout<<"\n Password: ";
	rewind(stdin);
	getline(cin, xUS.sPassword);
}
void docFileUsers(List &L)
{
	ifstream fcin;
	fcin.open("user.DAT");
	while (fcin.eof() != 1)
	{
		User xUS;
		rewind(stdin);
		getline(fcin, xUS.sAccount, '#');
		rewind(stdin);
		getline(fcin, xUS.sPassword, '#');
		rewind(stdin);
		getline(fcin, xUS.sName, '#');
		fcin>>xUS.nAge;
		fcin.ignore(1);
		rewind(stdin);
		getline(fcin, xUS.sAddress, '#');
		rewind(stdin);
		getline(fcin, xUS.nNumberPhone, '#');
		rewind(stdin);
		getline(fcin,xUS.sMailAddress);
		addTail(L, xUS);
	}
	fcin.close();
}
void docFileAdmins(AdminList &L) {
	ifstream fcin;
	fcin.open("administrators.dat");
	while (fcin.eof() != 1)
	{
		Administrators xAdmin;
		rewind(stdin);
		getline(fcin, xAdmin.sAcount_Admin, '#');
		rewind(stdin);
		getline(fcin, xAdmin.sPassword_Admin);
		addTailAdmin(L, xAdmin);
	}
	fcin.close();
}
void docFileEmployees(EmployeeList &L) {
	ifstream fcin;
	fcin.open("employee.dat");
	while (fcin.eof() != 1)
	{
		Employee xEmployee;
		rewind(stdin);
		getline(fcin, xEmployee.sAccount_user, '#');
		rewind(stdin);
		getline(fcin, xEmployee.sPassword_user);
		addTailEmployee(L, xEmployee);
	}
	fcin.close();
}
void addTail(List &L, User xUS)
{
	Node *pNew = CreateNode(xUS);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = pNew;
	}
	else
	{
		L.pTail->pNext = pNew;
		L.pTail = pNew;
	}
}
void addTailAdmin(AdminList &L, Administrators xAdmin) {
	AdminNode *pNew = CreateNodeAdmin(xAdmin);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = pNew;
	}
	else
	{
		L.pTail->pNext = pNew;
		L.pTail = pNew;
	}
}
void addTailEmployee(EmployeeList &L, Employee xEmployee) {
	EmployeeNode *pNew = CreateNodeEmployee(xEmployee);
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = pNew;
	}
	else
	{
		L.pTail->pNext = pNew;
		L.pTail = pNew;
	}
}
void outputUser(User xUS)
{
	cout<<"\n Account: "<< xUS.sAccount<<endl;
	cout<<" Password: "<< xUS.sPassword <<endl;
	cout<<"\n Ho Ten: "<<  xUS.sName <<endl;
	cout<<"\n Tuoi: "<<  xUS.nAge <<endl;
	cout<<"\n Address: "<< xUS.sAddress <<endl;
	cout<<"\n nNumberPhone: "<<  xUS.nNumberPhone <<endl;
	cout<<"\n MailAddress: "<<  xUS.sMailAddress<<endl;
}
void outputUsers(List L)
{
	User xUS;
	cout << "\n______________XUAT DS______________\n";
	for(Node *p=L.pHead;p!=NULL;p=p->pNext)
	{
		outputUser(p->xData);
		cout<<endl;
	}
}
