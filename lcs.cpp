/*
 * =====================================================================================
 *
 *       Filename:  lcs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/14 14:18:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int LEN = 201;

vector<vector<int> > vd(LEN, vector<int>(LEN));
vector<vector<int> > vp(LEN, vector<int>(LEN));

void lcs_extend(string x, int m, string y, int n) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i-1] == y[j-1]) {
                vd[i][j] = vd[i-1][j-1] + 1;
                vp[i][j] = 1;
            }
            else {
                if (vd[i-1][j] >= vd[i][j-1])
                {
                    vd[i][j] = vd[i-1][j];
                    vp[i][j] = 2;
                }
                else {
                    vd[i][j] = vd[i][j-1];
                    vp[i][j] = 3;

                }
            }
        }
    }
}

void lcs_print(const string &x, const int m, const string &y, const int n) {
    if (m == 0 || n == 0 ) return;
    if (vp[m][n] == 1) {
        lcs_print(x, m-1, y, n-1);
        cout << x[m-1];
    }
    else if(vp[m][n] == 2) {
        lcs_print(x , m-1, y, n);
    }
    else {
        lcs_print(x, m, y, n-1);
    }
}

void vp_vd_print(const int m, const int n) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << vd[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << vp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    lcs_extend(str1, str1.size(), str2, str2.size());
    cout << vd[str1.size()][str2.size()] << endl;
    lcs_print(str1, str1.size(), str2, str2.size());
    cout << endl;
    vp_vd_print(str1.size(), str2.size());
    return 0;
}
