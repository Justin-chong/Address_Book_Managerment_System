#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string m_name;//
	int m_sex;//1男2女
	int m_age;
	string m_phone;
	string m_address;
};
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录当前报讯的联系人个数
	int m_size;
};

void Menu()
{
	printf("*********************\n");
	printf("****1.添加联系人 ****\n");
	printf("****2.显示联系人 ****\n");
	printf("****3.删除联系人 ****\n");
	printf("****4.查找联系人 ****\n");
	printf("****5.修改联系人 ****\n");
	printf("****6.清空联系人 ****\n");
	printf("****0.退出通讯录 ****\n");
	printf("*********************\n");
}
//检测联系人是否存在，如果存在则返回联系人在数组中的具体位置，否则返回-1
//参数1通讯录   参数2 姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//找到了对应的姓名
		if (abs->personArray[i].m_name == name)
		{
			return i;//找到返回下标
		}
	}

	return -1;
}
//1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满了
	if (abs->m_size >= MAX)
	{
		printf("通讯录人数已满,无法添加!\n");
		return;
	}
	else
	{
		//添加名字
		string name;
		printf("请输入姓名:\n");
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
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
			cout << "输入错误，请重新输入：" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
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
			cout << "输入错误，请从新输入：" << endl;
		}
		//电话
		cout << "请输入联系电话:" << endl;
		string phoneNumber;
		cin >> phoneNumber;
		abs->personArray[abs->m_size].m_phone = phoneNumber;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;
		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功!!!" << endl;
		system("pause");//暂停
		system("cls");//清屏
	}
}
//2.显示联系人
void showPerson(Addressbooks* abs)
{
	//判断人数
	if (abs->m_size == 0)
	{
		cout << "记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "住址：" << abs->personArray[i].m_address << endl;
		}
	}
	system("pause");//暂停
	system("cls");//清屏
}
//3.删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您想删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "未查到此人" << endl;
	}
	else
	{
		//查到了要进行删除的操作
		cout << "查到了" << endl;
		for (int i = ret; i < abs->m_size; i++)
		{//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//更新人数
		cout << "删除成功!!!" << endl;
	}
	system("pause");//暂停
	system("cls");//清屏
}
//4.查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您想要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断人存不存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到了" << endl;
		cout << "名字：" << abs->personArray[ret].m_name << "\t";
		cout << "性别：" << abs->personArray[ret].m_sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_age << "\t";
		cout << "电话：" << abs->personArray[ret].m_phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_address << endl;
		system("pause");
		system("cls");

	}  
}
//5.修改联系人信息
void changePerson(Addressbooks* abs)

{
	cout << "请输入您需要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;

	}
	else////修改各种信息
	{
		cout << "查到了" << endl;
		//name
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		
		abs->personArray[ret].m_name = name;
		//sex
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
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
				cout << "输入错误，请重新输入：" << endl;
		}
		//age
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;
		//phone
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;
		//address
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_address = address;
		cout << "修改成功！！！" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(Addressbooks* abs)
{
	

	abs->m_size = 0;//逻辑清空操作
	cout << "当前通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构变量
	Addressbooks abs;
	//初始化当前人员个数
	abs.m_size = 0;
	int input = 0;
	do
	{
		Menu();
		cin >> input;

		switch (input)
		{
		case 1://1.添加联系人
			addPerson(&abs);
			break;
		case 2://.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
		/*{
			cout << "请输入删除联系人的姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到了" << endl;
			}
		}*/
			deletePerson(&abs);
			break;

		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			changePerson(&abs);
			break;
		case 6://6.清空联系人
			cleanPerson(&abs);
			break;
		case 0://0.退出通讯录
			printf("欢迎下次使用\n");
			break;
		default:
			printf("选择错误，请重新选择：\n");
			break;
		}
	} while (input);
	return 0;
}