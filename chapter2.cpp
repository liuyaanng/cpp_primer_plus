#include <iostream>

using namespace std;

void test1(){
	cout << "MY name is GeekOcean!" << endl;
	cout << "Address: You Guass" << endl;
}

void test2(){
	int long_num;
	cout << "Enter long num: ";
	cin >> long_num;
	cout << "bit is : " << long_num * 220 << endl;
}

void test4(){
	int years;
	cout << "Enter years: ";
	cin >> years;
	cout << "There are " << years * 12 << "Month. " << endl;
}

void test5(){
	int temp;
	cout << "Please enter a Celsius value: ";
	cin >> temp;
	cout << temp << "degrees Celsius is " << (int)(temp * 1.8 + 32) << "degrees Fahrenheit" << endl;
}

void test6(){
	double light_year;
	cout << "Enter the number of light years: ";
	cin >> light_year;
	cout << light_year << "light years = " << (int)(light_year * 63240) << "astronomical units. " << endl;
}

void test7(int hour, int min){
	cout << "Enter the number of hours: ";
	cin >> hour;
	cout << "Enter the number of minutes: ";
	cin >> min;
	cout << "Time: " << hour << ':' << min;
}

int main(){
	// test1();
	// test2();
	// test4();
	// test5();
	// test6();
	int hour, min;
	test7(hour, min);
	return 0;
}
