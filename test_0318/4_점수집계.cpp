/*
1. TC�� �־�����. TC���� 5���� �Է��� �־�����.(�Է��� 1���� 10���� ����)

2. �Է��� �����ؼ� ���� �ְ� ����.
	2.1 �� 3���� �Ϳ��� �ְ�-���� ���̸� ����Ѵ�.
	2.2 �� 3���� ���� ���� ���Ѵ�.

3. �ְ�-���� ���̰� 4�̻��̸� KIN�� ����Ѵ�.
	Ȥ�� ���� ����Ѵ�.
-------------------
DATA�� �����ϴ� ����.
+DATA���� �ְ�, ������ ���ϴ� ���.
=�����͸� ���������� �����ϴ� ����.

�� �������� �ְ�� ������ ���ϴ� ���.
�� ������ �����͵��� ���� ���ϴ� ���.
*/
#include <stdio.h>

void findMaxValue(int *pSrc, int nSrcSize, int *pRes);
void findMinValue(int *pSrc, int nSrcSize, int *pRes);
void refineData(int nSrcTarget, int *pSrc, int nSrcSize);
void calculateSum(int *pSrc, int nSrcSize, int *pRes);
bool isKIN(int nMax, int nMin);

void deriveResult(int *pSrc, int nSrcSize);

int main()
{
	int arStorage[5]{};
	int nStorageSize(5);

	int nInputNum(0);
	int nData(0);
	//
	freopen("input.txt", "r", stdin);
	scanf("%d", &nInputNum);
	for (int i = 0; i < nInputNum; ++i)
	{
		for (int i = 0; i < 5; ++i)
		{
			scanf("%d", &nData);
			arStorage[i] = nData;
		}
		
		deriveResult(arStorage, nStorageSize);
	}

	return 0;
}

void findMaxValue(int * pSrc, int nSrcSize, int * pRes)
{
	int nMaxTemp(0);

	nMaxTemp = 0;
	for (int i = 0; i < nSrcSize; ++i)
	{
		if (pSrc[i] > nMaxTemp && pSrc[i] != 0)
		{
			nMaxTemp = pSrc[i];
		}
	}
	*pRes = nMaxTemp;
}

void findMinValue(int * pSrc, int nSrcSize, int * pRes)
{
	int nMinTemp(0);

	nMinTemp = 11;
	for (int i = 0; i < nSrcSize; ++i)
	{
		if (pSrc[i] < nMinTemp && pSrc[i] != 0)
		{
			nMinTemp = pSrc[i];
		}
	}

	*pRes = nMinTemp;
}

void refineData(int nSrcTarget, int * pSrc, int nSrcSize)
{
	for (int i = 0; i < nSrcSize; ++i)
	{
		if (pSrc[i] == nSrcTarget)
		{
			pSrc[i] = 0;
			break;
		}
	}
}

void calculateSum(int * pSrc, int nSrcSize, int * pRes)
{
	int nSum(0);

	nSum = 0;
	for (int i = 0; i < nSrcSize; ++i)
	{
		nSum += pSrc[i];
	}
	*pRes = nSum;
}

bool isKIN(int nMax, int nMin)
{
	if (nMax - nMin >= 4)
		return true;
	else
		return false;
}


void deriveResult(int * pSrc, int nSrcSize)
{
	int nMaxValue(0);
	int nMinValue(0);
	int nSum(0);
	int nSecondMax(0);
	int nSecondMin(0);

	findMaxValue(pSrc, nSrcSize, &nMaxValue);
	findMinValue(pSrc, nSrcSize, &nMinValue);
	refineData(nMaxValue, pSrc, nSrcSize);
	refineData(nMinValue, pSrc, nSrcSize);

	findMaxValue(pSrc, nSrcSize, &nSecondMax);
	findMinValue(pSrc, nSrcSize, &nSecondMin);
	if (isKIN(nSecondMax, nSecondMin) == true)
	{
		printf("KIN\n");
	}
	else
	{
		nSum = 0;
		calculateSum(pSrc, nSrcSize, &nSum);
		nSum = nSum;
		printf("%d\n", nSum);
	}
}
