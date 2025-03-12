# Mapper: mapper_high_low_temp.py
import sys
import csv

def read_input(file):
    for line in file:
        yield line.strip()

# Process each line from stdin
for line in read_input(sys.stdin):
    try:
        # Parse the CSV line
        reader = csv.reader([line])
        for row in reader:
            if len(row) != 2:
                continue  # Skip lines with incorrect format
            date, temp = row
            print(f"{date}\t{temp}")  # Emit date and temperature as key-value pairs
    except Exception as e:
        continue  # Skip lines that cause parsing errors
