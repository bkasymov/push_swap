#include "../../includes/push_swap.h"

int   ft_init_array(t_vars *psv, int argc, int a) {
  int   j;
  int   tmp;

  tmp = argc - 1;
  j = 0;
  if (!(psv->arr = (int *)malloc(sizeof(int) * (argc))))
    return (1);
  while (tmp >= j)
  {
    psv->arr[j] = 0;
    j++;
  }
  return (0);
}