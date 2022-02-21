#include <bits/stdc++.h>
using namespace std;
int derangements = 0;
int flag = 0;
vector<string> repeated_derangements;
// Function to print derangements of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
int permute(string a, int l, int r,string original)
{
	// Check for valud derangement
	if (l == r){
        for(int i = 0;i < original.size();i++){
            if(a[i] == original[i]){
                flag = 1;
            }
        }
        if(!flag){
            int flag2 = 1;
            for(int k = 0;k < repeated_derangements.size();k++){
                if(repeated_derangements[k] == a){
                    flag2 = 0;
                }
            }
            if(flag2){
                repeated_derangements.push_back(a);
                derangements++;
            }
        }
        flag = 0;
    }
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l+1, r,original);

			//backtrack
			swap(a[l], a[i]);
		}
	}
    return derangements;
}

int main()
{
    string original, modified;
    cout<<"Enter string\n";
    cin>>original;
    modified = original;
    derangements = permute(original, 0, original.size() - 1,original);
    cout<<derangements;
    return 0;
}

