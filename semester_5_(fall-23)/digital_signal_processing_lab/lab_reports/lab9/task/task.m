clc
clear 
close all;

% Transmitter
%% Import Voices
[maleVoice, Fs1] = audioread('funniest-thing.wav');
[femaleVoice, Fs2] = audioread('self-destruct-sequence.wav');
[randomVoice, Fs3] = audioread('monkey-scream.wav');

%% Play the voices
% Define the duration to play (5 seconds)
duration = 5;

% Calculate the number of samples for 5 seconds
% Assuming the sampling rate (Fs1, Fs2, Fs3) is the same for all files
numSamples = Fs1 * duration;

% Extract the first 5 seconds of each filtered voice
segmentMale = maleVoice(1:numSamples);
segmentFemale = femaleVoice(1:numSamples);
segmentRandom = randomVoice(1:numSamples);

% Play the segments (one after the other, with a pause in between)
sound(segmentMale, Fs1);
pause(duration + 1); % Pause for the duration of the clip plus a buffer

sound(segmentFemale, Fs2);
pause(duration + 1); % Pause for the duration of the clip plus a buffer

sound(segmentRandom, Fs3);
pause(duration + 1); % Pause for the duration of the clip plus a buffer

%% Analyze the spectrum
Y1 = fft(maleVoice);
Y2 = fft(femaleVoice);
Y3 = fft(randomVoice);

P2_1 = abs(Y1/length(maleVoice));
P1_1 = P2_1(1:length(maleVoice)/2+1);
P1_1(2:end-1) = 2*P1_1(2:end-1);

P2_2 = abs(Y2/length(femaleVoice));
P1_2 = P2_2(1:length(femaleVoice)/2+1);
P1_2(2:end-1) = 2*P1_2(2:end-1);

P2_3 = abs(Y3/length(randomVoice));
P1_3 = P2_3(1:length(randomVoice)/2+1);
P1_3(2:end-1) = 2*P1_3(2:end-1);

f1 = Fs1*(0:(length(maleVoice)/2))/length(maleVoice);
f2 = Fs2*(0:(length(femaleVoice)/2))/length(femaleVoice);
f3 = Fs3*(0:(length(randomVoice)/2))/length(randomVoice);

figure
subplot(3,1,1);
plot(f1,P1_1) ;
title('Spectrum of Male Voice');
xlabel('f (Hz)');
ylabel('|P1(f)|');

subplot(3,1,2);
plot(f2,P1_2) ;
title('Spectrum of Female Voice');
xlabel('f (Hz)');
ylabel('|P1(f)|');

subplot(3,1,3);
plot(f3,P1_3) 
title('Spectrum of Random Voice')
xlabel('f (Hz)')
ylabel('|P1(f)|')

%% Passing the signals to LPF

% Design a low-pass filter (example: Butterworth)
cutoff_frequency = 3000; 
order = 6;

% Normalize the frequency
Wn = cutoff_frequency/(Fs1/2); 

% Design the filter
[b, a] = butter(order, Wn, 'low');

% Apply the filter
filteredMaleVoice = filter(b, a, maleVoice);
filteredFemaleVoice = filter(b, a, femaleVoice);
filteredRandomVoice = filter(b, a, randomVoice);

% Plot the results
figure;
subplot(3, 1, 1);
plot(filteredMaleVoice);
title('Filtered Male Voice');

subplot(3, 1, 2);
plot(filteredFemaleVoice);
title('Filtered Female Voice');

subplot(3, 1, 3);
plot(filteredRandomVoice);
title('Filtered Random Voice');

%% Play the filtered voices
% Extract the first 5 seconds of each filtered voice
segmentMale = filteredMaleVoice(1:numSamples);
segmentFemale = filteredFemaleVoice(1:numSamples);
segmentRandom = filteredRandomVoice(1:numSamples);

% Play the segments (one after the other, with a pause in between)
sound(segmentMale, Fs1);
pause(duration + 1); % Pause for the duration of the clip plus a buffer

sound(segmentFemale, Fs2);
pause(duration + 1); % Pause for the duration of the clip plus a buffer

sound(segmentRandom, Fs3);

%% Modulating the voices signals with different carriers

% Define carrier frequencies for each voice signal
carrierFreqMale = Fs1/4; % Example frequency in Hz
carrierFreqFemale = Fs1/5; % Example frequency in Hz
carrierFreqRandom = Fs1/6; % Example frequency in Hz

% Assuming that the sampling rates for all signals are the same (Fs1)
% If not, you need to resample them to a common sampling rate

% Amplitude modulate the signals
modulatedMale = ammod(segmentMale, carrierFreqMale, Fs1);
modulatedFemale = ammod(segmentFemale, carrierFreqFemale, Fs1);
modulatedRandom = ammod(segmentRandom, carrierFreqRandom, Fs1);

% Plot the modulated signals
figure
subplot(3, 1, 1);
plot(modulatedMale);
title('AM Modulated Male Voice');

subplot(3, 1, 2);
plot(modulatedFemale);
title('AM Modulated Female Voice');

subplot(3, 1, 3);
plot(modulatedRandom);
title('AM Modulated Random Voice');

% Channel
%% Creating and adding a channel noise to the modulated signals:
noiseLevel = 0.01; % Adjust this value as needed
noiseMale = noiseLevel * randn(size(modulatedMale));
noiseFemale = noiseLevel * randn(size(modulatedFemale));
noiseRandom = noiseLevel * randn(size(modulatedRandom));

% Create noisy signals
noisyMale = modulatedMale + noiseMale;
noisyFemale = modulatedFemale + noiseFemale;
noisyRandom = modulatedRandom + noiseRandom;

% Plot the original noise and the noisy signals
figure
subplot(3, 2, 1);
plot(noiseMale);
title('Noise for Male Voice');

subplot(3, 2, 2);
plot(noisyMale);
title('Noisy AM Modulated Male Voice');

subplot(3, 2, 3);
plot(noiseFemale);
title('Noise for Female Voice');

subplot(3, 2, 4);
plot(noisyFemale);
title('Noisy AM Modulated Female Voice');

subplot(3, 2, 5);
plot(noiseRandom);
title('Noise for Random Voice');

subplot(3, 2, 6);
plot(noisyRandom);
title('Noisy AM Modulated Random Voice');


% Receiver
%% Demodulate the noisy signals
demodulatedMale = amdemod(noisyMale, carrierFreqMale, Fs1);
demodulatedFemale = amdemod(noisyFemale, carrierFreqFemale, Fs1);
demodulatedRandom = amdemod(noisyRandom, carrierFreqRandom, Fs1);

% Plot the demodulated signals
figure
subplot(3, 1, 1);
plot(demodulatedMale);
title('Demodulated Male Voice');

subplot(3, 1, 2);
plot(demodulatedFemale);
title('Demodulated Female Voice');

subplot(3, 1, 3);
plot(demodulatedRandom);
title('Demodulated Random Voice');

%% Design a low-pass filter
cutoffFrequency2 = 3000; % Change as needed, typically a bit above voice frequency range
order2 = 6; % Filter order, can be adjusted

% Normalize the frequency
Wn2 = cutoffFrequency2/(Fs1/2); 

% Design the filter (Butterworth filter used as an example)
[b2, a2] = butter(order2, Wn2, 'low');

% Apply the filter to the demodulated signals
filteredMale = filter(b2, a2, demodulatedMale);
filteredFemale = filter(b2, a2, demodulatedFemale);
filteredRandom = filter(b2, a2, demodulatedRandom);

% Plot the filtered signals
figure
subplot(3, 1, 1);
plot(filteredMale);
title('Filtered Demodulated Male Voice');

subplot(3, 1, 2);
plot(filteredFemale);
title('Filtered Demodulated Female Voice');

subplot(3, 1, 3);
plot(filteredRandom);
title('Filtered Demodulated Random Voice');

%% Play the filtered, demodulated male voice
sound(filteredMale, Fs1);

% Pause for the duration of the clip plus a small buffer
pause(length(filteredMale)/Fs1 + 1);

% Play the filtered, demodulated female voice
sound(filteredFemale, Fs1);

% Pause for the duration of the clip plus a small buffer
pause(length(filteredFemale)/Fs1 + 1);

% Play the filtered, demodulated random voice
sound(filteredRandom, Fs1);

% Pause for the duration of the clip plus a small buffer
pause(length(filteredRandom)/Fs1 + 1);
