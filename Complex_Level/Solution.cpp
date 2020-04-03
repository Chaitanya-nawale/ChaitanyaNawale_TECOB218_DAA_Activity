#include <bits/stdc++.h>

using namespace std;

string morganAndString(string a, string b) {
    string result;
    int i =0;
    int j =0;
    int k =0;
    int l =0;
    int alen = a.length();
    int blen = b.length();
    do
    {
        if(a[i]<b[j])
        {
            result +=a[i];
            i++;
        } 
        else if(a[i]==b[j])
        {
            k = i+1;
            l = j+1;
            while(a[k]==b[l]&&k<alen&&l<blen)
            {
                k++;
                l++;
            }
            if(a[k]<b[l]&&k<alen)
            {
                result +=a[i];
                i++;
            }
            else
            {
                result +=b[j];
                j++;    
            }
        }
        else
        {
            result +=b[j];
            j++;
        }
    }while(i<alen&&j<blen);
    while(i<alen)
    {
        result +=a[i];
        i++;
    }
    while(j<blen)
    {
        result +=b[j];
        j++;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
