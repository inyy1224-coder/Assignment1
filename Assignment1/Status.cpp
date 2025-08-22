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
	// 변수 선언
	int status[4]; // status[0]은 HP, status[1]은 MP, status[2]은 공격력, status[3]은 방어력

	while (true)
	{
		// HP와 MP 입력
		cout << "HP와 MP를 입력해주세요: ";
		cin >> status[0] >> status[1];

		if (status[0] > 50 && status[1] > 50)
		{
			break;
		}
		cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}

	while (true)
	{
		// 공격력과 방어력을 입력
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> status[2] >> status[3];

		if (status[2] > 0 && status[3] > 0)
		{
			break;
		}
		cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
	}

	int choice = 0;
	int hPPotion = 0;
	int mPPotion = 0;

	setPotion(5, &hPPotion, &mPPotion);

	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
	cout << "=============================================" << endl;
	cout << "<스탯 관리 시스템>" << endl;
	cout << "1. HP 회복" << endl;
	cout << "2. MP 회복" << endl;
	cout << "3. HP 강화" << endl;
	cout << "4. MP 강화" << endl;
	cout << "5. 공격 스킬 사용" << endl;
	cout << "6. 필살기 사용" << endl;

	while (1) {
		cout << "번호를 선택해주세요: ";
		cin >> choice;

		if (choice == 7) {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}

		switch (choice) {
		case 1:
			if (hPPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			status[0] += 20;
			hPPotion--;
			cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 HP: " << status[0] << endl;
			cout << "남은 포션 수: " << hPPotion << endl;
			break;

		case 2:
			if (mPPotion <= 0) {
				cout << "포션이 부족합니다." << endl;
				continue;
			}
			status[1] += 20;
			mPPotion--;
			cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
			cout << "현재 MP: " << status[1] << endl; // stat[0] -> stat[1]
			cout << "남은 포션 수: " << mPPotion << endl;
			break;
		case 3:
			status[0] = status[0] * 2;
			cout << "* HP가 2배로 증가되었습니다." << endl;
			cout << "현재 HP: " << status[0] << endl;
			cout << "남은 포션 수: " << hPPotion << endl;
			break;
		case 4:
			status[1] = status[1] * 2;
			cout << "* MP가 2배로 증가되었습니다." << endl;
			cout << "현재 MP: " << status[1] << endl; // stat[0] -> stat[1]
			cout << "남은 포션 수: " << mPPotion << endl;
			break;
		case 5:
			if (status[1] < 50)
			{
				cout << "스킬 사용이 불가합니다." << endl;
				continue;
			}
			else
			{
				status[1] = status[1] - 50;
			}
			cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl;
			cout << "현재 MP: " << status[1] << endl; // stat[0] -> stat[1]
			break;
		case 6:
			status[1] = status[1] / 2;
			cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
			cout << "현재 MP: " << status[1] << endl; // stat[0] -> stat[1]
			break;
		default:
			cout << "다시 입력해주세요." << endl;
			break;
		}
	}

	return 0;
}

