//7
double pi = 3.14159265359;
cout << pi << endl;
// "3.14159"
cout << setprecision(7) << pi << endl;
// "3.141593"
cout << fixed << setprecision(7) << pi << endl;
// "3.1415927"

//9
int v = 220;
cout << v << endl;
// "220"
cout << setw(6) << v << endl;
// "   220"
cout << setw(6) << setfill('0') << v << endl;
// "000220"
cout << setw(6) << setfill('0') << left << v << endl;
// "220000"

//8
cout << hex << v << endl;
// "dc" (hex lowercase print)
cout << uppercase << v << endl;
// "DC" (HEX uppercase print)
cout << oct << v << endl;
// "334" (Octal print)
cout << bitset<8>(v) << endl;
// "11011100" (N-bit Binary Unsigned Int print)
