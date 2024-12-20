function [] = POIRepresentar( handles,entorno,POI,ID,numPOIs,numFigure )
global general
%% Comprueba que la posición del POI esté dentro de las dimensiones del entorno representado
minimoX = entorno.minX; maximoX = entorno.minX+entorno.dimX*entorno.deltaXY;
minimoY = entorno.minY; maximoY = entorno.minY+entorno.dimY*entorno.deltaXY;
if ID > numPOIs
 warnPos = true;
else
 valX = POI.posicion(1); valY = POI.posicion(2);
 warnPos = (valX < minimoX || valX > maximoX || valY < minimoY || valY > maximoY);
end

%% Representa gráficamente el objetivo en el entorno.
graficos = 1; % if entorno.ejemplo == 0 graficos = 2; end
while graficos ~= 0
 if graficos == 2
  subplot 121;
% else
%  if entorno.ejemplo == 0 subplot 122; end
 end
 if ~warnPos
  %% determinación del color en función de prioridad del objetivo
  switch POI.prioridad
   case 1
    color = [  1   0   0];        % rojo - máxima prioridad (atención de forma inmediata)
   case 2
    color = [255 165   0]./255;	 % naranja - emergencia (~10-15 minutos)
   case 3
    color = [  1   1   0];        % amarillo - urgencia (~60 minutos)
   case 4
    color = [  0 128   0]./255;	 % verde - urgencia menor (~2 horas)
   case 5
    color = [  0   0   1];        % azul - sin urgencia (~4 horas)
   otherwise
    color = [  0   0   0];        % negro - no requiere atención
  end
  %% representación gráfica de la ocupación de la víctima en el entorno
  % for x = victima.rejilla.xMin:victima.rejilla.xMax
  %  for y = victima.rejilla.yMin:victima.rejilla.yMax
  %   if victima.rejilla.ocupacion(x,y) == 1
  %    DibujarCeldaRejilla(entorno,[x y],...
  %                        color,1);
  %   end
  % end
  % end
  %% representación gráfica de caja externa de tamaño fijo (proporcional al zoom).
  if isfield(POI,'posicion') && ~isempty(POI.posicion)
   vertices = [-0.50 -0.50 +0.50 +0.50 -0.50
               -0.50 +0.50 +0.50 -0.50 -0.50]';
   if POI.aproximacion < .035*(handles.figura.XLim(2)-handles.figura.XLim(1))
    escala = diag([1 1])*.035*(handles.figura.XLim(2)-handles.figura.XLim(1));
   else
    escala = diag([POI.aproximacion POI.aproximacion]);
   end
   vertices = (escala*vertices');
   vertices = vertices + repmat(POI.posicion', 1, size(vertices, 2));
 %   patch('Faces',1:size(vertices,2),'Vertices',vertices',...
 %         'EdgeColor','k','LineWidth',1,...
 %         'FaceColor',color);
   % representación gráfica del área de incertidumbre de posición de la víctima
 %  vertices = victima.contornoIncertidumbre;
 %  vertices = vertices + repmat(victima.posicion', 1, size(vertices, 2));
 %  patch('Faces',1:size(vertices,2),'Vertices',vertices',...
 %        'FaceColor','none','LineStyle',':');
   %% representación gráfica del posicionamiento de la víctima en el entorno
 %  vertices = victima.contornoVictima;
 %  vertices = vertices + repmat(victima.posicion', 1, size(vertices, 2));
 %  patch('Faces',1:3,'Vertices',vertices','FaceColor',color);
   %% representación del identificador de la víctima en el entorno
   % if POI.prioridad > 3, color = 'white'; else, color = 'black'; end
   % prompt = {['{\color{red}\fontsize{16}',char(10735),char(9709),'} ',num2str(ID)]
   %           POI.idFull};
   if POI.visible
    if isempty(POI.idFull)
     prompt = {['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{13}',char(9737),'}']};
     % prompt = {['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{13}',char(9737),'} ',num2str(ID)]};
    else
     prompt = {''
               ['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{13}',char(9737),'}']
               POI.idFull};
     % prompt = {['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{13}',char(9737),'} ',num2str(ID)]
     %           POI.idFull};
    end
    if ( numFigure == 1 && ( ~isfield(general,'POI') || ( isfield(general,'POI') && ( ID > numel(general.POI) ) ) ) ) || ...
       ( numFigure == 2 && ( ~isfield(general,'POIZoom') || ( isfield(general,'POIZoom') && ( ID > numel(general.POIZoom) ) ) ) )
     if numFigure == 1
      general.POI(ID).text = text(POI.posicion(1),POI.posicion(2),prompt,...
           'Background','none',... % 'w',...
           'Color','k',...%'FontWeight','bold',...
           'HorizontalAlignment','center',...
           'Visible','on');
      general.POI(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
           'MarkerSize',3,... 
           'MarkerEdgeColor','none',... % 'w',...
           'MarkerFaceColor',color,...
           'Visible','off');
     else
      general.POIZoom(ID).text = text(POI.posicion(1),POI.posicion(2),prompt,...
           'Background','none',... % 'w',...
           'Color','k',...%'FontWeight','bold',...
           'HorizontalAlignment','center',...
           'Visible','on');
      general.POIZoom(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
           'MarkerSize',3,... 
           'MarkerEdgeColor','none',... % 'w',...
           'MarkerFaceColor',color,...
           'Visible','off');
     end
    else
     if ID <= numPOIs
      if numFigure == 1, set(general.POI(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'String',prompt,'Visible','on'); end
      if numFigure == 2, set(general.POIZoom(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'String',prompt,'Visible','on'); end
      if numFigure == 1, set(general.POI(ID).plot,'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(ID).plot,'Visible','off'); end
     else
      if numFigure == 1, set(general.POI(end).text,'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(end).text,'Visible','off'); end
      if numFigure == 1, set(general.POI(end).plot,'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(end).plot,'Visible','off'); end
      if numFigure == 1, general.POI(end) = []; end
      if numFigure == 2, general.POIZoom(end) = []; end
     end
    end
   else
    if ( numFigure == 1 && ( ~isfield(general,'POI') || ( isfield(general,'POI') && ( ID > numel(general.POI) ) ) ) ) || ...
       ( numFigure == 2 && ( ~isfield(general,'POIZoom') || ( isfield(general,'POIZoom') && ( ID > numel(general.POIZoom) ) ) ) )
     if numFigure == 1
      general.POI(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
           'MarkerSize',3,... 
           'MarkerEdgeColor','none',... % 'w',...
           'MarkerFaceColor',color,...
           'Visible','on');
      general.POI(ID).text = text(POI.posicion(1),POI.posicion(2),'',...
           'Background','none',... % 'w',...
           'Color','k',...%'FontWeight','bold',...
           'HorizontalAlignment','center', ...
           'Visible','off');
     else
      general.POIZoom(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
           'MarkerSize',3,... 
           'MarkerEdgeColor','none',... % 'w',...
           'MarkerFaceColor',color,...
           'Visible','on');
      general.POIZoom(ID).text = text(POI.posicion(1),POI.posicion(2),'',...
           'Background','none',... % 'w',...
           'Color','k',...%'FontWeight','bold',...
           'HorizontalAlignment','center', ...
           'Visible','off');
     end
    else
     if ID <= numPOIs
      if numFigure == 1, set(general.POI(ID).plot,'XData',POI.posicion(1),'YData',POI.posicion(2),'MarkerFaceColor',color,'Visible','on'); end
      if numFigure == 2, set(general.POIZoom(ID).plot,'XData',POI.posicion(1),'YData',POI.posicion(2),'MarkerFaceColor',color,'Visible','on'); end
      if numFigure == 1, set(general.POI(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'Visible','off'); end
     else
      if numFigure == 1, set(general.POI(end).plot,'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(end).plot,'Visible','off'); end
      if numFigure == 1, set(general.POI(end).text,'Visible','off'); end
      if numFigure == 2, set(general.POIZoom(end).text,'Visible','off'); end
      if numFigure == 1, general.POI(end) = []; end
      if numFigure == 2, general.POIZoom(end) = []; end
     end
    end
   end
  else
   if ( numFigure == 1 && ( ~isfield(general,'POI') || ( isfield(general,'POI') && ( ID > numel(general.POI) ) ) ) ) || ...
      ( numFigure == 2 && ( ~isfield(general,'POIZoom') || ( isfield(general,'POIZoom') && ( ID > numel(general.POIZoom) ) ) ) )
    if numFigure == 1
     general.POI(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
          'MarkerSize',3,... 
          'MarkerEdgeColor','none',... % 'w',...
          'MarkerFaceColor',color,...
          'Visible','off');
     general.POI(ID).text = text(POI.posicion(1),POI.posicion(2),'',...
          'Background','none',... % 'w',...
          'Color','k',...%'FontWeight','bold',...
          'HorizontalAlignment','center', ...
          'Visible','off');
    else
     general.POIZoom(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
          'MarkerSize',3,... 
          'MarkerEdgeColor','none',... % 'w',...
          'MarkerFaceColor',color,...
          'Visible','off');
     general.POIZoom(ID).text = text(POI.posicion(1),POI.posicion(2),'',...
          'Background','none',... % 'w',...
          'Color','k',...%'FontWeight','bold',...
          'HorizontalAlignment','center', ...
          'Visible','off');
    end
   else
    if ID <= numPOIs
     if numFigure == 1, set(general.POI(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'String','','Visible','off'); end
     if numFigure == 2, set(general.POIZoom(ID).text,'Position',[POI.posicion(1) POI.posicion(2) 0],'String','','Visible','off'); end
     if numFigure == 1, set(general.POI(ID).plot,'XData',POI.posicion(1),'YData',POI.posicion(2),'Visible','off'); end
     if numFigure == 2, set(general.POIZoom(ID).plot,'XData',POI.posicion(1),'YData',POI.posicion(2),'Visible','off'); end
    else
     if numFigure == 1, set(general.POI(end).text,'Visible','off'); end
     if numFigure == 2, set(general.POIZoom(end).text,'Visible','off'); end
     if numFigure == 1, set(general.POI(end).plot,'Visible','off'); end
     if numFigure == 2, set(general.POIZoom(end).plot,'Visible','off'); end
     general.POI(end) = [];
    end
   end
  end
 else
  if ( numFigure == 1 && ( ~isfield(general,'POI') || ( isfield(general,'POI') && ( ID > numel(general.POI) ) ) ) ) || ...
     ( numFigure == 2 && ( ~isfield(general,'POIZoom') || ( isfield(general,'POIZoom') && ( ID > numel(general.POIZoom) ) ) ) )
   if numFigure == 1, general.POI(ID).text = text('Visible','off'); end
   if numFigure == 2, general.POIZoom(ID).text = text('Visible','off'); end
   if numFigure == 1, general.POI(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
                                                  'MarkerSize',3,... 
                                                   'MarkerEdgeColor','none',... % 'w',...
                                                   'MarkerFaceColor','none',...
                                                   'Visible','off');
   end
   if numFigure == 2, general.POIZoom(ID).plot = plot(POI.posicion(1),POI.posicion(2),'o',... % 'd'
                                                      'MarkerSize',3,... 
                                                      'MarkerEdgeColor','none',... % 'w',...
                                                      'MarkerFaceColor','none',...
                                                      'Visible','off');
   end
  else
   if ID <= numPOIs
    if numFigure == 1, set(general.POI(ID).text,'Visible','off'); end
    if numFigure == 2, set(general.POIZoom(ID).text,'Visible','off'); end
    if numFigure == 1, set(general.POI(ID).plot,'Visible','off'); end
    if numFigure == 2, set(general.POIZoom(ID).plot,'Visible','off'); end
   else
    if numFigure == 1, set(general.POI(end).text,'Visible','off'); end
    if numFigure == 2, set(general.POIZoom(end).text,'Visible','off'); end
    if numFigure == 1, set(general.POI(end).plot,'Visible','off'); end
    if numFigure == 2, set(general.POIZoom(end).plot,'Visible','off'); end
    if numFigure == 1, general.POI(end) = []; end
    if numFigure == 2, general.POIZoom(end) = []; end
   end
  end
 end
 graficos = graficos-1;
end
end