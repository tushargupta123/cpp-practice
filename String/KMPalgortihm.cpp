// Longest Proper Prefix Suffix array
// proper prefix of "abc" => "","a","ab"       => proper means of length less than that of string
// suffix of "abc" => "","c","bc","abc"

// lps[] we check for longest length of proper prefix that matches with suffix
// also note that lps[0] is always 0 and lps[1] is 1 if str[0]==str[1]
// ex - "abacabad"
// lps[] = {0,0,1,0,1,2,3,0}

// Program for generating LPS[]

#include<iostream>
using namespace std;

int* lps(string str){
    int n = str.length();
    int *lpsArr = new int[n];
    int len = 0;
    int i=1;
    lpsArr[0] = 0;
    while(i<n){
        if(str[i] ==str[len]){
            len++;
            lpsArr[i] = len;
            i++;
        }else{
            if(len == 0){
                lpsArr[i] = 0;
                i++;
            }else{
                len = lpsArr[len-1];
            }
        }
    }
    return lpsArr;
}

// KMP algortihm is also used for searching pattern in string           -> O(n)  time     => n = length of string
//                                                                      -> O(m)  space     => m = length of pattern
// it is same as improved naive algorithm but the difference is when a pattern is not matched then we dont have to start from beginning of the pattern
// we can take help of lpsArr to know from where we have to start

int main(){
    string str = "ababcababaad";
    string pat = "ababa";
    int *lpsArr = lps(pat);
    int n = str.length();
    int m = pat.length();
    int i=0,j=0;
    while(i<n){
        if(pat[j]==str[i]){
            i++;
            j++;
        }else if(i<n && pat[j]!=str[i]){
            if(j==m){
                cout<<(i-j)<<" ";
                j = lpsArr[j-1];
            }else{
                if(j==0){
                    i++;
                }else{
                    j = lpsArr[j-1];
                }
            }
        }
    }
}