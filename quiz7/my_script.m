﻿%
% SCRIPT: MAIN
%
%   Main script to call sjf.m
%


%% CLEAN-UP

clear
close all


%% PARAMETERS

% ..... simulation properties
nProc          = 5;   % number of process
maxDuration    = 9;   % maximum processing time (per process)
maxArrivalTime = 15;  % maximum arrival timestep

% ..... preemptive or not?
preempt = true;

%% (BEGIN)

fprintf('\n *** begin %s ***\n\n',mfilename);

%% PREPARE EXPERIMENT

fprintf( '...prepare experiment...\n' ); 

a = sort(randperm(maxArrivalTime,nProc));
d = randi(maxDuration,1,nProc);
n = cell(1,sum(d)+max(a));
for i = 1:nProc
  n{a(i)} = {sprintf('P%d',i), d(i)};
end

fprintf( '   - DONE\n');


%% SIMULATION

fprintf( '...simulation...\n' ); 

for i = 1:length(n)
  fprintf(' .Timestep %03d | ', i)
  
  job = n{i};
  %disp(sjf(job, preempt))
  curProc = sjf(job, preempt);
  
  if ~isempty( job )
    fprintf('Job (%s,%3d) submitted | ',job{:})
  else
    fprintf('                       | ')
  end

  
  if strcmpi(curProc, '_')
    fprintf('IDLE      \n')
  else
    fprintf('Running %s\n', curProc)
  end
    
end


fprintf( '   - DONE\n');


%% (END)

fprintf('\n *** end %s ***\n\n',mfilename);


%%------------------------------------------------------------
%
% AUTHORS
%
%   Dimitris Floros                         fcdimitr@auth.gr
%
% VERSION       0.1
%
% CHANGELOG 
%
%   0.1 (Jan 14, 2020) - Dimitris
%       * initial implementation
%
% TIMESTAMP     <Jan 14, 2020: 14:01:07 Dimitris>
%
% ------------------------------------------------------------
