function [puntoCentrado] = PuntoInsercion(entorno, punto)
%% Calcula la posici�n del entorno que corresponde al centro geom�trico del una celda.
x = punto(1); y = punto(2);
puntoCentrado = Celda2Punto(entorno,Punto2Celda(entorno,[x y]));
end