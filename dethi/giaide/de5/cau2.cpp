#include <bits\stdc++.h>

using namespace std;

class Ngay
{
protected:
    int ngay, thang, nam;

public:
    Ngay();
    Ngay(int ngay, int thang, int nam);
    void Nhap();
    void Xuat();
};

class Nguoi : public Ngay
{
private:
    char chungMinhThu[30], hoTen[30], noiSinh[30];

public:
    Nguoi();
    Nguoi(int ngay, int thang, int nam, char *chungMinhThu, char *hoTen, char *noiSinh);
    void Nhap();
    void Xuat();
    void operator=(Nguoi x);
    friend void SapXep(Nguoi *a, int n);
};

Ngay::Ngay()
{
    ngay = thang = nam = 0;
}

Ngay::Ngay(int ngay, int thang, int nam)
{
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

void Ngay::Nhap()
{
    cout << "Nhap ngay, thang, nam: ";
    cin >> ngay >> thang >> nam;
}

void Ngay::Xuat()
{
    cout << left << setw(2) << ngay << "/" << setw(2) << thang << "/" << setw(9) << nam << endl;
}

Nguoi::Nguoi() : Ngay()
{
    strcpy(chungMinhThu, "");
    strcpy(hoTen, "");
    strcpy(noiSinh, "");
}

Nguoi::Nguoi(int ngay, int thang, int nam, char *chungMinhThu, char *hoTen, char *noiSinh) : Ngay(ngay, thang, nam)
{
    strcpy(this->chungMinhThu, chungMinhThu);
    strcpy(this->hoTen, hoTen);
    strcpy(this->noiSinh, noiSinh);
}

void Nguoi::Nhap()
{
    cout << "Nhap chung minh thu: ";
    fflush(stdin);
    gets(this->chungMinhThu);
    cout << "Nhap ho ten        : ";
    fflush(stdin);
    gets(this->hoTen);
    cout << "Nhap noi sinh      : ";
    fflush(stdin);
    gets(this->noiSinh);
    Ngay::Nhap();
}

void Nguoi::Xuat()
{
    cout << left << setw(30) << this->chungMinhThu << setw(30) << this->hoTen << setw(30) << this->noiSinh;
    Ngay::Xuat();
}

void Nguoi::operator=(Nguoi x)
{
    strcpy(this->chungMinhThu, x.chungMinhThu);
    strcpy(this->hoTen, x.hoTen);
    strcpy(this->noiSinh, x.noiSinh);
    this->ngay = x.ngay;
    this->thang = x.thang;
    this->nam = x.nam;
}

void NhapDanhSach(Nguoi *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nguoi thu " << i + 1 << endl;
        a[i].Nhap();
    }
}

void XuatDanhSach(Nguoi *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].Xuat();
    }
}

void SapXep(Nguoi *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1].nam > a[j].nam)
            {
                Nguoi temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void title()
{
    cout << left << setw(30) << "Chung minh thu" << setw(30) << "Ho ten" << setw(30) << "Noi sinh" << setw(15) << "Ngay" << endl;
}

int main()
{
    int n;
    cin >> n;
    Nguoi *a = new Nguoi[n];

    NhapDanhSach(a, n);

    title();
    XuatDanhSach(a, n);

    SapXep(a, n);
    title();
    XuatDanhSach(a, n);
    return 0;
}