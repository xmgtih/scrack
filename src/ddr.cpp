#include "crack.h"

int ddr_find(value_type v){
  int L,R;
  find_piece(ci, N, v, L,R);
  n_touched += R - L;
  return targeted_random_crack(ci,v,arr,N,L,R,MAX_NCRACK,CRACK_AT);
}

int view_query(int a, int b){
  merge_ripple(ci, arr, N, pins, pdel, a, b);  // merge qualified updates
  int i2 = ddr_find(b);  // unlimited cracks allowed plus one crack on v2
  int i1 = ddr_find(a);  // unlimited cracks allowed plus one crack on v1
  return i2 - i1;
}

int count_query(int a, int b){
  merge_ripple(ci, arr, N, pins, pdel, a, b);  // merge qualified updates
  int i2 = ddr_find(b);  // unlimited cracks allowed plus one crack on v2
  int i1 = ddr_find(a);  // unlimited cracks allowed plus one crack on v1
  int cnt = 0;
  for (int i=i1; i<i2; i++)
    if (arr[i]>=0) cnt++;
  return cnt;
}
