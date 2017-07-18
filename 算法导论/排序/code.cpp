#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<time.h>

std::vector<double> insert_sort(std::vector<double> &x);

int main()
{
	using namespace std;
	int max_int = 1000;
	clock_t beg_time1, beg_time2, insert_time = 0, orgin_time = 0;
	for(int i = 0;i<1000; i++)
	{
		srand(unsigned int(time(0)));
		vector<double> x(max_int);
		for(int j = 0;j<x.size();j++)
			x[j] = rand();
		beg_time1 = clock();
		vector<double> y = insert_sort(x);
		insert_time += clock() - beg_time1;
		beg_time2 = clock();
		sort(x.begin(),x.end());
		orgin_time += clock() - beg_time2;
	}
	cout << "insert time is "<< (double)insert_time << endl;
	cout << "origin time is "<< (double)orgin_time << endl;
	return 0;
}

std::vector<double> insert_sort(std::vector<double> &x)
{
	using namespace std;
	vector<double> y(x.size());
	y[0] = x[0];
	for(int i = 1; i<x.size(); i++)
	{
		int j = i-1;
		while(j>=0 && y[j] > x[i])
		{
			y[j+1] = y[j];
			j--;
		}
		y[j+1] = x[i];
	}
	return y;
}
