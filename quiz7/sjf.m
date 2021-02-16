function curProc = sjf(arrival, flagPreempt)

    %persistent variables
    persistent waitingP;
    persistent waitingPTime;
    persistent currentP;
    persistent currentPTimeRem;

    %isEmpty 
    if isempty(waitingP)
        waitingP = {};
    end

    if isempty(waitingPTime)
        waitingPTime = [];
    end

    if isempty(currentP)
        currentP = {};
    end

    if isempty(currentPTimeRem)
        currentPTimeRem = [];
    end

    if isempty(arrival)
        %nothing
    else
        waitingP{length(waitingP)+1}=arrival;   %append process
        waitingPTime(length(waitingPTime)+1)=arrival{2}; %append time of process
    end
    
    if flagPreempt == true
        if isempty(currentP)
            if ~isempty(waitingP)
                min = waitingP{1}; 
                min = min{2}; %min = min waitingPTime
                minindex = 1;
                for i=2:length(waitingP)
                    temp = waitingP{i};
                    temp = temp{2};
                    if temp<min
                        min = temp;
                        minindex = i;
                    end
                end
                currentP = waitingP{minindex};
                waitingP(minindex) = [];
                currentPTimeRem = currentP{2}-1;  %time -1 quantum
                currentP{2} = currentPTimeRem;
                curProc = currentP{1};
                %disp(curProc)
                return;
            else
                curProc='_';
                %disp(curProc)
                return;
            end
        else
            if currentPTimeRem == 0;
                if ~isempty(waitingP)
                    min = waitingP{1};
                    min = min{2};
                    minindex = 1;
                    for i=2:length(waitingP)
                        temp = waitingP{i};
                        temp = temp{2};
                        if temp<min
                            min = temp;
                            minindex = i;
                        end
                    end
                    currentP = waitingP{minindex};
                    waitingP(minindex) = [];
                    currentPTimeRem = currentP{2}-1;  %time -1 quantum
                    currentP{2} = currentPTimeRem;
                
                    curProc = currentP{1};
                    %disp(curProc)
                    return;
                else
                    curProc = '_';
                    return;
                end
            else
                curProc = currentP{1};
                %disp(curProc)
                currentPTimeRem = currentPTimeRem - 1; %mhpos thelei ena mesa?
                return;
            end
        end
    end
end
                
    
    
    
    
    
    
    
