#include<iostream>
#include<math.h>

using namespace std;
struct hihi 
{
	int n;
	float a[99];
};
typedef struct hihi mang;
void nhap(mang &x);
mang nhan(mang x,mang y);

int main()
{
	mang x,y,z;
	nhap(x);
	nhap(y);
	if(x.n>=y.n)
	{
		y.n=x.n;
	}
	else
	{
		x.n=y.n;
	}
	z=nhan(x,y);
	
	for(int i=0;i<=2*x.n;i++)
	{
		if(i<2*x.n)
			{
				cout<<z.a[i]<<"x^"<<i<<"+";
			}
			else
			{
				cout<<z.a[i]<<"x^"<<i<<"."<<endl;
			}
	}
	
	return 0;
}
void nhap(mang &x)
{
	cout<<"Nhap bac cua da thuc : ";
	cin>>x.n;
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
{	//cout<<"truoc while";
	mang c;
	int k=0; int h=0;
	for(int i=0;i<=2*x.n;i++)
	{
		c.a[i]=0;
	}
	while(k<=(2*x.n))
	{
		if(k<=x.n)
		{
			for(int i=0;i<=k;i++)
			{
					c.a[k]=c.a[k]+x.a[i]*y.a[k-i];	
			}
		}
		else
		{
			h++;
			for(int i=h;i<=x.n;i++)
			{
					c.a[k]=c.a[k]+x.a[i]*y.a[k-i];
			}
		}
		k++;
	}
	
	return c;
}
