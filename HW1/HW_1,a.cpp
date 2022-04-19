#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int a[10] = { 0,0,1,1,1,1,0,1,0,0 };
	cout << "The number of a[0] value=" << count(&a[0], &a[9], a[0]);
	return 0;
}
