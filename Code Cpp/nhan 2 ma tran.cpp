#include<iostream>
#include<math.h>
int i,j,h,m,n,u,v,s;
using namespace std;

int main()
{
	int a[99][99]; //Khai bao ma tran A
	int b[99][99]; //Khai bao ma tran B
	int c[99][99]; //Khai bao ma tran C
	cout<<"Nhap so hang , so cot cua ma tran A : ";
    cin>>m; cin>>n;
    cout<<"Nhap so hang , so cot cua ma tran B : ";
    cin>>u; cin>>v;
    cout<<"Nhap ma tran A : "<<endl;
    for(int q=1;q<=m;q++)
    {
    	for(int b=1;b<=n;b++)
    	{
    		cin>>a[q][b];
		}
	}
	cout<<"Nhap ma tran B : "<<endl;
	   for(int q=1;q<=u;q++)
    {
    	for(int w=1;w<=v;w++)
    	{
    		cin>>b[q][w];
		}
	}
    if(n!=u)//Kiem tra xem 2 ma tran co the nhan voi nhau khong :v
    {
    	cout<<"Hai ma tran nay khong nhan voi nhau duoc dau nhe !!! ";
	}
	else
	{
		for(j=1;j<=m;j++)
		{   
		   
			for(h=1;h<=v;h++)
			{   
			    s=0; 
				for(i=1;i<=n;i++)
				{
					s=s+a[j][i]*b[i][h];				
				}
				c[j][h]=s;
			}
		
		}
		cout<<"ma tran C=AxB la : "<<endl;
		for(int q=1;q<=m;q++)
		{
			for(int b=1;b<=v;b++)
			{
				cout<<c[q][b]<<"  ";
				if(b==v)
				{
					cout<<endl;
				}
			}
		}
	}
	return 0;
	
 } 
