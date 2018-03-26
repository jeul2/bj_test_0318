/*
1. 0�� �Էµɶ����� �Է¹޴´�. N�� 1000�ڸ� ����.

2. �ش� N�� �ڸ������� ���ؼ� ���ڸ��϶� ���� �ݺ��Ѵ�.

3. ����� ����Ѵ�.
-----------------
N�� �ڸ����� �̾Ƴ��� �迭[4]�� ��Ÿ���� ���.
�̸� ���ؼ� �ݺ�.
N�� 1�� �ڸ��� ��� ����.

*/
#include <stdio.h>

void initialize(int *pSrc, int nSize);
void setData(int nNumber, int *pSrc, int nSize);
void sumData(const int *pSrc, int nSize, int *pRes);

int main()
{
	char strData[1000 + 1]{};
	int arData[1000 + 1]{};
	int nArraySize(1000);

	int nData(0);
	int nProcessNumber(0);
	int nTemp(0);
	//
	//freopen("input.txt", "r", stdin);
	scanf("%d", &nData);
	while (nData != 0)
	{
		nProcessNumber = nData;
		while (nProcessNumber != 0 && nProcessNumber >= 10)
		{
			initialize(arData, nArraySize);
			setData(nProcessNumber, arData, nArraySize);
			sumData(arData, nArraySize, &nTemp);
			nProcessNumber = nTemp;
		}
		printf("%d\n", nProcessNumber);

		scanf("%d", &nData);
	}

	return 0;
}

void initialize(int * pSrc, int nSize)
{
	for (int i = 0; i < nSize; ++i)
	{
		pSrc[i] = 0;
	}
}

void setData(int nNumber, int * pSrc, int nSize)
{
	int nTempData(0);
	int nCount(0);
	
	nTempData = nNumber;
	nCount = 0;
	while (nTempData != 0 && nCount < nSize)
	{
		pSrc[nCount] = nTempData % 10;
		nTempData = nTempData / 10;
		++nCount;
	}
	//test
	//for (int i = 0; i < nSize; ++i)
	//{
	//	printf("[%d]", pSrc[nSize - i - 1]);
	//}
	//printf("\n");
	//test end
}

void sumData(const int * pSrc, int nSize, int * pRes)
{
	int nSum(0);

	nSum = 0;
	for (int i = 0; i < nSize; ++i)
	{
		nSum += pSrc[i];
	}
	*pRes = nSum;
}
