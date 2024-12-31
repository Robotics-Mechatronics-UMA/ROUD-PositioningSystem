function [ punto ] = Celda2Punto( entorno,celda )
%% Determina el punto en el entorno correspondiente a una celda de rejilla.
x = celda(1); y = celda(2);
punto(1) = entorno.minX + (x-1)*entorno.deltaXY;
punto(2) = entorno.minY + (y-1)*entorno.deltaXY;
end