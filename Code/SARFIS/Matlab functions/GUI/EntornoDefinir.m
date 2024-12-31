function [ entorno ] = EntornoDefinir(tipo, fichero)
%% Define el entorno.
% determinaci�n de las caracter�sticas del entorno
% especificaci�n del entorno mediante mapa de elevaci�n
%  valor NaN indica fuera del entorno
%  los valores pueden ser n�meros enteros o reales, positivos o negativos
%global timerUpdate general
%stop(timerUpdate);
%general.updated = false;
%if isfield(general,'monitor'), general = rmfield(general,'monitor'); end
%if isfield(general,'monitorZoom'), general = rmfield(general,'monitorZoom'); end
%if isfield(general,'trajectory'), general = rmfield(general,'trajectory'); end
%if isfield(general,'trajectoryZoom'), general = rmfield(general,'trajectoryZoom'); end
%if isfield(general,'agent'), general = rmfield(general,'agent'); end
%if isfield(general,'agentZoom'), general = rmfield(general,'agentZoom'); end
%if isfield(general,'POI'), general = rmfield(general,'POI'); end
%if isfield(general,'POIZoom'), general = rmfield(general,'POIZoom'); end
if tipo == 0
 if (exist(strcat(fichero,'.mat'),'file') == 2), load(strcat(fichero,'.mat'));
 else
  % lectura de fichero XYZ procedente del tratamiento de im�genes desde UAV
  [X,Y,Z] = XYZread(strcat(fichero,'.xyz'));
  % extrae valores RGB que se incluye en fichero XYZ procedente de Pix4Dmapper
  ImR = X(2:2:end,:); ImG = Y(2:2:end,:); ImB = Z(2:2:end,:);
  % extrae valores XYZ del fichero XYZ procedente de Pix4Dmapper
  X = X(1:2:end,:); Y = Y(1:2:end,:); Z = Z(1:2:end,:);
  rejilla = flip(XYZ2grid(X,Y,Z))';
  % construye imagen RGB y mapa de elevaci�n del fichero XYZ procedente de Pix4Dmapper
  imagen(:,:,1) = XYZ2grid(X,Y,ImR);
  imagen(:,:,2) = XYZ2grid(X,Y,ImG);
  imagen(:,:,3) = XYZ2grid(X,Y,ImB);
  imagen(isnan(imagen)) = 0;
  imagen = uint8(imagen);
  minX = min(X); maxX = max(X); minY = min(Y);
  save(strcat(fichero,'.mat'),'minX','maxX','minY','rejilla','imagen');
 end
else
 if (exist(strcat(fichero,'.mat'),'file') == 2), load(strcat(fichero,'.mat'));
 else
  % lectura de fichero XYZ
  [X,Y,Z] = XYZread(strcat(fichero,'.xyz'));
  rejilla = flip(XYZ2grid(X,Y,Z))';
  minX = min(X); maxX = max(X); minY = min(Y);
  save(strcat(fichero,'.mat'),'minX','maxX','minY','rejilla');
 end
end

%% se asigna rejilla al entorno con mapa de elevaci�n
entorno.minX = minX; entorno.minY = minY;
entorno.dimX = size(rejilla,1); entorno.dimY = size(rejilla,2);
entorno.deltaXY = (maxX-minX)/(entorno.dimX-1);
entorno.elevacion = rejilla;

%% c�lculo de valores m�ximo y m�nimo del mapa de elevaci�n
entorno.vMin = min(min(entorno.elevacion));
entorno.elevacion(isnan(entorno.elevacion)) = Inf;
entorno.vMax = max(entorno.elevacion(isfinite(entorno.elevacion)));

%% determina si el entorno es un modelo de ejemplo o imagen desde UAV (ejemplo = 0)
entorno.tipo = tipo;
if entorno.tipo == 0
 entorno.imagen = imagen;
 entorno.foto_DEM = 0;
else
 fichero = split(fichero,'\');
 entorno.fichero = fichero{end};
end
%start(timerUpdate);
end