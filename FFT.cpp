// https://atcoder.jp/contests/atc001/tasks/fft_c
#include <complex>
void fft(int n, int s, bool eo, complex<double> *x, complex<double> *y) {
    const int m = n / 2;
    const double pi = acos(-1);
    const double theta = 2 * pi / n;
    if(n == 1) {
        if(eo) {
            for(int q = 0; q < s; q++) {
                y[q] = x[q];
            }
        }
    } else {
        for(int p = 0; p < m; p++) {
            const complex<double> wp = polar(1.0, -p * theta);
            for(int q = 0; q < s; q++) {
                const auto a = x[q + s * (p + 0)];
                const auto b = x[q + s * (p + m)];
                y[q + s * (2 * p + 0)] = a + b;
                y[q + s * (2 * p + 1)] = (a - b) * wp;
            }
        }
        fft(n / 2, 2 * s, !eo, y, x);
    }
}
const int N = 1 << 18;
complex<double> x[N];
complex<double> y[N];
complex<double> tmp[N];
int main() {
    ll n;
    cin >> n;
    int sz = 2 * 100000;
    for(int i = 1; i <= n; i++) {
        int in1, in2;
        cin >> in1 >> in2;
        x[i].real(in1);
        y[i].real(in2);
    }
    fft(N, 1, false, x, tmp);
    fft(N, 1, false, y, tmp);
    for(int i = 0; i < N; i++) {
        x[i] *= y[i];
        x[i] = conj(x[i]);
    }
    fft(N, 1, false, x, tmp);
    for(int i = 0; i < N; i++) {
        x[i] = conj(x[i]) * (1.0 / N);
    }
}
