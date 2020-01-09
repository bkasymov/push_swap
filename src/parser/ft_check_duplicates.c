#include "../../includes/push_swap.h"

/*
 ** argc - 1 because it's name of programms
 */

int		*ft_intcpy(int *dst, const int *src, int count)
{
		  int	i;

		  i = -1;
		  while (i < count)
		  {
		    dst[count] = src[count];
		    count--;
		  }
		  return (dst);
}

int     ft_check_duplicates(t_vars *psv, int end)
{
	int     i;
	int     *dupl;

	while (end > i)
	{
		printf("\n[%d]: %d ", i,psv->a[i]);
		i++;
	}
	printf("end: %d",end);
	i = 0;
	if (!(dupl = (int *)malloc(sizeof(int) * (end))))
		exit(1);
	dupl = ft_intcpy(dupl, (int *)psv->a, end-1);
	//ft_quick_sort(dupl, 0, end - 1);
	printf("\ndupl:");
	while (end > i)
	{
		printf("\n%d ", dupl[i]);
		i++;
	}
	return (0);
}

void	ft_quick_sort(int *array, int start, int end)
{
	int q;

	if (start < end)
	{
		q = ft_partition(array, start, end);
		ft_quick_sort(array, start, q - 1);
		ft_quick_sort(array, q + 1, end);
	}
}

/*
**		ft_partition - Разбиение массива и основной
**		процесс сортировки протекает в данной функции.
**		Состояние: На стадии проверки
**		Нормы: ✓
*/

int		ft_partition(int *array, int start, int end)
{
	int pivot;
	int i;
	int temp;
	int j;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

