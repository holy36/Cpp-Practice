#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

struct NODE
{
	int sbd;
	char hoten[50];
	struct NODE *left, *right;
};
typedef struct NODE node;
typedef struct NODE * tree;

void khoitao(tree &t)
{
	t=NULL;
}

void them(tree &t, int x, char y[])
{

	if(t==NULL)		
	{	node *k=new node;
		k->sbd=x;
		strcpy(k->hoten,y);
		k->left=NULL;
		k->right=NULL;
		t=k;
	}
	else
	{
		if(t->sbd==x)	return;
		if(t->sbd>x)	them(t->left,x,y);
		if(t->sbd<x)	them(t->right,x,y);
	}
}

void Dg(tree t)
{
	if(t!=NULL)
	{
	Dg(t->left);
	cout<<" "<<t->sbd;
	Dg(t->right);
	}
}
void Dt(tree t)
{
	if(t!=NULL)
	{
	cout<<" "<<t->sbd;
	Dg(t->left);
	Dg(t->right);
	}
}
void Ds(tree t)
{
	if(t!=NULL)
	{
	Dg(t->left);
	Dg(t->right);
	cout<<" "<<t->sbd;
	}
}
int kiemtra(tree t,int sbd)
{	int s=0;
	if(t!=NULL)
	{
		if(t->sbd==sbd)
		{
			return 1; 
		}
		if(t->sbd!=sbd)
		{
			if(kiemtra(t->left,sbd)!=0)	return 1;
			if(kiemtra(t->right,sbd)!=0)	return 1;
		}
	}
	return 0;
}
void nhap(tree &t,int n)
{
	for(int i=0;i<n;i++)
	{
		int x; char y[50];
		cout<<endl<<"Nhap ho ten sinh vien can them : "; fflush(stdin);	gets(y);
		cout<<"Nhap so bao danh cua sinh vien  : ";	cin>>x;
		them(t,x,y);
	}
	return; 
}
void timsv(tree t,int sbd)
{
	if(t!=NULL)
	{
		if(t->sbd==sbd)
		{
			cout<<"Sinh vien co so bao danh "<<sbd<<" la "<<t->hoten;	return; 
		}
		if(t->sbd!=sbd)
		{
			timsv(t->left,sbd);
			timsv(t->right,sbd);
		}
	}
	return;
}

void makeEmpty(tree &t)
{
if (t == NULL) 		return;
makeEmpty(t->left); 
makeEmpty(t->right); 
delete t; 
t = NULL;
}

void swap(int &a,int &b)
{
	int k=a;
	a=b;
	b=k;
	return;
}
void vundong(int a[],int n,int i)
{
	int max=i;
	if((a[2*i+1]>a[max]) && (2*i+1<n))
		max=2*i+1;
	if((a[2*i+2]>a[max]) && (2*i+2<n))
		max=2*i+2;
	if(max!=i)
	{	swap(a[i],a[max]);
		vundong(a,n,max);
	}
	return;
}

void incay(int a[],int n)
{
	int k=1;
	for(int i=0;i<n;i++)
	{
		if(i+1>=k){
			cout<<endl;
			k=k*2;
		}
		cout<<a[i]<<" ";
	}
	return;
}

int main()
{
	tree t; khoitao(t); int n,sbd,a[99];
	cout<<"Nhap cay : "<<endl<<"Nhap so phan tu cua cay : "; cin>>n; 
	nhap(t,n);	Dt(t); Dg(t); Ds(t);
	cout<<endl<<"Nhap so bao danh can tim : "; cin>>sbd;
	if(kiemtra(t,sbd)!=0)	timsv(t,sbd);		
	else if(kiemtra(t,sbd)==0)	cout<<"Khong co sinh vien nao co so bao danh "<<sbd;
	
	// Vun dong theo so bao danh
	cout<<"Vui long nhap lai so bao danh de chuong trinh vun dong ";
	 for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";  	cin>>a[i];
	}
	for(int i=n/2-1;i>=0;i--)
	{
		vundong(a,n,i);
	}
	incay(a,n);
	// Neu can in ten sinh vien thi chi can su dung them ham timsv . O day chac chan so bao danh da thuoc tree nen khong can kiem tra 
	return 0;
}
