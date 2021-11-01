#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<numeric>

using namespace std;
/*
1)
������� ��������������� ������ ����� �����. ���������� ����������� ������� insert_sorted, ������� ��������� ������ � ����� ����� � ��������� ����� ����� � ������������ ������� � �������,
����� ��������������� ���������� �����������.
���������� ��������� ������� insert_sorted, ������� ������ ���������� �������� � ����� �����������, ���������� ����� ��� ��������.
*/



template<typename T>
void insert_sorted(vector<T>& _cont, const T& _value) {
    auto const it = lower_bound(_cont.begin(), _cont.end(), _value);
    if (it == _cont.end())
    {
        _cont.push_back(_value);
    }
    else
    {
        _cont.insert(it, _value);
    }
}


template<typename T>
void printvec(std::vector<T>& vec)
{
    size_t num = 0;
    for (auto value : vec)
    {
        std::cout << num << " : " <<  value << std::endl;
        num++;
    }
}

/*

2)������������ ������, ��������� �� 100 ������������ �����, �������������� ����� �������� ����������� �������. �� ������ ����� ������� ����� �������� ������ ������ ����� �����, �������������� �������� ������, � ������� ����� �������� ������� ����� �����. �������� ������������ ������� �����. ���������� ������, ������� �������� �������� ������ �� ��������� � ���������� �� �������:
i=0N-1(ai-bi)2 ,
���:
N - ���������� ��������� � �������,
a - ������� ������� � �������� �������,
b - ������� ������� � ������ �������
*/


struct Round
{
    int operator() (float value)
    {
        return static_cast<int>(value);
    }
};

struct Diff
{
    float operator() (float value)
    {
        return pow((value - static_cast<int>(value)), 2);
    }
};


int main()
{
	vector<int> vec = { 1,3,5,7,12,15 };
    insert_sorted<int>(vec, 8);
    insert_sorted<int>(vec, 17);

    //printvec(vec);

    vector<float> analog_numbrs(100);
    vector<int> digit_numbers;
    vector<float> difference;
    generate(analog_numbrs.begin(), analog_numbrs.end(), []() {
        return rand()%100 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        });

    
    transform(analog_numbrs.begin(), analog_numbrs.end(), back_inserter(digit_numbers), Round());
    cout << " -------------------------- \n";
    printvec(analog_numbrs);
    cout << " -------------------------- \n";
    printvec(digit_numbers);

    transform(analog_numbrs.begin(), analog_numbrs.end(), back_inserter(difference), Diff());   
    cout << " -------------------------- \n";
    printvec(difference);



    float flaw = accumulate(difference.begin(), difference.end(), 0);

    cout << "Summ of square differences is : " << flaw << endl;

	return 0;
}
