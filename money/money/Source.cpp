//Blaze McNeill
//
// Money Check Lab
// 
// tens place in million and thousands broken
//
#include <iostream>
using namespace std;
void doones(int dollars)
{
	switch (dollars)
	{
	case 1: cout << "One ";
		break;
	case 2: cout << "Two ";
		break;
	case 3: cout << "Three ";
		break;
	case 4: cout << "Four ";
		break;
	case 5: cout << "Five ";
		break;
	case 6: cout << "Six ";
		break;
	case 7: cout << "Seven ";
		break;
	case 8: cout << "Eight ";
		break;
	case 9: cout << "Nine ";
	}
}
void dotens(int first)
{
	switch (first)
	{
	case 2: cout << "Twenty ";
		break;
	case 3: cout << "Thirty ";
		break;
	case 4: cout << "Forty ";
		break;
	case 5: cout << "Fifty ";
		break;
	case 6: cout << "Sixty ";
		break;
	case 7: cout << "Seventy ";
		break;
	case 8: cout << "Eighty ";
		break;
	case 9: cout << "Ninety ";
	}
}
void doteens(int second)
{
	switch (second)
	{
	case 0: cout << "Ten ";
		break;
	case 1: cout << "Eleven ";
		break;
	case 2: cout << "Twelve ";
		break;
	case 3: cout << "Thirteen ";
		break;
	case 4: cout << "Fourteen ";
		break;
	case 5: cout << "Fifteen ";
		break;
	case 6: cout << "Sixteen ";
		break;
	case 7: cout << "Seventeen ";
		break;
	case 8: cout << "Eightteen ";
		break;
	case 9: cout << "Nineteen";
	}
}
void do2digit(int dollars)
{
	int first, second;
	first = dollars / 10;
	second = dollars % 10;
	if (first == 1)
		doteens(second);
	else
	{
		dotens(first);
		doones(second);
	}
}
void doHundreds(int hundred)
{
	int seconds, hundreds;

	seconds = hundred % 100;
	//seconds = third; //test
	hundreds = hundred / 100;

	if (hundreds > 999.98)
	{
		do2digit(seconds);
		cout << "Hundreds";
	}

	else if (hundreds <= 999.98)
	{
	
		switch (hundreds)
		{
		case 1: cout << "One Hundred ";
			break;
		case 2: cout << "Two Hundred ";
			break;
		case 3: cout << "Three Hundred ";
			break;
		case 4: cout << "Four Hundred ";
			break;
		case 5: cout << "Five Hundred ";
			break;
		case 6: cout << "Six Hundred ";
			break;
		case 7: cout << "Seven Hundred ";
			break;
		case 8: cout << "Eight Hundred ";
			break;
		case 9: cout << "Nine Hundred ";

		}
	}
	do2digit(seconds);

}
void doThousands(int thou)
{
	int hundreds, thous, hundred;

	hundreds = thou % 1000;

	thous = thou / 1000;
	hundred = hundreds % 1000;


	if (thou > 9999)
	{
		doHundreds(hundreds);
		cout << " Thousand ";
	}
	else if (thou <= 9999.98)
	{
		 switch (thous)
		 {
		 case 1: cout << "One Thousand ";
			 break;
		 case 2: cout << "Two Thousand ";
			 break;
		 case 3: cout << "Three Thousand ";
			 break;
		 case 4: cout << "Four Thousand ";
			 break;
		 case 5: cout << "Five Thousand ";
			 break;
		 case 6: cout << "Six Thousand ";
			 break;
		 case 7: cout << "Seven Thousand ";
			 break;
		 case 8: cout << "Eight Thousand ";
			 break;
		 case 9: cout << "Nine Thousand ";

		 }
	}
	
	doHundreds(hundred);
	
}
void doMillions(int mil)
{
	int thousands, mils, hundreds;

	thousands = mil % 1000000;

	mils = mil / 1000000;

	hundreds = thousands % 1000;

	if (mil > 9999999.98)
	{
		doHundreds(hundreds);
		cout << " Million ";
	}

	else if (mils <= 9999999.98)
	{
		switch (mils)
		{
		case 1: cout << "One Million ";
			break;
		case 2: cout << "Two Million ";
			break;
		case 3: cout << "Three Million ";
			break;
		case 4: cout << "Four Million ";
			break;
		case 5: cout << "Five Million ";
			break;
		case 6: cout << "Six Million ";
			break;
		case 7: cout << "Seven Million ";
			break;
		case 8: cout << "Eight Million ";
			break;
		case 9: cout << "Nine Million ";

		}
	}
	doThousands(thousands);

}
int main()
{
	double dollars;
	int cents;

	cout << "Amount? ";
	cin >> dollars;
	cout << endl;

	while (dollars != 0)
	{
		cents = (dollars * 100);
		if (cents == 100)
		{
			cents = 0;
			dollars++;
		}
		else
			cents %= 100; 

		//thousands and stuff is broken

		if (dollars == 1.00)
			cout << "Dollar and No Cents";

		else if (dollars == 1000000000)
			cout << "One Billion Dollars and No Cents";

		else if (dollars >= 100000)
		{
		
			doMillions(dollars);
			cout << " Dollars and ";
			//millions
		}

		else if (dollars >= 1000) {
		
			doThousands(dollars);
			cout << " Dollars and ";
			//thousands

		}
		

		else if (dollars >= 100) {
			doHundreds(dollars);
			cout << " Dollars and ";
			//hundreds
		}
		//spacing

		else if (dollars >= 10)
			do2digit(dollars);

		if (cents != 0) 
		{
			do2digit(cents);
			cout << " Cents ";
		}
		else
			cout << " No Cents ";

		cout << "\n\nAmount? ";
		cin >> dollars;
		cout << endl;
	}
}