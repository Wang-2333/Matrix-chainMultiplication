#include<iostream>
using namespace std;

int const M = 7;
void matrix_chain(int* p, int Length, int m[][M], int s[][M])
{
	int q, n = Length - 1;
	for (int i = 1; i <= n; i++) 
		m[i][i] = 0;
	for (int l = 2; l <= n; l++) 
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;  
			m[i][j] = 0xffffff;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void print(int s[][M], int i, int j)
{
	if (i == j) cout << "A" << i;
	else
	{
		cout << "(";
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main()
{
	int p[M] = { 5,30,10,25,15,20 };
	int m[M][M], s[M][M];
	matrix_chain(p, M, m, s);
	cout << "当n=5时最优解为: \n" << m[1][5];
	cout << "\n括号化方案为：\n";
	print(s, 1, 5);
	return 0;
}