#define _CRT_SECURE_NO_WARNINGS 1
#include < stdio.h >
#include < assert.h >

int main()
{
	int arr[5] = {0};  //5个人的名次（放到数组中）第一列1-5表示A-E  第二列代表名次
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;
	int sit = 0;
	for (i1 = 1; i1 <= 5 && sit == 0; i1++) //A的名次
	{
		for (i2 = 1; i2 <= 5 && sit == 0; i2++) //B的名次
		{
			if (i2 != i1)
			{
				for (i3 = 1; i3 <= 5 && sit == 0; i3++)
				{
					if (i3 != i2 && i3 != i1)
					{
						for (i4 = 1; i4 <= 5 && sit == 0; i4++)
						{
							if (i4 != i3 && i4 != i2 && i4 != i1)
							{
								for (i5 = 1; i5 <= 5 && sit == 0; i5++)
								{
									if (i5 != i4 && i5 != i3 && i5 != i2 && i5 != i1)
									{
										arr[0] = i1; //获取排列的组合
										arr[1] = i2;
										arr[2] = i3;
										arr[3] = i4;
										arr[4] = i5;
										if (((arr[1] == 2 && arr[0] == 3) == 0) + //A的两句话有一句是错的
											((arr[1] == 2 || arr[0] == 3) == 1) +  //A的两句话有一句是对的
											((arr[1] == 2 && arr[4] == 4) == 0) +
											((arr[1] == 2 || arr[4] == 4) == 1) +
											((arr[2] == 1 && arr[3] == 2) == 0) +
											((arr[2] == 1 || arr[3] == 2) == 1) +
											((arr[3] == 3 && arr[2] == 5) == 0) +
											((arr[3] == 3 || arr[2] == 5) == 1) +
											((arr[4] == 4 && arr[0] == 1) == 0) +
											((arr[4] == 4 || arr[0] == 1) == 1) == 10  //10个条件都必须满足，此时的名次才是对的
											)
										{  //满足条件 则arr[i][1]中放的就是每个人的顺序
											sit = 1; //停止
										}
										else; //否则//改变排列（最多5*4*3*2*1种 排列方法）
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("A=%d B=%d C=%d D=%d E=%d",arr[0], arr[1], arr[2], arr[3], arr[4]);
	return 0;
}
