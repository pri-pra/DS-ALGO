#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef map<PII, int> MPI;

int T, N;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int x, y, xmin, xmax, ymin, ymax;
        int y_xmin, y_xmax;
        MPI seen;
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            seen[ PII(x, y) ] = i+1;
            if (i == 0) {
                xmin = xmax = x;
                ymin = ymax = y_xmin = y_xmax = y;
            } else {
                if (x <= xmin) {
                    if(x == xmin) y_xmin = min(y_xmin, y);
                    else y_xmin = y;
                    xmin = x;
                }

                if (x >= xmax) {
                    if (x == xmax)  y_xmax = max(y_xmax, y);
                    else y_xmax = y;
                    xmax = x;
                }
                ymin = min(y, ymin), ymax = max(y, ymax);
            }
        }
        if (seen[ PII(xmin, ymin) ] > 0)  printf("1\n%d NE\n", seen[ PII(xmin, ymin) ]);
        else if (seen[ PII(xmin, ymax) ] > 0) printf("1\n%d SE\n", seen[ PII(xmin, ymax) ]);
        else if (seen[ PII(xmax, ymax) ] > 0) printf("1\n%d SW\n", seen[ PII(xmax, ymax) ]);
        else if (seen[ PII(xmax, ymin) ] > 0) printf("1\n%d NW\n", seen[ PII(xmax, ymin) ]);
        else {
            printf("2\n");
            if (y_xmin <= y_xmax) {
                printf("%d NE\n", seen[ PII(xmin, y_xmin) ]);
                printf("%d SW\n", seen[ PII(xmax, y_xmax) ]);
            } else {
                printf("%d SE\n", seen[ PII(xmin, y_xmin) ]);
                printf("%d NW\n", seen[ PII(xmax, y_xmax) ]);
            }
        }
    }
    return 0;
}