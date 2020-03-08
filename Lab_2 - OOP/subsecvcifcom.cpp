#include <iostream>
using namespace std;

int apare(int n, int c)
{//verifica daca cifra c apare in numarul n
    while(n>0)
    {//descompun pe n in cifre
        if(n%10==c) return 1;//am gasit cifra c
        n=n/10;//elimin ultima cifra
    }
    return 0;// nu s-a gasit cifra c
}

int comune(int a, int b)
{//verifica daca a si b au cel putin o cifra comuna
    int nr=0;
    for(int c=0;c<=9;c++)//pacurg cifrele [0,9]
        if(apare(a,c) && apare(b,c))//daca cifra c apare atat in a cat si in b
            nr++;//return 1;//am gasit cifra comuna
    if(nr>=2) return 1;
    return 0;//nu am gasit cifra comuna
}

pair<int,int> LongestSubsecvCifCom(int n, int v[100])
{
   int i=1;
   int lungMax=0, pozMax=0;
   int nrCifCom = 0;

   while(i<=n)
   {
       int k=i;
       nrCifCom = 0;
       while( (comune(v[k],v[k+1]) == 1) && k<=n)
       {
           nrCifCom++;
           k++;
       }

       if (nrCifCom>lungMax)
       {
           lungMax = nrCifCom;
           pozMax = i;
       }
       i++;
   }

   pair <int, int> pereche;
   pereche.first = pozMax;
   pereche.second = lungMax + pozMax;
   return pereche;
}
