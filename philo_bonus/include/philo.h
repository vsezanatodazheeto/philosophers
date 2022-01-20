/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 05:21:15 by yshawn            #+#    #+#             */
/*   Updated: 2021/11/21 20:10:00 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define MIN_ARG_COUNT		5
# define MAX_ARG_COUNT		6
# define MAX_PHILO_NUM		200
# define MIN_PHILO_TIME		60
# define FORK_BAD_EXITED	69

# define E_ARG				"Erorr: "
# define E_NOTNUM			"is not a number.\n"
# define E_RANGE			"Error: value or values out of range\n"
# define E_MALLOC			"Error: malloc()\n"
# define E_FORK				"Error: fork()\n"
# define E_SEM_OPEN			"Error: sem_open()\n"
# define E_THR_CREATE		"Error: pthread_create()\n"

# define SEM_FORK			"sem_forks"
# define SEM_MESG			"sem_message"

# define M_FORK				"has taken a fork"
# define M_THINK			"is thinking"
# define M_EAT				"is eating"
# define M_SLEEP			"is sleeping"
# define M_DIE				"died"

typedef enum e_status
{
	ENUM_FORK,
	ENUM_THINK,
	ENUM_EAT,
	ENUM_SLEEP,
	ENUM_DIE
}	t_status;

typedef struct s_sem
{
	sem_t			*forks;
	sem_t			*message;
}	t_sem;

typedef struct s_opt {
	int				num;
	int				num_eat;
	int				t_die;
	int				t_eat;
	int				t_sleep;

	int				id;
	int				num_ate;
	uint64_t		ts_start;
	uint64_t		ts_last_eat;
	struct s_sem	*semaphore;
	struct s_opt	*philo;
} t_opt,	t_philo;

void		error_handle(char *msg);
void		parse(int ac, char *av[], t_opt *opt);
void		init(t_opt *opt, t_sem *semaphore, t_philo **philo);

// extra functions
void		philo_actions(t_philo *philo);
uint64_t	gettime_ms(void);
void		sleep_ms(uint64_t time);
void		message(t_philo *philo, t_status stat);

// lib functions
int			ft_atoi(const char *str);
int			ft_isnumber(char *str);
void		ft_putstr_fd(char *s, int fd);
void		*ft_memcpy(void *dest, const void *source, size_t size);

#endif