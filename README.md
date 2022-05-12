# Ascii_Invaders
# Space invaders inspired game made in C
To run the game execute ./asciiInvaders.exe followed by objects inputs
- objeto[posX=número,posY=número,sprite=carácter,tipo=personaje,vida=número,puntuacion=número]
- objeto[posX=número,posY=número,sprite=carácter,tipo=misil,direccion=direccion_e,danio=número]
- objeto[posX=número,posY=número,sprite=carácter,tipo=enemigo,vida=número,puntuacion=número,movimientos=x=número,y=número,x=número,y=número,x=número,y=número,x=número,y=número]

Example:
> ./asciiInvaders.exe objeto[posX=6,posY=9,sprite=A,tipo=personaje,vida=5,puntuacion=0] 
objeto[posX=6,posY=3,sprite=.,tipo=misil,direccion=ascendente,danio=10] 
objeto[posX=5,posY=3,sprite=.,tipo=misil,direccion=descendente,danio=10] 
objeto[posX=5,posY=7,sprite=V,tipo=enemigo,vida=100,puntuacion=10,movimientos=x=0,y=1,x=1,y=0,x=-
1,y=0,x=0,y=-1] 
objeto[posX=1,posY=3,sprite=V,tipo=enemigo,vida=100,puntuacion=10,movimientos=x=0,y=1,x=1,y=0,x=-
1,y=0,x=0,y=-1] 

