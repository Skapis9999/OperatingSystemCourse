function status = pageFaults(pageReq, nFrame)


    persistent frames = zeros(nFrame, 1);
    persistent times = zeros(nFrame, 1);
    
    found=0;        %flag
    for j=1:nFrame
        if(frames(j)==pageReq)
            found=1;        %flag found positive
            times(j)=time;
            break;
        end
    end
    
    if(found==1)
        status = 'H';   
        return
    end
    status='M';
    [M,I] = min(times);     %min and index of min
    times(I) = time;
    frames(I) = pageReq;
    
end


