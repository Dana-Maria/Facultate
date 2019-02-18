#include <iostream>

using namespace std;

int ordine = 1;

int getCadran(int x, int y, int k)
{
    int power = (1 << (k-1));

    if (x >= 0 && x < power && y >= 0 && y < power)
        return 1;
    if (x >= 0 && x < power && y >= power && y < (2 * power) )
        return 2;
    if (x >= power && x < (2 * power ) && y >= 0 && y < power)
        return 3;
    if (x >= power && x < (2 * power) && y >= power && y < (2 * power))
        return 4;

    return -1;
}

void divide(int xEmpty, int yEmpty, int** mat, int k, int xStSus, int yStSus) {

    if (k == 1) {

        for (int i = xStSus; i < xStSus + 2; i++)
            for (int j = yStSus; j < yStSus + 2; j++)
                if (i != xEmpty || j != yEmpty)
                    mat[i][j] = ordine;
        ordine++;
    }

    else {
        int powerOf2 = ( 1 << (k - 1) ); // 2 ^ (k-1)

        /*
            divide(powerOf2 - 1, powerOf2 - 1, mat, k - 1, 0, 0); // top left
            divide(powerOf2 - 1, powerOf2, mat, k - 1, 0, powerOf2); // top right
            divide(powerOf2, powerOf2 - 1, mat, k - 1, powerOf2, 0); // bottom left
            divide(powerOf2, powerOf2, mat, k - 1, powerOf2, powerOf2); // bottom right */

        int cadran = getCadran(xEmpty, yEmpty, k);
        //cout << endl << cadran << " " << ordine;

        if (cadran == 1) {

            divide(xEmpty, yEmpty, mat, k - 1, 0, 0); // top left
            divide(powerOf2 - 1, powerOf2, mat, k - 1, 0, powerOf2); // top right
            divide(powerOf2, powerOf2 - 1, mat, k - 1, powerOf2, 0); // bottom left
            divide(powerOf2, powerOf2, mat, k - 1, powerOf2, powerOf2); // bottom right

            mat[powerOf2 - 1][powerOf2] = ordine;
            mat[powerOf2][powerOf2 - 1] = ordine;
            mat[powerOf2][powerOf2] = ordine;
            ordine++;
        }

        else if (cadran == 2) {

            divide(powerOf2 - 1, powerOf2 - 1, mat, k - 1, 0, 0); // top left
            divide(xEmpty, yEmpty, mat, k - 1, 0, powerOf2); // top right
            divide(powerOf2, powerOf2 - 1, mat, k - 1, powerOf2, 0); // bottom left
            divide(powerOf2, powerOf2, mat, k - 1, powerOf2, powerOf2); // bottom right

            mat[powerOf2 - 1][powerOf2 - 1] = ordine;
            mat[powerOf2][powerOf2 - 1] = ordine;
            mat[powerOf2][powerOf2] = ordine;
            ordine++;
        }

        else if (cadran == 3) {

            divide(powerOf2 - 1, powerOf2 - 1, mat, k - 1, 0, 0); // top left
            divide(powerOf2 - 1, powerOf2, mat, k - 1, 0, powerOf2); // top right
            divide(xEmpty, yEmpty, mat, k - 1, powerOf2, 0); // bottom left
            divide(powerOf2, powerOf2, mat, k - 1, powerOf2, powerOf2); // bottom right

            mat[powerOf2 - 1][powerOf2 -1] = ordine;
            mat[powerOf2 - 1][powerOf2] = ordine;
            mat[powerOf2][powerOf2] = ordine;
            ordine++;
        }

        else if (cadran == 4) {
            divide(powerOf2 - 1, powerOf2 - 1, mat, k - 1, 0, 0); // top left
            divide(powerOf2 - 1, powerOf2, mat, k - 1, 0, powerOf2); // top right
            divide(powerOf2, powerOf2 - 1, mat, k - 1, powerOf2, 0); // bottom left
            divide(xEmpty, yEmpty, mat, k - 1, powerOf2, powerOf2); // bottom right

            mat[powerOf2 - 1][powerOf2 - 1] = ordine;
            mat[powerOf2 - 1][powerOf2] = ordine;
            mat[powerOf2][powerOf2 - 1] = ordine;
            ordine++;
        }
    }
}

int main()
{
    int n, x, y;

    cin >> n >> x >> y;

    int** mat;
    int powerOf2 = ( 1 << n );

    mat = new int*[powerOf2];
    for (int i = 0; i < powerOf2; i++)
        mat[i] = new int[powerOf2];

    mat[x - 1][y - 1] = 0;
    divide(x - 1, y - 1, mat, n, 0, 0);

    cout << endl;
    for (int i = 0; i < powerOf2; i++) {
        for (int j = 0; j < powerOf2; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
