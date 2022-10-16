#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

struct ngaysinh
{
	int ngay,thang,nam;
};

struct  SV
{
	int masv; char hoten[50]; int gioitinh; ngaysinh ns; char diachi[100]; char lop[12]; char khoa[7];
};
typedef struct SV sinhvien;
struct NODE
{
	sinhvien s;
	struct NODE *next;
};
typedef struct NODE node;
struct LIST
{
	node *first;
	node *last;
}; typedef struct LIST list;
void khoitao(list &l)
{
	l.first=NULL;
	l.last=NULL;
}

node *creat(sinhvien sv)
{	
	node *x= new node;
	if(x==NULL)	return NULL;
	x->s.masv=sv.masv;	strcpy(x->s.hoten,sv.hoten);	x->s.gioitinh=sv.gioitinh;	x->s.ns=sv.ns;	strcpy(x->s.diachi,sv.diachi);	strcpy(x->s.lop,sv.lop);	strcpy(x->s.khoa,sv.khoa);
	x->next=NULL;
	return x;
}

void add(list &o,node *n)
{
	if(o.first==NULL)	o.first=o.last=n;
	else	
	{
		n->next=o.first;
		o.first=n;
	}
}

void nhapsv(sinhvien &sv)
{
	printf("\nNhap ho va ten sinh vien : "); 	fflush(stdin);	gets(sv.hoten);
	printf("Nhap ma sinh vien : ");  scanf("%d",&sv.masv);
	printf("Nhap gioi tinh sinh vien ( 1 la nam , 0 la nu , cac so con lai la BD ) : " );	scanf("%d",&sv.gioitinh);  
	printf("Nhap ngay , thang , nam sinh cua sinh vien :\n	Ngay : ");  scanf("%d",&sv.ns.ngay); printf("	Thang : ");	scanf("%d",&sv.ns.thang);	printf("	Nam : ");	scanf("%d",&sv.ns.nam);
	printf("Nhap khoa cua sinh vien : "); 	fflush(stdin);	gets(sv.khoa);
	printf("Nhap lop cua sinh vien : ");	fflush(stdin);	gets(sv.lop);
	printf("Nhap dia chi noi o cua sinh vien : ");	fflush(stdin);	gets(sv.diachi);
}
void insv(list a)
{	node *p;	p=a.first;
	while(p!=NULL)
	{	
		printf("\nMa sinh vien : %d ",p->s.masv);
		printf("\n	Ho va ten : %s ",p->s.hoten);
		printf("\n	Gioi tinh : "); if(p->s.gioitinh==1)	printf("Nam"); 	else if(p->s.gioitinh==0)	printf("Nu"); 	else	printf("Bede");
		printf("\n	Ngay sinh : ngay %d thang %d nam %d .",p->s.ns.ngay,p->s.ns.thang,p->s.ns.nam);
		printf("\n	Hoc sinh lop : %s\n	Khoa %s .",p->s.lop,p->s.khoa);
		printf("\n	Noi o : %s",p->s.diachi);
		p=p->next;
	}
}
void sapxep(list &a)
{
	node *p, *q;	 	
	for(p=a.first;p!=NULL;p=p->next)
	{
		q=p;
		for(q=q->next;q!=NULL;q=q->next)
		{
			if(p->s.masv>q->s.masv)
			{
				sinhvien k;
				k=p->s;
				p->s=q->s;
				q->s=k; 
			}
		}
	}
}
void addsx(list &a,node *x)
{
	node *p,*q;
	p=a.first;
	if(x->s.masv<p->s.masv)
	{
		add(a,x);
		return;	
	}
	for(p=p->next;p!=NULL;p=p->next)	if(x->s.masv<p->s.masv) {	q=p; break; }
	p=a.first;
	while(p->next!=NULL)
	{	
		if(p->next==q)
		{
			x->next=q;
			p->next=x;
			return;
		}
		p=p->next;
	}
	p->next=x;
	x->next=NULL;

}

int main()
{
	list a;	khoitao(a);	int n; 	printf("Nhap so sinh vien trong danh sach : ");	scanf("%d",&n);  
	for(int i=0;i<n;i++)
	{
		sinhvien A;  nhapsv(A);	 add(a,creat(A)); 
	}
	sapxep(a); 	insv(a);	sinhvien B;	printf("\nNhap sinh vien can them vao : \n "); nhapsv(B);	addsx(a,creat(B));
	printf("\nDanh sach moi sau khi da them sinh vien moi la : \n ");		insv(a);
	return 0;
	
}

