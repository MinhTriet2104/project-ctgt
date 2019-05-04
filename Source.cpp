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
void addTail(List &L, User xUS);
void login(User xUS);
void inputList(List &L, User &xUS);
void output1user(List L);
void output(List L);
void docFile(List &L ,int nN);
//ham main
void main()
{
	List L;
	User xUS;
	login(xUS);
	/*input(L, xUS);*/
	
	inputList(L, xUS);
	
	output(L);
	system("pause");
}
//dinh nghia ham con
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
void docFile(List &L ,int nN)
{

	ifstream fcin;
	fcin.open("Text.DAT", ios::in);
	if(fcin.is_open() == true)
	{
		cout<<" Doc file thanh cong";

	}
	else
	{
		cout<<" Doc file khong thanh cong ";
	}
	User xUS;
	Node *p = L.pHead;
	p=CreateNode(xUS);
	for(int i =0;i<nN;i++)
	{
		
		
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
void output1user(User xUS)
{
	cout<<"\n Account: "<< xUS.sAccount<<endl;
		cout<<" Password: "<< xUS.sPassword <<endl;
		cout<<"\n Ho Ten: "<<  xUS.sName <<endl;
		cout<<"\n Tuoi: "<<  xUS.nAge <<endl;
		cout<<"\n Address: "<< xUS.sAddress <<endl;
		cout<<"\n nNumberPhone: "<<  xUS.nNumberPhone <<endl;
		cout<<"\n MailAddress: "<<  xUS.sMailAddress<<endl;
}
void output(List L)
{
	User xUS;
	cout << "\n______________XUAT DS______________\n";
	for(Node *p=L.pHead;p!=NULL;p=p->pNext)
	{
		output1user(p->xData);
		cout<<endl;
	}

}
void inputList(List &L, User &xUS)
{
	Node *p = L.pHead;
	int nN = 4;
	docFile(L, nN);
	for (p;p!=NULL;p=p->pNext)
	{
		
		p=CreateNode(xUS);
		addTail(L, xUS);
	}
}
