#include<iostream>
using namespace std;
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		if (N == 0 || M == 0)
		{
			break;
		}
		else
		{
			int m[N][M];
			int r[M][N];
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cin >> m[i][j];
					r[j][i] = m[i][j];
				}
			}
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (j != 0)
					{
						cout << " " << r[i][j];
					}
					else
					{
						cout << r[i][j];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}