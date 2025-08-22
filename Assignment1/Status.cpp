#include <iostream>
#include <string>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;

	*p_MPPotion = count;
}


int main()
{
	// ���� ����
	int status[4]; // status[0]�� HP, status[1]�� MP, status[2]�� ���ݷ�, status[3]�� ����

	while (true)
	{
		// HP�� MP �Է�
		cout << "HP�� MP�� �Է����ּ���: ";
		cin >> status[0] >> status[1];

		if (status[0] > 50 && status[1] > 50)
		{
			break;
		}
		cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
	}

	while (true)
	{
		// ���ݷ°� ������ �Է�
		cout << "���ݷ°� ������ �Է����ּ���: ";
		cin >> status[2] >> status[3];

		if (status[2] > 0 && status[3] > 0)
		{
			break;
		}
		cout << "���ݷ��̳� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
	}

	int choice = 0;
	int hPPotion = 0;
	int mPPotion = 0;

	setPotion(5, &hPPotion, &mPPotion);

	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;
	cout << "=============================================" << endl;
	cout << "<���� ���� �ý���>" << endl;
	cout << "1. HP ȸ��" << endl;
	cout << "2. MP ȸ��" << endl;
	cout << "3. HP ��ȭ" << endl;
	cout << "4. MP ��ȭ" << endl;
	cout << "5. ���� ��ų ���" << endl;
	cout << "6. �ʻ�� ���" << endl;

	while (1) {
		cout << "��ȣ�� �������ּ���: ";
		cin >> choice;

		if (choice == 7) {
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}

		switch (choice) {
		case 1:
			if (hPPotion <= 0) {
				cout << "������ �����մϴ�." << endl;
				continue;
			}
			status[0] += 20;
			hPPotion--;
			cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
			cout << "���� HP: " << status[0] << endl;
			cout << "���� ���� ��: " << hPPotion << endl;
			break;

		case 2:
			if (mPPotion <= 0) {
				cout << "������ �����մϴ�." << endl;
				continue;
			}
			status[1] += 20;
			mPPotion--;
			cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
			cout << "���� MP: " << status[1] << endl; // stat[0] -> stat[1]
			cout << "���� ���� ��: " << mPPotion << endl;
			break;
		case 3:
			status[0] = status[0] * 2;
			cout << "* HP�� 2��� �����Ǿ����ϴ�." << endl;
			cout << "���� HP: " << status[0] << endl;
			cout << "���� ���� ��: " << hPPotion << endl;
			break;
		case 4:
			status[1] = status[1] * 2;
			cout << "* MP�� 2��� �����Ǿ����ϴ�." << endl;
			cout << "���� MP: " << status[1] << endl; // stat[0] -> stat[1]
			cout << "���� ���� ��: " << mPPotion << endl;
			break;
		case 5:
			if (status[1] < 50)
			{
				cout << "��ų ����� �Ұ��մϴ�." << endl;
				continue;
			}
			else
			{
				status[1] = status[1] - 50;
			}
			cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�." << endl;
			cout << "���� MP: " << status[1] << endl; // stat[0] -> stat[1]
			break;
		case 6:
			status[1] = status[1] / 2;
			cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl;
			cout << "���� MP: " << status[1] << endl; // stat[0] -> stat[1]
			break;
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
			break;
		}
	}

	return 0;
}

