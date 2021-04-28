#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

class SanPham
{
    string TenSanPham;
    double GiaTienSanPham;

public:
    SanPham() {}
    SanPham(string _TenSanPham, double _GiaTienSanPham)
    {
        this->TenSanPham = _TenSanPham;
        this->GiaTienSanPham = _GiaTienSanPham;
    }
    string getTenSanPham()
    {
        return this->TenSanPham;
    }
    double getGiaTienSanPham()
    {
        return this->GiaTienSanPham;
    }
};

class HoaDon
{
    char MaHoaDon[7];
    string KhachHang;
    SanPham *sanpham;
    int capacitySP;
    int sizeSP;
    int ThueSuat;

public:
    HoaDon()
    {
        this->capacitySP = 10;
        this->sizeSP = 0;
        this->sanpham = new SanPham[capacitySP];
        this->ThueSuat = 0;
    }
    HoaDon(string _MaHoaDon, string _KhachHang, int _ThueSuat)
    {
        this->capacitySP = 10;
        this->sizeSP = 0;
        strcpy(this->MaHoaDon, _MaHoaDon.c_str());
        this->sanpham = new SanPham[capacitySP];
        this->KhachHang = _KhachHang;
        this->ThueSuat = _ThueSuat;
    }
    ~HoaDon()
    {
        delete[] sanpham;
    }
    void setCapacitySP(int newCapacity)
    {
        SanPham *newSanPham = new SanPham[newCapacity];
        for (int i = 0; i < this->sizeSP; i++)
        {
            newSanPham[i] = sanpham[i];
        }
        this->capacitySP = newCapacity;
        delete[] sanpham;
        sanpham = newSanPham;
    }
    void addSP(string ten, double gia)
    {
        SanPham newSanPham(ten, gia);
        if (this->sizeSP == this->capacitySP)
        {
            int last = this->capacitySP + 1;
            setCapacitySP(last);
        }
        sanpham[this->sizeSP] = newSanPham;
        this->sizeSP++;
    }
    int getSize()
    {
        return this->sizeSP;
    }
    string getMaHoaDon()
    {
        return string(this->MaHoaDon);
    }
    string getKhachHang()
    {
        return this->KhachHang;
    }
    string getTenSP(int idx)
    {
        return this->sanpham[idx].getTenSanPham();
    }
    double getGiaTienSP(int idx)
    {
        return this->sanpham[idx].getGiaTienSanPham();
    }
    int getThue()
    {
        return this->ThueSuat;
    }
    double sumGiaTienSP()
    {
        double sum = 0;

        for (int i = 0; i < this->sizeSP; i++)
        {
            sum += sanpham[i].getGiaTienSanPham();
        }
        if (ThueSuat == 0)
            return sum;
        return sum * (1 + (double)ThueSuat / 100);
    }
};

class CongTy
{
    HoaDon *BanLe, *GTGT;
    int size1, size2;
    int capacity;

public:
    CongTy()
    {
        this->size1 = 0;
        this->size2 = 0;
        this->capacity = 10;
        this->BanLe = new HoaDon[capacity];
        this->GTGT = new HoaDon[capacity];
    }
    CongTy(int _capacity)
    {
        this->size1 = 0;
        this->size2 = 0;
        this->capacity = _capacity;
        this->BanLe = new HoaDon[capacity];
        this->GTGT = new HoaDon[capacity];
    }
    ~CongTy()
    {
        delete[] BanLe;
        delete[] GTGT;
    }
    void setCapacity(int newCapacity)
    {
        HoaDon *newBanLe = new HoaDon;
        HoaDon *newGTGT = new HoaDon;
        for (int i = 0; i < this->size1; i++)
        {
            newBanLe[i] = BanLe[i];
        }
        for (int i = 0; i < this->size2; i++)
        {
            newGTGT[i] = GTGT[i];
        }
        this->capacity = newCapacity;
        delete[] BanLe;
        delete[] GTGT;
        BanLe = newBanLe;
        GTGT = newGTGT;
    }
    void add(HoaDon newHoaDon)
    {
        if (this->size1 == this->capacity || this->size2 == this->capacity)
        {
            int last = this->capacity + 1;
            setCapacity(last);
        }
        if (newHoaDon.getThue() == 0)
        {
            BanLe[this->size1] = newHoaDon;
            this->size1++;
        }
        else
        {
            GTGT[this->size2] = newHoaDon;
            this->size2++;
        }
    }
    // Cau 1
    void print()
    {
        cout << "----------------------------" << endl;
        cout << "Thong tin cac hoa don ban le" << endl;
        bool firstTime = true;
        for (int i = 0; i < this->size1; i++)
        {
            if (!firstTime)
                cout << endl;
            cout << BanLe[i].getMaHoaDon() << " " << BanLe[i].getKhachHang() << " " << BanLe[i].getThue() << endl;
            for (int j = 0; j < BanLe[i].getSize(); j++)
            {
                cout << BanLe[i].getTenSP(j) << " " << BanLe[i].getGiaTienSP(j) << endl;
            }
            firstTime = false;
        }
        cout << "----------------------------" << endl;
        cout << "Thong tin cac hoa don GTGT" << endl;
        firstTime = true;
        for (int i = 0; i < this->size2; i++)
        {
            if (!firstTime)
                cout << endl;
            cout << GTGT[i].getMaHoaDon() << " " << GTGT[i].getKhachHang() << " " << GTGT[i].getThue() << endl;
            for (int j = 0; j < GTGT[i].getSize(); j++)
            {
                cout << GTGT[i].getTenSP(j) << " " << GTGT[i].getGiaTienSP(j) << endl;
            }
            firstTime = false;
        }
        cout << endl;
    }
    // Cau 2
    int countGTGT()
    {
        return this->size2;
    }
    // Cau 3
    void printX(string Customer)
    {
        vector<HoaDon> v;
        for (int i = 0; i < this->size1; i++)
        {
            if (BanLe[i].getKhachHang() == Customer)
            {
                v.push_back(BanLe[i]);
            }
        }
        for (int i = 0; i < this->size2; i++)
        {
            if (GTGT[i].getKhachHang() == Customer)
            {
                v.push_back(GTGT[i]);
            }
        }
        bool firstTime = true;
        for (int i = 0; i < v.size(); i++)
        {
            if (!firstTime)
                cout << endl;
            cout << v[i].getMaHoaDon() << " " << v[i].getKhachHang() << " " << v[i].getThue() << endl;
            for (int j = 0; j < v[i].getSize(); j++)
            {
                cout << v[i].getTenSP(j) << " " << v[i].getGiaTienSP(j) << endl;
            }
            firstTime = false;
        }
        cout << endl;
    }
    // Cau 4
    void sorting()
    {
        vector<HoaDon> v;
        for (int i = 0; i < this->size1; i++)
        {
            v.push_back(BanLe[i]);
        }
        for (int i = 0; i < this->size2; i++)
        {
            v.push_back(GTGT[i]);
        }
        bool haveSwapped = false;
        for (int i = 0; i < v.size() - 1; i++)
        {
            haveSwapped = false;
            for (int j = 0; j < v.size() - i - 1; j++)
            {
                if (v[j].sumGiaTienSP() < v[j + 1].sumGiaTienSP())
                {
                    swap(v[j], v[j + 1]);
                    haveSwapped = true;
                }
                else if (v[j].sumGiaTienSP() == v[j + 1].sumGiaTienSP())
                {
                    if (v[j].getKhachHang().compare(v[j + 1].getKhachHang()) >= 0)
                    {
                        swap(v[j], v[j + 1]);
                        haveSwapped = true;
                    }
                }
            }
            if (haveSwapped == false)
                break;
        }
        cout << "Danh sach cac hoa don cua cong ty" << endl;
        bool firstTime = true;
        for (int i = 0; i < v.size(); i++)
        {
            if (!firstTime)
                cout << endl;
            cout << v[i].sumGiaTienSP() << " " << v[i].getMaHoaDon() << " " << v[i].getKhachHang();
            firstTime = false;
        }
    }
    // Cau 5
    double totalMoney()
    {
        double sum = 0;
        for (int i = 0; i < this->size1; i++)
        {
            sum += BanLe[i].sumGiaTienSP();
        }
        for (int i = 0; i < this->size2; i++)
        {
            sum += GTGT[i].sumGiaTienSP();
        }
        return sum;
    }
};

int main()
{
    CongTy *obj = new CongTy;
    int n, ThueSuat;
    string MaHoaDon, KhachHang, TenSanPham;
    double GiaTien;
    cout << "So luong hoa don" << endl;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++)
    {
        cout << "Ma hoa don" << endl;
        getline(cin, MaHoaDon);
        cout << "Ten nguoi mua hang" << endl;
        getline(cin, KhachHang);
        int SoLuongSanPham;
        cout << "Thue suat" << endl;
        cin >> ThueSuat;
        cout << "So luong san pham da mua" << endl;
        cin >> SoLuongSanPham;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        HoaDon newHoaDon(MaHoaDon, KhachHang, ThueSuat);
        for (int j = 0; j < SoLuongSanPham; j++)
        {
            cout << "Ten san pham" << endl;
            getline(cin, TenSanPham);
            cout << "Gia tien" << endl;
            cin >> GiaTien;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            newHoaDon.addSP(TenSanPham, GiaTien);
        }
        obj->add(newHoaDon);
    }
    // Cau 1
    obj->print();
    // Cau 2
    cout << "Tong so hoa don GTGT: " << obj->countGTGT() << endl;
    // Cau 3
    string name;
    cout << "\nTen khach hang muon xuat hoa don:" << endl;
    getline(cin, name);
    obj->printX(name);
    // Cau 4
    obj->sorting();
    cout << endl;
    //Cau 5
    cout << "\nTong tien cua cong ty: " << obj->totalMoney() << endl;
    delete obj;
    return 0;
}