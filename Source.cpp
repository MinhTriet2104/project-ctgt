/*
PROJECT Cau truc du lieu
*/

//khai bao thu vien
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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
//ham main
void main()
{
	List userL;
	AdminList AdminL;
	EmployeeList EmployeeL;
	
	docFileAdmins(AdminL);
	docFileEmployees(EmployeeL);
	docFileUsers(userL);
	
	outputUsers(userL);

	system("pause");
}
//dinh nghia ham con
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
