/*
Longest Increasing Subsequence
Complexity for LIS Algo -> O(NlogN)  
N-number of elements
*/

#include<bits/stdc++.h>
using namespace std;

// NOTE : aux is not necesserily the LIS but its length is same as LIS
int length_LIS(int arr[], int n)
{
    vector<int> aux;    //auxiliary vector stores the array elements likely to be LIS 
    for(int i = 0; i < n; i++) 
    {
        // Change lower_bound to upper_bound for non-decreasing subsequence 
        auto itr = lower_bound(aux.begin(), aux.end(), arr[i]);
        if (itr == aux.end()) 
            aux.push_back(arr[i]); // No element is larger than arr[i]
        else 
            *itr = arr[i]; // replace the element in aux with elemwnt just smaller than it.
    }
  return aux.size();

} 

void find_LIS(int arr[],int n)
{
    vector<int> aux(n, 0);
	vector<vector<int>> parent(n);

	aux[0] = arr[0];

	parent[0].push_back(arr[0]);
	int aux_size = 1;
	for (int i = 1; i < n; i++) 
    {

		auto it =lower_bound(aux.begin(), aux.begin() + aux_size, arr[i]);

		if (it == aux.begin() + aux_size) 
        {
			aux[aux_size] = arr[i];
						
			parent[aux_size] = parent[aux_size - 1];
			parent[aux_size].push_back(arr[i]);
			aux_size++;
		}
		else 
        {
			if (*it != arr[i]) {
				aux[it- aux.begin()] = arr[i];
				
				parent[it - aux.begin()][parent[it - aux.begin()].size() - 1] = arr[i];
			}
		}

	}

	cout << "length " << aux_size << endl;

	for (auto x : parent[aux_size - 1]) {
		cout << x << " ";
	}
}
 
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n= sizeof(arr)/sizeof(int);
    
    // Strictly increasing sub sequence
    cout << "Length of LIS is :" << length_LIS(arr,n) << endl;

    // Print the LIS
    find_LIS(arr,n);
}

// Intersting question :
// Given arr1[N], arr2[M]   1<M<N<10^5
// Find minimum elements you need to add in arr1 such that arr2 is a subsequence of arr1?
// Soln: Codenation 1 april 2020 : hint(use maps, LIS)
