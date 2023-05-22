function causal_signal = sig_causal(signal, position)
    % Check if the position vector is valid
    if ~isvector(position)
        error('Position vector must be a valid vector.');
    end
    
    % Check if the position vector is monotonically increasing
    if ~issorted(position) || any(diff(position) <= 0)
        error('Position vector must be monotonically increasing.');
    end
    
    % Find the minimum position value
    min_position = min(position);
    
    % Check if the minimum position value is non-negative
    if min_position < 0
        error('Position vector must contain non-negative values.');
    end
    
    % Calculate the shift amount to make the signal causal
    shift_amount = min_position;
    
    % Shift the signal to make it causal
    causal_signal = circshift(signal, -shift_amount);
end
