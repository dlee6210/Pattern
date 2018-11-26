/*
�۲���ģʽ��Observer Pattern  
��Ҫ����������.
ʹ�ã����۲���״̬�����ı�ʱ����֪ͨ�۲��ߡ�
��Ҫ���룺���۲����ڲ�����һ���۲��߶�����б�  
*/

#include<stdio.h>
#include<vector>
#include"IObserver.h"
#include"ISubject.h"
//
class CObserver : public IObserver
{
public:
	virtual void Nodify(int inum);
};
void CObserver::Nodify(int inum)
{
	printf("In CObserver inum = %d\n",inum);
}
//
class CObserver2 :public IObserver
{
public:
	virtual void Nodify(int inum);
};
void CObserver2::Nodify(int inum)
{
	printf("in CObserver2 inum = %d\n",inum);
}
//
class CSubject :public ISubject
{
public:
	virtual void AddObject(IObserver *p);

	void NodifyObserver();

	std::vector<IObserver *>m_pVecObserver;
};

void CSubject::AddObject(IObserver *p)
{
	//List
	m_pVecObserver.push_back(p);
}
void CSubject::NodifyObserver()
{
	std::vector<IObserver *>::iterator iter;
	for (iter = m_pVecObserver.begin(); iter != m_pVecObserver.end(); iter++)
	{
		(*iter)->Nodify(1);
	}
}
//
int main(int argc, char *argv[])
{
	
	IObserver *pB = new CObserver();
	IObserver *pB2 = new CObserver2();

	CSubject  *pS = new CSubject();

	pS->AddObject(pB);
	pS->AddObject(pB2);

	pS->NodifyObserver();

	for (;;);

	return 0;
}