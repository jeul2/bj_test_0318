/*
1. TC가 주어진다. TC별로 5개의 입력이 주어진다.(입력은 1에서 10까지 정수)

2. 입력을 정제해서 최저 최고를 뺀다.
	2.1 뺀 3개의 것에서 최고-최저 차이를 계산한다.
	2.2 뺀 3개의 것의 합을 구한다.

3. 최고-최저 차이가 4이상이면 KIN을 출력한다.
	혹은 합을 출력한다.
-------------------
DATA를 보관하는 구조.
+DATA내의 최고, 최저를 구하는 기능.
=데이터를 순차적으로 보관하는 구조.

그 구조에서 최고와 최저를 구하는 기능.
그 구조의 데이터들의 합을 구하는 기능.
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
