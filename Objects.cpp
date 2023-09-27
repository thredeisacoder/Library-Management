#include <iostream>
#include <string>

using namespace std;

class DanhMucSach {
public:
    int maSach;
    int trangThai;
    string viTri;
    DanhMucSach* next;

    DanhMucSach(int ma, int trangThai, const string& viTri) : maSach(ma), trangThai(trangThai), viTri(viTri), next(nullptr) {}
};

class Sach {
public:
    string ISBN;
    string tenSach;
    int soTrang;
    string tacGia;
    int namXuatBan;
    string theLoai;
    DanhMucSach* danhMucSach;
    Sach* next;

    Sach(const string& isbn, const string& ten, int trang, const string& tacGia, int namXB, const string& theLoai) : 
        ISBN(isbn), tenSach(ten), soTrang(trang), tacGia(tacGia), namXuatBan(namXB), theLoai(theLoai), danhMucSach(nullptr), next(nullptr) {}
};

class TheDocGia {
public:
    int maThe;
    int phai;
    string ho;
    string ten;
    int trangThaiThe;
    Sach* danhSachSachMuon[10]; // Mảng lưu trữ tối đa 10 cuốn sách mà độc giả mượn
    int soLuongSachMuon;

    TheDocGia(int ma, int phai, const string& ho, const string& ten, int trangThaiThe) : 
        maThe(ma), phai(phai), ho(ho), ten(ten), trangThaiThe(trangThaiThe), soLuongSachMuon(0) {
            for (int i = 0; i < 3; i++) {
                danhSachSachMuon[i] = nullptr;
            }
        }
};

// Định nghĩa các hàm thành viên của lớp để thêm/xóa/sửa thông tin và thực hiện các chức năng khác.

int main() {
    // Khởi tạo các đối tượng lớp và thực hiện các chức năng quản lý thư viện ở đây
    return 0;
}
