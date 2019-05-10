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

//Khai bao struct
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
struct AdminNode {
	Administrators xData;
	AdminNode *pNext;
};
struct AdminList {
	AdminNode *pHead;
	AdminNode *pTail;
	AdminList() {
		pHead = pTail = NULL;
	}
};
struct EmployeeNode {
	Employee xData;
	EmployeeNode *pNext;
};
struct EmployeeList {
	EmployeeNode *pHead;
	EmployeeNode *pTail;
	EmployeeList() {
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
void addTail(User xUS);
void addTailAdmin(Administrators xAdmin);
void addTailEmployee(Employee xEmployee);
void outputUser(User xUS);
void outputUsers();
void docFileUsers();
void docFileAdmins();
void docFileEmployees();
void SetColor(int ForgC);
void menuAdmin();
void menuEmployee(string sUser);
void login();
void loading();
int checkUsername(string sUser, string sPass);
void editEmployee();
void ghiFileUser();
void ghiFileEmployee();
void ghiFileUserAccount(User xUser);
void changePassword(string sUser);

//Bien toan cuc
List userL;
AdminList AdminL;
EmployeeList EmployeeL;

//ham main
void main() {
	docFileAdmins();
	docFileEmployees();
	docFileUsers();
	
	//outputUsers(userL);

	login();

	system("pause");
}

//dinh nghia ham con
void ghiFileUserAccount(User xUser) {
	ofstream fcout;
	fcout.open(xUser.sAccount + ".dat");
	fcout << xUser.sName << '#';
	fcout << xUser.nAge << '#';
	fcout << xUser.sAddress << '#';
	fcout << xUser.nNumberPhone << '#';
	fcout << xUser.sMailAddress;
	fcout.close();
}

void ghiFileEmployee() {
	ofstream fcout;
	fcout.open("employee.dat");
	for (EmployeeNode *p = EmployeeL.pHead; p != NULL; p = p->pNext) {
		fcout << p->xData.sAccount_user << '#';
		fcout << p->xData.sPassword_user;
		if (p->pNext) {
			fcout << endl;
		}
	}
	fcout.close();
}

void ghiFileUser() {
	ofstream fcout;
	fcout.open("user.dat");
	for (Node *p = userL.pHead; p != NULL; p = p->pNext) {
		fcout << p->xData.sAccount << '#';
		fcout << p->xData.sPassword << '#';
		fcout << p->xData.sName << '#';
		fcout << p->xData.nAge << '#';
		fcout << p->xData.sAddress << '#';
		fcout << p->xData.nNumberPhone << '#';
		fcout << p->xData.sMailAddress;
		if (p->pNext) {
			fcout << endl;
		}
	}
	fcout.close();
}

void changePassword(string sUser) {
	string sPass;
	string sPass2;
	SetColor(13);
	cout << "\t\tNhap password moi: ";
	rewind(stdin);
	SetColor(15);
	getline(cin, sPass);

	do {
		SetColor(13);
		cout << "\t\tNhap lai password moi: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, sPass2);
		if (sPass != sPass2) {
			SetColor(12);
			cout << "\t\t\tNhap lai khong dung\n";
		}
	} while (sPass != sPass2);
	
	for (Node *p = userL.pHead; p != NULL; p = p->pNext) {
		if (p->xData.sAccount == sUser) {
			p->xData.sPassword = sPass;
		}
	}
	for (EmployeeNode *p = EmployeeL.pHead; p != NULL; p = p->pNext) {
		if (p->xData.sAccount_user == sUser) {
			p->xData.sPassword_user = sPass;
		}
	}
}

void editEmployee() {
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                 ";
	SetColor(14);
	cout << "ADMIN EDIT";
	SetColor(10);
	cout <<"                    *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	string sUsername;
	SetColor(13);
	cout << "\t\tNhap Username ban muon edit: ";
	rewind(stdin);
	SetColor(11);
	getline(cin, sUsername);
	bool flag = 0;
	for(Node *p = userL.pHead;p != NULL; p = p->pNext) {
		if (p->xData.sAccount == sUsername) {
			flag = 1;
			outputUser(p->xData);
			cout << endl;
			SetColor(10);
			cout << "\n\t\t\t * Lua chon edit * \n";
			SetColor(14);
			cout << "\t\t\t   1. Ho ten\n";
			cout << "\t\t\t   2. Tuoi\n";
			cout << "\t\t\t   3. Dia chi\n";
			cout << "\t\t\t   4. SDT\n";
			cout << "\t\t\t   5. Mail\n";
			cout << "\t\t\t   6. Quay lai\n";
			SetColor(13);
			int iOption;
			cout << "\n\t\t\t- Ban muon edit: ";
			SetColor(15);
			cin >> iOption;
			string sMoi;
			int iMoi;
			switch (iOption)
			{
			case 1:
				SetColor(13);
				cout << "\t\tNhap Ho ten moi: ";
				SetColor(15);
				rewind(stdin);
				getline(cin, sMoi);
				p->xData.sName = sMoi;
				SetColor(10);
				ghiFileUserAccount(p->xData);
				ghiFileUser();
				cout << "\n\t\t\tThay doi thanh cong!\n";
				system("pause");
				system("cls");
				menuAdmin();
				break;
			case 2:
				SetColor(13);
				cout << "\t\tNhap Tuoi moi: ";
				SetColor(15);
				rewind(stdin);
				cin >> iMoi;
				p->xData.nAge = iMoi;
				SetColor(10);
				ghiFileUserAccount(p->xData);
				ghiFileUser();
				cout << "\n\t\t\tThay doi thanh cong!\n";
				system("pause");
				system("cls");
				menuAdmin();
				break;
			case 3:
				SetColor(13);
				cout << "\t\tNhap Dia chi moi: ";
				SetColor(15);
				rewind(stdin);
				getline(cin, sMoi);
				p->xData.sAddress = sMoi;
				SetColor(10);
				ghiFileUserAccount(p->xData);
				ghiFileUser();
				cout << "\n\t\t\tThay doi thanh cong!\n";
				system("pause");
				system("cls");
				menuAdmin();
				break;
			case 4:
				SetColor(13);
				cout << "\t\tNhap SDT moi: ";
				SetColor(15);
				rewind(stdin);
				getline(cin, sMoi);
				p->xData.nNumberPhone = sMoi;
				SetColor(10);
				ghiFileUserAccount(p->xData);
				ghiFileUser();
				cout << "\n\t\t\tThay doi thanh cong!\n";
				system("pause");
				system("cls");
				menuAdmin();
				break;
			case 5:
				SetColor(13);
				cout << "\t\tNhap Mail moi: ";
				SetColor(15);
				rewind(stdin);
				getline(cin, sMoi);
				p->xData.sMailAddress = sMoi;
				SetColor(10);
				ghiFileUserAccount(p->xData);
				ghiFileUser();
				cout << "\n\t\t\tThay doi thanh cong!\n";
				system("pause");
				system("cls");
				menuAdmin();
				break;
			default:
				system("cls");
				menuAdmin();
				break;
			}
		}
	}
	if (flag == 0) {
		SetColor(12);
		cout << "\n\t\t\tUsername khong ton tai!\n";
		cout << endl;
		system("pause");
		system("cls");
		menuAdmin();
	}
}

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
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(200);
    }
	cout << endl;
}

int checkUsername(string sUser, string sPass) {
	AdminNode *p = AdminL.pHead;
	EmployeeNode *q = EmployeeL.pHead;
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

void login() {
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
		if (checkUsername(sUsername, sPass) == 1){
			SetColor(10);
			cout << "\n\n\t\t\t      Dang nhap thong cong!!!\n";
			cout << "\n\t\t\t\t\t\t";
			loading(3);
			system("cls");
			menuAdmin();
		}
		else if (checkUsername(sUsername, sPass) == 2) {
			SetColor(10);
			cout << "\n\n\t\t\t      Dang nhap thong cong!!!\n";
			cout << "\n\t\t\t\t\t\t";
			loading(3);
			system("cls");
			menuEmployee(sUsername);
		}
		else if (checkUsername(sUsername, sPass) == 0) {
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
	SetColor(15);
	cin >> iOption;
	switch (iOption) {
	case 1:
		SetColor(13);
		cout << "\n\n\t\tName: \t\t";
		SetColor(15);
		cout << xUS.sName << endl << endl;
		SetColor(13);
		cout << "\t\tAge: \t\t";
		SetColor(15);
		cout << xUS.nAge << endl << endl;
		SetColor(13);
		cout << "\t\tAddress: \t";
		SetColor(15);
		cout << xUS.sAddress << endl << endl;
		SetColor(13);
		cout << "\t\tPhone: \t\t";
		SetColor(15);
		cout << xUS.nNumberPhone << endl << endl;
		SetColor(13);
		cout << "\t\tMail: \t\t";
		SetColor(15);
		cout << xUS.sMailAddress << endl << endl << endl;
		system("pause");
		system("cls");
		menuEmployee(sUser);
	case 2:
		cout << endl;
		changePassword(sUser);
		ghiFileUser();
		ghiFileEmployee();
		SetColor(10);
		cout << "\n\t\t\tDoi password thanh cong!!!\n";
		system("pause");
		system("cls");
		menuEmployee(sUser);
		break;
	default:
		system("cls");
		login();
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
	SetColor(15);
	cin >> iOption;
	switch (iOption) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		system("cls");
		editEmployee();
		break;
	case 4:
		system("cls");
		outputUsers();
		system("pause");
		system("cls");
		menuAdmin();
		break;
	case 5:
		system("cls");
		break;
	default:
		break;
	}
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
void docFileUsers()
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
		addTail(xUS);
	}
	fcin.close();
}
void docFileAdmins() {
	ifstream fcin;
	fcin.open("administrators.dat");
	while (fcin.eof() != 1) {
		Administrators xAdmin;
		rewind(stdin);
		getline(fcin, xAdmin.sAcount_Admin, '#');
		rewind(stdin);
		getline(fcin, xAdmin.sPassword_Admin);
		addTailAdmin(xAdmin);
	}
	fcin.close();
}
void docFileEmployees() {
	ifstream fcin;
	fcin.open("employee.dat");
	while (fcin.eof() != 1) {
		Employee xEmployee;
		rewind(stdin);
		getline(fcin, xEmployee.sAccount_user, '#');
		rewind(stdin);
		getline(fcin, xEmployee.sPassword_user);
		addTailEmployee(xEmployee);
	}
	fcin.close();
}
void addTail(User xUS)
{
	Node *pNew = CreateNode(xUS);
	if (userL.pHead == NULL)
	{
		userL.pHead = userL.pTail = pNew;
	}
	else
	{
		userL.pTail->pNext = pNew;
		userL.pTail = pNew;
	}
}
void addTailAdmin(Administrators xAdmin) {
	AdminNode *pNew = CreateNodeAdmin(xAdmin);
	if (AdminL.pHead == NULL)
	{
		AdminL.pHead = AdminL.pTail = pNew;
	}
	else
	{
		AdminL.pTail->pNext = pNew;
		AdminL.pTail = pNew;
	}
}
void addTailEmployee(Employee xEmployee) {
	EmployeeNode *pNew = CreateNodeEmployee(xEmployee);
	if (EmployeeL.pHead == NULL)
	{
		EmployeeL.pHead = EmployeeL.pTail = pNew;
	}
	else
	{
		EmployeeL.pTail->pNext = pNew;
		EmployeeL.pTail = pNew;
	}
}
void outputUser(User xUS) {
	SetColor(13);
	cout<<"\n \t\tAccount: ";
	SetColor(15);
	cout << xUS.sAccount<<endl;

	SetColor(13);
	cout<<" \t\tPassword: ";
	SetColor(15);
	cout << xUS.sPassword <<endl;

	SetColor(13);
	cout<<"\n \t\tHo Ten: ";
	SetColor(15);
	cout <<  xUS.sName <<endl;

	SetColor(13);
	cout<<"\n \t\tTuoi: ";
	SetColor(15);
	cout <<  xUS.nAge <<endl;

	SetColor(13);
	cout<<"\n \t\tAddress: ";
	SetColor(15);
	cout << xUS.sAddress <<endl;

	SetColor(13);
	cout<<"\n \t\tnNumberPhone: ";
	SetColor(15);
	cout <<  xUS.nNumberPhone <<endl;

	SetColor(13);
	cout<<"\n \t\tMailAddress: ";
	SetColor(15);
	cout <<  xUS.sMailAddress<<endl;
}
void outputUsers() {
	User xUS;
	SetColor(10);
	cout << "\n**************************** Danh Sach User ****************************\n";
	int i = 1;
	for(Node *p = userL.pHead;p!=NULL;p=p->pNext) {
		SetColor(14);
		cout << "\n\t\t-------------- User " << i << " --------------\n";
		outputUser(p->xData);
		cout<<endl;
		i++;
	}
}
