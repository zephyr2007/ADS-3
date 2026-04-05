// Copyright 2025 NNTU-CS
#include "alg.h"
#include <cstdint>

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t max = num;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = num * 3 + 1;
    }
    if (num > max) {
      max = num;
    }
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int count = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num = num / 2;
    } else {
      num = 3 * num + 1;
    }
    ++count;
  }
  return count;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound,
                        uint64_t rbound) {
  if (lbound > rbound) {
    *maxlen = 0;
    return 0;
  }

  unsigned int maxLen = 0;
  uint64_t result = lbound;

  for (uint64_t num = lbound; num <= rbound; ++num) {
    unsigned int len = collatzLen(num);
    if (len > maxLen) {
      maxLen = len;
      result = num;
    }
  }

  *maxlen = maxLen;
  return result;
}
