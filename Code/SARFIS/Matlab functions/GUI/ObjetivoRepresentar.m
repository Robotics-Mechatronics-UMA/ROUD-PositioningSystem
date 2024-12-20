function [] = ObjetivoRepresentar( handles,entorno,objetivo,ID,numObjetivos,numFigure )
global LoRa

%%%%% OJO: No está implementado el uso de los últimos argumentos de la
%%%%% función por no utilizarse durante las Jornadas 2023

%% Comprueba que la posición del objetivo esté dentro de las dimensiones del entorno representado
minimoX = entorno.minX; maximoX = entorno.minX+entorno.dimX*entorno.deltaXY;
minimoY = entorno.minY; maximoY = entorno.minY+entorno.dimY*entorno.deltaXY;
if isfield(objetivo.user,'posicion')
 valX = objetivo.user.posicion(1); valY = objetivo.user.posicion(2);
end
warnPos = isfield(objetivo.user,'posicion') && (valX < minimoX || valX > maximoX || valY < minimoY || valY > maximoY);
%warnPos = (valX < minimoX || valX > maximoX || valY < minimoY || valY > maximoY);

%% Representa gráficamente el objetivo en el entorno.
graficos = 1; % if entorno.ejemplo == 0 graficos = 2; end
while graficos ~= 0
 if graficos == 2
  subplot 121;
% else
%  if entorno.ejemplo == 0 subplot 122; end
 end
 %% determinación del color en función de prioridad del objetivo
 switch objetivo.user.prioridad
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
 if isfield(objetivo.user,'posicion') && ~isempty(objetivo.user.posicion)
  vertices = [-0.50 -0.50 +0.50 +0.50 -0.50
              -0.50 +0.50 +0.50 -0.50 -0.50]';
  if objetivo.user.aproximacion < .035*(handles.figura.XLim(2)-handles.figura.XLim(1))
   escala = diag([1 1])*.035*(handles.figura.XLim(2)-handles.figura.XLim(1));
  else
   escala = diag([objetivo.user.aproximacion objetivo.user.aproximacion]);
  end
  vertices = (escala*vertices');
  vertices = vertices + repmat(objetivo.user.posicion', 1, size(vertices, 2));
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
  if ~warnPos
   % if objetivo.user.prioridad > 3, color = 'white'; else, color = 'black'; end
   % prompt = {['{\color{red}\fontsize{16}',char(9708),char(10304),char(10308),char(10310),char(10311),'} ',num2str(ID)]
   %           objetivo.user.idFull};
   if objetivo.user.visible
    nivelRSSI = ['\color{black}',char(9601)];
    if     min(objetivo.automatic.rssi{1}(:)) < objetivo.user.minUmbral, nivelRSSI = ['\color{black}',char(9601)];
    elseif min(objetivo.automatic.rssi{1}(:)) < (objetivo.user.minUmbral+objetivo.user.maxUmbral)/2, nivelRSSI = ['\color{orange}',char(9603)];
    elseif min(objetivo.automatic.rssi{1}(:)) < objetivo.user.maxUmbral, nivelRSSI = ['\color{orange}',char(9605)];
    elseif min(objetivo.automatic.rssi{1}(:)) >= objetivo.user.maxUmbral, nivelRSSI = ['\color[rgb]{0 .5 .5}',char(9608)];
    end
    % prompt = {['{\color{red}\fontsize{16}',char(9650),char(9709),char(11044),'\fontsize{9}',nivelRSSI,'} ',num2str(ID)]
    %           objetivo.user.idFull};
    if isempty(objetivo.user.idFull)
     prompt = {['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{16}',char(9650),'\color{black}\fontsize{9}',nivelRSSI,'} ',num2str(ID)]};
    else
     prompt = {['{\color[rgb]{',num2str(color(1)),',',num2str(color(2)),',',num2str(color(3)),'}\fontsize{16}',char(9650),'\color{black}\fontsize{9}',nivelRSSI,'} ',num2str(ID)]
               objetivo.user.idFull};
    end
    for j = 1:length(LoRa.keys)
     if objetivo.automatic.enableMap(j)
      key = char(LoRa.keys{j}(4));
      prompt{length(prompt)+1} = ['{\color{gray}',key,'=',char(sprintf("%.1f",objetivo.automatic.valor(j))),char(LoRa.keys{j}(6)),'}'];
     end
    end
    text(objetivo.user.posicion(1),objetivo.user.posicion(2),prompt,...
         'Background','w',...
         'Color','k',...%'FontWeight','bold',...
         'HorizontalAlignment','center');
   else
    plot(objetivo.user.posicion(1),objetivo.user.posicion(2),'o',...
         'MarkerSize',10,...
         'MarkerEdgeColor','w',...
         'MarkerFaceColor',color);
   end
  end
 end
 graficos = graficos-1;
end
end