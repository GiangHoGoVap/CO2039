#include <iostream>
#include <vector>
using namespace std;

vector<int> divisible3and5(int limit){
	vector<int> ans;
	for (int i=1; i<=limit; i++){
		if (i % 3 == 0 && i % 5 == 0){
			ans.push_back(i);
		}
	}
	return ans;
}

int sum3or5(int limit){
	int sum = 0;
	for (int i=1; i<=limit; i++){
		if (i % 3 == 0 || i % 5 == 0){
			sum += i;
		}
	}
	return sum;
}

int countNotDivisible3or5(int limit){
	int cnt = 0;
	for (int i=1; i<=limit; i++){
		if (i % 3 == 0 || i % 5 == 0) continue;
		cnt++;
	}
	return cnt;
}

int main(){
	int Limit;
	cout << "Input the limit: ";
	cin >> Limit;
	if (Limit >= 10 && Limit <= 150){
		vector<int> ans1 = divisible3and5(Limit);
		cout << "Numbers are divisible by both 3 and 5: ";
		bool firstTime = true;
		for (int i=0; i<ans1.size(); i++){
			if (!firstTime) cout << " ";
			cout << ans1[i];
			firstTime = false;
		}
		cout << endl;
		int ans2 = sum3or5(Limit);
		cout << "Sum of numbers being divisible by either 3 or 5: " << ans2 << endl;
		int ans3 = countNotDivisible3or5(Limit);
		cout << "Count of numbers not being divisble by 3 or 5: " << ans3 << endl;
	}
	return 0;
}
