/*
����ģʽ��Proxy Pattern
ʹ��ԭ������м��������ֱ�Ӳ���ʵ�ֶ��󣬷��Ͽ���ԭ��(��չ�ǿ��ţ��޸��Ǳպϵ�)
����չ�����ࡣ
�������ί���඼�̳���ͬ�Ľӿڡ�
*/
#include<stdio.h>
#include"IProxy.h"

//ִ�ж��� 
class CDoSomething :public IProxy
{
public:
	void Display(int inum);
};
void CDoSomething::Display(int inum)
{
	printf("CDoSomething Display =%d\n",inum);
}

//����
class CProxy :public IProxy
{
private:
	CDoSomething *m_pDoSomething;
public:
	
	CProxy():m_pDoSomething(NULL)
	{

	};

	~CProxy()
	{
		if (m_pDoSomething)
			delete m_pDoSomething;
	};

	void Display(int inum);

	//something   
};
void CProxy::Display(int inum)
{
	if (m_pDoSomething == nullptr)
		m_pDoSomething = new CDoSomething();
	
	m_pDoSomething->Display(inum);
}

int main(int argc, char *argv[])
{
	CProxy dlg;
	
	dlg.Display(1);

	for (;;);

	return 0;
}