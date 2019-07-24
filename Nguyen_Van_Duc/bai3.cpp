#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
 
struct CongNhan{
    char hoten[30];
    int ma[30];
    char gt[5];
    float luong, heso, phucap, luongthuclinh;
    
};
 
typedef CongNhan CN;
 
void nhap(CN &cn);
void nhapN(CN a[], int n);
void xuat(CN cn);
void xuatN(CN a[], int n);

 
void nhap(CN &cn){
	float luongthuc;
    printf("\nNhap ho ten: "); fflush(stdin); gets(cn.hoten);
    printf("\nNhap gioi tinh: "); gets(cn.gt);
    printf("\nNhap ma cong nhan: "); scanf("%d", &cn.ma);
    printf("\nNhap luong: "); scanf("%f", &cn.luong);
    printf("\nNhap he so: "); scanf("%f", &cn.heso);
    printf("\nNhap phu cap: "); scanf("%f", &cn.phucap);
    
}
void tinhluongthuc(CN &cn){
    cn.luongthuclinh = (cn.luong * cn.heso + cn.phucap);    
}

int dscndat(CN dscn[], CN dscndat[], int n){
	int j=0;
	float luongthuc;
	for(int i = 0; i< n; ++i){
		luongthuc = dscn[i].luong*dscn[i].heso + dscn[i].phucap;
		if(luongthuc>=2000000){
			dscndat[j]=dscn[i];
			j++;
		}
	}
	return j;
}
void nhapN(CN a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap CN thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
void xuat(CN cn){
    printf("\nHo ten CN: %s", cn.hoten);
    printf("\nMa cong nhan: %d", cn.ma);
    printf("\nLuong cong nhan: %f", cn.luong);
    printf("\nHe so: %f", cn.heso);
    printf("\nphu cap: %f", cn.phucap);
}
 
void xuatN(CN a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nThong tin SV thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}
int main(){
    int n;
    do{
        printf("\nNhap so luong CN: "); scanf("%d", &n);
    }while(n <= 0);
    CN a[n];
    CN b[n];
    
                printf("\nBan da chon nhap DS cong nhan!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                xuatN(a, n);
                dscndat(a,b,n);
				printf("\nDanh sach > 2000000!");
				xuatN(b,dscndat(a,b,n));
    }

