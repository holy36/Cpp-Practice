#include<iostream>
#include<math.h>

using namespace std;
struct ditmemay 
{
	int n;
	float a[99];
};
typedef struct ditmemay mang;

mang nhan(mang x,mang y);
void kiemtra(mang x,mang y);
void nhap(mang &x);

int main()
{
	mang x,y,c;
	kiemtra(x,y);
	nhap(x);
	nhap(y);
	c=nhan(x,y);
	cout<<"Da thuc sau khi nhan la : ";
	for(int i=0;i<=2*x.n;i++)
	{
		if(i<2*x.n)
			{
				cout<<x.a[i]<<"x^"<<i<<"+";
			}
			else
			{
				cout<<x.a[i]<<"x^"<<i<<"."<<endl;
			}
	}
	return 0;
}
void nhap(mang &x)
{
	cout<<"Da thuc co dang : "<<endl;
	for(int i=0;i<=x.n;i++)
	{
		if(i<x.n)
		{
			cout<<"a"<<i<<"x^"<<i<<"+";
		}
		else
		{
			cout<<"a"<<i<<"x^"<<i<<"."<<endl;
		}
	}
	for(int i=0;i<=x.n;i++)
	{
		cout<<"Nhap a["<<i<<"] = ";
		cin>>x.a[i];
	}
	cout<<"Da thuc vua nhap la : ";
	for(int i=0;i<=x.n;i++)
	{
		if(i<x.n)
			{
				cout<<x.a[i]<<"x^"<<i<<"+";
			}
			else
			{
				cout<<x.a[i]<<"x^"<<i<<"."<<endl;
			}
	}
}
mang nhan(mang x,mang y)
{
	mang c;
	int k=0; int h=0;
	while(k<=(2*x.n))
	{
		if(k<=x.n)
		{
			for(int i=0;i<=k;k++)
			{
				for(int j=k;j>=0;j--)
				{
					c.a[k]=0;
					c.a[k]=c.a[k]+x.a[i]*y.a[j];
				}
			}
			k++;
		}
		else
		{
			h++;
			for(int i=h;i<=x.n;i++)
			{
				for(int j=x.n;j>=h;j--)
				{
					c.a[k]=0;
					c.a[k]=c.a[k]+x.a[i]*y.a[j];
				}
			}
		}
	}
	return c;
}
void kiemtra(mang x,mang y)
{
	cout<<"Nhap bac cua da thuc A : ";
	cin>>x.n;
	cout<<"Nhap bac cua da thuc B : ";
	cin>>y.n;
	if(x.n>=y.n)
	{
		y.n=x.n;
	}
	else
	{
		x.n=y.n;
	}
}
