/*
代理模式：Proxy Pattern
使用原因：添加中间代理，避免直接操作实现对象，符合开闭原则(扩展是开放，修改是闭合的)
可扩展代理类。
代理类和委托类都继承相同的接口。
*/
#include<stdio.h>
#include"IProxy.h"

//执行对象 
class CDoSomething :public IProxy
{
public:
	void Display(int inum);
};
void CDoSomething::Display(int inum)
{
	printf("CDoSomething Display =%d\n",inum);
}

//代理
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