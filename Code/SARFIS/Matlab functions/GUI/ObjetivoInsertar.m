function [ objetivo ] = ObjetivoInsertar( entorno,idFullObjetivo,visibleObjetivo,...
                                          modoPosicion,unidad,punto,minUmbral,maxUmbral,...
                                          aproximacion,orientacion,enableAproximacion,tiempoActividad,...
                                          modoCoeficiente,coefPositivo,coefNegativo,...
                                          prioridad,temperatureEvent,timeEvent,pattern,event,enablePlanning,enableFreeze)
%% Inserta los parámetros definidos por el usuario para un punto de interés en el entorno.
global LoRa %Zigbee
 % asignación de especificaciones del objetivo
 objetivo.idFull            = idFullObjetivo;
 objetivo.visible           = visibleObjetivo;
 objetivo.modoPosicion      = modoPosicion;
 objetivo.unidadPosicion    = unidad;
 objetivo.posicion          = punto;
 objetivo.minUmbral         = minUmbral;
 objetivo.maxUmbral         = maxUmbral;
 objetivo.aproximacion      = aproximacion;
 objetivo.orientacion       = orientacion;
 objetivo.enableAprox       = enableAproximacion;
 objetivo.actividad         = tiempoActividad;
 objetivo.coeficiente       = modoCoeficiente;
 objetivo.coefPos           = coefPositivo;
 objetivo.coefNeg           = coefNegativo;
 if prioridad <= 0 || prioridad > 6,  objetivo.prioridad = 6; else, objetivo.prioridad = prioridad; end
 objetivo.temperatureEvent  = temperatureEvent;
 objetivo.timeEvent         = timeEvent;
 objetivo.pattern           = pattern;
 objetivo.event             = event;
 objetivo.enable            = enablePlanning;
 objetivo.enableFreeze      = enableFreeze;
%  %%
%  rejilla.xMin = Inf; rejilla.xMax = -Inf; rejilla.yMin = Inf; rejilla.yMax = -Inf;
%  rejilla.ocupacion = zeros(size(entorno.elevacion));
%  % polígono con forma triangular de tamaño total 1x1
%  vertices = [-0.50 +0.00 +0.50 -0.50;
%              -0.50 +0.50 -0.50 -0.50]';
%  % determinación de los vértices del polígono representativo de la víctima
%  vertices = (vertices*[entorno.deltaXY*.9 0;0 entorno.deltaXY*.9])';
%  victima.contornoVictima = vertices;
%  
%  % polígono con forma cuadrada de tamaño 1x1
%  vertices = [-0.50 -0.50 +0.50 +0.50 -0.50
%              -0.50 +0.50 +0.50 -0.50 -0.50]';
%  % determinación de los vértices del polígono representativo del contorno de incertidumbre
%  victima.contornoIncertidumbre = (vertices*[0 0
%                                             0 0])';
%  % victima.contornoIncertidumbre = (vertices*[victima.dimension(1) 0
%  %                                            0 victima.dimension(2)])';
%  
%  %% determinación de la ocupación del área de incertidumbre de posición de la víctima
%  vertices = victima.contornoIncertidumbre;
%  vertices = vertices + repmat(objetivo.posicion', 1, size(vertices, 2));
%  for i = 1:size(vertices,2)-1
%   p1 = vertices(:,i); p2 = vertices(:,i+1);
%   dx = p2(1)-p1(1); dy = p2(2)-p1(2); theta = atan2d(dy,dx);
%   dxy = PuntoInsercion(entorno,p1)+...
%         [(sign(dx))*entorno.deltaXY/2 (sign(dy))*entorno.deltaXY/2];
%   dj = abs(Punto2Celda(entorno,p2)-Punto2Celda(entorno,p1));
%   GenerarRejillaOcupacion(entorno,p1);
%   for j = 0:dj(1)-1
%    p = [dxy(1) p1(2)+sign(dy)*abs((dxy(1)-p1(1))*tand(theta))]+...
%        j*[sign(dx)*entorno.deltaXY sign(dy)*entorno.deltaXY*abs(tand(theta))];
%    GenerarRejillaOcupacion(entorno,p);
%   end
%   for j = 0:dj(2)-1
%    p = [p1(1)+sign(dx)*abs((dxy(2)-p1(2))*cotd(theta)) dxy(2)]+...
%        j*[sign(dx)*entorno.deltaXY*abs(cotd(theta)) sign(dy)*entorno.deltaXY];
%    GenerarRejillaOcupacion(entorno,p);
%   end
%   GenerarRejillaOcupacion(entorno,p2);
%  end
%  
%  %% Actualiza la matriz representativa de la ocupación de la víctima en el entorno
%  for x = rejilla.xMin:rejilla.xMax-1
%   cambio = 0;
%   for y = rejilla.yMin:rejilla.yMax-1
%    if cambio == 1 && rejilla.ocupacion(x,y) == 0 && rejilla.ocupacion(x,y+1) == 1
%     cambio = 2; yyMax = y;
%    end
%    if cambio == 0 && rejilla.ocupacion(x,y) == 1 && rejilla.ocupacion(x,y+1) == 0
%     cambio = 1; yyMin = y;
%    end
%   end
%   if cambio == 2
%    for y = yyMin:yyMax
%     rejilla.ocupacion(x,y) = 1;
%    end
%   end
%  end
%  victima.rejilla = rejilla;

%  function [ ] = GenerarRejillaOcupacion( entorno,punto )
%  %% determinación de las celdas de rejilla correspondientes a un punto en el entorno
%  coord = Punto2Celda(entorno, punto);
%  % determinación de las coordenadas X e Y mínimas en la ocupación del entorno
%  if rejilla.xMin > coord(1)
%   rejilla.xMin = coord(1);
%  end
%  if rejilla.yMin > coord(2)
%   rejilla.yMin = coord(2);
%  end
%  rejilla.ocupacion(coord(1),coord(2)) = 1;
%  %% modificación para que un mismo punto pueda pertenecer a 1, 2 o 4 celdas
%  if punto(1)/entorno.deltaXY + 0.5 == coord(1)-1
%   if coord(1) > 1, coord(1) = coord(1)-1; end
%   rejilla.ocupacion(coord(1),coord(2)) = 1;
%  end
%  if punto(2)/entorno.deltaXY + 0.5 == coord(2)-1
%   if coord(2) > 1, coord(2) = coord(2)-1; end
%   rejilla.ocupacion(coord(1),coord(2)) = 1;
%  end
%  % determinación de las coordenadas X e Y máximas en la ocupación del entorno
%  if rejilla.xMax < coord(1)
%   rejilla.xMax = coord(1);
%  end
%  if rejilla.yMax < coord(2)
%   rejilla.yMax = coord(2);
%  end
%  end

end