#pragma once /*yêu cầu trình biên dịch chỉ biên dịch một lần cho một file header. 
Nó giúp tăng tốc độ biên dịch và tránh việc xảy ra các lỗi trùng lặp khi định nghĩa các hàm trong các tệp header khác nhau.*/
#include <iostream>
#include "goto_draw.cpp"
#include <ctime>
#include "update.cpp"
#include "inkhung.cpp"
using namespace std;
int c;
string getTime() // khai báo hàm getTime trả về kiểu string
{
    time_t now = time(0); // khai báo biến now kiểu time_t, và khởi tạo nó bằng thời gian hiện tại sử dụng hàm time().
    char time_buf[80]; //khai báo một mảng ký tự time_buf có độ dài 80, dùng để lưu trữ thời gian sau khi được định dạng.
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", localtime(&now)); // được sử dụng để định dạng thời gian now thành chuỗi ký tự theo định dạng "%H:%M:%S" (giờ:phút:giây) và lưu vào mảng time_buf.
    return string(time_buf); //trả về chuỗi ký tự sau khi được định dạng và lưu trong mảng time_buf dưới dạng kiểu string.
}
string getDay()
{
    time_t now = time(0); // lấy thời gian hiện tại bằng cách sử dụng hàm time() và lưu vào biến now.
    char time_buf[80]; // tạo một mảng ký tự với kích thước 80 để lưu trữ chuỗi thời gian được định dạng.
    strftime(time_buf, sizeof(time_buf), "%d/%m/%Y", localtime(&now)); /*Sử dụng hàm strftime() để định dạng thời gian và lưu vào mảng time_buf.
	                                                                    Th/s đầu là mảng ký tự cần lưu chuỗi thời gian, thứ 2 là kích thước của mảng,
																		 tham số thứ ba là định dạng của chuỗi thời gian được yêu cầu
																		  (trong trường hợp này là "dd/mm/yyyy"),
																		   và tham số cuối cùng là thời gian được định dạng.
	                                                                     Hàm localtime() được sử dụng để chuyển đổi thời gian từ dạng số sang dạng cấu trúc tm để có thể định dạng.*/
																		 return string(time_buf);
}
string printTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
}
/*Hàm printTime() sử dụng cấu trúc tm được khai báo trong thư viện ctime để lấy giờ,
 phút và giây hiện tại và trả về chuỗi string định dạng theo định dạng "HH:MM:SS".*/
	string printDate()
{
    time_t now = time(0); // lấy thời gian hiện tại ở đơn vị giây tính từ năm 1970 đến hiện tại.
    tm *ltm = localtime(&now); //chuyển đổi thời gian tính bằng giây thành đối tượng tm, chứa các thông tin về thời gian như giờ, phút, giây, ngày, tháng, năm.
    return to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);; //lấy thông tin năm từ đối tượng tm, cộng thêm 1900 (vì đối tượng tm chỉ lưu trữ số năm tính từ 1900) và chuyển sang chuỗi.
}
/*Hàm printDate() dùng để trả về ngày hiện tại dưới dạng chuỗi có định dạng "dd/mm/yyyy".*/
void success()
{
    cout << "------------------" << endl;
    SetColor(0, 9);
    cout << " Yeu cau cua ban da duoc thuc hien" << endl;
    cout << " Thoi gian: " << printTime() << endl;
    cout << " Ngay: " << printTime() << endl;
    SetColor(0, 7);
    cout << "------------------" << endl;
}
//đưa ra thông báo
void trasach(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	bool *kt = new bool[sosach + 1];
	for (int i = 1; i <= sosach; i++)
		kt[i] = false;

	string st = hs[h].borrow;
	string s;
	int muon;
	for (int i = 0; i <= st.length(); i++)
		if (st[i] == ';')
		{
			muon++;
			kt[stoi(s)] = true;
			s = "";
		}
		else
			s = s + st[i];
	int n;
	cout << "Nhap so sach ban muon tra hoac nhap 0 de huy yeu cau: ";
	cin >> n;
	while (n > muon - 1)
	{
		SetColor(0, 12);
		cout << "Khong hop le! ban chi muon " << muon - 1 << " quyen sach";
		SetColor(0, 7);
		cout << (char)16 << "Nhap lai so sach ban muon tra: ";
		cin >> n;
	}
	while (n < 0)
	{
		SetColor(0, 12);
		cout << "Nhap sai! vui long nhap lai:" << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		cin >> n;
	}
	if (n == 0)
	{
		SetColor(0, 10);
		cout << "Ban da huy yeu cau tra sach!" << endl;
		SetColor(0, 7);
	}
	if (n > 0)
	{
		int nn = n;
bool *kt = new bool[sosach + 1];
for (int i = 1; i <= sosach; i++)
    kt[i] = false;
string st = hs[h].borrow;
string s;
vector<int> ms1;
for (int i = 0; i < st.length(); i++)
    if (st[i] == ';')
    {
        kt[stoi(s)] = true;
        s = "";
    }
    else
        s = s + st[i];
cout << "Nhap ma sach ban muon muon, ngan cach boi enter: " << endl;
SetColor(0, 4);
cout << "LUU Y !!! Ban khong duoc muon 1 sach nhieu cuon hoac muon sach da het ( so luong = 0) " << endl;
SetColor(0, 7);
while (n > 0)
{
    n--;
    int ms;

    cout << " " << (char)16 << (char)16;
    cin >> ms;
    while ((ms <= 0) || (kt[ms] == true) || (sach[ms].amount == "0") || (ms > sosach))
    {
        SetColor(0, 4);
        cout << "Ban can nhap dung theo yeu cau, nhap lai ma: " << endl;
        cout << "Cac sach ma sach ban dang muon: ";
        cout << hs[h].borrow << endl;
        SetColor(0, 7);
        cout << " " << (char)16 << (char)16;
        cin >> ms;
    }

    //update
    SetColor(0, 2);
    cout << "Ban dang muon quyen " << sach[ms].bookname << endl;
    SetColor(0, 7);
    kt[ms] = true;
    ms1.push_back(ms);
    if (hs[h].borrow == "0;")
        hs[h].borrow = "";
    hs[h].borrow = hs[h].borrow + to_string(ms) + ";";
    int t = stoi(sach[ms].amount) - 1;
    sach[ms].amount = to_string(t);
}
n = nn;
string ngm, ngt;
int lc2;
success();
cout << "Ban co muon in phieu khong?" << endl;
cout << "	1. In phieu muon" << endl;
cout << "	2. Khong in" << endl;
cin >> lc2;
		if (lc2 == 1)
		{
			ofstream phieutra("phieutra.txt");
			phieutra << "Phieu tra sach" << endl;
			phieutra << "=============================" << endl;
			phieutra << "Ho ten: " << hs[h].hoten << endl;

			phieutra << "Ma so sach: "
					 << "   ";

			phieutra << "Ten sach: " << endl;
			for (int j = 0; j < n; j++)
			{
				phieutra << sach[ms1[j]].code;
				for (int l = sach[ms1[j]].code.length(); l < 15; l++)
				{
					phieutra << " ";
				}
				phieutra << sach[ms1[j]].bookname << endl;
			}
			phieutra << "Ngay tra: " << getDay() << endl;

			phieutra << "                             " << endl;
			phieutra << "=============================" << endl;
			phieutra << "Nguoi muon ky va ghi ro ho ten" << endl;
		}
		if (lc2 == 1)
		{
			SetColor(0, 10);
			cout << "In phieu tra thanh cong!" << endl;
			cout << "Hoan tat tra sach!" << endl;
			SetColor(0, 7);
		}
		if (lc2 == 2)
		{
			cout << "Ban da chon khong in phieu muon" << endl;
			SetColor(0, 10);
			cout << "Hoan tat tra sach" << endl;
			SetColor(0, 7);
		}
		update(hs, sohs, sach, sosach, h);
	}
}
void muon(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	cout << "Nhap so sach can muon (toi da 5 quyen), ngan cach boi enter: " << endl;
	int n;
	cin >> n;
	while ((n > 5))
	{
		SetColor(0, 4);
		cout << "Ban can chi duoc muon toi da 5 cuon" << endl;
		SetColor(0, 7);
		cout << "Nhap lai: ";
		cin >> n;
	}
	while (n < 0)
	{
		SetColor(0, 12);
		cout << "Nhap sai! vui long nhap lai:" << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		cin >> n;
	}
	if (n == 0)
	{
		SetColor(0, 10);
		cout << "Ban da huy yeu cau muon sach!" << endl;
		SetColor(0, 7);
	}
	if (n > 0)
	{

		int nn = n;
		bool *kt = new bool[sosach + 1];
		for (int i = 1; i <= sosach; i++)
			kt[i] = false;
		string st = hs[h].borrow;
		string s;
		vector<int> ms1;
		for (int i = 0; i <= st.length(); i++)
			if (st[i] == ';')
			{
				kt[stoi(s)] = true;
				s = "";
			}
			else
				s = s + st[i];
		cout << "Nhap ma sach ban muon muon, ngan cach boi enter: " << endl;
		SetColor(0, 4);
		cout << "LUU Y !!! Ban khong duoc muon 1 sach nhieu cuon hoac muon sach da het ( so luong = 0) " << endl;
		SetColor(0, 7);
		while (n > 0)
		{
			n--;
			int ms;

			cout << " " << (char)16 << (char)16;
			cin >> ms;
			//while ((kt[ms] == true) || (sach[ms].amount == "0") || ms <= 0 || ms > sosach)
			while ((ms <= 0) || (kt[ms] == true) || (sach[ms].amount == "0") || (ms > sosach))
			{
				SetColor(0, 4);
				cout << "Ban can nhap dung theo yeu cau, nhap lai ma: " << endl;
				cout << "Cac sach ma sach ban dang muon: ";
				cout << hs[h].borrow << endl;
				SetColor(0, 7);
				cout << " " << (char)16 << (char)16;
				cin >> ms;
			}

			//update
			SetColor(0, 2);
			cout << "Ban dang muon quyen " << sach[ms].bookname << endl;
			SetColor(0, 7);
			kt[ms] = true;
			ms1.push_back(ms);
			if (hs[h].borrow == "0;")
				hs[h].borrow = "";
			hs[h].borrow = hs[h].borrow + to_string(ms) + ";";
			int t = stoi(sach[ms].amount) - 1;
			sach[ms].amount = to_string(t);
		}
		n = nn;
		//	cout << ms1[1] << endl;
		string ngm, ngt;
		int lc2;
		success();
		cout << "Ban co muon in phieu khong?" << endl;
		cout << "	1. In phieu muon" << endl;
		cout << "	2. Khong in" << endl;
		cin >> lc2;

		//	cout <<"Ma sach muon: "<< hs[h].borrow<<endl;;
		if (lc2 == 1)
		{
			ofstream phieumuon("phieumuon.txt");
			phieumuon << "Phieu muon sach" << endl;
			phieumuon << "=============================" << endl;
			phieumuon << "Ho ten: " << hs[h].hoten << endl;

			phieumuon << "Ma so sach: "
					  << "   ";

			phieumuon << "Ten sach: " << endl;
			for (int j = 0; j < n; j++)
			{
				phieumuon << sach[ms1[j]].code;
				for (int l = sach[ms1[j]].code.length(); l < 15; l++)
				{
					phieumuon << " ";
				}
				phieumuon << sach[ms1[j]].bookname << endl;
			}
			phieumuon << "Ngay muon: " << getDay() << endl;

			phieumuon << "                             " << endl;
			phieumuon << "=============================" << endl;
			phieumuon << "Nguoi muon ky va ghi ro ho ten" << endl;
		}
		if (lc2 == 1)
		{
			SetColor(0, 10);
			cout << "In phieu muon thanh cong!" << endl;
			cout << "Hoan tat muon sach!" << endl;
			SetColor(0, 7);
		}
		if (lc2 == 2)
		{
			cout << "Ban da chon khong in phieu muon" << endl;
			SetColor(0, 10);
			cout << "Hoan tat muon sach" << endl;
			SetColor(0, 7);
		}
		update(hs, sohs, sach, sosach, h);
	}
}
void us1(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	SetColor(0, 10);
	cout << "+++++++++++++++++++++ CAC SACH HIEN CO THEO TUY CHON CUA BAN +++++++++++++++++++++" << endl;
	SetColor(0, 7);
	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 11);
	cout << left << setw(6) << "Ma sach" << " | ";
	cout << left << setw(33) << "Ten sach" << " | ";
	cout << left << setw(20) << "The loai" << " | ";
	cout << left << setw(8) << "So luong" << " | " << endl;
	cout << "-----------------------------------------------------------------------------" << endl;

	for (int i = 1; i < sosach + 1; i++)
	{
		cout << left << "   " << setw(3) << sach[i].code << " | ";
		cout << left << setw(30) << sach[i].bookname << " | ";
		cout << left << setw(17) << sach[i].category << " | ";
		cout << left << setw(6) << sach[i].amount << " | " << endl;
	}

	cout << "-----------------------------------------------------------------------------" << endl;
	SetColor(0, 10);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetColor(0, 7);
}
void us2(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long sosach, int h)
{
	long k = 1;
	system("cls");
	string st, t;

	for (int i = 1; i <= sohs; i++)
	{
		st = hs[h].getUserName();
		if (st == hs[i].getUserName())
		{
			t = hs[i].borrow;
			SetColor(0, 10);
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			SetColor(0, 7);
			if (t == "0;")
			{
				cout << "\nXin Chao ";
				SetColor(0, 9);
				cout << hs[i].hoten;
				SetColor(0, 7);
				cout << " , ban chua muon quyen sach nao!" << endl;
			}
			else
			{
				cout << "\nXin Chao ";
				SetColor(0, 9);
				cout << hs[i].hoten;
				SetColor(0, 7);
				cout << " , cac sach ban dang muon la: "
					 << endl;
				inkhung();
				st = hs[i].borrow;
				string sst;
				for (int i = 0; i < st.length(); i++)
				{
					if (st[i] == ';')
					{
						int num;
						stringstream ss;
						ss << sst;
						ss >> num;
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
				}

				cout << "_________________________________________________________________________" << endl;
				SetColor(0, 10);
				cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				SetColor(0, 14);

				cout << "\n1. In danh sach" << endl;
				cout << "2. Tra sach" << endl;
				cout << "3. Tro lai man hinh chon" << endl;
				SetColor(0, 7);
				cout << " " << (char)16 << (char)16;
				cin >> c;
				if (c == 1)
				{

					ofstream outfile;
					outfile.open("booklist.txt");
					outfile << "Xin Chao " << hs[i].hoten << " , cac sach ban dang muon la: " << endl
							<< endl;
					outfile << "_________________________________________________________________________" << endl;
					outfile << setw(2) << left << "|";
					outfile << setw(8) << left << "Ma sach";
					outfile << setw(11) << left << "|";
					outfile << setw(33) << left << "Ten sach";
					outfile << setw(5) << left << "|";
					outfile << setw(13) << left << "The loai";
					outfile << "|" << endl;
					outfile << "_________________________________________________________________________" << endl;
					st = hs[i].borrow;
					string sst;
					for (int i = 0; i < st.length(); i++)
					{
						if (st[i] == ';')
						{
							int num;
							stringstream ss;
							ss << sst;
							ss >> num;
							outfile << setw(5) << left << "|";
							outfile << setw(5) << left << sach[num].code;
							outfile << setw(4) << left << "|";
							outfile << setw(40) << sach[num].bookname;
							outfile << setw(2) << left << "|";
							outfile << setw(16) << sach[num].category << "|" << endl;
							k++;
							sst = "";
						}
						else
							sst = sst + st[i];
					}
					outfile << "_________________________________________________________________________" << endl;
					outfile.close();

					//success();
					//break;
				}
				if (c == 2)
					trasach(hs, sohs, sach, sosach, h);
			}
		}
	}
}
string convert(string s)
{
	for (int i = 0; i <= s.length(); i++)
		s[i] = tolower(s[i]);
	return s;
}

void us3(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	long g = 0;
	system("cls");
	vector<book> tam;
	tam.push_back(sach[0]);
	while (g == 0)
	{
		string tensach;
		SetColor(0, 11);
		cout << " Ban muon tim kiem sach gi?" << endl;
		cout << "  -> Nhap sach ban muon tim o day: ";
		SetColor(0, 7);
		fflush(stdin);
		getline(cin, tensach);
		int n = tensach.length();
		for (int i = 1; i <= sosach; i++)
			if (convert(sach[i].bookname).find(tensach) < sach[i].bookname.length())
				tam.push_back(sach[i]);
		//	cout << tam.size();
		g = tam.size() - 1;
		if (g == 0)
		{
			system("cls");
			SetColor(0, 4);
			cout << "Khong tim duoc sach thoa man" << endl;
			SetColor(0, 7);
		}
	}
	SetColor(0, 10);
	cout << " Tim kiem thanh cong!!" << endl;
	SetColor(0, 7);
	us1(hs, sohs, tam, g, h); // Cai nay chi de trinh bay cac sach, con muon quyen nao thi dung ham muon sau; neu kieu la us1 thi se auto goi ham muon, neu us3 us4 thi tu goi
	SetColor(0, 14);
	cout << "1. Muon sach" << endl;
	cout << "2. Tro lai man hinh chon" << endl;
	SetColor(0, 7);
	cout << " " << (char)16 << (char)16;
	cin >> c;
	if (c == 1)
	{
		muon(hs, sohs, sach, sosach, h);
	}
}
void us4(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	vector<book> tam;
	SetColor(0, 2);
	cout << "Hien tai thu vien co cac the loai sau:" << endl;
	map<string, int> kt;
	string ngc[1000];
	//for (int i=1;i<=sosach;i++) kt[sach[i].category] = 1;
	SetColor(0, 3);
	int k = 0;
	for (int i = 1; i <= sosach; i++)
		kt[sach[i].category] = 1;
	for (auto x : kt)
	{
		k++;
		cout << "  " << k << ". " << x.first << endl; //<< " " << x.second;
		ngc[k] = x.first;
	}
	SetColor(0, 7);
	cout << "Ban muon loc theo the loai nao?" << endl;
	cout << (char)16 << "Nhap so: ";
	int so;
	cin >> so;
	while ((so < 0) || (so > k))
	{
		SetColor(0, 12);
		cout << "Khong hop le!" << endl;
		SetColor(0, 7);
		cout << " Vui long nhap lai: ";
		cout << (char)16;
		cin >> so;
	}
	tam.push_back(sach[0]);
	for (int i = 1; i <= sosach; i++)
		if (sach[i].category == ngc[so])
			tam.push_back(sach[i]);
	long sotam = tam.size() - 1;
	us1(hs, sohs, tam, sotam, h);
	SetColor(0, 14);
	cout << "1. Muon sach" << endl;
	cout << "2. Chon the loai khac." << endl;
	cout << "3. Tro ve man hinh chon" << endl;
	SetColor(0, 7);
	cout << " " << (char)16 << (char)16;
	cin >> c;
	if (c == 1)
	{
		muon(hs, sohs, sach, sosach, h);
	}
	if (c == 2)
	{
		us4(hs, sohs, sach, sosach, h);
	}
}
void us5(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{
	string mk, lmk;
	system("cls");
	SetColor(0, 12);
	cout << " DOI MAT KHAU" << endl;
	SetColor(0, 11);
	cout << "Nhap mat khau moi: ";
	SetColor(0, 7);
	cin >> mk;
	while (mk == hs[h].getPassword())
	{
		system("cls");
		SetColor(0, 4);
		cout << (char)19 << "Ban da nhap trung mat khau cu" << endl;
		SetColor(0, 11);
		cout << "Nhap mat khau moi: ";
		SetColor(0, 7);
		cin >> mk;
		//	cout << "Nhap lai mat khau moi: ";cin >> lmk;
	}
	SetColor(0, 11);
	cout << "Nhap lai mat khau moi: ";
	SetColor(0, 7);
	cin >> lmk;
	while (mk != lmk)
	{
		system("cls");
		SetColor(0, 4);
		cout << (char)19 << "Mat khau khong trung khop" << endl;
		SetColor(0, 11);
		cout << "Nhap mat khau moi: ";
		SetColor(0, 7);
		cin >> mk;
		SetColor(0, 11);
		cout << "Nhap lai mat khau moi: ";
		SetColor(0, 7);
		cin >> lmk;
	}
	hs[h].setPassword(mk);
	update(hs, sohs, sach, sosach, h);
}
void user(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach, int h)
{ // dang dang nhap hoc sinh h
	system("cls");
	SetColor(0, 2);
	cout << "Dang nhap thanh cong " << endl;
	SetColor(0, 7);
	cout << " Xin chao: ";
	SetColor(0, 9);
	cout << hs[h].hoten;
	SetColor(0, 7);
	cout << " " << (char)1 << endl;
	SetColor(0, 14);
	cout << "1. Xem cac sach thu vien co - Muon sach" << endl;
	cout << "2. Kiem tra sach ban dang muon - Tra sach" << endl;
	cout << "3. Tim kiem sach - Muon sach " << endl;
	cout << "4. Loc sach theo the loai - Muon sach " << endl;
	cout << "5. Doi mat khau" << endl;
	SetColor(0, 7);
	int ma;
	cout << "Nhap chon lua cua ban: " << endl;
	cout << " " << (char)16 << (char)16;
	cin >> ma;

	switch (ma)
	{

	case 1:
		int lenh;
		us1(hs, sohs, sach, sosach, h);
		SetColor(0, 14);
		cout << "\n1. Muon sach" << endl;
		cout << "2. Tro ve man hinh chon " << endl;
		SetColor(0, 7);
		cout << " " << (char)16 << (char)16;
		cin >> lenh;
		if (lenh == 2)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		};
		if (lenh == 1)
		{

			muon(hs, sohs, sach, sosach, h); // Cong
			int lenh;
			cout << "-------------------------------";
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
				user(hs, sohs, sach, sosach, h);
			}
		}
		break;
	case 2:
		us2(hs, sohs, sach, sosach, h);
		if (c == 1)
		{
			SetColor(0, 10);
			cout << " In danh sach thanh cong!" << endl;
			SetColor(0, 7);
			cout << "----------------------" << endl;
			cout << "Ban co muon lam gi nua khong: " << endl;
			SetColor(0, 14);

			cout << "1. Tra sach" << endl;
			cout << "2. Tro lai man hinh chon" << endl;

			SetColor(0, 7);
			cout << " " << (char)16 << (char)16;
			int lenh;
			cin >> lenh;
			if (lenh == 1)
			{
				trasach(hs, sohs, sach, sosach, h);
				cout << "-------------------------------";
				cout << "\nBan co muon lam gi nua khong: " << endl;
				SetColor(0, 14);
				cout << "1. Tro ve man hinh chon " << endl;
				cout << "2. Ket thuc " << endl;
				SetColor(0, 7);
				int lenhx;
				cout << " " << (char)16 << (char)16;
				cin >> lenhx;
				if (lenhx == 1)
				{
					system("cls");
					user(hs, sohs, sach, sosach, h);
				}
			}
			if (lenh == 2)
			{
				system("cls");
				user(hs, sohs, sach, sosach, h);
			}
		}
		if (c == 2)
		{

			cout << "-------------------------------";
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			int lenh;
			cout << " " << (char)16 << (char)16;
			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				user(hs, sohs, sach, sosach, h);
			}
			if (lenh == 2)
			{
			};
		}
		if (c == 3)
		{

			system("cls");
			user(hs, sohs, sach, sosach, h);
		}

		break; // Sy
	case 3:
		us3(hs, sohs, sach, sosach, h);
		//us2(hs, sohs, sach, sosach,h);
		//int lenh;
		if (c == 1)
		{
			cout << "-------------------------------";
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			int lenh;
			cout << " " << (char)16 << (char)16;
			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				user(hs, sohs, sach, sosach, h);
			}
		}
		if (c == 2)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
	case 4:
		us4(hs, sohs, sach, sosach, h);

		if (c == 1)
		{
			cout << "-------------------------------";
			cout << "\nBan co muon lam gi nua khong: " << endl;
			SetColor(0, 14);
			cout << "1. Tro ve man hinh chon " << endl;
			cout << "2. Ket thuc " << endl;
			SetColor(0, 7);
			int lenh;
			cout << " " << (char)16 << (char)16;
			cin >> lenh;
			if (lenh == 1)
			{
				system("cls");
				user(hs, sohs, sach, sosach, h);
			}
		}
		if (c == 3)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
	case 5:
		us5(hs, sohs, sach, sosach, h);
		SetColor(0, 2);
		cout << "Ban da doi mat khau thanh cong" << endl;
		SetColor(0, 7);
		cout << "-------------------------------";
		cout << "\nBan co muon lam gi nua khong: " << endl;
		SetColor(0, 14);
		cout << "1. Tro ve man hinh chon " << endl;
		cout << "2. Ket thuc " << endl;
		SetColor(0, 7);
		int s;
		cout << " " << (char)16 << (char)16;
		cin >> s;
		if (s == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		};
		break;
	};
}
