#include<stdio.h>
void	func(char	**s1,	char	**s2)
{
char	*t=NULL;
t	=	*s1;
*s1	=	*s2;
*s2	=	t;
}
int	main(void)
{
char	*s1	=	"ABCD",	*s2	=	"abcd";
func(&s1,	&s2);
printf("\n	s1=%s	s1=%s",	s1,	s2);
{
char	s1[5]	=	"ABCD",	s2[5]	=	"abcd";
//func(&s1,	&s2);
printf("\n	s1=%s	s2=%s",	s1,	s2);
}
return	0;
}
