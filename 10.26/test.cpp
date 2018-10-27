#include <fstream>
#include <iostream>

int sa[] = {0, 3, 1, 0}, sb[] = {0, 0, 1, 3};
int g[1000005] = {0};

int main()
{
    std::ofstream fout("out.txt");
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 1; i <= 3; i++)
    {
        a += sa[i], b += sb[i];
        for (int j = 1; j <= 3; j++)
        {
            a += sa[j], c += sb[j];
            for (int k = 1; k <= 3; k++)
            {
                a += sa[k], d += sb[k];
                for (int l = 1; l <= 3; l++)
                {
                    b += sa[l], c += sb[l];
                    for (int m = 1; m <= 3; m++)
                    {
                        b += sa[m], d += sb[m];
                        for (int n = 1; n <= 3; n++)
                        {
                            c += sa[n], d += sb[n];
                            for (int nn = 1; nn <= 3; nn++)
                            {
                                a += sa[nn], e += sb[nn];
                                for (int nnn = 1; nnn <= 3; nnn++)
                                {
                                    b += sa[nnn], e += sb[nnn];
                                    for (int eee = 1; eee <= 3; eee++)
                                    {
                                        c += sa[eee], e += sb[eee];
                                        for (int rrr = 1; rrr <= 3; rrr++)
                                        {
                                            d += sa[rrr], e += sb[rrr];
                                            int dd = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
                                            g[dd]++;
                                            d -= sa[rrr], e -= sb[rrr];
                                        }
                                        c -= sa[eee], e -= sb[eee];
                                    }
                                    b -= sa[nnn], e -= sb[nnn];
                                }
                                a -= sa[nn], e -= sb[nn];
                            }
                            c -= sa[n], d -= sb[n];
                        }
                        b -= sa[m], d -= sb[m];
                    }
                    b -= sa[l], c -= sb[l];
                }
                a -= sa[k], d -= sb[k];
            }
            a -= sa[j], c -= sb[j];
        }
        a -= sa[i], b -= sb[i];
    }
    for (int i = 1; i < 1000000; i++)
        if (g[i] == 6)
            fout << " && ss == " << i;
}
