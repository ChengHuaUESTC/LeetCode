/*
 * =====================================================================================
 *
 *       Filename:  heap_sequence.cpp
 *
 *    Description:  The N largest of N * N
 *
 *        Version:  1.0
 *        Created:  07/04/14 21:19:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAXN = 100;
int N;
int A[MAXN], B[MAXN];

typedef struct node_t{
    int sum;
    int a;
    int b;
    bool operator>(const node_t &other) const {
        return sum > other.sum;
    }
}node_t;

void k_merge() {
    sort(A, A + N);
    sort(B, B + N);
    priority_queue<node_t, vector<node_t>, greater<node_t> > q;
    
    for ( int i = 0; i < N; ++i ) {
        node_t node;
        node.sum = A[0] + B[i];
        node.a = 0;
        node.b = i;
        q.push(node);
    }

    for ( int i = 0; i < N; ++i ) {
        node_t node = q.top(); q.pop();
        cout << node.sum << endl;
        node_t node1;
        node1.sum = A[node.a + 1] + B[node.b];
        node1.a = node.a + 1;
        node1.b = node.b;
        q.push(node1);
    }
}

int main() {
    cin >> N;
    int tmp;
    for (int i = 0; i < N; ++i ) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i ) {
        cin >> B[i];
    }
    k_merge();
    return 0;
}
