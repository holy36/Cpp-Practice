#include<iostream>
#include<cstring>
#include<math.h>

using namespace std;

void test_menu_1()
{
		char menu1[6];
	cout<<"Mang co 6 phan tu"<<endl<<"Nhap tung phan tu:"<<endl;
	for(int i=0;i<6;i++) 
	{
		cout<<"Nhap phan tu thu "<<i<<": ";
		cin>>menu1[i]; 
	}
	char *ptr;
	int sum=0;
	ptr= menu1;	
	for(int i=0;i<6;i++) 
	{
		if(*(ptr+i)>=65&&*(ptr+i)<=90)
		{
			*(ptr+i)=*(ptr+i)+32;
		} 
		sum=sum+*(ptr+i);
	}

	cout<<"Chuoi sau khi thuc hien test1 la:"<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<*(ptr+i);
	}
	cout<<endl<<"Tong cac ky tu la:"<<sum<<endl;
}
void test_menu_2()
{
	int a[100];
	int check=1;
	int n;
	cout<<"Nhap so gia tri cua mang:"; cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap gia tri thu"<<i<<" cua mang: ";
		cin>>a[i];
	}
	for(int i=0;i<n-2;i++)
	{
		if((a[i]+a[i+1])!=a[i+2])
		{
			check=0;
		}
	}
	if(check==1)
	{
		cout<<"Day la day Fibonacci";
	}
	else
	{
		cout<<"Day khong phai day Fibonacci";
	}
}
class cdate
	{
		
		public:
			int ngay,thang,nam;
			cdate();
			cdate(int ,int ,int );
			friend ostream & operator<<(ostream &os, cdate a);
			int operator++()
			{
				return (1+ngay);
			}
			void sosanh(cdate y);
	};
	
	cdate::cdate()
	{
		ngay=1; thang=1; nam=2023;
	}
	cdate::cdate(int x,int y,int z)
	{
		ngay=x; thang=y; nam=z;
	}
	ostream & operator<<(ostream &os, cdate a)
{
		os<<a.ngay;	os<<"/";	os<<a.thang;	os<<"/";	os<<a.nam;
	return os;
}

	void cdate::sosanh(cdate y)
	{
		if(this->nam>y.nam)
		{
			cout<<"Ngay "<<this<<" lon hon ngay"<<y;
		}
		else if(this->nam<y.nam)
		{
			cout<<"Ngay "<<this<<" nho hon ngay"<<y;
		}
		else if(this->nam==y.nam)
		{
				if(this->thang>y.thang)
			{
				cout<<"Ngay "<<this<<" lon hon ngay"<<y;
			}
			else if(this->thang<y.thang)
			{
				cout<<"Ngay "<<this<<" nho hon ngay"<<y;
			}
			else if(this->thang==y.thang)
			{
					if(this->ngay>y.ngay)
				{
					cout<<"Ngay "<<this<<" lon hon ngay"<<y;
				}
				else if(this->ngay<y.ngay)
				{
					cout<<"Ngay "<<this<<" nho hon ngay"<<y;
				}
				else if(this->ngay==y.ngay)
				{
					cout<<"Hai ngay "<<this<<" va "<<y<<" co gia tri bang nhau";
				}
			}
		}
	}
	void test_menu_3()
{	int d,m,y,d1,m1,y1;
	cdate x; 
		cout<<"Ngay thang duoc tao mac dinh la:"<<endl;
	cout<<x;
		cout<<"Nhap ngay, thang, nam muon tao thu cong:"<<endl;
		cin>>d>>m>>y;
	cdate k(d,m,y);
	cout<<"Ngay thang nam ban vua tao la:";
		cout<<k<<endl;
	cout<<"Ngay sau khi tang 1 gia tri la: "<<++k<<endl;
		cout<<"Nhap ngay, thang, nam muon so sanh:"<<endl;
		cin>>d1>>m1>>y1;
	cdate u(d1,m1,y1);
	k.sosanh(u);
}

class Chistory:public cdate
{
	public:
		string name;
		Chistory();
		Chistory(int ,int ,int, string);
		friend ostream & operator<<(ostream &os, cdate a);
		friend istream & operator>>(istream &is, cdate a);
				
};
	ostream & operator<<(ostream &os, Chistory a)
{		os<<"Ten su kien: "<<a.name<<endl;
		os<<a.ngay;	os<<"/";	os<<a.thang;	os<<"/";	os<<a.nam<<endl;
	return os;
}
	istream & operator>>(istream &is, Chistory &a)
{		cout<<endl<<"Nhap ngay, thang, nam to chuc su kien: ";
		is>>a.ngay>>a.thang>>a.nam;
		cout<<"Nhap ten su kien: ";
		fflush(stdin);
		getline(is,a.name);
	return is;
}
Chistory::Chistory()
{
	ngay=1; thang=1; nam=2023; name="Liucute";
}
Chistory::Chistory(int x,int y,int z,string name1)
{	
	ngay=x; thang=y; nam=z;
	name=name1;
}

void sapxep(int n,Chistory a[]);
void sapxep(int n,Chistory a[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].nam<a[j].nam)
			{
				swap(a[i],a[j]);
			}
			else if(a[i].nam==a[j].nam && a[i].thang<a[j].thang)
			{
				swap(a[i],a[j]);
			}
			else if(a[i].nam==a[j].nam && a[i].thang==a[j].thang && a[i].ngay<a[j].ngay)
			{
				swap(a[i],a[j]);
			}
		}
	}
}

void test_menu_4()
{	string a;
	int x,y,z; int n;
	cout<<"Nhap ten su kien: ";
	getline(cin,a);
	cout<<"Nhap ngay, thang, nam to chuc su kien:";
	cin>>x>>y>>z;
	Chistory k(x,y,z,a);
	cout<<k<<endl;	
	cout<<"Nhap so su kien:";
	cin>>n;
	Chistory arr[100];
	for(int i=0;i<n;i++)
	{	
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	sapxep(n,arr);
	cout<<"Su kien sau khi sap xep la:";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
}
int main()
{
	cout<<"Menu: "<<endl;
	cout<<"1. Test menu1"<<endl<<"2. Test menu2"<<endl<<"3. Test menu3"<<endl<<"4. Test menu4"<<endl<<"5. Exit"<<endl;
	cout<<"Nhap lua chon: ";
	int n;
	cin>>n; 
	while(n>5 || n<1)
	{	cout<<"Nhap so tu 1->5, vui long nhap lai";
		cin>>n;	
	}
	if(n==1) {	test_menu_1();	}
		else if(n==2) { test_menu_2();		}
		else if(n==3) { test_menu_3();		}
		else if(n==4) { test_menu_4();		}
		else if(n==5) { cout << "Thoat!!!\n";
		exit(1);	}
	return 0;
} 
