FROM python:alpine
WORKDIR /app 
COPY requirements.txt /app/requirements.txt
RUN pip install -r requirements.txt
EXPOSE 5000
COPY . /app
CMD python ./app.py
