/*
1. 10���� ���� �ְ�, �� ������ ���Լ��� ������� �Էµȴ�.

2. �����ȿ� ����� ���� ������ ���� ���� ã�´�.
	2.1 1������ ������� 0, 10������ ���Լ��� 0�̴�.
	2.2 ��� ����� ������ ź��.
	2.3 �� �ñ⸦ ���ʿ�� ����, ���� ���� ���� -�� ���� ����.
	2.4 ������ �ִ� ������ 10000���̴�. �����ʰ� �Է¿��þ���.

3. ���� ���.
--------
���� Ŭ����/���, ����ִ�/ž�±��, �������, �ִ񰪰��ű��

*/
#include <stdio.h>

class C_TRAIN
{
private:
	int m_nPeopleNum;
	int m_nMaxPeopleNum;
public:
	C_TRAIN();
	C_TRAIN(const C_TRAIN &) = delete;
	const C_TRAIN& operator =(const C_TRAIN &) = delete;
	~C_TRAIN();
public:
	void getOnTrain(int nNumber);
	void getOffTrain(int nNumber);
	void updateMaxPeople();
	void printMaxPeople();
};

int main()
{
	C_TRAIN cTrain;
	int nData(0);
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &nData);
		cTrain.getOffTrain(nData);
		scanf("%d", &nData);
		cTrain.getOnTrain(nData);
		cTrain.updateMaxPeople();
	}
	cTrain.printMaxPeople();
	return 0;
}

C_TRAIN::C_TRAIN()
	: m_nPeopleNum(0), m_nMaxPeopleNum(0)
{
}

C_TRAIN::~C_TRAIN()
{
}

void C_TRAIN::getOnTrain(int nNumber)
{
	m_nPeopleNum += nNumber;
}

void C_TRAIN::getOffTrain(int nNumber)
{
	m_nPeopleNum -= nNumber;
}

void C_TRAIN::updateMaxPeople()
{
	if (m_nMaxPeopleNum < m_nPeopleNum)
		m_nMaxPeopleNum = m_nPeopleNum;
}

void C_TRAIN::printMaxPeople()
{
	printf("%d\n", m_nMaxPeopleNum);
}
