#include<iostream>
#include<cstring>
using namespace std;
using ll = unsigned long long;
const int N = 998244353;

typedef struct m {
    ll Matrix[3][3];
}mat;

mat m;

void matirx_multiply(mat m, mat m1, mat &answer)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ans = 0;
            for (int k = 0; k < 3; k++)
            {
                ans += (m.Matrix[i][k] % N) * (m1.Matrix[k][j] % N);
            }
            answer.Matrix[i][j] = ans % N;
        }
    }
    return;
}

void InitMat(mat& m, int a, int b, int c)
{
    m.Matrix[0][0] = a;
    m.Matrix[0][1] = b;
    m.Matrix[0][2] = 1;
    m.Matrix[1][0] = 1;
    m.Matrix[2][2] = 1;
    return;
}

void copy(mat& desti, mat source)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            desti.Matrix[i][j] = source.Matrix[i][j];
        }
    }
    return;
}

ll fast_power(mat m, ll n, ll f1, ll f2, ll c)
{
    mat answer;
    memset(answer.Matrix, 0, sizeof(answer.Matrix));
    //copy(answer, m);
    answer.Matrix[0][0] = 1;
    answer.Matrix[1][1] = 1;
    answer.Matrix[2][2] = 1;
    while (n)
    {
        if (n & 1) {
            matirx_multiply(answer, m, answer);
        }
        matirx_multiply(m, m, m);
        n >>= 1;
    }
    ll output;
    output = ((answer.Matrix[0][0] % N) * (f2 % N) + (answer.Matrix[0][1] % N) * (f1 % N) + (answer.Matrix[0][2] % N) * (c % N)) % N;
    return output;
}


int main()
{
    freopen("data.txt", "r", stdin);
    freopen("my.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, f1, f2, a, b, c;
    cin >> n >> f1 >> f2 >> a >> b >> c;
    memset(m.Matrix, 0, sizeof(m.Matrix));
    InitMat(m, a, b, c);
    ll ans = 0;
    if (n == 1) ans = f1;
    if (n == 2) ans = f2;
    else ans = fast_power(m, n - 2, f1, f2, c);
    cout << ans << '\n';
    return 0;
}