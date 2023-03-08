#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	int Ngay;
	int Thang;
	char BienSo[10];
	int SoKhach;
}Record;
int main()
{
	FILE *f1,*f2;
	Record XE;
	int i,N,TongHanhKhach=0;
	
	//nhap thong tin vao file XeKhach.dat
	
	if((f1=fopen("C:\\QLXK\\XeKhach.dat","wb"))==NULL)
	{
		printf("\nKhong tao duoc tep");
		exit(1);
	}
	else
	{
		printf("\nSo chuyen xe khach: ");
		scanf("%d",&N);
		
		for(i=1;i<=N;i++)
		{
			printf("\nThong tin chuyen xe thu %d: \n",i);
			printf("Ngay: "); scanf("%d",&XE.Ngay);
			printf("Thang: "); scanf("%d",&XE.Thang);
			printf("Bien so: "); fflush(stdin);
			gets(XE.BienSo); fflush(stdin);
			printf("So Khach: "); scanf("%d",&XE.SoKhach);
			
			fwrite(&XE, sizeof(XE), 1, f1);//viet du lieu vao file f1
		}
		fclose(f1);
	}
	
	//Duyet noi dung file XeKhach.dat
	//tinh tong so hanh khach khoi hanh ngay 29/4 
	f1=fopen("C:\\QLXK\\XeKhach.dat","rb");
	
	printf("\n\n DANH SACH BAN DAU \n");
	printf("\nSTT  Bien so   So hanh khach");
	i = 0;
	while (fread(&XE, sizeof(XE), 1, f1) )
	printf("\n%-5d%-10s%-10d",++i,XE.BienSo,XE.SoKhach);

	rewind(f1);
	
	while (fread(&XE, sizeof(XE), 1, f1) > 0)
		if(XE.Ngay==29 && XE.Thang==4)
			TongHanhKhach=TongHanhKhach+XE.SoKhach;
	
	printf("\n\nSo hanh khach khoi hanh ngay 29/4 la: %d",TongHanhKhach);
	
	
	// Tao file f2
	printf("\n\n Tao file BaoCao.txt\n");
	rewind(f1);
	
	f2 = fopen("C:\\QLXK\\Baocao.txt", "wb");

	int D,M,dem=0;
	printf("Nhap D: "); scanf("%d",&D);
	printf("Nhap M: "); scanf("%d",&M);
	
	
	//tim va in ra danh sach nhung xe khoi hanh vao
	//ngay D thang M
	for(i=1;i<=N;i++)
	{
		fread(&XE, sizeof(XE), 1, f1);
		if(XE.Ngay==D && XE.Thang==M)
		{
			fwrite(&XE, sizeof(XE), 1, f2);
			dem++;
		}
	}
	fclose(f2);
	
	//doc file f2
	
	f2 = fopen("C:\\QLXK\\Baocao.txt", "rb");
	
	//in danh sach trong file Baocao.txt
	printf("\nSTT  Bien so   So hanh khach");
	for(i=1;i<=dem;i++)
	{
		fread(&XE, sizeof(XE), 1, f2);
		printf("\n%-5d%-10s%-10d",i,XE.BienSo,XE.SoKhach);
	}
	
	fclose(f2);

	fclose(f1);
}









