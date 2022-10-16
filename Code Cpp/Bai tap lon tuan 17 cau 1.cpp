#include <iostream>
#include<math.h>
#include<queue>
#define V 10
using namespace std;

void taomt(int arr[][10]) {
  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++)
      arr[i][j] = 0;
}

void add(int arr[][10], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void inmt(int arr[][10]) {
  for (int i = 1; i <= 9; i++) 
  {
  	if(i==1)
  	{
  		cout<<"	1	2	3	4	5	6	7	8	9"<<endl<<endl;;
	}
    cout<<i<<"	";
    for (int j = 1; j <= 9; j++) 
	{
    cout<<arr[i][j]<<"	";
    }
    cout<<endl;
  }
}

struct Node
{
	int data;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};
void Listimit(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void add(List& l,int x)
{
	Node* node = new Node;
	node->data = x;
	node->next = NULL; 
	if (l.head == NULL)
	{
		l.head = node;
		l.tail = node;
	}
	else
	{
		node->next = l.head;
		l.head = node;
	}
}
void inList(List l)
{
	if (l.head != NULL)
	{
		Node* node = l.head;
		while (node != NULL)
		{
			cout << node->data << ' ';
			node = node->next;
		}
	}
}
void dfs(int x, int m[10][10], int visited[V])
{
	visited[x]=1;
	cout<<x;
	for(int j=1;j<=V;j++)
	{	
		if(m[x][j]==1)
		{
			if(visited[j]==0)	dfs(j,m,visited);
			else if(visited[j]==1)	continue;
			
		}
	}
}
void bfs(int x,int m[10][10], int visited[V], queue <int> q)
{
	visited[x]=1;
	cout<<x;
			for(int j=1;j<=9;j++)
			{
				if(m[x][j]==1 )	
				{
					if(visited[j]==0)
					q.push(j); 
					else if(visited[j]==1)	continue;
					
				}
			}
			while(!q.empty())
				{	
				if(visited[q.front()]==0)
				{
				bfs(q.front(),m,visited,q);
				q.pop();
				} 
				if(visited[q.front()]==1)
				{
					q.pop();
				}
			}
}
int main() {
	// O day chon Denebola la 1 , Zosma la 2 , Chertan la 3 , Regulus la 4 , Algieba la 5 , Adhafera la 6 , Rasalas la 7 
	// cai chom sao khong co ten ky hieu chu n kia la 8 , ky hieu chu E la 9 
  int m[10][10];
  taomt(m);
  add(m,1,2); add(m,1,3); add(m,2,3); add(m,2,5); add(m,4,3); 
  add(m,8,4); add(m,8,5); add(m,6,5); add(m,6,7); add(m,7,9); 
  inmt(m); 
  	// Chuyen tu ma tran ke sang danh sach ke
  for(int i=1;i<=9;i++)
  {
  	List a[i]; Listimit(a[i]);
  	for(int j=V;j>=1;j--)
  	{
  		if(m[i][j]==1)	add(a[i],j);
	}
	cout<<"Danh sach ke cua "<<i<<" la : "; inList(a[i]); cout<<endl;
  }
  int visited[V];
  for(int i=1;i<=9;i++)
  {
  	for(int j=1;j<=9;j++)	visited[j]=0;
  	cout<<"Duyet theo chieu sau bat dau tu diem "<<i<<" la : ";	  dfs(i,m,visited);
  	cout<<endl;
  }
  int r; cout<<"Chon diem bat dau duyet theo chieu sau : "; cin>>r;
  	for(int j=1;j<=9;j++)	visited[j]=0;
  	queue <int> y;  while(!y.empty())	 y.pop();
  	cout<<"Duyet theo chieu rong bat dau tu diem "<<r<<" la : "; bfs(r,m,visited,y);
  	cout<<endl;

  return 0;
}
