%% carga el fichero ROSbag deseado
format longG, clc
ROSbag_file_default = '2023-10-11-14-28-09_splited.bag';
ROSbag_file = input(['Input the ROSbag filename (default = "', ROSbag_file_default, '") : ']);
if isempty(ROSbag_file) ROSbag_file = ROSbag_file_default; end
speed = input('Input the speed coefficient to accelerate the simulation (default = 1) : ');
if isempty(speed) speed = 1; end
rosbag('info',ROSbag_file);
bag = rosbag(ROSbag_file);

%: selecciona los topics deseados (cada bit indica un topic seleccionado)
ROStopics = {};
msgType = {};
pub = {};
idx = 1;
for i=1:height(bag.AvailableTopics)
  %: crea los publicadores para republicar mensajes
  try
    pub{idx} = rospublisher(bag.AvailableTopics.Row{i},char(bag.AvailableTopics.MessageType(i)),'IsLatching',false, 'DataFormat', 'struct');
    ROStopics{idx} = bag.AvailableTopics.Row{i};
    idx = idx+1;
  end
end
idx = idx-1;

%: selecciona el intervalo de tiempo deseado (por defecto, [bag.StartTime bag.EndTime])
interval =  [bag.StartTime bag.EndTime];

%: extrae los mensajes de los topics e intervalo de tiempo deseados
bagFullSelection = select(bag,'Topic',ROStopics,'Time',interval);
msgsFull = readMessages(bagFullSelection, 'DataFormat', 'struct');

%% prepara la sincronizacion para republicar los mensajes
disp('ROSbag_play is initialized with the ROSbag file.');
disp('Push ENTER key to continue with ROStopics republications ...');
pause;
disp('Running... wait the simulation is ended.');
startTimeNow = datetime('now'); idxROStopic = []; nextTime = 0; i = 1;
for i = 1:height(bagFullSelection.MessageList)
 while datetime('now')-startTimeNow < (1/speed)*seconds(nextTime); end
 topicName = char(bagFullSelection.MessageList.Topic(i));
 idxPub = find(matches(ROStopics,topicName));
 try
   send(pub{idxPub},msgsFull{i});
 end
 if i < height(bagFullSelection.MessageList), nextTime = bagFullSelection.MessageList.Time(i+1)-bagFullSelection.MessageList.Time(1); end
end
disp('ROSbag_play is finished.');