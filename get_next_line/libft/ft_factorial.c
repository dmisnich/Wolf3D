/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:49:17 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/23 18:49:19 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	int res;

	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		res = 1;
		while (nb > 1)
		{
			res = res * nb--;
		}
	}
	return (res);
}
