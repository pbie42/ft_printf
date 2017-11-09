/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/11 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int main()
{
	int a,b;
	float c,d;

	a = 15;
	b = a / 2;
	printf("Ints\n");
	printf("%d\n",b);
	printf("%3d\n",b);
	printf("%03d\n",b);
	printf("\n");
	
	printf("Floats\n");
	c = 15.3;
	d = c / 3;
	printf("%3.2f\n",d);
	
	
	int Fahrenheit;
	
	for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
		printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));
		
	printf("\n");


	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Float number: %3.2f\n", 3.14159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Unsigned value: %u\n", 150);
	printf("Just print the percentage sign %%\n");


	printf(":%s:\n", "Hello, world!");
	printf(":%15s:\n", "Hello, world!");
	printf(":%.10s:\n", "Hello, world!");
	printf(":%-10s:\n", "Hello, world!");
	printf(":%-15s:\n", "Hello, world!");
	printf(":%.15s:\n", "Hello, world!");
	printf(":%15.10s:\n", "Hello, world!");
	printf(":%-15.10s:\n", "Hello, world!");
}
