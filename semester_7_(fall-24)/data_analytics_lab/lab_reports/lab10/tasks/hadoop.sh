cat weather.csv | #read the data
python mapper.py  | # separate the data into date and temperature
python reducer.py; # find the lowest and highest temperatures