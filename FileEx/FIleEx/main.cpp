#include <iostream>
#include "FileEx.h"

int main()
{
    FileEx cFileEx;

    cFileEx.Open();
    cFileEx.Write();
    cFileEx.Change();
    cFileEx.Close();
    return 0;
}

