%% HSI Parameters

% RH regions from the RFP
RH_Bounds = [7.5 17.5 27.5 32.5 37.5 ...
             47.5 52.5 72.5 92.5];

% HSI state coding
% 0 = Comfort
% 1 = Alert
% 2 = Danger
% 3 = Emergency
% 4 = LowTemp

Comfort = 0;
Alert = 1;
Danger = 2;
Emergency = 3;
LowTemp = 4;

%% Operating temperature range

T_Min = 20;
T_Max = 39;