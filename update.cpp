#pragma once
#include <iostream>
void update(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach, int h){
	fstream fin, fout;
	fin.open("data.csv", ios::in);
	fout.open("datanew.csv", ios::out);
	for (int i=0;i<=sohs;i++)
		{
			fout << hs[i].getUserName() << "," << hs[i].getPassword() << "," << hs[i].hoten << "," << hs[i].borrow << "\n";
		}
	fin.close();
	fout.close();

	// xóa tệp hiện có

	remove("data.csv");

	// // đổi tên file cập nhật bằng tên file hiện có

	rename("datanew.csv", "data.csv");
	// SACH
//	fstream fin, fout;
	fin.open("danhsachsach.csv", ios::in);
	fout.open("danhsachsachnew.csv", ios::out);
	for (int i=0;i<=sosach;i++)
		{
			fout << sach[i].code << "," <<  sach[i].bookname << "," << sach[i].category << "," << sach[i].amount << "\n";
		}
	fin.close();
	fout.close();

	// xóa tệp hiện có

	remove("danhsachsach.csv");

	// // đổi tên file cập nhật bằng tên file hiện có

	rename("danhsachsachnew.csv", "danhsachsach.csv");
	// SACH
}
void update2(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach, map<string,int> chk){
	fstream fin, fout;
	fin.open("data.csv", ios::in);
	fout.open("datanew.csv", ios::out);
	for (int i=0;i<=sohs;i++)
	if (chk[hs[i].getUserName()]==1)
		{
			fout << hs[i].getUserName() << "," << hs[i].getPassword() << "," << hs[i].hoten << "," << hs[i].borrow << "\n";
		}
	fin.close();
	fout.close();

	// xóa tệp hiện có
	remove("data.csv");

	// // đổi tên file cập nhật bằng tên file hiện có

	rename("datanew.csv", "data.csv");
	
}
