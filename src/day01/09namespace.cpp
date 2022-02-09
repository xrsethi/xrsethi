#include "iostream"			//����C++ͷ�ļ�
using namespace std;        //�ļ� iostream û�������׼�� std:��Ҫ���ǳ���Ա�Լ�д,�����д��Ҫ��ʾ������
//namespace ��Ϊ�����ڴ��ģ����������Լ��ڳ���Աʹ�ø��ָ�����C++��ʱ����Щ��ʶ����������������ͻ c++����ؼ��� namespace,���Ը��õؿ��Ʊ�ʶ����������
/*
* c++�����ռ�Ķ��壺namespace name { ... }
* �����ռ��ʹ�� using namespace NamespaceA һ��ʹ�����
*/

void main01()
{
	std::cout << "namespace test" << std::endl;
}

//���������ռ�
namespace namespaceA
{
	int a = 0;
}
namespace namespaceB
{
	int a = 20;
	namespace namespaceC
	{
		struct Teacher
		{
			char name[10];
			int age;
		};
	}
}

//ʹ�������ռ�
void main02()
{
	using namespace namespaceA;
	using namespace namespaceB;
	cout << namespaceA::a << endl;
	cout << namespaceB::a << endl;

	namespaceB::namespaceC::Teacher t1;
	t1.age = 12;
	cout << t1.age << endl;

}

/*
* c++��׼Ϊ�˺�c���ֿ���ҲΪ����ȷʹ�������ռ䣬�涨ͷ�ļ������ú�׺ .h
* ��γ�Ϊ���֣��͵�ȥԴ�����濴 ����������������ʲô�����Ͳ�ʲô
* ���ڰ汾��c++���õ�ʱ iostream.h ���˳�Ц��˵�ٶ����������Ż�ȥ����.h 
* 
*/
//�� day01 10