/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:43:29 by rguerrer          #+#    #+#             */
/*   Updated: 2024/02/22 12:37:05 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

void		ft_error(char *str);
int			ft_check_args(int ac, char **av);
void		ft_init_philos(t_philo *philo, char **av, t_program *program,
				pthread_mutex_t *forks);
void		ft_init_forks(pthread_mutex_t *forks, char *num);
void		ft_init_program(t_program *program, t_philo *philo);
size_t		ft_get_time(void);
void		*ft_philo_routine(void *philo);
int			ft_start_threads(t_program *program, pthread_mutex_t *forks);
void		*ft_monitor(void *arg);
void		ft_destroy_all(char *str, t_program *program,
				pthread_mutex_t *forks);
int			ft_usleep(size_t time);
void		ft_print_status(t_philo *philo, char *str, int id);
int			ft_dead_loop(t_philo *ph);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif