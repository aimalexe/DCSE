# Reducer: reducer_high_low_temp.py
import sys

highest_temp = None
highest_date = None
lowest_temp = None
lowest_date = None

# Process each key-value pair from stdin
for line in sys.stdin:
    try:
        date, temp = line.strip().split("\t")
        temp = float(temp)

        # Check for highest temperature
        if highest_temp is None or temp > highest_temp:
            highest_temp = temp
            highest_date = date

        # Check for lowest temperature
        if lowest_temp is None or temp < lowest_temp:
            lowest_temp = temp
            lowest_date = date

    except Exception as e:
        continue  # Skip lines with errors

# Emit the results
if highest_date and highest_temp is not None:
    print(f"Highest Temperature: {highest_temp}°C on {highest_date}")
if lowest_date and lowest_temp is not None:
    print(f"Lowest Temperature: {lowest_temp}°C on {lowest_date}")
