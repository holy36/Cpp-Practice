#include<iostream>
#include<cstring>
#include<string.h>
#include<math.h>

using namespace std;

class SinhVien
{
	public:
		int MaSV,NamSinh,DiemTB;
		string TenSV;
		SinhVien();
		SinhVien(int ,string ,int ,int );
		void Nhap();
		void HienThi();	
		~SinhVien()
		{
			cout<<"Sinh vien da bi huy!"<<endl;
		}
		SinhVien& operator=(SinhVien );
		int sosanh(SinhVien b);
};
int SinhVien::sosanh(SinhVien b)
{	
	if(this->MaSV==b.MaSV)
	{
		if(this->TenSV==b.TenSV)
		{
			if(this->NamSinh==b.NamSinh)
			{
				if(this->DiemTB==b.DiemTB)
				{
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else 	return 0;
	}
	else	return 0;
}

SinhVien::SinhVien()
{
	MaSV=0; NamSinh=0; DiemTB=0; TenSV="Giang lau"; DiemTB=0;
}
SinhVien::SinhVien(int x,string y,int z,int t)
{
	MaSV=x; TenSV=y; NamSinh=z; DiemTB=t;
}
void SinhVien::Nhap()
{	cout<<endl<<"Nhap ten sinh vien: "; fflush(stdin); getline(cin,TenSV);
	cout<<"Nhap MSSV: "; cin>>MaSV;
	cout<<"Nhap nam sinh: "; cin>>NamSinh;
	cout<<"Nhap diem trung binh: "; cin>>DiemTB;
	return;
}
void SinhVien::HienThi()
{
	cout<<"Sinh vien: "<<TenSV<<", MSSV: "<<MaSV<<", nam sinh: "<<NamSinh<<", Diem trung binh: "<<DiemTB<<endl;
	return;
}
SinhVien& SinhVien::operator=(SinhVien b)
{
	this->MaSV=b.MaSV;
	this->TenSV=b.TenSV;
	this->NamSinh=b.NamSinh;
	this->DiemTB=b.DiemTB;
	return *this;
}

class LopHoc
{
	public:
		string TenLop;	int SoSV;
		SinhVien DanhSachSV[100];
		~LopHoc()
		{
			cout<<"Lop hoc da bi huy"<<endl;
		}
		LopHoc()
		{
			TenLop="Lop 0"; SoSV=0;
		}
		LopHoc(string a,int b,SinhVien c[])
		{
			TenLop=a;	SoSV=b;	   
			for(int i=0;i<b;i++)
			{
				DanhSachSV[i]=c[i];
			}
		}
		void TimKiem(SinhVien x)
		{
			for(int i=0;i<this->SoSV;i++)
			{
				if(x.sosanh(this->DanhSachSV[i])==1)
				{
					cout<<"Sinh vien nay co trong lop";
					return;
				}
			}
			cout<<"Sinh vien nay khong co trong lop"<<endl<<endl;
			return;
		}
		void Nhaplop()
		{	
			cout<<endl<<"Nhap ten lop sinh vien: ";
			cin>>TenLop;
			cout<<"Nhap so sinh vien: "; cin>>SoSV;
			for(int i=0;i<SoSV;i++)
			{	int j=0;
				cout<<endl<<"Nhap sinh vien thu "<<i+1<<endl;
				DanhSachSV[i].Nhap();
				if(i>0)
				{
						while(DanhSachSV[j].MaSV==DanhSachSV[i].MaSV)
						{	
							cout<<"Nhap trung ma sinh vien da co trong lop, nhap lai: ";
							DanhSachSV[i].Nhap();
							j++;
							if(j==i)	break;
						}
				}
			}
		return;
		}
		void HienthiLop()
		{
			cout<<"Lop: "<<TenLop<<" co "<<SoSV<<" sinh vien. Cac thanh vien lan luot la :"<<endl;
			for(int i=0;i<SoSV;i++) DanhSachSV[i].HienThi();
		}
		void ThemSV(SinhVien x)
		{   int i=0;
			SoSV=SoSV+1;
			cout<<endl<<"Nhap sinh vien them vao lop: ";
			DanhSachSV[SoSV-1].Nhap();
				while(DanhSachSV[i].MaSV==DanhSachSV[SoSV-1].MaSV)
				{	
					cout<<"Nhap trung ma sinh vien da co trong lop, nhap lai: ";
					DanhSachSV[SoSV-1].Nhap();
					i++;
					if(i==(SoSV-1)) break;
				}
		}
		void TestSV(int k)
		{
			for(int i=k;i<SoSV;i++)
			{
				DanhSachSV[i]=DanhSachSV[i+1];
				if(i==SoSV-1) SoSV=SoSV-1;
			}
		}
		void XoaSV()
		{	cout<<"Thong tin ve lop hoc"<<endl;
			this->HienthiLop();
			int x;
			cout<<endl<<"Nhap MSSV muon xoa: "; cin>>x;
			for(int i=0;i<SoSV;i++)
			{
				if(DanhSachSV[i].MaSV==x)
				{
					this->TestSV(i);
				}
			}
		}
};
int main()
{	SinhVien k;
	k.Nhap();
	LopHoc x;
	x.Nhaplop();
	x.HienthiLop();
	x.TimKiem(k);
	x.ThemSV(k);
	x.HienthiLop();
	x.XoaSV();
	x.HienthiLop();
	return 0;
}
