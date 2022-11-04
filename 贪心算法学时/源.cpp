#include <iostream>
using namespace std;
struct Node
{
	float T;
	float V;
	bool mark;
	char char_mark;
	float pre_T_V;
};

int main(int argc, char* argv[])
{
	float T_all = 0.0;
	int N;
	int i;
	int M;
	cout<< "Enter the total class number:";
	cin >> N;
	cout << "Enter the total class time:";
	cin >>M;
	float T[99];
	float V[99];
	for (int a = 0; a < N; a++)
	{
	cout << "Enter the class mark:";
	cin >> V[a];
	cout << "Enter the class time:";
	cin >> T[a];
	}
	Node array[99];
	for (i = 0; i < N; i++)
	{
		array[i].V = V[i];
		array[i].T = T[i];
		array[i].char_mark = 65 + i;
		array[i].mark = false;
		array[i].pre_T_V = V[i] / T[i];
	}
	//for (i = 0; i < N; i++)
		//cout << array[i].pre_T_V << " ";
	//cout << endl;

	float V_all = 0.0;
	float max = 0.0;
	char charArray[99];
	int flag, n = 0;
	
	while (T_all <= M)
	{
		for (int index = 0; index < N; ++index)
		{
			if (array[index].pre_T_V > max && array[index].mark == false)
			{
				max = array[index].pre_T_V;
				flag = index;
			}
		}

		charArray[n++] = array[flag].char_mark;
		array[flag].mark = true;
		T_all += array[flag].T;
		V_all += array[flag].V;
		max = 0.0;
	}
	cout << "T_all:" << T_all - array[n - 1].T << endl;
	cout << "V_all:" << V_all-1<< endl;

	system("pause");
	return 0;
}
