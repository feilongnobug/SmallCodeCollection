#include <iostream>
#define LEN 20

using namespace std;

typedef struct NODE
{
  int data;
  NODE* next;
}mynode;

void* creat_list()
{
  mynode* HEAD = NULL;
  mynode* TMP = NULL;
  HEAD = new mynode;
  HEAD->data = 4518;
  HEAD->next = NULL;
  TMP = HEAD;
  int i = LEN;
  while(i--){
    HEAD = new mynode;
    HEAD->data = i;
    HEAD->next = TMP;
    TMP = HEAD;
  }
  return HEAD;
}

void free_list(mynode* pn)
{
	while(pn->next){
		mynode* tmp = pn;
		delete pn;
		pn = tmp->next;
	}
	cout<<"free pn: "<<pn<<endl;
	delete pn;
}

mynode* search_bydata(mynode* pn,int data){
	mynode* lastone;
	while(pn->next){
		if(data == pn->data){
			cout<<pn<<" : "<<pn->data<<endl;
			lastone = pn;
		}
		pn = pn->next;
	}
	return lastone;
}

//@info: i是插入的位置
//@param: pn指向一个链表
bool insert_(mynode* pn,int i,int data){
	int counter = 0;
	while(counter != i && pn){
		pn = pn->next;
		counter++;
	}
	mynode* newnode = new mynode;
	newnode->data = data;
	newnode->next = pn->next;
	pn->next = newnode;
	return true;
}

bool delete_(mynode* pn,int data){
	mynode* tmp;
	if(data == pn->data)
	{
		tmp = pn;
		pn = pn->next;
		delete tmp;
	}
	while(pn){
		if(pn->next && pn->next->data == data){
			tmp = pn->next;
			pn->next = tmp->next;
			delete tmp;
		}
		pn = pn->next;
	}
   return true;
}

void show(mynode* pn)
{  
  while(pn->next)
  {
    cout<<pn<<" : "<<pn->data<<endl;
    pn = pn->next; 
  }
  cout<<pn<<" : "<<pn->data<<endl;
}

int main()
{
  mynode* pn;
  cout<<"create my list:"<<endl;
  pn =(mynode*) creat_list();
  mynode* const HEAD = pn;
  show(HEAD);
  cout<<"search data = 10:"<<endl;
  search_bydata(HEAD,10);

  cout<<"insert 10 into mylist:"<<endl;
  insert_(HEAD,2,10);
  show(HEAD);
  
  cout << "search data = 10:"<<endl;
  search_bydata(HEAD,10);

  cout<<"delete 10 from mylist:"<<endl;
  delete_(HEAD,10);
  show(HEAD);
  cout<<endl;

  pn = HEAD;
  free_list(pn);
  cout<<"hello,world!"<<endl;
  return 0;
}
