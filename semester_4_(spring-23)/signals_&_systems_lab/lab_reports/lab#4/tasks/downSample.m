function [y] = downSample(sig, sam)
    j = 1;
    for n = 1: sam: length(sig)
        y(1, j) = sig(1, n);
        j = j + 1;
    end
end