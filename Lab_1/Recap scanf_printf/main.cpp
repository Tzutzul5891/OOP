#include <iostream>
#include <string>
using namespace std;

bool voc(char a)
{
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        return true;
    return false;
}

int len(char s[])
{
    int i, k = 0;
    for (i = 0; s[i]; i++)
        k++;
    return k;
}

char cuvinte[100][100];

void sortare(int k)
{
    int n = k, i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (len(cuvinte[i]) < len(cuvinte[j]))
                swap(cuvinte[i], cuvinte[j]);
}

int main()
{
    char s[100];
    int i = 0, k, j=0, n;
    while (scanf("%c", &s[i]) && s[i] != '\n')
        i++;
    s[i] = '\0', n = i, i = 0, k = 0;
    while (s[i]){
        if (voc(s[i])){
            cuvinte[k][j] = s[i];
            i++;
            j++;
        }
        else{
            cuvinte[k][j] = NULL;
            k++;
            i++;
            j = 0;
        }
    }
    cuvinte[k][j] = NULL;
    sortare(k);
    char aux[100];
    for (int i = 0; i <= k; i++) {

        printf("%s\n", cuvinte[i]);
    }
    return 0;
}
