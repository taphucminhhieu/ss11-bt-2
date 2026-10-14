#include <stdio.h>

typedef struct {
    char ma_kien_hang[20];
    float trong_luong;
    float nhiet_do_yeu_cau;
} PalletItem;

typedef struct {
    char ma_ke[20];
    float trong_luong_hien_tai;
    float tai_trong_toi_da;
    int la_kho_lanh;
} WarehouseShelf;

int kiem_tra_nhap_kho(WarehouseShelf ke, PalletItem kien) {
    if (ke.trong_luong_hien_tai + kien.trong_luong > ke.tai_trong_toi_da) {
        return 0;
    }

    if (ke.la_kho_lanh == 1) {
        if (kien.nhiet_do_yeu_cau < -18.0 || kien.nhiet_do_yeu_cau > 5.0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    WarehouseShelf ke_lanh = {"KE-COLD-01", 350.0, 500.0, 1};
    WarehouseShelf ke_thuong = {"KE-NORM-01", 300.0, 500.0, 0};

    PalletItem kien_1 = {"PL-01", 100.0, -10.0};
    PalletItem kien_2 = {"PL-02", 80.0, 25.0};
    PalletItem kien_3 = {"PL-03", 250.0, 20.0};

    printf("=== HE THONG KIEM DINH NHAP KHO WAREHOUSE ===\n\n");

    printf("--- TEST CASE 1: Kien hang hop le vao kho lanh (-10.0 C, 100.0 kg) ---\n");
    if (kiem_tra_nhap_kho(ke_lanh, kien_1) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO!\n\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO!\n\n");
    }

    printf("--- TEST CASE 2: Kien hang vi pham nhiet do kho lanh (25.0 C, 80.0 kg) ---\n");
    if (kiem_tra_nhap_kho(ke_lanh, kien_2) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO!\n\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO!\n\n");
    }

    printf("--- TEST CASE 3: Kien hang vuot qua tai trong toi da (300kg + 250kg > 500kg) ---\n");
    if (kiem_tra_nhap_kho(ke_thuong, kien_3) == 1) {
        printf("KET QUA: CHO PHEP NHAP KHO!\n\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO!\n\n");
    }

    return 0;
}
