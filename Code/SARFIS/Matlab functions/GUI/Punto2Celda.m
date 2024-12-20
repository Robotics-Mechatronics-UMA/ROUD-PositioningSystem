function [celda] = Punto2Celda(entorno,punto)
%% Determina la celda de rejilla correspondiente a una posición en el entorno.
x = punto(1); y = punto(2);
celda(1) = round((x-entorno.minX)/entorno.deltaXY)+1;
celda(2) = round((y-entorno.minY)/entorno.deltaXY)+1;
end