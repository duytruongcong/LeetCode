#include "pch.h"

#ifdef UTILITYCPLUSPLUS_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

void DLL_API InputArray(int& number, std::vector<int>& array);
void DLL_API OutputArray(std::vector<int> array);
void DLL_API SortNonDecreasingArray(std::vector<int>& array);