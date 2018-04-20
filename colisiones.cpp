int xt, yt;//cordenadas de tanque
int xb,yb;//cordenadas de bala de tanque
int xn,yn;//cordenadas de enemigo1

void detectarBala(){
	if (xb == xn && yb == yn+1 || xb == xn+2 && yb == yn+1 || xb == xn+3 && yb == yn+1 || xb == xn+4 && yb == yn+1 || xb+1 == xn+3 && yb == yn+2 || xb+1 == xn+3 && yb == yn){
		tanques ++;	
		if (yn > 11 && yt > 11){
			gotoxy(xn,yn); printf   ("     ");
			gotoxy(xn,yn+1); printf ("     ");
			gotoxy(xn,yn+2); printf ("     ");
			xn = 5;
			yn = 5;
			xb = 0;
			yb = 0;
			gotoxy(xn,yn); printf   (" ***");
			gotoxy(xn,yn+1); printf ("  *** ");
			gotoxy(xn,yn+2); printf (" ***");	
		}
			else{
				if(yn < 11 && yt < 11){
					gotoxy(xn,yn); printf   ("     ");
					gotoxy(xn,yn+1); printf ("     ");
					gotoxy(xn,yn+2); printf ("     ");
					xn = 5;
					yn = 18;
					xb = 0;
					yb = 0;
					gotoxy(xn,yn); printf   (" ***");
					gotoxy(xn,yn+1); printf ("  *** ");
					gotoxy(xn,yn+2); printf (" ***");	
				}
	
			}
	}
	
}
	// El segundo tanque.
	if (xbn == xbn2 && ybn-1 == ybn2 || xbn == xbn2 && ybn+1 == ybn2 || xbn == xbn2 && ybn == ybn2){
		gotoxy(xbn,ybn);printf (" ");
		xbn = 0;
		ybn = 0;
		xbn2 = 0;
		ybn2 = 0;
	}
}

  
