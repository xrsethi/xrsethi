
#include <iostream>
using namespace std;

/*
*	continue day_02 02
*	ָ������ã�ָ���Ǹ�����
*/
struct Teacher
{
	char name[64];
	int age;
};

//�ڵ��ú�����ȡ��Դ����Ҫ����ָ�루����˵��һ��ָ�븳ֵ����ַ����Ҳ�ɳ�Ϊ����ָ�������
int getTeacher(Teacher** p)		//����ָ��ģ�ͣ�pT1�Ǻ��ģ�p�Ǵ���ֵ������p��
{								//0xaa11,Ҳ����pT1�ĵ�ַ��װ��pT1һ����ַ��ʵ��
								//�û���Դ��pT1Ҳ�����ڿ����ĳ��ᣬp�ǿ�������
								//�����ĳ���װ�أ�ָ��Ŀ����Դ�ĵ�ַ������˵
								//��������ƣ��������ڼ�����о������ݣ����Ǳ���������ֵ

	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL)
	{
		return -2;
	}
	tmp->age = 78;
	*p = tmp;
	// p��ʵ�εĵ�ַ *ʵ�εĵ�ַȥ��ӵ��޸�ʵ�ε�ֵ
}
void freeTeacher(Teacher* pT1)
{
	if (pT1 == NULL)
	{
		return;
	}
	free(pT1);
}
//c++����ָ�������
int getTeacher2(Teacher* & myp)		//�ɰ� Teacher* ==��int& myp
{
	//��myp��ֵ �൱�ڸ�main�����е�pT1��ֵ
	myp = (Teacher*)malloc(sizeof(Teacher));
	if (myp == NULL)
	{
		return -1;
	}
	myp->age = 36;
}
int main()
{
	Teacher* pT1 = NULL;
	//1 c�����еĶ���ָ��
	getTeacher(&pT1);
	freeTeacher(pT1);
	cout << "age:" << pT1->age << endl;
	//2 c++�е�����(ָ�������)
	getTeacher2(pT1);
	cout << "age:" << pT1->age<< endl;
	freeTeacher(pT1);
	cout << "hello..." << endl;
}

/*
*	continue day_02 03
*	������
*/