#include <bits/stdc++.h>
using namespace std;

#define d 10

void search(char P[], char T[], int q)
{
	int M = strlen(P);
	int N = strlen(T);
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;

     for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 

	for (i = 0; i < M; i++) {
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (T[i + j] != P[j]) {
					break;
				}
            }
			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}
		if (i < N - M) {
			t = (d * (t - T[i] * h) + T[i + M]) % q;

			if (t < 0)
				t = (t + q);
		}
	}
}

int main()
{
	char T[] = "354861742287";
	char P[] = "22";

	int q = 13;
	search(P, T, q);
	return 0;
}

