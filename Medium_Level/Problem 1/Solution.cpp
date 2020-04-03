#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int cnt=0;
    int cr=0,cc=0;  
    int arr[8][2];
    for(int i =0;i<8;i++)
    {
        arr[i][0]=0;
        arr[i][1]=0;
    }
    for(int i =0;i<k;i++)
    {
        cr = obstacles[i][0];
        cc = obstacles[i][1];
        if(cr==r_q)
        {
            if(cc<c_q&&arr[1][1]<cc)
            {
                arr[1][0]= cr;
                arr[1][1]= cc;
            }
            else if(cc>c_q&&(arr[0][1]>cc||arr[0][1]==0))
            {
                arr[0][0]= cr;
                arr[0][1]= cc;
            }
        }
        else if(cc==c_q)
        {
            if(cr<r_q&&arr[3][0]<cr)
            {
                arr[3][0]= cr;
                arr[3][1]= cc;
            }
            else if(cr>r_q&&(arr[2][0]>cr||arr[2][0]==0))
            {
                arr[2][0]= cr;
                arr[2][1]= cc;
            }
        }
        else if(abs(c_q-cc)==abs(r_q-cr))
        {
            if(c_q-r_q==cc-cr)
            {
                if(cr<r_q&&arr[5][0]<cr)
                {
                    arr[5][0]= cr;
                    arr[5][1]= cc;
                }
                else if(cr>r_q&&(arr[4][0]>cr||arr[4][1]==0))
                {
                    arr[4][0]= cr;
                    arr[4][1]= cc;
                }
            }
            else if(cr<r_q&&arr[7][0]<cr)
            {
                arr[7][0]= cr;
                arr[7][1]= cc;
            }
            else if(cr>r_q&&(arr[6][0]>cr||arr[6][1]==0))
            {
                arr[6][0]= cr;
                arr[6][1]= cc;
            }
        }
        
    }
    if(arr[0][1]!=0)
    {
        cnt+= arr[0][1] - c_q -1;    
    }
    else
    {
        cnt += n-c_q;
    }
    cnt+= c_q-arr[1][1]-1;
    if(arr[2][1]!=0)
    {
        cnt+= arr[2][0] - r_q -1;
    }
    else
    {
        cnt += n-r_q;
    }
    cnt+= r_q-arr[3][0]-1;
    if(arr[4][1]!=0)
    {
        cnt+= arr[4][0] - r_q -1;
    }
    else
    {
        cnt += (r_q>c_q)?n-r_q:n-c_q;
    }
    if(arr[5][1]!=0)
    {
        cnt+= r_q - arr[5][0] -1;
    }
    else
    {
        cnt += (r_q<c_q)?r_q-1:c_q-1;
    }
    if(arr[6][1]!=0)
    {
        cnt+= arr[6][0] - r_q -1;
    }
    else
    {
        cnt += ((n-r_q)<(c_q-1))?n-r_q:c_q-1;
    }
    if(arr[7][1]!=0)
    {
        cnt+= r_q - arr[7][0] -1;
    }
    else
    {
        cnt += ((r_q-1)<(n-c_q))?r_q-1:n-c_q;
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);
    
    fout << result << "\n";
    
    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
