// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/


//eg=> arr[] = 40 20 30 10 30
// now say i=1, k=2, j=4
// temp_ans = fun(arr, i, k) + fun(arr, k + 1, j) + arr[i-1]*arr[k]*arr[j]
// OR temp_ans = fun(arr, 1, 2) + fun(arr, 3, 4) + arr[0]*arr[2]*arr[4]  => because in the question, dimensionality of a matrix is arr[x-1]*arr[x]


#include <bits/stdc++.h>
using namespace std;

int Solve(int arr[], int i, int j) {
	if (i >= j)  //base condn...will NOT work for i==j also....since only 1 sized array can NOT give dimensions of a matrix (we need atleast 2 elements to give size of a matrix)...thus j>i is compulsory 
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) //IMP=> constraints on k => till (j-1) //because the 2nd set is (k+1 to j) => ie. at last, it will be (j to j)
	{  
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];  // NOT arr[i] =>see main() function
		ans = min(ans, temp_ans);  // take temp minimum value from the temp answers
	}

	return ans;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << Solve(arr, 1, n - 1) << endl;  //i can NOT start from 0...since dimensions of matrix are arr[i-1]*arr[i]
	return 0;
}
