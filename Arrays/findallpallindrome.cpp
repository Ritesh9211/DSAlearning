#include<bits/stdc++.h>
#define M 26
using namespace std;

bool isPalin(string str,int* freq){

    memset(freq, 0, M * sizeof(int));
    int n = str.size();
    for(int i = 0; i <n; i++)
        freq[str[i] - 'a']++;
    int oddfre=0;
    for(int i=0;i<26;i++){
        if(freq[i]%2!=0) oddfre++;
    }

    return (n%2==0 && oddfre==0) || (n%2==1 && oddfre==1);
 
}

string reverse(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}
void printAllPossiblePalindromes(string str)
{
    int freq[M];
 
    // checking whether letter can make palindrome or not
    if (!isPalin(str, freq))
        return;
 
    int l = str.length();
 
    // half will contain half part of all palindromes,
    // that is why pushing half freq of each letter
    string half = "";
    char oddC;
    for (int i = 0; i < M; i++)
    {
        /* This condition will be true at most once */
        if(freq[i] % 2 == 1)
            oddC = i + 'a';
 
        half += string(freq[i] / 2, i + 'a');

        /* new string object using the constructor of the 
        std::string class. The first parameter, freq[i] / 2, 
        specifies the number of characters to be included in 
        the string, while the second parameter, i + 'a', 
        determines the initial character of the string. The 
        newly created string is then appended to the 
        existing string half.
        */
    }
 
    /* palin will store the possible palindromes one by one */
    string palin;
 
    // Now looping through all permutation of half, and adding
    // reverse part at end.
    // if length is odd, then pushing oddCharacter also in mid
    do
    {
        palin = half;
        if (l % 2 == 1)
            palin += oddC;
        palin += reverse(half);
        cout << palin << endl;
    }
    while (next_permutation(half.begin(), half.end()));
}
int main(){
    string str = "aabcb";
    printAllPossiblePalindromes(str);
    return 0;
}