#include<string>
#include<iostream>

int clear_char(std::string &x);
int max_clear_char(std::string &x);
int main(void)
{
	using namespace std;
	int n;
	cin >>n;
	for(int i = 1; i<=n; i++)
	{
		string x;
		cin >> x;
		cout << max_clear_char(x) << endl;
	}
	return 0;
}


int clear_char(std::string &x)
{
	if(x.size() <= 1)
	{
		return 0;
	}
	else
	{
		std::string next_string = x;
		char pre_char = next_string[0];
		int first_num = 0;
		int count = 0;
		for(int i = 1; i < next_string.size();i++)
		{
			if(next_string[i] == pre_char)
			{
				first_num = i - 1;
				while(i < next_string.size() && next_string[i]==pre_char)
				{
					i++;
				}	
				next_string = next_string.substr(0,first_num) + next_string.substr(i,x.size());
				count = count + i - first_num;
				i = first_num;
				if(i >= next_string.size())
					break;
			}
			pre_char = next_string[i];
		}
		if(count != 0)
		{
			return count + clear_char(next_string);
		}
		else
		{
			return 0;
		}
		
	}
}

int max_clear_char(std::string &x)
{
	int max_num = 0;
	char insert_char[3] = {'A','B','C'};
	for(int i = 0;i < x.size();i++)
	{
		for(int j = 0;j < 3;j++)
		{
			std::string temp_str = x.substr(0,i+1) + insert_char[j] + x.substr(i+1, x.size());
			int temp = clear_char(temp_str);
			if(temp > max_num)
				max_num = temp;
		}
	}
	return max_num;
}
