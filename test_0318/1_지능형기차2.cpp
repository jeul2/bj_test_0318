/*
1. 10개의 역이 있고, 각 역에서 진입수와 진출수가 입력된다.

2. 기차안에 사람이 가장 많았을 때의 수를 찾는다.
	2.1 1번역의 진출수는 0, 10번역의 진입수는 0이다.
	2.2 모든 사람은 내리고 탄다.
	2.3 그 시기를 알필요는 없고, 기차 안의 수가 -인 경우는 없다.
	2.4 기차의 최대 정원은 10000명이다. 정원초과 입력역시없다.

3. 수를 출력.
--------
기차 클래스/사람, 사람최댓값/탑승기능, 하차기능, 최댓값갱신기능

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
