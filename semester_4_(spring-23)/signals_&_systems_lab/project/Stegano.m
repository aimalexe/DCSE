% Clear the existing workspace
clear all;

% Clear the command window
clc;

% Read the input image
input = imread('img.png');

% Convert image to grayscale if it is RGB
if size(input, 3) == 3
    input = rgb2gray(input);
end

% Resize the image to the required size
input = imresize(input, [512 512]);

% Message to be embedded
message = 'Testing';

% Length of the message where each character is 8 bits
len = length(message) * 8;

% Get all the ASCII values of the characters of the message
ascii_value = uint8(message);

% Convert the decimal values to binary
bin_message = transpose(dec2bin(ascii_value, 8));

% Get all the binary digits in a separate row
bin_message = bin_message(:);

% Length of the binary message
N = length(bin_message);

% Converting the char array to numeric array
bin_num_message = str2num(bin_message);

% Initialize output as input
output = input;

% Get height and width for traversing through the image
height = size(input, 1);
width = size(input, 2);

% Counter for the number of embedded bits
embed_counter = 1;

% Traverse through the image
for i = 1 : height
    for j = 1 : width

        % If more bits are remaining to embed
        if (embed_counter <= len)

            % Finding the Least Significant Bit of the current pixel
            LSB = bitget(input(i, j), 1);

            % Find whether the bit is the same or needs to change
            temp = xor(LSB, bin_num_message(embed_counter));

            % Updating the output to input + temp
            output(i, j) = bitset(input(i, j), 1, temp);

            % Increment the embed counter
            embed_counter = embed_counter + 1;
        end

    end
end

% Write both the input and output images to local storage
% Mention the path to a folder here.
imwrite(input, 'D:\programing\my_github_account\DCSE\semester_4_(spring-23)\signals_&_systems_lab\project\imgbg.png');
imwrite(output, 'D:\programing\my_github_account\DCSE\semester_4_(spring-23)\signals_&_systems_lab\project\output.png');


filename = 'D:\programing\my_github_account\DCSE\semester_4_(spring-23)\signals_&_systems_lab\project\output.xlsx';
xlswrite(filename, output);
