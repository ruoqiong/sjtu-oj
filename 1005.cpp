#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ***p = new int **[n];     //三维数组
	int b[10] = { 0 };              //用10是为了方面后面的用b的下标来计数
	string *decision = new string[n];
	for (int i = 0; i < n; i++)    //初始化，在后面的操作中有错误的会被置为“Wrong”
		decision[i] = "Right";

	for (int i = 0; i < n; i++)   //申请内存空间
	{
		p[i] = new int *[9];
		for (int j = 0; j < 9; j++)
		{
			p[i][j] = new int[9];
		}
	}

	for (int i = 0; i < n; i++)       //输入并行检查
	{
		for (int j = 0; j < 9; j++)
		{
			for (int l = 0; l < 10; l++)
				b[l] = 0;

			for (int k = 0; k < 9; k++)   //行检查
			{
				cin >> p[i][j][k];  //输入
				b[p[i][j][k]]++;  // p[i][j][k]元素值对应b[]的下标。  
				if (b[p[i][j][k]] > 1)   //说明值 p[i][j][k] 出现了两次以上。 
				{
					decision[i] = "Wrong";
				}
			}
		}

	}

	for (int i = 0; i < n; i++)      //列检查
	{
		if ("Wrong" == decision[i])
			continue;

		for (int j = 0; j < 9; j++)
		{
			if ("Wrong" == decision[i])
				break;;

			for (int l = 0; l < 10; l++)
				b[l] = 0;

			for (int k = 0; k < 9; k++)
			{
				b[p[i][k][j]]++;
				if (b[p[i][k][j]]>1)
				{
					decision[i] = "Wrong";
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)      //分块检查每块大小为3*3
	{
		if ("Wrong" == decision[i])
			continue;

		for (int j = 0; j < 3; j++)
		{

			for (int k = 0; k < 3; k++)
			{
				if ("Wrong" == decision[i])
					break;
				for (int l = 0; l < 10; l++)
					b[l] = 0;
				for (int x = 0; x < 3; x++)
					for (int y = 0; y < 3; y++)
					{
						b[p[i][3 * j + x][3 * k + y]]++;
						if (b[p[i][3 * j + x][3 * k + y]]>1)
						{
							decision[i] = "Wrong";
							break;
						}
					}
			}
		}
	}
	for (int i = 0; i < n; i++)   //输出结果
	{
		cout << decision[i] << endl;
	}
	return 0;
}