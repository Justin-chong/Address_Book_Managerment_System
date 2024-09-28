#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string m_name;//
	int m_sex;//1��2Ů
	int m_age;
	string m_phone;
	string m_address;
};
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼��ǰ��Ѷ����ϵ�˸���
	int m_size;
};

void Menu()
{
	printf("*********************\n");
	printf("****1.�����ϵ�� ****\n");
	printf("****2.��ʾ��ϵ�� ****\n");
	printf("****3.ɾ����ϵ�� ****\n");
	printf("****4.������ϵ�� ****\n");
	printf("****5.�޸���ϵ�� ****\n");
	printf("****6.�����ϵ�� ****\n");
	printf("****0.�˳�ͨѶ¼ ****\n");
	printf("*********************\n");
}
//�����ϵ���Ƿ���ڣ���������򷵻���ϵ���������еľ���λ�ã����򷵻�-1
//����1ͨѶ¼   ����2 ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//�ҵ��˶�Ӧ������
		if (abs->personArray[i].m_name == name)
		{
			return i;//�ҵ������±�
		}
	}

	return -1;
}
//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size >= MAX)
	{
		printf("ͨѶ¼��������,�޷����!\n");
		return;
	}
	else
	{
		//�������
		string name;
		printf("����������:\n");
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else
			cout << "����������������룺" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 150 && age > 0)
			{
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			else
			cout << "���������������룺" << endl;
		}
		//�绰
		cout << "��������ϵ�绰:" << endl;
		string phoneNumber;
		cin >> phoneNumber;
		abs->personArray[abs->m_size].m_phone = phoneNumber;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;
		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ�!!!" << endl;
		system("pause");//��ͣ
		system("cls");//����
	}
}
//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�����
	if (abs->m_size == 0)
	{
		cout << "��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_address << endl;
		}
	}
	system("pause");//��ͣ
	system("cls");//����
}
//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "����������ɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "δ�鵽����" << endl;
	}
	else
	{
		//�鵽��Ҫ����ɾ���Ĳ���
		cout << "�鵽��" << endl;
		for (int i = ret; i < abs->m_size; i++)
		{//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//��������
		cout << "ɾ���ɹ�!!!" << endl;
	}
	system("pause");//��ͣ
	system("cls");//����
}
//4.������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "����������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж��˴治����
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
		cout << "���֣�" << abs->personArray[ret].m_name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_address << endl;
		system("pause");
		system("cls");

	}  
}
//5.�޸���ϵ����Ϣ
void changePerson(Addressbooks* abs)

{
	cout << "����������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;

	}
	else////�޸ĸ�����Ϣ
	{
		cout << "�鵽��" << endl;
		//name
		string name;
		cout << "������������" << endl;
		cin >> name;
		
		abs->personArray[ret].m_name = name;
		//sex
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else
				cout << "����������������룺" << endl;
		}
		//age
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//phone
		cout << "������绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;
		//address
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;
		cout << "�޸ĳɹ�������" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs)
{
	

	abs->m_size = 0;//�߼���ղ���
	cout << "��ǰͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ����
	Addressbooks abs;
	//��ʼ����ǰ��Ա����
	abs.m_size = 0;
	int input = 0;
	do
	{
		Menu();
		cin >> input;

		switch (input)
		{
		case 1://1.�����ϵ��
			addPerson(&abs);
			break;
		case 2://.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
		/*{
			cout << "������ɾ����ϵ�˵�����" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ���" << endl;
			}
		}*/
			deletePerson(&abs);
			break;

		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			changePerson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			printf("��ӭ�´�ʹ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}