#include "contrast.h"

int		main(int argc, char **argv)
{
	a_prop		*a;
	int			*int_map;
	g_prop		*g;
	FILE 		*fp;
	int			count;
	int			count2;
	int			i;
	t_pool		tp;

	i = 0;
	count = 0;
	count2 = 0;
	fp = 0;
	tp = tp_create(4);

	if (!(g = (g_prop*)malloc(sizeof(g_prop))))
		return (0);
	if (argc != 7)
		return (0);
	a = read_argv(argv, g);
	printf("%s\n", (*a).pgm);
	if (!(int_map = (int*)malloc(sizeof(int) * (*g).nbr_count)))
		return (0);

	int_map = to_int_map((*a).pgm);
	printf("nbr_count: %i\nwidth: %i\nheight: %i\ncalc_w: %i\ncalc_h: %i\n", (*g).nbr_count, (*g).width, (*g).height, (*g).calc_w, (*g).calc_h);
	
	fp = fopen((*a).file_name, "ab+");
	printf("con_lvl: %i\n", (*a).con_lvl);
	printf("contrast percent: %f\n", (double)((*a).con_lvl / 100.00));
	if (fp)
		printf("POOOG\n");
	tp_exec_queue_add(tp, &do_it, int_map, g);
	while (count < (*g).height)
	{
		while (count2 < (*g).width)
		{
			if ((*a).con_lvl != 0)
				int_map[i] = int_map[i] * (double) ((*a).con_lvl / 100.00) * (*g).max_grey;
			if (int_map[i] < 100 && int_map[i] > 9)
				fprintf(fp, "%i  ", int_map[i]);
			if (int_map[i] == 100)
				fprintf(fp, "%i ",int_map[i]);
			else
				fprintf(fp, "%i   ", int_map[i]);
			i++;
			count2++;
		}
		fprintf(fp, "%c", '\n');
		count2 = 0;
		count++;
	}
	return (0);
}

void	*do_it(void *data)
{
	t_thread *daddy = (t_thread *)data;
    int i = 0;
	while (i < 4)
	{

//		printf("nums: %i\n", daddy->env->rows[i][0]);
        /*this is where the calculation, writing, conversion, etc happens to/from each string*/
        /*maybe something like this vv?*/
		/*daddy->env->rows = ;*/
        daddy->env->thread_cnt--;
        if (daddy->env->thread_cnt == 0)
            pthread_cond_signal(&daddy->env->done);
        i++;
    }
	return (NULL);
}
