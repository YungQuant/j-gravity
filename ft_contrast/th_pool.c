#include "contrast.h"

struct s_pool tp_create(int n)
{
    t_pool pool;
    if (!(pool.threads = malloc(sizeof(t_thread) * n)))
        printf("thread malloc fail");
    return (pool);
}

int tp_get_nbr_proc(void)
{
    return (sysconf(_SC_NPROCESSORS_ONLN));
}

void	*do_something(void *data)
{
	t_thread *daddy = (t_thread *)data;
    int i = 0;
	while (i < 4)
	{

		printf("nums: %i\n", daddy->row[i]);
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

int tp_wait_for_queue(t_pool pool, clock_t time1)
{
	int i = 0;
	while (i < 4)
	{
		/*this v may as well be pseudo-code*/
		if (pthread_cond_init(&(pool.threads[i].env->done), NULL) == 0)
		{
			clock_t time2 = clock();
			int diff = time2 - time1;
			printf("time per queue %i\n",diff);
			pthread_cond_destroy(&(pool.threads[i].env->done));
			return (1);}
		else
			printf("processing...");
		i++;
	}
	i = 0;
	return (0);
}

int	**init_seg(int *data, g_prop *g)
{
	printf("1111111111111111111");
	seg		*s;
	if (!(s = (seg*)malloc(sizeof(seg))))
		return (0);
	int		count;
	int		count2;
	int		i;
	int		*cdata;

	cdata = data;
	i = 0;
	count = 0;
	count2 = 0;
	if (!(s->sp = (int**)malloc(sizeof(int*) * 4)))
		printf("malloc fail\n");
		return (0);
	printf("11111111");
	for (int i = 0; i < 4; i++){
		s->sp[i] = malloc(sizeof(int) * (*g).width * ((*g).nbr_count / (*g).height) + 10);}
		
	printf("CACA\n");
	while (count2 < (*g).width * ((*g).nbr_count / (*g).height) && count != (*g).nbr_count)
	{
		(*s).sp[0][i++] = *cdata;
		cdata++;
		count2++;
		count++;
	}
	count2 = 0;
	i = 0;
	while (count2 < (*g).width * ((*g).nbr_count / (*g).height) && count != (*g).nbr_count)
	{
		(*s).sp[1][i++] = *cdata;
		cdata++;
		count2++;
		count++;
	}
	count2 = 0;
	i = 0;
	while (count2 < (*g).width * ((*g).nbr_count / (*g).height) && count != (*g).nbr_count)
	{
		(*s).sp[2][i++] = *cdata;
		cdata++;
		count2++;
		count++;
	}
	count2 = 0;
	i = 0;
	printf("PPPOOOOOPKH\n");
	while (count2 < (*g).width * ((*g).nbr_count / (*g).height) && count != (*g).nbr_count)
	{
		(*s).sp[3][i++] = *cdata;
		count2++;
		count++;
		cdata++;
	}
	printf("seggggg %i", *s->sp[0]);
	return (s->sp);
}

void tp_exec_queue_add(t_pool pool, void *func, int *data, g_prop *g)
{
	printf("11111");
    t_env 	environment;
//	int		**poop;
	int		i;
	
	i = 0;
//	poop = init_seg(data, g);
    pthread_cond_init(&environment.signal, NULL);
    pthread_cond_init(&environment.done, NULL);
    pthread_mutex_init(&environment.lock, NULL);
	pthread_mutex_lock(&environment.lock);
    environment.thread_cnt = 4;
	

    while (i < 4)
    {
//		pool.threads[i].row = poop[i]; 
		pool.threads[i].env = &environment;
        pthread_create(&(pool.threads[i].thread), NULL, func, (void*)&(pool.threads[i]));
        i++;
    }

    /*we may not need to join in this function if "tp_wait_for_queue()" is supposed to manage the queue*/
    /*i dont think it is though*/
    /* environment->thread_cnt = 4; ?? */
//	clock_t time1 = clock();
    pthread_cond_broadcast(&(environment.signal));
	/*something to wait until processes finish*/
 	/*tp_wait_for_queue(pool, time1);*/

    while (i >= 0)
    {
        pthread_join(pool.threads[i].thread, NULL);
        i--;
    }
}
