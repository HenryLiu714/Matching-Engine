# Use Python 3.11 slim image as the base image
FROM python:3.11-slim

# Set the working directory to the main project folder
WORKDIR /app

# Copy the requirements.txt file into the container
COPY requirements.txt .

# Install the Python dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Copy the subfolder containing main.py to the container
COPY ./trade_messaging_service /app/trade_messaging_service

# Expose the port the server will run on
EXPOSE 56001

# Run the server
CMD ["python", "-u", "/app/trade_messaging_service/main.py"]