% Function to calculate Routh-Hurwitz table
function rh_table = routh_table(coeffs)
    n = length(coeffs);
    rh_table = zeros(n, ceil(n/2));
    
    % Fill the first two rows
    rh_table(1, :) = coeffs(1:2:end);
    rh_table(2, 1:min(length(coeffs(2:2:end)), size(rh_table, 2))) = coeffs(2:2:end);
    
    % Compute the Routh-Hurwitz table
    for i = 3:n
        for j = 1:ceil(n/2) - 1
            if rh_table(i-1, 1) == 0
                rh_table(i-1, 1) = 1e-4; % Avoid division by zero
            end
            rh_table(i, j) = -1 * (rh_table(i-1, 1) * rh_table(i-2, j+1) - ...
                                   rh_table(i-2, 1) * rh_table(i-1, j+1)) / rh_table(i-1, 1);
        end
    end
end