#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum enRunApp { enStar = 1, enExit = 2 };
enum enBase_Conv { enBase16 = 1, enBase10 = 2, enBase8 = 3, enBase2 = 4 };
enum enTo_Base_Conv { enTo_Base16 = 1, enTo_Base10 = 2, enTo_Base8 = 3, enTo_Base2 = 4 };

string GlobaelNumber;
int _Base;

int ReadOptionBase_Convertion();
void Project();


void ClearSkrean()
{
	system("cls");
	system("color 0F");
}

void Go_BackTo_Star_Menu()
{
	cout << endl << "Preass To Any Key To Go Back To Start Skrean ..." << endl; 
	system("pause>0");
	Project();
}

int Digits_Number_In_Intger(char Digit)
{
	switch (Digit)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': case 'a': return 10;
	case 'b': case 'B': return 11;
	case 'c': case 'C': return 12;
	case 'D': case 'd': return 13;
    case 'E': case 'e': return 14;
	case 'F': case 'f': return 15;
	}
}

string Digits_Number_In_Decimael_To_Hex(short Digits)
{
	string DigitsInHex[] = { "","1","2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"A" ,"B" ,"C","D","E","F" };
	return DigitsInHex[Digits ];
}

string Convert_Base_X_To_Base_16()
{
	unsigned long long LongGlobaelNumber_In_10 = stoi(GlobaelNumber);

	string NumberIN_16 = "";

	do
	{
		if (LongGlobaelNumber_In_10 % 16 != 0)
		{
			NumberIN_16 = (Digits_Number_In_Decimael_To_Hex(LongGlobaelNumber_In_10 % 16)) + NumberIN_16;
		}
		else
		{
			NumberIN_16 = "0" + NumberIN_16;
		}
		
		LongGlobaelNumber_In_10 /= 16;

	} while (LongGlobaelNumber_In_10 != 0);

	GlobaelNumber = NumberIN_16;
	return GlobaelNumber;
}

string Convert_Base_X_To_Base_8()
{
	unsigned long long LongGlobaelNumber_In_10 = stoi(GlobaelNumber);


	string NumberIN_8 = "";

	do
	{
		NumberIN_8 = to_string(LongGlobaelNumber_In_10 % 8)+ NumberIN_8;

		LongGlobaelNumber_In_10 /= 8;

	} while (LongGlobaelNumber_In_10 != 0);

	GlobaelNumber = NumberIN_8;
	return GlobaelNumber;
}

string Convert_Base_X_To_Base_2()
{
	  unsigned long long LongGlobaelNumber_In_10 = stoi(GlobaelNumber);

	string NumberIN_2 = "";
	
	do
	{
		NumberIN_2 = to_string(LongGlobaelNumber_In_10 % 2) + NumberIN_2;
		LongGlobaelNumber_In_10 /= 2;

	} while (LongGlobaelNumber_In_10 !=0);

	GlobaelNumber = NumberIN_2;
	return GlobaelNumber;
}

string Convert_Base_X_To_Base_10(short Base)
{
	int sum = 0, power = 0;
	string NewNumber = "";

	for (int i = GlobaelNumber.size() - 1; i >= 0; i--)
	{
		sum += Digits_Number_In_Intger(GlobaelNumber[i]) * pow(Base, power);
		power++;
	}
	GlobaelNumber = to_string(sum);

	return GlobaelNumber;
}

void Lanch_Converter_Menu_Skrean(enTo_Base_Conv Base_Conv)
{

	switch (Base_Conv)
	{
	case enTo_Base_Conv::enTo_Base16:
	{
		GlobaelNumber = Convert_Base_X_To_Base_10(_Base);
		Convert_Base_X_To_Base_16();
		break;
	}
	case enTo_Base_Conv::enTo_Base10:
	{
		Convert_Base_X_To_Base_10(_Base);
		break;
	}case enTo_Base_Conv::enTo_Base8:
	{
		GlobaelNumber = Convert_Base_X_To_Base_10(_Base);
		Convert_Base_X_To_Base_8();
		break;
	}case enTo_Base_Conv::enTo_Base2:
	{
		GlobaelNumber = Convert_Base_X_To_Base_10(_Base);
		Convert_Base_X_To_Base_2();
		break;
	}
	}

}

void Converter_Menu_Skrean()
{
	ClearSkrean();

	cout << "===========================================" << endl;
	cout << "           Converter Menu Skrean           " << endl;
	cout << "===========================================" << endl;
	cout << "    [1]  Convert To Base 16 .              " << endl;
	cout << "    [2]  Convert To Base 10 .              " << endl;
	cout << "    [3]  Convert To Base 8  .              " << endl;
	cout << "    [4]  Convert To Base 2  .              " << endl;
	cout << "===========================================" << endl;

	cout << endl << "Your Number Is : " << GlobaelNumber << endl;

	short Base = ReadOptionBase_Convertion();

	Lanch_Converter_Menu_Skrean((enTo_Base_Conv)Base);

	cout << endl << "Your New Number In Base " << Base << " Is : " <<
		GlobaelNumber << endl;


	Go_BackTo_Star_Menu();
}

void PrintBaseConvertSkeran(short Base)
{

	cout << "===========================================" << endl;
	cout << "                   Base " << Base << endl;
	cout << "===========================================" << endl;


}

int ReadOptionBase_Convertion()
{
	short number = 0;

	do
	{
		cout << endl << "Pleas Enter Your Choice ? [1 to 4] ? ";
		cin >> number;
	} while (!(number == 1 || number == 2 || number == 3 || number == 4));

	return number;
}

bool IsExit_Digits_In_Base_X(char Digits, short Base)
{
	switch (Base)
	{

	case  16:
	{
		return ((Digits >= '0' && Digits <= '9')
			|| (Digits >= 'A' && Digits <= 'F')
			|| (Digits >= 'a' && Digits <= 'f'));
	}
	case  10:
	{
		return ((Digits >= '0' && Digits <= '9'));
	}
	case  8:
	{
		return ((Digits >= '0' && Digits <= '7'));
	}
	case  2:
	{
		return ((Digits >= '0' && Digits <= '1'));
	}
	}

}

bool IsExit_Number_In_Base_X(string Number, short Base)
{

	for (int i = 0; i < Number.size(); i++)
	{
		if (!IsExit_Digits_In_Base_X(Number[i], Base))
		{
			return false;
		}

	}
	return true;
}

void ReadNumber(short Base)
{

	do
	{
		cout << "\nPleas Enter Your Number in Base " << Base << " ? " << endl;
		getline(cin >> ws, GlobaelNumber);

	} while (!IsExit_Number_In_Base_X(GlobaelNumber, Base));


}

void Base_2_Sckrean()
{
	PrintBaseConvertSkeran(2);
	ReadNumber(2);
}
void Base_8_Sckrean()
{
	PrintBaseConvertSkeran(8);
	ReadNumber(8);
}
void Base_10_Sckrean()
{
	PrintBaseConvertSkeran(10);
	ReadNumber(10);
}
void Base_16_Sckrean()
{
	PrintBaseConvertSkeran(16);
	ReadNumber(16);
}

void Lanch_BaseConvertion_Go(enBase_Conv Base_Conv)
{

	switch (Base_Conv)
	{
	case enBase_Conv::enBase16:
	{
		ClearSkrean();
		Base_16_Sckrean();
		Converter_Menu_Skrean();
		break;
	}
	case enBase_Conv::enBase10:
	{
		ClearSkrean();
		Base_10_Sckrean();
		Converter_Menu_Skrean();
		break;
	}case enBase_Conv::enBase8:
	{
		ClearSkrean();
		Base_8_Sckrean();
		Converter_Menu_Skrean();
		break;
	}case enBase_Conv::enBase2:
	{
		ClearSkrean();
		Base_2_Sckrean();
		Converter_Menu_Skrean();
		break;
	}
	}

}

void BaseConvertion_Go()
{

	ClearSkrean();

	cout << "\n\n\n\n\n\n\n\n\n\   ";
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t\t|              Your Number Base           |" << endl;
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t\t|         [1] Base 16 .                   | " << endl;
	cout << "\t\t\t\t\t\t|         [2] Base 10 .                   | " << endl;
	cout << "\t\t\t\t\t\t|         [3] Base 8  .                   |" << endl;
	cout << "\t\t\t\t\t\t|         [4] Base 2  .                   | " << endl;
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\n\n\n\n";
	int base = ReadOptionBase_Convertion();


	if (base == 1)
		_Base = 16;
	else if (base == 2)
		_Base = 10;
	else if (base == 3)
		_Base = 8;
	else if (base == 4)
		_Base = 2;



	Lanch_BaseConvertion_Go((enBase_Conv)base);

}

void SwitchOpstionRunApp(enRunApp RunApp)
{
	switch (RunApp)
	{
	case enRunApp::enStar:
	{
		ClearSkrean();
		BaseConvertion_Go();
		break;
	}
	case enRunApp::enExit:
	{
		ClearSkrean();
		cout << "Good Bay Sur " << endl;
		break;
	}
	}
}

int ReadOptionRunApp()
{
	short number = 0;

	do
	{
		cout << endl << "Pleas Enter Your Choice ? [1 to 2] ? ";
		cin >> number;
	} while (!(number == 1 || number == 2));

	return number;
}

void Project()
{
	ClearSkrean();
	cout << "\n\n\n\n\n\n\n\n\n\   ";
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t\t|               Run Appliction            |" << endl;
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\t\t\t\t\t\t|     [1] Star             [2] Exit       | " << endl;
	cout << "\t\t\t\t\t\t===========================================" << endl;
	cout << "\n\n\n\n";

	SwitchOpstionRunApp((enRunApp)ReadOptionRunApp());

}

int main()
{
	Project();
	return 0;
}