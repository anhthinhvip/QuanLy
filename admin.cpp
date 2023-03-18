#include<map>
#include <windows.h>
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
#include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
#include "docfile.cpp"
long kk;
book2 *tam;
hs2 *tam2;

using namespace std;
void xoatk(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach)
{
	map<string, int> chk;
	for (int i = 0; i <= sohs; i++)
		chk[hs[i].getUserName()] = 1;
	int n;
	//system("cls");
	cout << "SỐ TÀI KHOẢN BẠN MUỐN XÓA: ";
	SetColor(0, 2);
	cin >> n;
	SetColor(0, 7);
	while ((n > sohs) || (n <= 0))
	{
		cout << "NHẬP HỢP LỆ ";
		cin >> n;
	}
	sohs = sohs - n;
	cout << "NHẬP CÁC USERNAME, NGĂN CÁCH BỞI ENTER:" << endl;
	while (n > 0)
	{
		n--;
		string st;
		cout << (char)16;
		cin >> st;
		while ((chk[st] == 0) || (st == "ngoclinh"))
		{
			SetColor(0, 4);
			cout << "UserName KHÔNG TỒN TẠI, VUI LÒNG NHẬP LẠI" << endl;
			SetColor(0, 7);
			cout << (char)16;
			cin >> st;
		}
		chk[st] = 0;
		update2(hs, sohs, sach, sosach, chk);
		hs.resize(0);
		sach.resize(0);
		docfile(hs, sohs, sach, sosach);
		SetColor(0, 10);
		cout << "XÓA THÀNH CÔNG !" << endl;
		SetColor(0, 7);
	}
}

void xuat2(hs2 *hs, long sohs, vector<book> sach, long sosach)
{
	SetColor(0, 10);
	cout << "++++++++++++++++++++++ DANH SÁCH CÁC SINH VIÊN ĐANG MƯỢN SÁCH ++++++++++++++++++++++ " << endl
		 << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(4) << left << "STT";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(24) << left << "TÊN ĐĂNG NHẬP";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(20) << left << "TÊN SINH VIÊN";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "SỐ LƯỢNG"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	int i = 0;
	while (i < sohs)
	{
		i++;
		cout << setw(3) << left << "|";
		cout << setw(3) << left << i;
		cout << setw(5) << left << "|";
		cout << setw(29) << hs[i].username;
		cout << setw(4) << left << "|";
		cout << setw(26) << hs[i].hoten;
		cout << setw(5) << left << "|";
		cout << setw(6) << left << hs[i].sl << "|" << endl;
	};
	cout << "__________________________________________________________________________________" << endl;
	cout << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
void xuat3(vector<hocsinh> hs, long sohs, book2 *sach, long sosach)
{
	system("cls");
	cout << kk;
	SetColor(0, 10);
	cout << "+++++++++++++++++++++++++ SỐ LƯỢNG SÁCH ĐANG ĐƯỢC MƯỢN +++++++++++++++++++++++++" << endl
		 << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(8) << left << "MÃ SÁCH";
	SetColor(0, 7);
	cout << setw(11) << left << "|";
	SetColor(0, 11);
	cout << setw(33) << left << "TÊN SÁCH";
	SetColor(0, 7);
	cout << setw(3) << left << "|";
	SetColor(0, 11);
	cout << setw(11) << left << "THỂ LOẠI";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "SỐ LƯỢNG"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	string st;
	long long T = 0;
	for (int j = 1; j <= sosach; j++)
	{

		cout << setw(5) << left << "|";
		cout << setw(5) << left << sach[j].code;

		cout << setw(4) << left << "|";
		cout << setw(40) << sach[j].bookname;
		cout << setw(2) << left << "|";
		cout << setw(12) << left << sach[j].category;
		cout << setw(6) << left << "|";
		cout << setw(5) << left << sach[j].sl << "|" << endl;
		T = T + sach[j].sl;
		//   k++;
	}
	cout << "________________________________________________________________________________" << endl;
	SetColor(0, 11);
	cout << setw(49) << left << "TỔNG CỘNG	 ";
	SetColor(0, 7);
	cout << setw(15) << left << T << endl;
	cout << "________________________________________________________________________________" << endl
		 << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
bool temp1(book2 x, book2 y)
{
	return x.sl > y.sl;
};
bool temp2(book2 x, book2 y)
{
	return x.sl < y.sl;
};
bool cmp1(hs2 x, hs2 y)
{
	return x.sl > y.sl;
};
bool cmp2(hs2 x, hs2 y)
{
	return x.sl < y.sl;
};
void xuat4(vector<hocsinh> hs, long sohs, book2 *sach, long sosach)
{
	system("cls");
	SetColor(0, 10);
	cout << "+++++++++++++++++++++ SỐ LƯỢNG SÁCH HIỆN CÓ TRONG THƯ VIỆN +++++++++++++++++++++" << endl;
	SetColor(0, 7);
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 11);
	cout << "MÃ SÁCH";
	SetColor(0, 7);
	cout << " |";
	SetColor(0, 11);
	cout << "      TÊN SÁCH        ";
	SetColor(0, 7);
	cout << " 	   | ";
	SetColor(0, 11);
	cout << "    THỂ LOẠI  ";
	SetColor(0, 7);
	cout << "      | ";
	SetColor(0, 11);
	cout << "SỐ LƯỢNG";
	SetColor(0, 7);
	cout << " |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (int i = 1; i < sosach; i++)
	{ //	kk++;

		if (stoi(sach[i].code, 0) < 10)
			cout << " ";
		cout << "   " << sach[i].code << "   | ";
		cout << sach[i].bookname;
		for (int ii = sach[i].bookname.length(); ii <= 36; ii++)
			if (ii == 33)
				cout << "| ";
			else
				cout << " ";
		cout << sach[i].category;
		for (int ii = sach[i].category.length(); ii <= 20; ii++)
			if (ii == 17)
				cout << "| ";
			else
				cout << " ";
		cout << sach[i].sl;
		string tt = to_string(sach[i].sl);
		for (int i = 1; i < 7 - tt.length(); i++)
			cout << " ";
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 10);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetColor(0, 7);
}
void ad1(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	long k = 1;

	string st;
	cout << "Nhap username cua nguoi ma ban muon tra cuu: ";
	SetColor(0, 9);
	cin >> st;
	bool chay = false;
	SetColor(0, 7);
	for (int i = 1; i <= sohs; i++)
		if (st == hs[i].getUserName())
		{
			chay = true;
			cout << "Ho va ten: ";
			SetColor(0, 10);
			cout << hs[i].hoten << endl;
			SetColor(0, 7);
			if (hs[i].borrow == "0;")
			{
				SetColor(0, 4);
				cout << " !!! Hiện tại học sinh này chưa mượn sách cua thư viện!" << endl;
			}
			else
			{
				SetColor(0, 2);
				cout << "Các sách đang mượn: " << endl;
				SetColor(0, 7);
				inkhung();
				st = hs[i].borrow;
				string sst;
				for (int i = 0; i < st.length(); i++)
					if (st[i] == ';')
					{

						int num;
						stringstream ss;
						ss << sst;
						ss >> num; // CHUYEN XAU SANG SO - 1
						cout << setw(5) << left << "|";
						cout << setw(5) << left << sach[num].code;
						cout << setw(4) << left << "|";
						cout << setw(40) << sach[num].bookname;
						cout << setw(2) << left << "|";
						cout << setw(16) << sach[num].category << "|" << endl;
						k++;
						sst = "";
					}
					else
						sst = sst + st[i];
				cout << "_________________________________________________________________________" << endl;
			}
			break; //kiem duoc thi dung ko kiem nua
		}
	if (chay == false)
	{
		system("cls");
		cout << "Username không tồn tại " << endl;
		ad1(hs, sohs, sach, sosach);
	}
}
void ad2(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	system("cls");
	string t;
	string st;
	int i = 1;
	int sl[20];
	for (int i = 1; i <= sohs; i++)
	{
		sl[i] = 0;
	}
	SetColor(0, 10);
	cout << "++++++++++++++++++++++ DANH SÁCH SINH VIÊN ĐANG MƯỢN SÁCH ++++++++++++++++++++++ " << endl
		 << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(4) << left << "STT";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(24) << left << "TÊN ĐĂNG NHẬP";
	SetColor(0, 7);
	cout << setw(10) << left << "|";
	SetColor(0, 11);
	cout << setw(20) << left << "Tên sinh viên";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "Số lượng"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "__________________________________________________________________________________" << endl;
	for (int i = 1; i <= sohs; i++)
	{
		st = hs[i].borrow;
		string sst;
		for (int j = 0; j < st.length(); j++)
			if (st[j] == ';')
			{
				sl[i] = sl[i] + 1;
				sst = "";
			}
			else
				sst = sst + st[j];
	}

	int j = 1;
	tam2 = new hs2[sohs + 1];
	while (i <= sohs)
	{
		t = hs[i].borrow;
		if (t == "0;")
			sl[i] = 0;

		cout << setw(3) << left << "|";
		cout << setw(3) << left << j;
		tam2[j].hoten = hs[i].hoten;
		tam2[j].sl = sl[i];
		tam2[j].username = hs[i].getUserName();
		cout << setw(5) << left << "|";
		cout << setw(29) << hs[i].getUserName();
		cout << setw(4) << left << "|";
		cout << setw(26) << hs[i].hoten;
		cout << setw(5) << left << "|";
		cout << setw(6) << left << sl[i] << "|" << endl;

		j++;
		i++;
	};
	kk = j;
	cout << "__________________________________________________________________________________" << endl;
	cout << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
void ad3(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{

	int sl[sosach + 1];
	int T = 0;
	for (int i = 1; i <= sosach; i++)
	{
		sl[i] = 0;
	}
	//long k = 1;
	system("cls");
	SetColor(0, 10);
	cout << "+++++++++++++++++++++++++ SỐ LƯỢNG SÁCH ĐANG ĐƯỢC MƯỢN +++++++++++++++++++++++++" << endl
		 << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(8) << left << "Mã sách";
	SetColor(0, 7);
	cout << setw(11) << left << "|";
	SetColor(0, 11);
	cout << setw(33) << left << "Tên sách";
	SetColor(0, 7);
	cout << setw(3) << left << "|";
	SetColor(0, 11);
	cout << setw(11) << left << "Thể  loại ";
	SetColor(0, 7);
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(9) << left << "Số lượng"
		 << "|" << endl;
	SetColor(0, 7);
	cout << "________________________________________________________________________________" << endl;
	string st;
	for (int i = 1; i <= sohs; i++)
	{
		st = hs[i].borrow;
		string sst;
		for (int i = 0; i < st.length(); i++)
			if (st[i] == ';')
			{
				int num = stoi(sst);
				sl[num] = sl[num] + 1;
				sst = "";
			}
			else
				sst = sst + st[i];
	};
	kk = 0;
	tam = new book2[sosach + 1];
	for (int j = 1; j <= sosach; j++)
	{
		if (sl[j] != 0)
		{
			kk++;
			cout << setw(5) << left << "|";
			cout << setw(5) << left << sach[j].code;
			tam[kk].code = sach[j].code;
			tam[kk].bookname = sach[j].bookname;
			tam[kk].sl = sl[j];
			tam[kk].category = sach[j].category;
			cout << setw(4) << left << "|";
			cout << setw(40) << sach[j].bookname;
			cout << setw(2) << left << "|";
			cout << setw(12) << left << sach[j].category;
			cout << setw(6) << left << "|";
			cout << setw(5) << left << sl[j] << "|" << endl;
			T = T + sl[j];
			//k++;
		}
	}
	cout << "________________________________________________________________________________" << endl;
	SetColor(0, 11);
	cout << setw(49) << left << "Tổng cộng	 ";
	SetColor(0, 7);
	cout << setw(15) << left << T << endl;
	cout << "________________________________________________________________________________" << endl
		 << endl;
	SetColor(0, 10);
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	SetColor(0, 7);
}
void ad4(vector<book> sach, long sosach)
{
	SetColor(0, 10);
	cout << "+++++++++++++++++++++ SỐ LƯỢNG SÁCH HIỆN CÓ TRONG THƯ VIỆN +++++++++++++++++++++" << endl;
	SetColor(0, 7);
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 11);
	cout << "Mã sách";
	SetColor(0, 7);
	cout << " |";
	SetColor(0, 11);
	cout << "      Tên sách       ";
	SetColor(0, 7);
	cout << " 	   | ";
	SetColor(0, 11);
	cout << "    Thể loại  ";
	SetColor(0, 7);
	cout << "      | ";
	SetColor(0, 11);
	cout << "Số lượng";
	SetColor(0, 7);
	cout << " |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	kk = 0;

	tam = new book2[sosach + 1];
	for (int i = 1; i < sosach + 1; i++)
	{
		kk++;

		if (stoi(sach[i].code, 0) < 10)
			cout << " ";
		cout << "   " << sach[i].code << "   | ";
		cout << sach[i].bookname;
		for (int ii = sach[i].bookname.length(); ii <= 36; ii++)
			if (ii == 33)
				cout << "| ";
			else
				cout << " ";
		tam[kk].code = sach[i].code;
		tam[kk].bookname = sach[i].bookname;
		tam[kk].category = sach[i].category;
		tam[kk].sl = stoi(sach[i].amount);
		cout << sach[i].category;
		for (int ii = sach[i].category.length(); ii <= 20; ii++)
			if (ii == 17)
				cout << "| ";
			else
				cout << " ";
		cout << sach[i].amount;
		string tt = sach[i].amount;
		for (int i = 1; i < 7 - tt.length(); i++)
			cout << " ";
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 10);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetColor(0, 7);
}
void ad5(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach)
{
	cout << "Ban muốn thêm bao nhiêu sách :	";
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		SetColor(0, 2);
		cout << "Nhập mã sách " << i << ":" << endl;
		string ten;
		string sl, theloai;
		fflush(stdin);
		SetColor(0, 6);
		cout << "  " << (char)16 << "Nhập tên sách: ";
		getline(cin, ten);
		fflush(stdin);
		cout << "  " << (char)16 << "Nhập thể loại: ";
		getline(cin, theloai);
		cout << "  " << (char)16 << "Nhập số lượng: ";
		cin >> sl;
		cout << "-------" << endl;
		stringstream ss2;
		ss2 << sosach + i;
		string masach = ss2.str(); 
		book tam;
		tam.code = masach;
		tam.bookname = ten;
		tam.category = theloai;
		tam.amount = sl;
		sach.push_back(tam);
	};
	sosach = sosach + n; //cout << sosach;
	update(hs, sohs, sach, sosach, 0);
	SetColor(0, 10);
	cout << "Thêm sách thành công!";
	SetColor(0, 7);
}
//sử dụng quyền của admin
void admin(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach)
{
	system("cls");
	SetColor(0, 2);
	cout << "ĐĂNG NHẬP THÀNH CÔNG " << endl;
	SetColor(0, 14);
	cout << "1. Tìm kiếm thông tin sinh viên" << endl;
	cout << "2. Thống kê các sinh viên đang mượn - Sắp xếp - Xóa TK" << endl;
	cout << "3. Thống kê sách dang được sinh viên mượn - Sắp xếp" << endl;
	cout << "4. Thong ke cac sach hien tai cua thu vien" << endl;
	cout << "5. Nhap them dau sach moi" << endl;
	cout << "6. Xoa dau sach" << endl;
	int ma;
	SetColor(0, 7);
	cout << "Nhập lựa chọn của bạn: " << endl;
	cout << " " << (char)16 << (char)16;
	cin >> ma;
	switch (ma)
	{

	case 1:
		system("cls");
		ad1(hs, sohs, sach, sosach);
		cout << "Bạn có muốn làm gì nữa không ?: " << endl;
		SetColor(0, 14);
		cout << "1. Trở về màn hình chính " << endl;
		cout << "2. Kết thúc " << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		int lenh;
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			admin(hs, sohs, sach, sosach);
		}
		break;
	case 2:
		ad2(hs, sohs, sach, sosach);
		cout << "\nBan co muon lam gi nua khong" << endl;
		SetColor(0, 14);
		cout << "	1. Tro ve man hinh chon " << endl;
		cout << "	2. Sap xep giam dan theo so luong sach" << endl;
		cout << "	3. Sap xep tang dan theo so luong sach" << endl;
		cout << "	4. Xoa tai khoan" << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		cin >> lenh;
		if (lenh == 1)
		{

			system("cls");
			admin(hs, sohs, sach, sosach);
			break;
		}
		if (lenh == 2)
		{

			system("cls");
			sort(tam2 + 1, tam2 + sohs + 1, cmp1);
			xuat2(tam2, sohs, sach, sosach);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
		if (lenh == 3)
		{

			system("cls");
			sort(tam2 + 1, tam2 + sohs + 1, cmp2);
			xuat2(tam2, sohs, sach, sosach);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
		if (lenh == 4)
		{
			xoatk(hs, sohs, sach, sosach);
		}
		cout << "\nBan co muon lam gi nua khong: " << endl;
		SetColor(0, 14);
		cout << "1. Tro ve man hinh chon " << endl;
		cout << "2. Ket thuc " << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;

		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			admin(hs, sohs, sach, sosach);
		}
		break;

	case 3:
		ad3(hs, sohs, sach, sosach);
		cout << "\nBẠN CÓ MUỐN LÀM GÌ NỮA KHÔNG" << endl;
		SetColor(0, 14);
		cout << "	1. Tro ve man hinh chon " << endl;
		cout << "	2. Sap xep giam dan theo so luong sach" << endl;
		cout << "	3. Sap xep tang dan theo so luong sach" << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;

		cin >> lenh;
		// switch (lenh)
		if (lenh == 1)
		{

			system("cls");
			admin(hs, sohs, sach, sosach);
			break;
		}
		if (lenh == 2)
		{

			system("cls");
			sort(tam + 1, tam + kk + 1, temp1);
			xuat3(hs, sohs, tam, kk);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
		if (lenh == 3)
		{

			system("cls");
			sort(tam + 1, tam + kk + 1, temp2);
			xuat3(hs, sohs, tam, kk);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
	case 4:
		ad4(sach, sosach);
		cout << "\nBan co muon lam gi nua khong" << endl;
		SetColor(0, 14);
		cout << "	1. Tro ve man hinh chon " << endl;
		cout << "	2. Sap xep giam dan theo so luong sach" << endl;
		cout << "	3. Sap xep tang dan theo so luong sach" << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;

		cin >> lenh;
		if (lenh == 1)
		{

			system("cls");
			admin(hs, sohs, sach, sosach);
			break;
		}
		if (lenh == 2)
		{

			system("cls");
			sort(tam + 1, tam + kk + 1, temp1);
			xuat4(hs, sohs, tam, sosach);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
		if (lenh == 3)
		{

			system("cls");
			sort(tam + 1, tam + kk + 1, temp2);
			xuat4(hs, sohs, tam, sosach);
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;

			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				admin(hs, sohs, sach, sosach);
			}
			break;
		}
	case 5:
		ad5(hs, sohs, sach, sosach);
		system("cls");
		cout << "\nBan co muon lam gi nua khong: " << endl;
		SetColor(0, 14);
		cout << "1. Tro ve man hinh chon " << endl;
		cout << "2. Ket thuc " << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;

		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			admin(hs, sohs, sach, sosach);
		}
		break;
	}
}
