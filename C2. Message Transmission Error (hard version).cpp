https://codeforces.com/problemset/problem/2010/C2

/*
Let's break down the code step by step, explain it thoroughly, and walk through an example to illustrate how it works.

### Code Breakdown:

```cpp
#include<bits/stdc++.h>
using namespace std;
string s;
int fail[400000];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j;
    cin>>s;
```

1. **Includes and Global Variables**:
   - `#include<bits/stdc++.h>` is a common header file that includes almost all the standard libraries in C++.
   - `using namespace std;` lets you use standard C++ objects (e.g., `cin`, `cout`) without needing to prefix them with `std::`.
   - `string s;` is the input string.
   - `int fail[400000];` is an array that stores the **failure function** (also called the **prefix function**). The array length is set to 400,000 to accommodate large inputs.
   - `ios::sync_with_stdio(false)` and `cin.tie(0)` are optimizations for faster input and output.

```cpp
    cin >> s;
    n = s.length();
    fail[0] = 0;
    j = 0;
```
2. **Input and Initialization**:
   - The string `s` is taken as input.
   - `n` is set to the length of the string `s`.
   - The first value of the failure array (`fail[0]`) is initialized to `0` because the first character of a string has no proper prefix-suffix relationship.
   - `j = 0` initializes a pointer `j` for tracking the longest prefix-suffix match while processing the string.

```cpp
    for(i = 1; i < n; i++)
    {
        while(j > 0 && s[i] != s[j]) j = fail[j - 1];
        if(s[i] == s[j]) j++;
        fail[i] = j;
    }
```
3. **Computing the Failure Function (Prefix Function)**:
   - The loop iterates from `i = 1` to `n-1`, filling the `fail[]` array.
   - The failure function helps track the longest prefix that is also a suffix for every prefix of the string up to the current index `i`.
   
   Here's how it works:
   - **Mismatch handling**: If `s[i] != s[j]`, the algorithm looks at the previously computed `fail[j-1]` to reduce `j` to a smaller value where there might be a match.
   - **Match handling**: If `s[i] == s[j]`, `j` is incremented, indicating a longer matching prefix-suffix, and the value `fail[i]` is set to `j`.
   
   Essentially, `fail[i]` contains the length of the longest proper prefix of the substring `s[0...i]` which is also a suffix of the same substring.

```cpp
    if(fail[n-1] * 2 > n)
    {
        cout << "YES\n";
        for(i = 0; i < fail[n-1]; i++) cout << s[i];
        cout << '\n';
    }
    else cout << "NO\n";
```
4. **Checking for the Prefix**:
   - `fail[n-1]` gives the length of the longest prefix that is also a suffix for the entire string `s`.
   - The condition `fail[n-1] * 2 > n` checks if this prefix appears more than once in the string. This is because, if the length of this prefix-suffix is more than half the length of the string (`fail[n-1] * 2 > n`), it must appear at least twice (once as a prefix and once elsewhere in the string).
   
   - If the condition is true, the program prints "YES" and the prefix, which is the substring `s[0...fail[n-1]-1]`.
   - If the condition is false, it prints "NO".

```cpp
    return 0;
}
```
5. **End of Program**:
   - The program returns 0 and terminates.

---

### Example Walkthrough:

Let's take an example string: `ababab`.

1. **Input**:  
   The input string `s = "ababab"`.

2. **Failure Function Calculation**:
   - For `i = 1`: `s[1] != s[0]`, so `fail[1] = 0`.
   - For `i = 2`: `s[2] == s[0]`, so `j = 1`, and `fail[2] = 1`.
   - For `i = 3`: `s[3] == s[1]`, so `j = 2`, and `fail[3] = 2`.
   - For `i = 4`: `s[4] == s[2]`, so `j = 3`, and `fail[4] = 3`.
   - For `i = 5`: `s[5] == s[3]`, so `j = 4`, and `fail[5] = 4`.

   The failure array after processing the string is:  
   `fail[] = {0, 0, 1, 2, 3, 4}`.

3. **Checking the Condition**:
   - `fail[n-1] = fail[5] = 4`.  
   The condition `fail[n-1] * 2 > n` becomes `4 * 2 > 6`, which is true.

4. **Output**:
   Since the condition is true, the program prints "YES" and the longest prefix that is also a suffix, which is `"abab"`:
   ```
   YES
   abab
   ```

---

### Another Example:

For the string `abcabc`:

1. **Input**:  
   `s = "abcabc"`

2. **Failure Function Calculation**:
   - For `i = 1`: `s[1] != s[0]`, so `fail[1] = 0`.
   - For `i = 2`: `s[2] != s[0]`, so `fail[2] = 0`.
   - For `i = 3`: `s[3] == s[0]`, so `j = 1`, and `fail[3] = 1`.
   - For `i = 4`: `s[4] == s[1]`, so `j = 2`, and `fail[4] = 2`.
   - For `i = 5`: `s[5] == s[2]`, so `j = 3`, and `fail[5] = 3`.

   The failure array is:  
   `fail[] = {0, 0, 0, 1, 2, 3}`.

3. **Checking the Condition**:
   - `fail[n-1] = fail[5] = 3`.  
   The condition `fail[n-1] * 2 > n` becomes `3 * 2 > 6`, which is **false**.

4. **Output**:
   Since the condition is false, the program prints "NO":
   ```
   NO
   ```

---

### Summary:

- The code computes the **failure function** (or **prefix function**) using an algorithm similar to the **KMP string matching** algorithm.
- The condition `fail[n-1] * 2 > n` ensures that the longest prefix which is also a suffix appears at least twice in the string.
- Based on this condition, the program either prints "YES" and the prefix or "NO" if no such prefix exists.


*/
#include<bits/stdc++.h>
using namespace std;
string s;
int fail[400000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i,j;
	cin>>s;
	n=s.length();
	fail[0]=0;
	j=0;
	for(i=1;i<n;i++)
	{
		while(j>0&&s[i]!=s[j])j=fail[j-1];
		if(s[i]==s[j])j++;
		fail[i]=j;
	}
	if(fail[n-1]*2>n)
	{
		cout<<"YES\n";
		for(i=0;i<fail[n-1];i++)cout<<s[i];
		cout<<'\n';
	}
	else cout<<"NO\n";
	return 0;
}
 