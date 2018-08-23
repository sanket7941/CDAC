#include<stdio.h>

int main()
{
 int x,unit,tenth,hundred;
	printf("Enter the intenger");
	scanf("%d",&x);
  unit=x%10;
	tenth=x/10;

 switch(tenth)
 {
	case 1: 	if(unit==0)		{ printf("ten");	break;}
				else if(unit==1){ printf("eleven"); break;}
				else if(unit==2){ printf("twelv"); 	break;}
				else if(unit==3){ printf("thirteen");break;}
				else if(unit==4){ printf("fourt"); 	break;}
				else if(unit==5){ printf("fift"); 	break;}
				else if(unit==6){ printf("sixt"); 	break;}
				else if(unit==7){ printf("sevent"); break;}
				else if(unit==8){printf("eighti"); 	break;}
			  else             {printf("nint"); 	break;}



	case 2: printf("twenty"); 	break;
	case 3: printf("thirty"); 	break;
	case 4: printf("fourty"); 	break;
	case 5: printf("fifty"); 	break;
	case 6: printf("sixty"); 	break;
	case 7: printf("seventy"); 	break;
	case 8: printf("eighty"); 	break;
	case 9: printf("ninty"); 	break;

 }
 if(tenth!=1)
 {
   switch(unit)
   {
	    case 1:printf("one");	break;
	    case 2:printf("two");	break;
      case 3:printf("three");	break;
      case 4:printf("four");	break;
	    case 5:printf("five");	break;
	    case 6:printf("six");	break;
	    case 7:printf("seven");	break;
	    case 8:printf("eight");	break;
	    case 9:printf("nine");	break;
	    case 0:printf("zero");	break;
   }

 }
}
