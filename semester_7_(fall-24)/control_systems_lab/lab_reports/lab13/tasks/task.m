% Define system parameters
num_plant = [1]; 
den_plant = [1 3 1]; 

% Create plant transfer function
plant_tf = tf(num_plant, den_plant);

% Create open-loop system (without feedback)
open_loop_sys = plant_tf;

% Create closed-loop system (with unity feedback)
closed_loop_sys = feedback(open_loop_sys, 1); 

% Plot step response of closed-loop system
figure;
step(closed_loop_sys);
hold on;

% Define PID controller gains
kp_gain = 1; 
ki_gain = 1; 
kd_gain = 1;

% Create PID controller object
pid_controller = pid(kp_gain, ki_gain, kd_gain);

% Create closed-loop system with PID controller
closed_loop_sys_pid = feedback(pid_controller * plant_tf, 1);

% Plot step response of closed-loop system with PID controller
step(closed_loop_sys_pid);
hold off;

% Add labels and title
xlabel('Time (seconds)');
ylabel('Output');
title('Step Response Comparison');
legend('Without PID', 'With PID');