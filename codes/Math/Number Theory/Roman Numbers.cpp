//32
string decimalToRoman(int n){
	int d, b = 0;
	string ans = "";
	vector<vector<char>> datos = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', '\0'}};
	int miles = n / 1000;
	do{
		string tmp = "";
		d = n % 10;
		n /= 10;
		if(b < 3){
			if(0 <= d && d <= 3){
				tmp.append(d, datos[b][0]);
			}else if(d == 4){
				tmp += datos[b][0];
				tmp += datos[b][1];
			}else if(5 <= d && d <= 8){
				tmp += datos[b][1];
				tmp.append(d - 5, datos[b][0]);
			}else if(d == 9){
				tmp += datos[b][0];
				tmp += datos[b + 1][0];
			}
		}else{
			tmp.append(miles, 'M');
			ans = tmp + ans;
			break;
		}
		ans = tmp + ans;
		b++;
	}while(n != 0);
	return ans;
}

//21
int romanToDecimal(string n){
	int ans = 0;
	char curr, prev;
	bool f = false;
	map<char, int> datos = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	for(int i = n.size() - 1; i >= 0; i--){
		curr = n[i];
		if(i > 0) prev = n[i - 1];
		if(curr == 'V' && prev == 'I') ans += 4, f = true;
		else if(curr == 'X' && prev == 'I') ans += 9, f = true;
		else if(curr == 'L' && prev == 'X') ans += 40, f = true;
		else if(curr == 'C' && prev == 'X') ans += 90, f = true;
		else if(curr == 'D' && prev == 'C') ans += 400, f = true;
		else if(curr == 'M' && prev == 'C') ans += 900, f = true;
		else{
			if(!f) ans += datos[curr];
			f = false;
		}
	}
	return ans;
}
