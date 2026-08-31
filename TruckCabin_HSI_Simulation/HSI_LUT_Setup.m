%% HSI LUT based directly on the project RFP table
%
% HSI:
% 0 = Comfort
% 1 = Alert
% 2 = Danger
% 3 = Emergency
% 255 = invalid / outside defined range

clear HSI_T_bp HSI_RH_bp HSI_Table

%% Temperature breakpoints
%
% The RFP HSI table covers 20°C and upward.
%
% We use one breakpoint for each integer temperature from
% 20 through 39°C.

HSI_T_bp = 20:39;
LowTemp = 20;

%% RH breakpoints
%
% There are 10 RH regions in the RFP table.
%
% We intentionally DO NOT add 100 here.
% RH >= 92.5% is represented by the last column.

HSI_RH_bp = [ ...
    0 ...
    7.5 ...
    17.5 ...
    27.5 ...
    32.5 ...
    37.5 ...
    47.5 ...
    52.5 ...
    72.5 ...
    92.5 ];

%% RFP temperature boundaries for each RH region
%
% Column order:
%
% 1: RH < 7.5
% 2: 7.5 <= RH < 17.5
% 3: 17.5 <= RH < 27.5
% 4: 27.5 <= RH < 32.5
% 5: 32.5 <= RH < 37.5
% 6: 37.5 <= RH < 47.5
% 7: 47.5 <= RH < 52.5
% 8: 52.5 <= RH < 72.5
% 9: 72.5 <= RH < 92.5
% 10: RH >= 92.5

ComfortHigh = [ ...
    27 27 25 25 25 23 23 23 21 21 ];

AlertHigh = [ ...
    35 33 31 31 29 29 27 27 25 25 ];

DangerHigh = [ ...
    39 39 37 35 35 33 33 31 29 27 ];

EmergencyExists = [ ...
    false false true true true true true true true true ];

%% Create table
%
% Size = 20 temperatures × 10 RH regions

HSI_Table = 255 * ones( ...
    length(HSI_T_bp), ...
    length(HSI_RH_bp));

%% Fill HSI table

for r = 1:length(HSI_T_bp)

    T = HSI_T_bp(r);

    for c = 1:length(HSI_RH_bp)

        % Comfort
        if T < ComfortHigh(c)

            HSI_Table(r,c) = 0;

        % Alert
        elseif T < AlertHigh(c)

            HSI_Table(r,c) = 1;

        % Danger
        elseif T < DangerHigh(c)

            HSI_Table(r,c) = 2;

        % Emergency
        elseif EmergencyExists(c)

            HSI_Table(r,c) = 3;

        % No defined HSI region
        else

            HSI_Table(r,c) = 255;

        end

    end

end

%% Display results

disp('Temperature breakpoints:')
disp(HSI_T_bp)

disp('RH breakpoints:')
disp(HSI_RH_bp)

disp('HSI table:')
disp(HSI_Table)