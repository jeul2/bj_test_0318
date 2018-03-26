#include <stdio.h>

int main()
{
	int nTestNum(0);
	int nData(0);
	int nEvenSum(0);
	int nMinEvenData(0);

	//
	freopen("input.txt", "r", stdin);
	scanf("%d", &nTestNum);

	for (int i = 0; i < nTestNum; ++i)
	{
		nEvenSum = 0;
		nMinEvenData = 101;

		for (int i = 0; i < 7; ++i)
		{
			scanf("%d", &nData);
			if (nData % 2 == 0)
			{
				nEvenSum += nData;

				if (nMinEvenData > nData)
				{
					nMinEvenData = nData;
				}

			}


		}

		printf("%d %d\n", nEvenSum, nMinEvenData);

	}

	



	return 0;
}