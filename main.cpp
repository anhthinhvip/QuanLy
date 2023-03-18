#include <bits/stdc++.h>
#include <windows.h>
#include "data.cpp"
#include "admin.cpp"
#include "user.cpp"
#include "book.cpp"
#include <windows.h>
#include "goto_draw.cpp"
#include "docfile.cpp"
using namespace std;
int tt = 0;
string mk;
string tk;
long sohs, sosach;
vector<hocsinh> hs;
vector<book> sach;
bool kkt = false;
void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void GoTo(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawx(int x, int y, int width, int height)
{
    GoTo(x, y);
    cout << "╔";
    for (int i = 1; i < width; i++)
        cout << "═";
    cout << "╗";
    for (int i = 1; i < height; i++)
    {
        GoTo(x, y + i);
        cout << "║";
        GoTo(x + width, y + i);
        cout << "║";
    }
    GoTo(x, y + height);
    cout << "╚";
    for (int i = 1; i < width; i++)
        cout << "═";
    cout << "╝";
}

void drawbook()
{
    system("cls");
    SetColor(0x0F); // Set color to white text on black background
    GoTo(58, 2);
    cout << "╔════════════════════════════════════════╗" << endl;
    for (int i = 0; i <= 6; i++)
    {
        GoTo(58, 3 + i);
        cout << "║                                        ║" << endl;
    }
    GoTo(58, 9);
    cout << "╚════════════════════════════════════════╝" << endl;
    GoTo(62, 5);
    SetColor(0x0E); // Set color to yellow text on black background
    cout << "QUẢN LÝ THƯ VIỆN";
    SetColor(0x0F); // Set color back to white text on black background
    GoTo(66, 6);
    cout << "PHẠM VĂN THỊNH";
    drawx(55, 1, 120, 12);
    GoTo(67, 11);
    cout << "----oOo----";
}


void dangky()
{
	system("cls");
	draw(9, 2, 61, 11);
	string lmk = " ";
	string st;
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "ĐĂNG KÝ";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "NHẬP TÀI KHOẢN: ";
	GoTo(11, 6);
	cout << "NHẬP MẬT KHẨU: ";
	GoTo(11, 7);
	cout << "NHẬP LẠI MẬT KHẨU: ";
	while (mk != lmk)
	{
		GoTo(26, 6);
		cout << "                 ";
		GoTo(30, 7);
		cout << "                 ";
		bool kk = true;
		GoTo(27, 5);
		cout << "                 ";
		GoTo(27, 5);
		cin >> tk;
		while (kk == true)
		{
			for (int i = 0; i <= sohs; i++)
				if (tk == hs[i].getUserName())
				{
					GoTo(11, 8);
					cout << "                                            ";
					GoTo(11, 8);
					cout << "TÀI KHOẢN ĐÃ TỒN TẠI" << endl;
					kk = true;
					break;
				}
				else
					kk = false;
			if (kk == true)
			{
				GoTo(27, 5);
				cout << "                 ";
				GoTo(27, 5);
				cin >> tk;
			}
		}
		GoTo(26, 6);
		cin >> mk;
		GoTo(30, 7);
		cin >> lmk;
		if (mk != lmk)
		{
			//	system("cls");
			GoTo(11, 8);
			cout << "VUI LÒNG ĐĂNG KÝ THEO ĐÚNG YÊU CẦU" << endl;
		}
	}
	GoTo(11, 8);
	cout << "                                           ";
	GoTo(11, 8);
	SetColor(0, 2);
	cout << "ĐĂNG KÝ THÀNH CÔNG" << endl;
	SetColor(0, 7);
	fflush(stdin);
	GoTo(11, 9);
	cout << "NHẬP HỌ TÊN CỦA BẠN:  ";
	getline(cin, st);
	// lưu thông tin vào file "data.csv".
	fstream fout;
	// fstream fout; Khai báo một đối tượng luồng tệp fout để xử lý các hoạt động đầu vào / đầu ra của tệp.
	fout.open("data.csv", ios::out | ios::app);
	// mở file trong chế độ ghi (write mode) và cho phép ghi thêm nội dung vào cuối file nếu file đã tồn tại.
	hocsinh tam;
	fout << tk << "," << mk << "," << st << ",0;" << endl;
	// ghi dữ liệu tài khoản và mật khẩu vào file
	fout.close();
	// đóng file
	tam.setUserName(tk);
	tam.setPassword(mk);
	tam.hoten = st;
	tam.borrow = "0;";
	hs.push_back(tam);
	sohs++;
	user(hs, sohs, sach, sosach, sohs);
	// gọi hàm user để xử lý
}

int tim(string st)
{
	for (int i = 0; i <= sohs; i++)
	{
		if ((st == hs[i].getUserName()) && (st == "ngoclinh"))
		{
			cout << "XIN CHÀO ADMIN!" << endl;
			kkt = true;
			return i;
		}
		if (st == hs[i].getUserName())
			return i;
	}
	return -1;
}
/*Hàm tim nhận vào một chuỗi st và tìm kiếm trong danh sách các đối tượng hocsinh để trả về chỉ số của đối tượng hocsinh
nếu st trùng với userName của một đối tượng hocsinh trong danh sách. Nếu không tìm thấy, hàm trả về -1.
Trong quá trình tìm kiếm, nếu st trùng với userName của đối tượng admin, biến kkt được gán bằng true, đánh dấu rằng người dùng đã nhập tài khoản admin.*/
bool check(int h)
{
	if (h == -1)
	{
		// system("cls");
		SetColor(0, 4);
		GoTo(11, 7);
		cout << "KHÔNG CÓ TÀI KHOẢN NÀO ĐƯỢC TÌM THẤY, VUI LÒNG NHẬP ĐÚNG! " << (char)30;
		SetColor(0, 7);
		GoTo(27, 5);
		cout << "                    ";
		GoTo(26, 6);
		cout << "                    ";
		GoTo(27, 5);
		cin >> tk;
		GoTo(26, 6);
		cin >> mk;
		check(tim(tk));
	}
	else
	{
		// system("cls");

		if (hs[h].getPassword() == mk)
		{
			if (kkt == true)
			{
				admin(hs, sohs, sach, sosach);
				kkt = false;
			}
			else
				user(hs, sohs, sach, sosach, h);
		}
		else
		{
			GoTo(11, 7);
			cout << "                                     ";
			SetColor(0, 4);
			GoTo(11, 7);
			cout << (char)19 << "MẬT KHẨU SAI!!";
			kkt = false;
			SetColor(0, 7);
			GoTo(26, 6);
			cout << "                    ";
			GoTo(26, 6);
			cin >> mk;
			check(tim(tk));
		}
	};
}

void dangnhap()
{
	system("cls");
	draw(9, 2, 47, 8);
	SetColor(0, 2);
	GoTo(14, 4);
	cout << "ĐĂNG NHẬP";
	SetColor(0, 7);
	GoTo(11, 5);
	cout << "NHẬP TÀI KHOẢN: ";
	GoTo(11, 6);
	cout << "NHẬP MẬT KHẨU: ";
	GoTo(27, 5);
	cin >> tk;
	GoTo(11, 6);
	cout << "NHẬP MẬT KHẨU: ";
	cin >> mk;
	if (check(tim(tk))){
		system("cls");
		cout<<"Thành công";
	};
};
/*Hàm check(int h) được dùng để kiểm tra thông tin tài khoản đăng nhập của người dùng.
Ban đầu, hàm sẽ tìm kiếm tên tài khoản trong danh sách người dùng, nếu tìm thấy tài khoản thì hàm sẽ kiểm tra mật khẩu.
Nếu mật khẩu đúng, hàm sẽ chuyển người dùng đến giao diện tương ứng, nếu mật khẩu sai, hàm sẽ yêu cầu người dùng nhập lại mật khẩu.
 Nếu tài khoản không tồn tại, hàm sẽ yêu cầu người dùng nhập lại tên tài khoản. Biến h là chỉ số của tài khoản trong danh sách người dùng.
  Biến kkt được dùng để kiểm tra nếu tài khoản đăng nhập là admin. Nếu tài khoản đăng nhập là admin,
  hàm sẽ chuyển người dùng đến giao diện admin, nếu không, hàm sẽ chuyển người dùng đến giao diện người dùng.*/
int main()
{
	SetConsoleOutputCP(65001);
	system("title QUẢN LÝ THƯ VIỆN SÁCH");
	docfile(hs, sohs, sach, sosach);
	// cout << hs[7].hoten;
	drawbook();
	SetColor(0, 4);
	GoTo(10, 2);
	cout << "QUẢN LÝ THƯ VIỆN" << endl;

	GoTo(100, 25);
	GoTo(78, 26);
	SetColor(0, 7);
	SetColor(0, 9);
	SetConsoleOutputCP(65001);
	GoTo(11, 5);
	cout << "1. ĐĂNG NHẬP " << endl;
	GoTo(11, 6);
	cout << "2. ĐĂNG KÝ " << endl;
	SetColor(0, 7);
	GoTo(11, 7);
	int ma;
	cout << "NHẬP LỰA CHỌN:  ";
	cin >> ma;
	switch (ma)
	{
	case 1:
		dangnhap();
		break;
	case 2:
		dangky();
	}

	return 0;
}
