#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

struct maiyahoo
{
	char baihat[99],tacgia[99];
	float diem;
};
typedef struct maiyahoo baihat ;

struct maiyahii
{
	char nguoinghe[99],danghe[99];
	int stt[99],sobai;
	float diem[99];
};
typedef struct maiyahii nguoinghe;

baihat nhapbaihat(baihat &x)
{
	printf("\nTen bai hat : "); 	fflush(stdin);	gets(x.baihat);
	printf("Tac gia : ");   fflush(stdin);  gets(x.tacgia);
	printf("Diem danh gia : ");   scanf("%f",&x.diem);
	while(x.diem<0 || x.diem>10) 
	{
		printf("Diem phai trong khoang tu 0 den 10 : "); 	scanf("%f",&x.diem);
	}
	return x;
}

nguoinghe nhapnguoinghe(nguoinghe &x,int n)
{
	printf("\nTen nguoi nghe : "); fflush(stdin); gets(x.nguoinghe);
	printf("So bai hat da nghe : ");    scanf("%d",&x.sobai);
	while(x.sobai>n)
		{
			printf("So bai nguoi nghe lam sao nhieu hon so bai trong danh sach duoc !\nNhap lai di cu : \nSo bai hat da nghe : ");   scanf("%d",&x.sobai);
		}
	printf("\nDanh sach bai hat anh/chi %s da nghe : ",x.nguoinghe);  
	for(int i=0;i<x.sobai;i++)
	{
		printf("  \nTen bai hat : ");   fflush(stdin); gets(x.danghe);
		printf("  So thu tu : ");  scanf("%d",&x.stt[i]);
		while(x.stt[i]<=0||x.stt[i]>n)
		{
			printf("so thu tu chi tu 1 den so bai hat trong danh sach thoi\nSo thu tu : ");   scanf("%d",&x.stt[i]);
		}
		printf("  Diem danh gia : ");  scanf("%f",&x.diem[i]);
		while(x.diem[i]<0||x.diem[i]>10)
		{
			printf("Diem phai trong khoang tu 0 den 10 chu cu ! ");   scanf("%f",&x.diem[i]);
		}
	}
	
	return x;
	
}

int main()
{
	int n,m,p,tmax,tmin;
	float s[99],max=0,min=0;
	baihat a[99];
	for(int i=0;i<99;i++)	s[i]=0;
	printf("Nhap so bai hat : ");    scanf("%d",&n);
	while(n<0)
	{
		printf("so bai hat lam sao ma nho hon 0 duoc ! Nhap lai di \nSo bai hat : ");
		scanf("%d",&n);
	}
	for(int i=0;i<n;i++)	nhapbaihat (a[i]);
	printf(" \n\n Nhu vay danh sach bai hat la  : ");
	for(int i=0;i<n;i++)    printf("\nTen bai hat : %s ,   Tac gia : %s ,   Diem : %.2f ,   So thu tu bai hat : %d . ",a[i].baihat,a[i].tacgia,a[i].diem,i+1);
	nguoinghe b[99];
	printf("\n\n So nguoi nghe : ");  scanf("%d",&m);
		while(m<0)
	{
		printf("so nguoi nghe lam sao ma nho hon 0 duoc ! Nhap lai di \nSo nguoi nghe : ");
		scanf("%d",&m);
	}
	for(int i=0;i<m;i++) 
	{	
		nhapnguoinghe(b[i],n);
		while(b[i].sobai>n)
		{
			printf("so bai hat cua nguoi nghe lam sao ma lai con nhieu hon so bai hat trong danh sach duoc ! Nhap lai di ");
			nhapnguoinghe(b[i],n);
		}
		while(b[i].sobai<0)
		{
			printf("so bai hat cua nguoi nghe lam sao ma lai nho hon 0 duoc ! Nhap lai di ");
			nhapnguoinghe(b[i],n);
		}
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<b[i].sobai;k++)
			{
				if((j+1)==b[i].stt[k])
				{
					s[i]=s[i]+(a[j].diem-b[i].stt[k])*(a[j].diem-b[i].stt[k]);
				} 
				s[i]=sqrt(s[i]);	
		    }
	min=s[0]; max=s[0];
	for(int i=0;i<m;i++)
	{
		if(s[i]>max)  
		{
			max=s[i];
			tmax=i;
		}
		if(s[i]<min)
		{
			if(b[i].sobai==0)  s[i]=max;
			else
			{
			min=s[i];
			tmin=i;
			}
		}
	}
	for(int i=0;i<m;i++)
		if(s[i]==0)  s[i]=max;
	printf("\nNguoi hop voi ban nhat la : %s \nNguoi khong phu hop nhat : %s ",b[tmin].nguoinghe,b[tmax].nguoinghe);
	return 0; 
}
