#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct hihi
{
	int ngay,thang,nam;
};
typedef struct hihi lich;
void nhap(lich &x);

int main()
{
	lich x;
	nhap(x);
	if(x.ngay==0 || x.ngay>31 || x.thang>12)
	{
		cout<<"Loi so ngay : "
		exit(0);
	}	
	else
	{
		if(x.thang==1 || x.thang==3 || x.thang==5 || x.thang==7 || x.thang==8 || x.thang==10 || x.thang==12)
		{
			if(x.thang==12)
			{
				if(x.ngay>31)
				{
				cout<<"Loi so ngay trong thang khong duoc qua 31 ";
				}
				else
				{	
					if(x.ngay==31)
					{
					x.ngay=1;
					x.thang=1;
					x.nam++;
					cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
					else
					{
					x.ngay++;
					cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
				}
			}
			else
			{
				if(x.ngay>31)
				{
					cout<<"Loi so ngay : ";
				}
				else
				{
					if(x.ngay==31)
					{
						x.ngay=1;
						x.thang++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
					else
					{
						x.ngay++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
			}
			
			}
		}
		if(x.thang==4 || x.thang==6 || x.thang==9 || x.thang==11)
		{
			if(x.ngay>30)
			{
				cout<<"Loi so ngay";
			}
			else
			{
				if(x.ngay==30)
				{
					x.ngay=1;
					x.thang++;
					cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;

				}
				else
				{
					x.ngay++;
					cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
				}
			}
		}
		if( (x.nam%4==0 && (x.nam%100!=0 || x.nam<=100)) || (x.nam%400==0 && x.nam>=400))
		{
			if(x.thang==2)
			{
				if(x.ngay>29)
				{
					cout<<"Loi so ngay : ";
				}
				else
				{
					if(x.ngay==29)
					{
						x.ngay=1;
						x.thang++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;

					}
					else
					{
						x.ngay++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}	
				}
			}
		exit(0);
		}
		else
		{
			if(x.thang==2)
			{
				if(x.ngay>28)
				{
					cout<<"Loi so ngay : ";
				}
				else
				{
					if(x.ngay==28)
					{
						x.ngay=1;
						x.thang++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
					else
					{
						x.ngay++;
						cout<<"ngay hom sau la "<<x.ngay<<" thang "<<x.thang<<" nam "<<x.nam;
					}
					
				}
			}
		exit(0);
		}
	}
	return 0; 
}
void nhap(lich &x)
{
	cout<<"Nhap ngay thang nam : "<<endl<<" ngay : ";
	cin>>x.ngay; cout<<" thang : "; cin>>x.thang; cout<<" nam : "; cin>>x.nam;
}

