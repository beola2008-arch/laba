#include <iostream>
#include <conio.h>
using namespace std;
void size() {
	cout << "Data size ""bool"":" << sizeof(bool) << endl
		<< "Data size ""char"":" << sizeof(char) << endl
		<< "Data size ""short int"":" << sizeof(short int) << endl
		<< "Data size ""int"":" << sizeof(int) << endl
		<< "Data size ""long int"":" << sizeof(long int) << endl
		<< "Data size ""float"":" << sizeof(float) << endl
		<< "Data size ""double"":" << sizeof(double) << endl
		<< "Data size ""long double"":" << sizeof(long double) << endl;
	_getch();
}

void dva() {
	int num;
	int order=sizeof(int)*8;
	unsigned int mask = 1 << (order - 1);
	cout << "Enter an int number" << endl;
	cin >> num;
	for (int i = 0; i < order; i++){
		cout << ((num & (mask >> i)) ? '1' : '0');
		if (i == 0)
			cout <<" ";
		else if ((i+1)%8==0)
			cout << " ";
	}
	cout << "\n";
	_getch();
}

void zapit()
{
    union
    {
        unsigned int num1;
        float num;
    };
	int order = sizeof(int) * 8;
    unsigned int mask = 1 << (order - 1);
    cout << "Enter an float number" << endl;
    cin >> num;
    for (int i = 0; i < order; i++){
        cout << ((num1 & (mask >> i)) ? '1' : '0');
        if (i == 0 || i == 8)
            cout << " ";
    }
    cout << "\n";
    _getch();
}
void duble() {
		union {
			int mass[2];
			double doubleParam;
		};
		int order = sizeof(int) * 8;
		unsigned int mask = 1 << (order - 1);
		cout << "Enter an double number" << endl;
		cin >> doubleParam;
		for (int j = 1; j >= 0; j--){
			for (int i = 0; i < order; i++){
				cout << ((mass[j] & (mask >> i)) ? '1' : '0');
				if (j == 1 && (i == 0 || i == 11))
					cout << " ";
			}
		}

		cout << "\n";
		_getch();
	}
int bita(unsigned int num, int bit, int operation) {
	unsigned int mask = 1 << bit;
	if (operation == 1)
		num = num | mask;
	else if (operation == 2)
		num = num & ~mask;
	else if (operation == 3)
		num = num ^ mask;
	return num;
}
unsigned long long duu(unsigned long long num, int bit, int operation){
    unsigned long long mask = 1 << bit;
    if (operation == 1)
        num = num | mask;
    else if (operation == 2)
        num = num & ~mask;
    else if (operation == 3)
        num = num ^ mask;
    return num;
}
void umno() {
    int num;
    cout << "Enter int number: ";
    cin >> num;
    num = num << 1;
    cout << "Result: " << num << endl;
    _getch();
}

int main() {
	int opros;
	cout << "What task would you like to complete?: ";
	cin >> opros;
	switch (opros) {
	case 1:
		size();
		main();
		break;
	case 2:
		dva();
		main();
		break;
	case 3:
		zapit();
		main();
		break;
	case 4:
		duble();
		main();
		break;
	case 5:
        int vid;
        cout << "1 - int" << endl;
        cout << "2 - float" << endl;
        cout << "3 - double" << endl;
        cout << "Choose type: ";
        cin >> vid;
        switch (vid) {
        case 1: {
            unsigned int num;
            int bit, operation;

            cout << "Enter number: ";
            cin >> num;
            cout << "Enter bit (0-31): ";
            cin >> bit;
            cout << "1-set, 2-clear, 3-invert: ";
            cin >> operation;

            int order = sizeof(int) * 8;
            unsigned int mask = 1 << (order - 1);

            num = bita(num, bit, operation);

            cout << "\nAfter: ";
            for (int i = 0; i < order; i++) {
                cout << ((num & (mask >> i)) ? '1' : '0');
            }

            cout << "\n";
            break;
        }

        case 2: {
            union {
                float num;
                unsigned int bits;
            };

            int bit, operation;

            cout << "Enter float number: ";
            cin >> num;
            cout << "Enter bit (0-31): ";
            cin >> bit;
            cout << "1-set, 2-clear, 3-invert: ";
            cin >> operation;

            int order = sizeof(float) * 8;
            unsigned int mask = 1U << (order - 1);

            bits = bita(bits, bit, operation);

            cout << "\nAfter: ";
            for (int i = 0; i < order; i++) {
                cout << ((bits & (mask >> i)) ? '1' : '0');

                if (i == 0 || i == 8)
                    cout << " ";
            }

            cout << "\nNew: " << num << endl;
            break;
        }

        case 3: {
            union {
                double num;
                unsigned long long bits;
            };

            int bit, operation;

            cout << "Enter double number: ";
            cin >> num;
            cout << "Enter bit (0-63): ";
            cin >> bit;
            cout << "1-set, 2-clear, 3-invert: ";
            cin >> operation;

            int order = sizeof(double) * 8;
            unsigned long long mask = 1 << (order - 1);

            bits = duu(bits, bit, operation);

            cout << "\nAfter: ";
            for (int i = 0; i < order; i++) {
                cout << ((bits & (mask >> i)) ? '1' : '0');

                if (i == 0 || i == 11)
                    cout << " ";
            }

            cout << "\nNew: " << num << endl;
            break;
        }

        default:
            cout << "Error, try again";
            _getch();
            break;
        }
    case 6:
        umno();
        main();
        break;

    default:
        cout << "Error, try again";
        _getch();
        main();
        break;
    }
    return 0;
}
