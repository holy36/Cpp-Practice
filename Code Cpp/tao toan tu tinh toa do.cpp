#include<iostream>
#include<math.h>
using namespace std;

class toado
{
	private :
		float x,y,z;
	public :
		toado();
		toado(float &xx, float &yy,float &zz);
		friend istream & operator>>(istream &is, toado &a);	
		friend ostream & operator<<(ostream &os, toado a);
		toado operator+(toado );
		toado operator-(toado );
		toado operator*(toado );	
		float operator%(toado );
		toado& operator=(toado );
};
istream & operator>>(istream &is, toado &a)
{
	is>>a.x;
	is>>a.y;
	is>>a.z;
	return is;
}
toado::toado()
{
	x=0;	y=0;	z=0;
}
toado::toado(float &xx, float &yy,float &zz)
{
	x=xx;	y=yy;	z=zz;
}
ostream & operator<<(ostream &os, toado a)
{
	os<<"(";	os<<a.x;	os<<",";	os<<a.y;	os<<",";	os<<a.z;	os<<")";
	return os;
}
toado toado::operator+(toado b)
{
	toado c;
	c.x=this->x+b.x;
	c.y=this->y+b.y;
	c.z=this->z+b.z;
	return c;
}
toado toado::operator-(toado b)
{
	toado c;
	c.x=this->x-b.x;
	c.y=-b.y+this->y;
	c.z=-b.z+this->z;
	return c;
}
toado toado::operator*(toado b)
{
	toado c;
	c.x=this->y*b.z-this->z*b.y;
	c.y=-this->x*b.z+this->z*b.x;
	c.z=this->x*b.y-this->y*b.x;
	return c;
}
toado& toado::operator=(toado b)
{
	this->x=b.x;
	this->y=b.y;
	this->z=b.z;
	return *this;
}
float toado::operator%(toado b)
{
	return this->x*b.x+this->y*b.y+this->z*b.z;
}



int main()
{
	toado a,b,c;
	cout<<"Nhap toa do vecto A : "<<endl;
	cin>>a;
	cout<<"Vecto A la : "<<a<<endl;
	cout<<"Nhap toa do vecto B : "<<endl;
	cin>>b;
	cout<<"Vecto B la : "<<b<<endl;
	cout<<"Tong 2 vecto la"<<a+b<<endl;
	c=a*b;
	cout<<"Tich co huong cua 2 vecto la : "<<c<<endl;
	cout<<"Tich vo huong cua 2 vecto la : "<<a%b<<endl;
	cout<<"(a+b).(a*b)="<<(a+b)%(a*b);
	return 0;
}
