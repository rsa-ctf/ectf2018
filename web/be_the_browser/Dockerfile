# Base image
FROM python:2.7-slim

# Challenge author
MAINTAINER hehaichi@gmail.com

# Make sure everything's up-to-date
RUN apt-get update \
# Install dependencies
&&  pip install flask \
# Cleanup
&& rm -rf /var/lib/apt/lists/*

# Create the challenge directory
RUN mkdir -p /home/challenge /home/challenge/web

# Move the challenge file into the container
COPY web/ /home/challenge/web/

# Expose the required port
EXPOSE 40001

# Serve
CMD ["python", "/home/challenge/web/service.py"]

# docker build . -t number_place
# docker run -p 10101:10101 number_place