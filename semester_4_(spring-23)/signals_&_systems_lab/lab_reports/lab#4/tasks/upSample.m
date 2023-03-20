function [y]=upSample(sig, sam, N)
    y = zeros(size(sig));
    for n = 1: sam : length(sig) - 1
        y(n * N + 1) = sig(n + 1);
    end
end