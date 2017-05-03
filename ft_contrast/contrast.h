#ifndef CONTRAST_H
# define CONTRAST_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <time.h>

typedef struct				global_properties
{
	int						width;
	int						height;
	int						calc_w;
	int						calc_h;
	int						max_grey;
	char					*file_type;
	int						nbr_count;
}							g_prop;

typedef struct				argv_properties
{
	char					*pgm;
	int						con_lvl;
	char					*file_name;
}							a_prop;

typedef struct				s_environment
{
    pthread_cond_t			signal;
    pthread_cond_t			done;
    pthread_mutex_t			lock;
    int						thread_cnt;
}							t_env;

typedef struct				s_thread
{
    t_env					*env;
	int						*row;
    pthread_t				thread;
}							t_thread;

typedef struct				s_pool
{
	t_thread				*threads;
}							t_pool;

typedef	struct				segments
{
	int						**sp;
}							seg;

// to_int_map.c
int							*to_int_map(char *line);
int							find_width(char *line);

// validate.c
int							validate(char *str);

// input.c
char						*read_pgm(FILE *fp);
a_prop						*read_argv(char **argv, g_prop *g);

void						*do_it(void *data);

t_pool tp_create(int n);
int tp_get_nbr_proc(void);
void	*do_something(void *data);
int tp_wait_for_queue(t_pool pool, clock_t time1);
void tp_exec_queue_add(t_pool pool, void *func, int *data, g_prop *g);
int							**init_seg(int *data, g_prop *g);

#endif
