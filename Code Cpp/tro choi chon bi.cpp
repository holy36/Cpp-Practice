#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

int main()
{
	int k;
	cout<<"Nguoi chon cuoi thang "<<endl;
	int n;  cout<<"Nhap so vien bi : ";  cin>>n;  fflush(stdin);
	while(n<30 || n>50)
	{
		cout<<"Nhap lai di bro , so vien bi tu 30 den 50 vien : "<<endl;
		cin>>n;		fflush(stdin);
	}
	while(n>0)
	{
		cout<<"Nguoi choi chon : "; cin>>k;
			while(k<1 || k>5)
		{
			cout<<"Nhap lai di bro , so vien bi chon chi tu 1 den 5 : "<<endl;
			cin>>k;		
		}
		n=n-k;
		cout<<"So bi con lai : "<<n<<endl;
		if(n>=17)
		{
			cout<<"May tinh chon 5 "<<endl;
			n=n-5;
			cout<<"So bi con lai : "<<n<<endl;
			if(n==7 || n==8 || n==9 || n==10 ||n==11)
			{
				continue;
			}
		}
		else {
		switch(n)
		{
			case 7:
			case 13:
				cout<<"May tinh chon 1"<<endl;  	n=n-1;
				cout<<"So bi con lai : "<<n<<endl;
			
				break;
			case 8:
			case 14:
				cout<<"May tinh chon 2"<<endl;  	n=n-2;
				cout<<"So bi con lai : "<<n<<endl;
			
				break;
			case 9:
			case 15:
				cout<<"May tinh chon 3"<<endl;   	n=n-3;
				cout<<"So bi con lai : "<<n<<endl;
			
				break;
			case 10:
			case 16:
				cout<<"May tinh chon 4"<<endl;    	n=n-4;
				cout<<"So bi con lai : "<<n<<endl;
			
				break;
			case 11:
			case 17:  
				cout<<"May tinh chon 5"<<endl;   	n=n-5;
				cout<<"So bi con lai : "<<n<<endl;
			
				break;
		}
		if(n<=5)
		{
			cout<<"May tinh chon "<<n<<endl;
			n=0;
			cout<<"So bi con lai : "<<n<<endl;
		}
	}

	}
	cout<<"Xin chuc mung ban da thua !";
	return 0;
}
