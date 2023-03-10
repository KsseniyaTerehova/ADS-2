// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <iostream>
using namespace std;



double pown(double value, uint16_t n) {
  double R = value;
  for (int i = 2; i <= n; i++)
    R *= value;
  return R;
}

uint64_t fact(uint16_t n) {
  uint16_t R = 1;
  for (int i = 2; i <= n; i++)
    R *= i;
  return R;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double R = 1;
  for (uint16_t i = 1; i <= count; i++)
    R += calcItem(x, i);
  return R;
}

double sinn(double x, uint16_t count) {
  double R = x;
  for (uint64_t i = 2; i <= count; i++)
    R += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  return R;
}

double cosn(double x, uint16_t count) {
  double R = 1;
  for (uint64_t i = 2; i <= count; i++)
    R += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  return R;
}
int main() {
  cout << cosn(2, 6) << endl;
}
