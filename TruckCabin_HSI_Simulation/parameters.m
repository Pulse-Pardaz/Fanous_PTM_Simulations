%% Truck Cabin Simulation Parameters
% =========================================================
% Project: Poultry Transport Cabin Environmental Control
% =========================================================

%% Simulation

Ts = 1;                  % Main control cycle [s]
SimulationTime = 600;   % Simulation duration [s]

%% Thermal Plant

Cth = 50000;             % Effective thermal mass [J/degC]
UA = 100;                % Cabin thermal conductance [W/degC]

Q_birds = 200;           % Bird heat generation [W]
Qcool = 3000;            % Fan cooling capacity [W]

T_initial = 25;          % Initial cabin temperature [degC]
RH_initial = 60;         % Initial cabin RH [%]

%% Ambient conditions

T_ambient_initial = 20;
RH_ambient = 50;

%% Sensor model

T_sensor_sigma = 0.2;
RH_sensor_sigma = 2.0;

%% Sensor processing

MedianWindow = 5;
MaxTempRate = 3;         % [degC/s]

%% Sensor fusion

% Start with the laboratory configuration:
% 2 regional modules / 2 SHT31 sensors

NumSensors = 2;

% Equal weights initially.
% These can later be changed according to sensor position.
SensorWeights = [0.5 0.5];

%% Age calibration

DeltaT_Base = 0;
DeltaT_Growing = 3;
DeltaT_Chick = 7;

%% Control

Hysteresis = 1;          % degC
PersistenceTime = 30;    % s

%% CAN node supervision

NodeOfflineCycles = 3;
NodeDetectionTimeout = 5;

%% Test

FanInitial = 0;