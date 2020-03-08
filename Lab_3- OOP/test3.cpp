#include <iostream>
using namespace std;
#include "citire.h"
#include "afisare.h"
#include "subsecvcresc.h"
#include "subsecvcifcom.h"
#include "test3.h"
#include "assert.h"

void TestLongestConsecutiveSec()
{
    int v[7];
    v[1]= 12;
    v[2]= 2;
    v[3]= 3;
    v[4]= 4;
    v[5]= 11;
    v[6]= 7;
    pair<int,int> pereche;
    pereche.first = 2;
    pereche.second = 5;
    assert(pereche == LongestConsecutiveSec(6, v));

}

void TestLongestSubsecvCifCom()
{
    int v[10];
    v[1]= 120;
    v[2]= 167;
    v[3]= 5678;
    v[4]= 8672;
    v[5]= 39278;
    v[6]= 378;
    v[7]= 387;
    v[8]= 111;
    v[9]= 2479;

    pair<int,int> pereche;
    pereche.first = 2;
    pereche.second = 7;
    assert(pereche == LongestSubsecvCifCom(9, v));

}
